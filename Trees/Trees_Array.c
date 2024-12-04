#include <stdio.h>
#define MAX 10

typedef int Tree[MAX];
typedef int Stack[MAX];

int parent(int node, Tree T);
int* preorder(Tree T);

int main() {
    Tree T = {0, 1, 1, 1, 4, 1, 6, 6, 8, 8};
    printf("%d", parent(3, T));
}

int parent(int node, Tree T) {
    return T[node - 1];
}

int* preorder(Tree T) {
    // int* stack = (int*)malloc(sizeof(int) * MAX);
    
}