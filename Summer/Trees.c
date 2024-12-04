#include <stdio.h>
#define ARRAY_NUM 3
#define MAX 11


typedef int Tree[ARRAY_NUM][MAX];
void inorder(Tree T, int ndx);
void preorder(Tree T, int ndx);
void postorder(Tree T, int ndx);
void initTree(Tree* T);
// void insert

int main() {
    Tree T = {{21,25,10,20,8,7,6,31,19,18,40}, {1,-1,4,8,5,6,-1,-1,9,-1,-1}, {2,7,3,-1,-1,-1,-1,10,-1,-1,-1}};
    Tree Q;
    initTree(&Q);
    
    // inorder(T, 0);
    // preorder(T, 0);
}

void inorder(Tree T, int ndx) {
    if (ndx != -1) {
        inorder(T, T[1][ndx]);
        printf("%d ", T[0][ndx]);
        inorder(T, T[2][ndx]);
    }
}

void preorder(Tree T, int ndx) {
    if (ndx != -1) {
        printf("%d ", T[0][ndx]);
        preorder(T, T[1][ndx]);
        preorder(T, T[2][ndx]);
    }
}

void initTree(Tree* T) {
    int x, y;
    for (x = 0; x < ARRAY_NUM; x++) {
        for (y = 0; y < MAX; y++) {
            (*T)[x][y] = -1;
        }
    }
}

void postorder(Tree T, int ndx) {
    if (ndx != -1) {
        postorder(T, T[0][ndx]);
        postorder(T, T[1][ndx]);
        printf("%d ", T[2][ndx]);
    }
}