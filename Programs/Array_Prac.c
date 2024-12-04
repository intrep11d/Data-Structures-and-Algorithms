#include <stdio.h>
#include <stdlib.h>
#define SIZE 10


int* difference(int arr1[], int arr2[]);

int main() {
    int arr1[] = {1,2,5,8,10};
    int arr2[] = {1,2,10};

    int* catcher = difference(arr1, arr2);
    int t;
    for (t = 0; t < 2; t++) {
        printf("%d", catcher[t]);
    }
}

int* difference(int arr1[], int arr2[]) {
    int* D = (int*)malloc(sizeof(int) * SIZE);
    int x, y, found = 0, d = 0;
    for (x = 0; x < 5; x++) {
        for (y = 0; y < 3 && found != 1; y++) {
            if (arr1[x] == arr2[y]){
                found = 1;
            }
        }
        if (found != 1) {
            D[d] = arr1[x];
            d++;
        }
        found = 0;
    }
    return D;
}