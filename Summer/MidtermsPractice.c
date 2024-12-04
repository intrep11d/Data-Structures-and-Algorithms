#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char elem;
    struct node* link;
} *LIST;

void insertSorted(LIST* A, char elem);
void displayList(LIST A);

int main() {
    LIST L = NULL;
    insertSorted(&L, 'A');
    insertSorted(&L, 'B');
    insertSorted(&L, 'C');
    insertSorted(&L, 'E');
    insertSorted(&L, 'F');
    displayList(L);
}

void insertSorted(LIST* A, char elem) {
    LIST temp, *trav;
    for (trav = A; *trav != NULL && (*trav)->elem < elem; trav = &(*trav)->link) {}
    if (*trav != NULL && (*trav)->elem == elem) {
        printf("\nDuplicate found. Insert failed!\n");
    } else {
        temp = (LIST)malloc(sizeof(struct node));
        temp->elem = elem;
        temp->link = *trav;
        *trav = temp;
    }
}

void displayList(LIST A) {
    while (A != NULL) {
        printf("%c\n", A->elem);
        A = A->link;
    }
}