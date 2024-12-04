#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int elem;
    struct node* link;
}*LIST;

typedef int Position;

typedef enum {
    TRUE,
    FALSE
}Boolean;

void insertFirst(LIST* A, int X);
void printList(LIST A);
void insertPos(LIST* A, int X, Position P);

Boolean delete(LIST* A, int X);

int main() {
    Boolean check;
    LIST L = NULL;
    
    
    insertFirst(&L, 30);
    insertFirst(&L, 10);
    insertFirst(&L, 20);
    insertPos(&L, 100, 2);

    check = delete(&L, 30);
    printf("%u\n", check);
    delete(&L, 10);
    printList(L);
}

void insertFirst(LIST* A, int X) {
    LIST temp = (LIST)malloc(sizeof(struct node));
    if (temp != NULL) {
        temp->elem = X;
        temp->link = *A;
        *A = temp;
    }
}

Boolean delete(LIST* A, int X) {
    LIST* trav, temp;
    for (trav = A; *trav != NULL && (*trav)->elem != X; trav = &(*trav)->link) {}
    if (*trav != NULL && temp != NULL) {
        temp = *trav;
        *trav = (*trav)->link;
        free(temp);
    }
    return (*trav != NULL)? TRUE: FALSE;
}

void printList(LIST A) {
    LIST current = A;
    while (current != NULL) {
        printf("%d\n", current->elem);
        current = current->link;
    }
}

void insertPos(LIST* A, int X, Position P) {
    LIST* trav;
    
    int count;
    for (trav = A, count = 0; trav != NULL && count != P; trav = (*trav)->link){}
    LIST temp = (LIST)malloc(sizeof(struct node));
    temp->elem = X;
    temp->link = (*trav);
}