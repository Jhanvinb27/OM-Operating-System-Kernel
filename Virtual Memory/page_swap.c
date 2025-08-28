#include "memory.h"
#include "scsi.h"
#include "kernel.h"

void page_swap_out(int page_index) {
    if (page_map[page_index].pinned) return;

    // Write page to disk
    int swap_loc = page_map[page_index].swap_loc;
    if (swap_loc < 0) swap_loc = allocate_swap_space();
    scsi_write(swap_loc, (void*)page_map[page_index].physical_addr, PAGE_SIZE);

    page_map[page_index].used = 0;
    page_map[page_index].swap_loc = swap_loc;
}

void page_swap_in(int page_index) {
    if (page_map[page_index].used) return;

    int swap_loc = page_map[page_index].swap_loc;
    scsi_read(swap_loc, (void*)page_map[page_index].physical_addr, PAGE_SIZE);

    page_map[page_index].used = 1;
}
