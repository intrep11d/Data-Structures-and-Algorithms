#include<stdio.h>
#include<stdlib.h>

void display(int* newArr, int size);
int* runningSum(int* arr, int size, int *returnSize);



int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5, num = 10, returnSize;

    int* mallocArr = runningSum(arr, size, &returnSize);
    display(mallocArr, returnSize);
    free(mallocArr);


    
}

int* runningSum(int* arr, int size, int *returnSize) {
    int* newArr = (int*)malloc(sizeof(int)*size);
    int sum = 0;
    for(int x = 0; x < size; ++x) {
        sum += arr[x];
        newArr[x] = sum;
    }
    *returnSize = size;
    return newArr;
}

void display(int* newArr, int size) {
    printf("New Array: [ ");
        for(int y = 0; y < size; y++) {
            printf(" %d ", newArr[y]);
            if (y != size - 1) {
                printf("|");
            }
        }
        printf("]");
}


