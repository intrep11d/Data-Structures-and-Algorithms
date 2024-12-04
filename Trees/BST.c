#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
    int elem;
    struct cell* lchild;
    struct cell* rchild;
} ctype, *BST;

typedef enum {TRUE, FALSE} Boolean;

void insert(BST* T, int elem);
void display(BST T);
void delete(BST* T, int elem);
Boolean member(BST T, int elem);
void populateBST(BST* T, int elem[], int count);

int main() {
    int nums[] = {10,11,12,4,287,9,45,3};
    BST T = NULL;
    populateBST(&T, nums, 8);
    // delete(&T, 287);
    display(T);
    if (member(T, 5) == TRUE) {
        printf("\nThis is TRUE");
    }
}

void insert(BST* T, int elem) {
    BST* trav;
    for (trav = T; *trav != NULL;) {
        if (elem > (*trav)->elem) {
            trav = &(*trav)->rchild;
        } else {
            trav = &(*trav)->lchild;
        }
    }
    BST temp = (BST)malloc(sizeof(ctype));
    temp->elem = elem;
    temp->lchild = NULL;
    temp->rchild = NULL;
    *trav = temp;
}

void display(BST T) {
    if (T != NULL) {
        printf("%d ", T->elem);
        display(T->lchild);
        display(T->rchild);
    }
}

Boolean member(BST T, int elem) {
    BST trav; 
    for (trav = T; trav != NULL && trav->elem != elem; trav = (trav->elem < elem) ? trav->rchild : trav->lchild){} 
    return (trav == NULL ? FALSE : TRUE);
}

void delete(BST* T, int elem) {
    BST* trav, temp;
    for (trav = T; *trav != NULL && (*trav)->elem != elem; ) {
        if (elem < (*trav)->elem) {
            trav = &(*trav)->lchild;
        } else {
            trav = &(*trav)->rchild;
        }
    }
    
    temp = *trav;
    if ((temp)->lchild != NULL) {
        *trav = 
    }
    *trav = NULL;
    free(temp); 
    
}

void populateBST(BST* T, int elem[], int count) {
    int x = 0; 
    while (x < count) {
       insert(T, elem[x]); 
       x++;
    }
}