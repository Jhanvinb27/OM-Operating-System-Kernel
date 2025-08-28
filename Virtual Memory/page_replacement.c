#include "memory.h"

int page_replacement_policy() {
    // Simple FIFO replacement
    for (int i = 0; i < PAGEABLE_PAGES; i++) {
        if (!page_map[i].pinned && page_map[i].used) return i;
    }
    return 0; // fallback
}
