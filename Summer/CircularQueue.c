#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int front, rear;
} Queue;

void initQueue_Array(Queue* Q);
void enqueue(Queue* Q, int data);
void displayQueue(Queue Q);
void dequeue(Queue* Q);

int main (){
    Queue L;
    initQueue_Array(&L);
    enqueue(&L, 10);
    enqueue(&L, 20);
    enqueue(&L, 30); 
    enqueue(&L, 40);
    enqueue(&L, 50);
    enqueue(&L, 60);
    enqueue(&L, 70);
    enqueue(&L, 80);
    enqueue(&L, 90);
    enqueue(&L, 100);
    enqueue(&L, 190);

    // dequeue(&L);
    // dequeue(&L);
    // dequeue(&L);
    displayQueue(L);
}

void initQueue_Array(Queue* Q) {
    Q->front = 0;
    Q->rear = -1;
}

void enqueue(Queue* Q, int data) {
    if ((Q->rear + 2) % MAX != Q->front) {
        Q->rear = (Q->rear + 1) % MAX;
        Q->elem[Q->rear] = data;
    } else {
        printf("Queue is full!\n");
    }
}

void displayQueue(Queue Q) {
    int x;
    for (x = Q.front; x <= Q.rear; x++) {
        printf("%d %d\n", x, Q.elem[x]);
    }
}

void dequeue(Queue* Q) {
    if ((Q->rear + 1) % MAX != Q->front) {
        Q->front++;
    } else {
        printf("\nQueue is empty!");
    }
}