#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int elem;
    struct node *link;
} *LIST;

typedef struct {
    LIST front, rear;
} Queue;

void initQueue(Queue *Q);
void enqueue(Queue *Q, int num);
void dequeue(Queue *Q);
void front(Queue Q);

int main() {
    Queue Q;
    initQueue(&Q);
    enqueue(&Q, 10);
    enqueue(&Q, 40);
    front(Q);
    dequeue(&Q);
}

void initQueue(Queue *Q) {
    Q->front = NULL;
    Q->rear = NULL;
}

void enqueue(Queue *Q, int num) {
    LIST temp = (LIST)malloc(sizeof(struct node));
    if (temp != NULL) {
        temp->elem = num;
        temp->link = NULL;
        Q->front == NULL ? (Q->front = temp) : (Q->rear->link = temp);
        Q->rear = temp;   
    }
}

void front(Queue Q) {
    printf("%d", Q.front->elem);
}

void dequeue(Queue *Q) {
    LIST temp;
    temp = Q->front;
    Q->front = Q->front->link;
    free(temp);
}