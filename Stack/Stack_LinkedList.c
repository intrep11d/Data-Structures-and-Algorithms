#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char elem;
    struct node *link;
} *Stack;

typedef enum {TRUE, FALSE} Boolean;
void initStack(Stack *S);
void push(Stack *S, char X);
void display(Stack S);
void pop(Stack *S);
char top(Stack S);


int main() {
    Stack S;
    initStack(&S);
    push(&S, 'A');
    push(&S, 'B');
    printf("%c", top(S));
    // pop(&S);
    // display(S);
}

void initStack(Stack *S) {
    *S = NULL;
}

void push(Stack *S, char X) {
    Stack temp = (Stack)malloc(sizeof(struct node));
    if (temp != NULL) {
        temp->elem = X;
        temp->link = *S;
        *S = temp;
    }
}

void display(Stack S) {
    
}

void pop(Stack *S) {
    if (*S != NULL) {
        Stack temp = (Stack)malloc(sizeof(struct node));
        temp = *S;
        *S = (*S)->link;
        free(temp);
    }
}

char top(Stack S) {
    return (S != NULL) ? S->elem : '\0';
}