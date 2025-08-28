#ifndef MEMORY_H
#define MEMORY_H

#include "common.h"
#include "kernel.h"

#define PAGE_SIZE 4096
#define PAGE_N_ENTRIES 1024
#define N_KERNEL_PTS 1
#define N_PROCESS_STACK_PAGES 4
#define PAGEABLE_PAGES 24

typedef struct page_map_entry {
    uint32_t physical_addr;
    uint32_t virtual_addr;
    int pinned;          // 1 if the page cannot be swapped
    int swap_loc;        // Location on disk if swapped out
    int used;            // 1 if the page is in use
} page_map_entry_t;

// Function prototypes
void init_memory();
uint32_t page_addr(int page_index);
void setup_page_table(pcb_t *pcb);
int page_alloc();
void page_swap_out(int page_index);
void page_swap_in(int page_index);
void page_fault_handler(uint32_t fault_addr);

#endif
