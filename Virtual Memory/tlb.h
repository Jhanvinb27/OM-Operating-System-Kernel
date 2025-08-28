#ifndef TLB_H
#define TLB_H

#include "common.h"

void flush_tlb_entry(uint32_t vaddr);
void flush_tlb();

#endif
