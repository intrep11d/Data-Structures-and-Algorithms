#include <stdio.h>
#include <stdlib.h>
// #include <assert.h>
#define MAX 7

typedef struct {
    int elem[MAX];
    int lastNdx;
}List;

void display(List A);
void heapifySubtree(List* A, int node);
void heapify(List* A);
int deletemin(List* A);
void heapSort(List* A);

//Heap property is min.

int main() {
    List L = {{6,2,9,4,2,0,5}, MAX - 1};
    // display(L);
    List T = {{9,8,8}, 2};
    // heapify(&T);
    // int catcher = deletemin(&L);
    // display(T);
    // printf("\nMin: %d", catcher);
    // heapify(&L);
    heapify(&L);
    // heapSort(&L);
    display(L);
}

void display(List A) {
    int x;
    // printf("\nNODE\tLABEL\n");
    for(x = 0 ; x < MAX; x++) {
        // printf("%d\t%d\n", x, A.elem[x]);
        printf("%d ", A.elem[x]);
    }
}

// void heapifySubtree(List* A, int node) { // Recursive
//     int lchild = (node * 2) + 1, rchild = lchild + 1, small, temp, parent;
//     if (rchild <= A->lastNdx ) {
//         small = A->elem[lchild] <= A->elem[rchild] ? lchild : rchild;
//         if (A->elem[small] < A->elem[node]) {
//             temp = A->elem[node];
//             A->elem[node] = A->elem[small];
//             A->elem[small] = temp;
//         }
//         heapifySubtree(A, small);
//     }
// }

void heapifySubtree(List* A, int node) { // Iterative
    int lchild = (node * 2) + 1, rchild = lchild + 1, small, temp, parent = node;
    small = A->elem[lchild] <= A->elem[rchild] ? lchild : rchild; //Find smallest child
    while (small <= A->lastNdx && A->elem[small] <= A->elem[parent]) { //check if smallest is valid and if value at small is lesser than value at parent
        temp = A->elem[parent];
        A->elem[parent] = A->elem[small];
        A->elem[small] = temp;
    } 
}



void heapify(List* A) {
    int parent;
    for (parent = ((A->lastNdx) - 1) / 2; parent >= 0; parent--) {
        heapifySubtree(A, parent);
    }
}   


int deletemin(List* A) {
    int min = A->elem[0];
    A->elem[0] = A->elem[A->lastNdx];
    A->elem[A->lastNdx] = min;
    A->lastNdx--;
    heapify(A);
    // printf("\nMIN: %d", min);
    return min;
}

void heapSort(List* A) {
    heapify(A);
    while (A->lastNdx != -1) {
        deletemin(A);
    }
}