#include "memory.h"
#include "scsi.h"
#include "util.h"
#include "kernel.h"

static page_map_entry_t page_map[PAGEABLE_PAGES];

void init_memory() {
    // Initialize kernel and free pages
    for (int i = 0; i < PAGEABLE_PAGES; i++) {
        page_map[i].physical_addr = i * PAGE_SIZE;
        page_map[i].virtual_addr = 0;
        page_map[i].pinned = 0;
        page_map[i].swap_loc = -1;
        page_map[i].used = 0;
    }
}

uint32_t page_addr(int page_index) {
    if (page_index < 0 || page_index >= PAGEABLE_PAGES) return 0;
    return page_map[page_index].physical_addr;
}

int page_alloc() {
    for (int i = 0; i < PAGEABLE_PAGES; i++) {
        if (!page_map[i].used && !page_map[i].pinned) {
            page_map[i].used = 1;
            memset((void*)page_map[i].physical_addr, 0, PAGE_SIZE);
            return i;
        }
    }
    // If no free page, select one to swap out
    int victim = page_replacement_policy();
    page_swap_out(victim);
    page_map[victim].used = 1;
    return victim;
}
