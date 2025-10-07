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

    //temp size since allocation not guaranteed to succeed
    size_t new_capacity = allocation_count + 1;

    //resizing array to hold new allocation
    void* temp = realloc(allocation_array, sizeof(allocation_t) * new_capacity);
    if (temp == NULL) {
        printf("Memory allocation failed while adding allocation\n");
        return;
    }

    allocation_array = temp;

    //zeroing out new allocation entry
    allocation_array[allocation_count - 1] = (allocation_t){0};

    void* allocation = malloc(size);
    if (allocation == NULL) {
        printf("Memory allocation failed for requested size %zu\n", size);
        return;
    }

    allocation_array[allocation_count - 1].id = generate_unique_id(); // need to implement this function
    allocation_array[allocation_count - 1].size = size;
    allocation_array[allocation_count - 1].addr = allocation;

    allocation_count++;
}

void remove_allocation(int id) {
    // Implementation of remove_allocation
    if (allocation_array == NULL || allocation_count == 0) {
        printf("No allocations to remove\n");
        return;
    }

    for (int i =0; i< allocation_count; i++) {
        if (allocation_array[i].id == id) {
            //freeing memory
            free(allocation_array[i].addr);

            // Shift remaining allocations down
            for (int j = i; j < allocation_count - 1; j++) {
                allocation_array[j] = allocation_array[j + 1];
            }
            allocation_count--;
            allocation_array = realloc(allocation_array, sizeof(allocation_t) * allocation_count);

            // If no allocations left, free the array and set pointer to NULL
            if (allocation_count == 0) {
                free(allocation_array);
                allocation_array = NULL;
            }
            printf("Allocation with ID %d removed\n", id);
            return;
        }
    }
    printf("Allocation with ID %d not found\n", id);
    return;
}

void print_allocations() {
    // Implementation of print_allocations
    if (allocation_array == NULL || allocation_count == 0) {
        printf("No current allocations\n");
        return;
    }
    printf("Current Allocations:\n");
    for (int i = 0; i < allocation_count; i++) {
        printf("ID: %d, Size: %zu, Address: %p\n", allocation_array[i].id, allocation_array[i].size, allocation_array[i].addr);
    }
    return;
}
