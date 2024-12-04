#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node {
    int elem;
    struct node *link;
}*LIST;

typedef int Position;

typedef enum {TRUE, FALSE} Boolean;

void insertFirst(LIST* A, int X);
void display(LIST A);
void insertLast(LIST *A, int X);
void insertPos(LIST* A, int X, Position P);
void deleteFirst(LIST* A);
Boolean deleteElem(LIST*A, int X);

#endif