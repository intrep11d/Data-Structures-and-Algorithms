#include <stdio.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} LIST;

void initList(LIST *L);
void display(LIST L);
void insertFirst(LIST *L, int X);
void insertLast(LIST *L, int X);
void insertSorted(LIST *L, int X);

int main() {
    LIST L = {{3, 4, 5}, 3};
    // initList(&L);
    insertSorted(&L, 2);

    display(L);
}

void initList(LIST *L) {
    L->count = 0;
}

void display(LIST L) {
    int x;
    for (x = 0; x < L.count; x++) {
        printf("%d\n", L.elem[x]);
    }
}

void insertFirst(LIST *L, int X) {
    if (L->count != MAX) {
        int x;
        for (x = L->count; x > 0; x--) {
            L->elem[x] = L->elem[x - 1];
        }
        L->elem[0] = X;
        L->count++;
    } else {
        printf("List is full!");
    }
}

void insertLast(LIST *L, int X) {
    if (L->count != MAX) {
        L->elem[L->count] = X;
        L->count++;
    }
}

void insertSorted(LIST *L, int X) {
    if (L->count != MAX) {
        int x;
        for (x = L->count; x > 0 && X < L->elem[x - 1]; x--) {
            L->elem[x] = L->elem[x - 1];
        }
        L->elem[x] = X;
        L->count++;
    }
}