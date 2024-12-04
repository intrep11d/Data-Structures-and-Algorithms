#include <stdio.h>
#define MAX 10

typedef struct {
    char elem[MAX];
    int top;
} Stack;

typedef enum {TRUE, FALSE} Boolean;
void initStack(Stack *S);
void push(Stack *S, char element);
void display(Stack *S);
void pop(Stack *S);
Boolean isEmpty(Stack S);
Boolean isFull(Stack S);
char top(Stack S);

int main() {
    Stack A;
    initStack(&A);
    push(&A, 'a');
    push(&A, 'b');
    // printf("%c", top(S));
    display(A);
}

void initStack(Stack *S) {
    S->top = -1;
}

void push(Stack *S, char element) {
    if (S->top != MAX - 1) {
        S->top++;
        S->elem[S->top] = element;
    }
}

// void display(Stack S) {
//     while (S.top != -1) {
//         printf("%c\n", S.elem[S.top]);
//         pop(&S);
//     }
// }

// void display(Stack *S) {
//     char temp[MAX];
//     while (S.top != -1) {
//         temp[S.top] = top(S);
//         pop(&S);
//     }
//     int x;
//     for (x = S.top; )

// }

void pop(Stack *S) {
    if (S->top != -1) {
        S->top--;
    }
}

Boolean isEmpty(Stack S) {
    return (S.top == -1) ? TRUE : FALSE;
}

Boolean isFull(Stack S) {
    return (S.top == MAX - 1) ? TRUE : FALSE;
}

char top(Stack S) {
    return (S.top != -1) ? S.elem[S.top] : '\0';
}