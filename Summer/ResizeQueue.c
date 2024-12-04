#include <stdio.h>
#include <stdlib.h>

typedef enum {TRUE, FALSE} Boolean;

typedef struct queue{
    int* data;
    int front, rear, capacity;
} Queue;

Queue* initQ(void);
Boolean enqueue(Queue* Q, int elem);
void visualize(Queue Q);
void resize(Queue* Q);
Boolean dequeue(Queue* Q);
int front(Queue Q);

int main() {
    Queue* Q;
    int choice, elem, frontCatcher;
    Q = initQ();
    while (choice != 0) {
        printf("\nSelect an operation: [1] Enqueue | [2] Dequeue | [0] Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 0:
                visualize(*Q);
                break;
            case 1:
                printf("Select number to enqueue: \n");
                scanf("%d", &elem);

                if (enqueue(Q, elem) == TRUE) {
                    printf("Success adding %d.\n", elem);
                } else {
                    printf("Enqueue failed.");
                }
                break;
            case 2:
                frontCatcher = front(*Q);
                if (dequeue(Q) == TRUE) {
                    printf("Success removing %d.\n", frontCatcher);
                }
                break;
            default:
                printf("Invalid action\n");
                break;
        }
    }
}

Queue* initQ(void) {
    Queue* Q = (Queue*)malloc(sizeof(struct queue));
    if (Q != NULL) {
        Q->capacity = 5;
        Q->data = (int*)malloc(sizeof(int) * Q->capacity);
        Q->front = 0;
        Q->rear = -1;
    }
    return Q;
}

Boolean enqueue(Queue* Q, int elem) {
    Boolean retVal = FALSE;
    if ((Q->rear + 2) % Q->capacity != Q->front) {
        Q->rear = (Q->rear + 1);
        Q->data[Q->rear] = elem;
        retVal = TRUE;
    } else {
        printf("Queue is full. Resizing...\n");
        resize(Q);
        Q->rear = (Q->rear + 1);
        Q->data[Q->rear] = elem;
        retVal = TRUE; 
    }
    return retVal;
}

void visualize(Queue Q) {
    if ((Q.rear + 1) != Q.front) {
        int x;
        printf("Queue [");
        for (x = Q.front; x < Q.rear + 1; x++) {
            printf("%d, ", Q.data[x]);
        }
        printf("]");
    } else {
        printf("Queue is empty.\n");
    }
}

void resize(Queue* Q) {
    int x, *newArr;
    Q->capacity = Q->capacity * 2;
    newArr = (int*)malloc(sizeof(int) * Q->capacity);
    for (x = Q->front; x < Q->rear + 1; x++) {
        newArr[x] = Q->data[x];
    }
    Q->data = newArr;
}

int front(Queue Q) {
    return Q.data[Q.front];
}

Boolean dequeue(Queue* Q) {
    Boolean retVal = FALSE;
    if ((Q->rear + 1) % Q->capacity != Q->front) {
        Q->front++;
        retVal = TRUE;
    } else {
        printf("Queue is empty.\n");
    }
    return retVal;
}