#ifndef ALLOCATION_H
#define ALLOCATION_H

#include <stddef.h>

void add_allocation(size_t size);
void remove_allocation(int id);
void print_allocations();

#endif // ALLOCATION_H