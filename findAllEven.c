#include <stdio.h>
#include <stdlib.h>

int* findAllEven(int arr[], int size);

int main() {
    int arr[5] = {1 ,2, 3, 4, 6};
    int size = 5;
 
    int* retArr = findAllEven(arr, 5);
    for (int x = 0; x < 5; x++) {
        printf("Array [%d]: %d\n", x, retArr[x]);
    }
    free(retArr);
}

int* findAllEven(int arr[], int size) {
    int j = 0, count = 1;
    int* newArr = (int*)malloc(size * sizeof(int));
    for (j = 0; j < size; j++) {
        if (arr[j] % 2 == 0) {
            newArr[count] = arr[j];
            count++;
        }
    }
    newArr[0] = count - 1;
    return newArr;
}