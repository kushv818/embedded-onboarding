#include <allocation.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

typedef struct {
  int id;            // Unique identifier for this allocation
  size_t size;       // Size in bytes
  void* addr;        // Address returned by malloc
} allocation_t;

static allocation_t* allocation_array = NULL;
int allocation_count = 0;

void add_allocation(size_t size) {

    allocation_count++;

    //reallocating memory for new allocation
    allocation_array = realloc(allocation_array, sizeof(allocation_t) * (allocation_count));

    //adding allocation to array
    allocation_array[allocation_count - 1] = (allocation_t){0};

    void* allocation = malloc(size);
    allocation_array[allocation_count - 1].id = generate_unique_id(); // need to implement this function
    allocation_array[allocation_count - 1].size = size;
    allocation_array[allocation_count - 1].addr = allocation;
    
}

void remove_allocation(int id) {
    // Implementation of remove_allocation

}

void print_allocations() {
    // Implementation of print_allocations
}
