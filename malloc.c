#include<stdio.h>
#include<stdlib.h>

int main() {
    int num;
    int numArr[];

    printf("Input a number: ");
    scanf("%d", &num);

    int* numPtr = malloc(sizeof(int)*num);

    printf("Input for malloc: ");
    for(int i = 0; i < num; ++i) {
        scanf("%d", numPtr + i);
    }

    for(int x = 0; x < num; ++x) {
        printf("%d", *numPtr + x);
    }


}