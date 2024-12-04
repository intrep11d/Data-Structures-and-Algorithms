#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef int SET[MAX];

SET* Union(SET A, SET B);
SET* Intersection(SET A, SET B);
SET* Difference(SET A, SET B);
void display(SET A);

int main() {
    SET A = {1, 0, 1, 1, 0};
    SET B = {0, 0, 1, 0, 1};
    SET* C;
    C = Union(A, B);
    // C = Intersection(A, B);
    // C = Difference(A, B);
    
    display(*C);

}

SET* Union(SET A, SET B) {
    SET* C = (SET*)malloc(sizeof(SET));
    int x;
    for (x = 0; x < MAX; x++) {
        if (A[x] == 1 | B[x] == 1) {
            (*C)[x] = 1;
        } else {
            (*C)[x] = 0;
        }
    }
    return C;
}

void display(SET A) {
    int x;
    for (x = 0; x < MAX; x++) {
        if (A[x] == 1) {
            printf("%d\n", x);
        }
    }
}

SET* Intersection(SET A, SET B) {
    SET* C = (SET*)malloc(sizeof(SET));
    if (C != NULL) {
        int x;
        for (x = 0; x < MAX; x++) {
           (*C)[x] = A[x] == 1 && B[x] == 1 ? 1 : 0;
        }
    }
    return C;
}

SET* Difference(SET A, SET B) {
    SET* C = (SET*)malloc(sizeof(SET));
    if (C != NULL) {
        int x;
        for (x = 0; x < MAX; x++) {
            (*C)[x] = (A[x] == 1 && B[x] == 0) ? 1 : 0;
        }
    }
    return C;
}