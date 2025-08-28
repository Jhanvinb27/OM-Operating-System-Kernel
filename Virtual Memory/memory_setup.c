#include "memory.h"
#include "kernel.h"
#include "util.h"

void setup_page_table(pcb_t *pcb) {
    uint32_t *page_dir = (uint32_t*)page_alloc();
    pcb->page_directory = page_dir;

    // Map kernel and screen memory
    for (int i = 0; i < N_KERNEL_PTS; i++) {
        uint32_t *pt = (uint32_t*)page_alloc();
        for (int j = 0; j < PAGE_N_ENTRIES; j++) {
            pt[j] = (i * PAGE_N_ENTRIES + j) * PAGE_SIZE | 3; // Present + RW
        }
        page_dir[i] = ((uint32_t)pt) | 3;
    }

    // Allocate stack pages for process
    for (int i = 0; i < N_PROCESS_STACK_PAGES; i++) {
        int page_idx = page_alloc();
        page_map[page_idx].virtual_addr = PROCESS_STACK + i * PAGE_SIZE;
    }

    // Load process code/data into pages
    // This would be done via copying from a process image (simplified here)
}
