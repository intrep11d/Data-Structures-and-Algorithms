#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define N 5
#define INFINITY INT_MAX

typedef enum {TRUE, FALSE} Boolean;

typedef Boolean Graph[N][N];
typedef int LGraph[N][N];
typedef struct node {
    int dest;
    struct node * link;
}*LList;

typedef LList AdjList[N];

int first(Graph G, int j);
int* Dijkstra(LGraph G, int source);
int min(int num1, int num2);
void printDijkstra(LGraph G, int source);
void Floyd(LGraph A, LGraph C);
void printMatrix(LGraph G);
void printPath(int target, int* P);

int main () {
    // Graph G = {{FALSE,TRUE,FALSE,TRUE}, {FALSE,FALSE,TRUE,FALSE}, {FALSE,FALSE,FALSE,TRUE}, {FALSE,TRUE,FALSE,FALSE}};
    LGraph L = {{INFINITY,10,INFINITY,30,100},
                {INFINITY,INFINITY,50,INFINITY,INFINITY},
                {20,INFINITY,INFINITY,INFINITY,10},
                {INFINITY,INFINITY,20,INFINITY,60},
                {INFINITY,INFINITY,INFINITY,INFINITY,INFINITY}
               };
    LGraph G = {{INFINITY,10,INFINITY,30,100},
                {INFINITY,INFINITY,50,INFINITY,INFINITY},
                {20,INFINITY,INFINITY,INFINITY,10},
                {INFINITY,INFINITY,20,INFINITY,60},
                {INFINITY,INFINITY,INFINITY,INFINITY,INFINITY}
               };
    LGraph B;
    Floyd(B, G);
    // printDijkstra(L, 0); 
    AdjList A;
    printMatrix(B);
    // int catcher = first(G, 2);
    // printf("%d", catcher);
    // printDijkstra(L, 1); 
    // system("clear");
}

int first(Graph G, int j) {
    int i;
    for (i = 0; i < N && G[i][j] != TRUE; i++) {}
    return (G[i][j] == TRUE) ? i : -1;
}

int* Dijkstra(LGraph G, int source) {
    int S[N]; // Initial source, already visited vertices
    int* D = (int*)malloc(sizeof(int) * N); // Array to be returned that containes the shortest path from the source to every other node
    int P[N];
    int x, y, w, z, c, small; // Multiple indices just for programmer (you) to keep track of loops and sets
    // V is implied to be the indices of the matrix; i < N
    for (x = 0; x < N; x++) { // Initializing the D array
        D[x] = G[source][x]; 
        P[x] = INFINITY;
    }
    D[source] = 0;
    P[source] = source;
    S[source] = 1;
    for (y = 0; y < N; y++) { // Choose a vertex w in [V-S such that D[w] is a minimum
        small = INT_MAX;
        for (z = 0; z < N; z++) {
            if (S[z] == 0 && D[z] < small) {
                small = D[z];
                w = z;      
            }
        }
        S[w] = 1;
        for (c = 0; c < N; c++) {
            if (S[c] == 0 && G[w][c] != INFINITY && D[c] > D[w] + G[w][c]) {
                // D[c] = min(D[c], D[w] + G[w][c]);
                D[c] = D[w] + G[w][c];
                P[c] = w;
            }
        }
    }
    int target = 2;
    printf("Path: ");
    printPath(target, P);
    printf("\nTotal cost: %d", D[target]);
    return D;
}

int min(int num1, int num2) {
    return (num1 <= num2) ? num1 : num2;
}

void printDijkstra(LGraph G, int source) {
    int* catcherArr = Dijkstra(G, source);
    int x;
    printf("\n");
    for (x = 0; x < N; x++) {
        printf("%d ", catcherArr[x]);
    }
}

void Floyd(LGraph A, LGraph C) {
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            A[i][j] = C[i][j];
        }
    }
    for (i = 0; i < N; i++) {
        A[i][i] = 0;
    }
    for (k = 0; k < N; k++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (A[i][k] != INFINITY && A[k][j] != INFINITY && A[i][k] + A[k][j] < A[i][j]) { // != INFINITY because of INT_MAX
                    A[i][j] = A[i][k] + A[k][j];
                }
            }
        }
    }
}

void printMatrix(LGraph G) {
    int x, y;
    for (x = 0; x < N; x++) {
        for (y = 0; y < N; y++) {
            if (G[x][y] != INFINITY) {
                printf("%4d ", G[x][y]);
            } else {
                printf("%4s ", "INF");
            }
        }
        printf("\n");
    }
}

void printPath(int target, int* P) { 
    if (target != INFINITY) {
        printPath(P[target], P);
        printf("%d ", target);
    }
}