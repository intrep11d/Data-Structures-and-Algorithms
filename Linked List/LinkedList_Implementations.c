#ifndef LINKEDLIST_IMPLEMENTATIONS_C
#define LINKEDLIST_IMPLEMENTATIONS_C
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void insertFirst(LIST* A, int X) {
    LIST temp = (LIST)malloc(sizeof(struct node));
    if (temp != NULL) {
        temp->elem = X;
        temp->link = *A;
        *A = temp;
    }
}

void display(LIST A) {
    LIST trav;
    for (trav = A; trav != NULL; trav = trav->link){
        printf("%d\n", trav->elem);
    }
}

void insertLast(LIST* A, int X) {
    LIST temp = (LIST)malloc(sizeof(struct node));
    LIST* trav;
    if (temp != NULL) {
        temp->elem = X;
        temp->link = NULL;
        for(trav = A; *trav != NULL; trav = &(*trav)->link){}
        *trav = temp;
    }
}

void insertPos(LIST* A, int X, Position P) {
    LIST temp = (LIST)malloc(sizeof(struct node));
    LIST* trav;
    int counter;
    if (temp != NULL) {
        for (trav = A, counter = 0; *trav != NULL && counter != P; trav = &(*trav)->link) {
            counter++;
        }
        temp->elem = X;
        temp->link = *trav;
        *trav = temp;
    }
}

void deleteFirst(LIST* A) {
    if (*A != NULL) {
        LIST temp = *A;
        *A = (*A)->link;
        free(temp);
    }
}

void deleteLast(LIST* A) {
    if (*A != NULL) {
        LIST temp;
        LIST* trav;
        for (trav = A; *trav != NULL && (*trav)->link != NULL; trav = &(*trav)->link) {}
        temp = *trav;
        *trav = NULL;
        free(temp);
    }
}

Boolean deleteElem(LIST*A, int X) {
    LIST temp, *trav;
    Boolean flag = FALSE;
    for (trav = A; *trav != NULL && (*trav)->elem != X; trav = &(*trav)->link){}
    if (*trav != NULL) {
        temp = *trav;
        *trav = (*trav)->link;
        free(temp); 
        flag = TRUE;
    }
    return flag;
}

void checkBool(Boolean flag) {
    if (flag == TRUE) {
        printf("This is TRUE\n\n");
    } else {
        printf("This is FALSE\n\n");
    }
}




#endif