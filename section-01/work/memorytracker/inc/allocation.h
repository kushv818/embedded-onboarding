#ifndef ALLOCATION_H
#define ALLOCATION_H

#include <stddef.h>

void add_allocation(int size);
void remove_allocation(int id);
void print_allocations();

#endif // ALLOCATION_H