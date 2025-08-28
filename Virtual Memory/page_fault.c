#include "memory.h"
#include "kernel.h"

void page_fault_handler(uint32_t fault_addr) {
    // Find page index corresponding to fault_addr
    int page_index = -1;
    for (int i = 0; i < PAGEABLE_PAGES; i++) {
        if (page_map[i].virtual_addr == (fault_addr & 0xFFFFF000)) {
            page_index = i;
            break;
        }
    }

    if (page_index < 0) {
        // Allocate a new page
        page_index = page_alloc();
        page_map[page_index].virtual_addr = fault_addr & 0xFFFFF000;
    }

    // Bring the page in if swapped
    page_swap_in(page_index);

    flush_tlb_entry(fault_addr);
}
