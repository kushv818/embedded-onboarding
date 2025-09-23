#include <stdio.h>
#include <stdlib.h>


void FizzBuzz(int n){
        if (n % 3 == 0 && n % 5 == 0){
            printf("FizzBuzz\n");
        }
        else if (n % 3 == 0){
            printf("Fizz\n");
        }
        else if (n % 5 == 0){
            printf("Buzz\n");
        }
        else{
            printf("%d\n", n);
        }
}

int compare_desc(const void *a, const void *b){
    return (*(int*)b - *(int*)a);
}

int main(){
    printf("Hello, World!\n");
    int* arr = (int *)malloc(sizeof(int) * 20);

    printf("memory allocation check\n");
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    printf("populating array values\n");
    for (int i = 0; i < 20; i++){
        arr[i] = i+1;
    }

    printf("running fizzbuzz on array values\n");
    for (int i = 0; i < 20; i++){
        FizzBuzz(arr[i]);
    }

    printf("running fizzbuzz from 1-30\n");
    for (int i = 1; i <= 30; i++){
        FizzBuzz(i);
    }

    //defining qsort for integers and running it dynamically allocated buffer

    qsort(arr,20,sizeof(int),compare_desc);
    for (int i = 0; i < 20; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}