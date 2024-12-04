#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int elem;
    struct node* prev;
    struct node* next;
} *LIST;

typedef struct {
    LIST head;
    LIST tail;
} Queue;

void initQueue(Queue* Q);
void enqueue(Queue* Q, int num);
void printH(Queue Q);
void printT(Queue Q);


int main() {
    Queue L;
    initQueue(&L);
    enqueue(&L, 10);
    enqueue(&L, 20);
    printH(L);
    // printT(L);
}

void initQueue(Queue* Q) {
    Q->head = NULL;
    Q->tail = NULL;
}

void enqueue(Queue* Q, int num) {
   LIST temp;
   temp = (LIST)malloc(sizeof(struct node));
   temp->elem = num;
   temp->prev = Q->tail;
   temp->next = NULL;
   if (Q->tail != NULL) {
    Q->tail->next = temp;
   } else {
    Q->head = temp;
   }
   Q->tail = temp;
}

void printH(Queue Q) {
    LIST trav;
    for (trav = Q.head; trav != NULL; trav = trav->next) {
        printf("%d\n", trav->elem);
    }
}

void printT(Queue Q) {
    LIST trav;
    for (trav = Q.tail; trav != NULL; trav = trav->prev) {
        printf("%d\n", trav->elem);
    }
}