#include <stdio.h>
#define MAX 10

typedef struct {
    char elems[MAX];
    int rear, front;
} Queue;

void initQueue(Queue *Q);
void enqueue(Queue *Q, char X);
void display(Queue Q);
void dequeue(Queue *Q);

int main() {
    Queue Q;
    char elements[] = {"abcdefghijk"};
    initQueue(&Q);
    int x;
    // for (x = 0; x < 8; x++) {
    //     enqueue(&Q, elements[x]);
    // }
    dequeue(&Q);
    // dequeue(&Q);
    display(Q);
}

void initQueue(Queue *Q) {
    Q->rear = -1;
    Q->front = 0;
}

void enqueue(Queue *Q, char X) {
    if ((Q->rear + 2) % MAX != Q->front) {
        Q->rear = (Q->rear + 1) % MAX;
        Q->elems[Q->rear] = X;
    } else {
        printf("\nQueue is full!");
    }
}

void display(Queue Q) {
    int x;
    printf("INDEX\tELEMENT\n");
    for (x = Q.front; x < Q.rear + 1; x++) {
        printf("%d\t%c\n", x, Q.elems[x]);
    }
    printf("Front: %d\nRear: %d", Q.front, Q.rear);
}

void dequeue(Queue *Q) {
    if (Q->rear != Q->front ) {
        Q->front = (Q->front + 1) % MAX;
    } else {
        printf("Queue empty");
    }
}
