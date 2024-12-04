#include <stdio.h>
#include <stdlib.h>

int* findDuplicate(int A[], int size);
void printArray(int A[], int size);
int main() {
    int arr[] = {1, 2, 2, 3, 4, 5, 6, 7, 6};
    int size = 9;

    int* retArr = findDuplicate(arr, size);
    printArray(retArr, size);
}

int* findDuplicate(int A[], int size) {
    int x = 0, j = 0;
    int* sortArr = (int*)malloc(size * sizeof(int));

    for (x = 0; x < size; x++) {
        if (A[x] / A[x] != 1) {
            sortArr[j] = A[x];
            j++;
        }
    }
    return sortArr;
}

void printArray(int A[], int size) {
    int y = 0;
    for (y = 0; y < size; y++) {
        printf("Array [%d]: %d\n", y, A[y]);
    }
}