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
Boolean isMember(BST T, int elem);
Boolean delete(BST* T, int elem);


int main() {
    BST T = NULL;
    insert(&T, 10);
    insert(&T, 20);
    insert(&T, 4);
    insert(&T, 1);
    if (isMember(T, 10) == TRUE) {
        printf("Found!\n");
    } else {
        printf("Not found!\n");
    }
    display(T);
}

void insert(BST* T, int elem) {
    BST* trav;
    for (trav = T; *trav != NULL; ) {
        if (elem < (*trav)->elem) {
            trav = &(*trav)->lchild;
        } else {
            trav = &(*trav)->rchild;
        }
    }
    BST temp;
    temp = (BST)malloc(sizeof(ctype));
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

Boolean isMember(BST T, int elem) {
    BST trav;
    for (trav = T; trav != NULL && trav->elem != elem; ) {
        if (elem < trav->elem) {
            trav = trav->lchild;
        } else {
            trav = trav->rchild;
        }
    }
    return (trav != NULL) ? TRUE : FALSE;
}

Boolean delete(BST* T, int elem) {
    BST temp, *trav;
    for (trav = T; (*trav) != NULL && (*trav)->elem != elem; ) {
        if (elem < (*trav)->elem) {
            trav = (*trav)->lchild;
        } else {
            trav = (*trav)->rchild;
        }
    }
    if (*trav != NULL) {
        temp = *trav;
    }
}