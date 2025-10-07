#include <stdio.h>
#include "../inc/allocation.h"

int main(){

printf("Adding 3 allocations\n");

//add 3 allocations
add_allocation(100);
add_allocation(200);
add_allocation(300);

//print all
print_allocations();

//remove non-existent id
remove_allocation(5);

//remove one by id
remove_allocation(2);

//print again
print_allocations();

//free all at the end
remove_allocation(1);
remove_allocation(3);
print_allocations();

//removing non-existent id
remove_allocation(5);

return 0;
}