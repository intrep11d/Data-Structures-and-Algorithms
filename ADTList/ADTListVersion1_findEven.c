#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int elem[MAX];
    int count;
}LIST;

void initList(LIST *L);
LIST findEven(LIST L);
LIST findOdd(LIST L);
void printList(LIST L);

int main() {
    LIST peopleList = {{1, 2, 3, 4, 6}, MAX};
    int x = 0;
    LIST retList = findEven(peopleList);
    
    printList(retList);
    
}

LIST findEven(LIST L) {
    int j;
    LIST evenList = {0};
    for (j = 0; j < L.count; j++) {
        if (L.elem[j] % 2 == 0) {
            evenList.elem[evenList.count] = L.elem[j];
            evenList.count++;
        }
    }
    return evenList;
}

LIST findOdd(LIST L) {
    int y;
    LIST oddList = {{0}, 1};
    for (y = 0; y < L.count; y++) {
        if (L.elem[y] % 2 == 1 && L.count != 0) {
            oddList.elem[oddList.count] = L.elem[y];
            oddList.count++;
        }
    }
    oddList.elem[0] = oddList.count - 1;
    return oddList;
}

void printList(LIST L) {
    int z = 0;
    printf("\nLIST L\n");
    printf("-----------\n");
    for (z = 0; z < L.count; z++) {
        printf("elem[%d]: %d\n", z, L.elem[z]);
    }
}

