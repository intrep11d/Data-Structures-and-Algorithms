#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int data;
    int link;
}nodeType;

typedef struct {
    nodeType Nodes[MAX];
    int avail;
}VirtualHeap;

typedef int List;

void initList(List* L);
int allocSpace(VirtualHeap* VH);
void initVHeap(VirtualHeap* VH);
void dealloc(VirtualHeap* VH, int ndx);
void insertFirst(VirtualHeap* VH, List* A, int num);
void display(VirtualHeap VH, List A);
void insertLast(VirtualHeap* VH, List* L, int num);
void insertPos(VirtualHeap* VH, List* L, int num, int pos);
void insertSorted(VirtualHeap* VH, List* L, int num);


int main() {
    VirtualHeap V;
    List L;
    initList(&L);
    initVHeap(&V);
    insertLast(&V, &L, 10);
    insertLast(&V, &L, 20);
    insertLast(&V, &L, 30);
    insertSorted(&V, &L, 20);
    // insertPos(&V, &L, 69, 0);
    display(V, L);
    

}

void initList(List* L) {
    *L = -1;
}

void initVHeap(VirtualHeap* VH) {
    int x;
    for (x = MAX - 1; x >= 0; x--) {
        VH->Nodes[x].link = x - 1;
    }
    VH->avail = MAX - 1;
}

int allocSpace(VirtualHeap* VH) {
    int ndx = VH->avail;
    if (ndx != 1) {
        VH->avail = VH->Nodes[ndx].link;
    }
    return ndx;
}

void dealloc(VirtualHeap* VH, int ndx) {
    VH->Nodes[ndx].link = VH->avail;
    VH->avail = ndx;
}

void insertFirst(VirtualHeap* VH, List* A, int num) {
    int temp = allocSpace(VH);
    if (temp != -1) {
        VH->Nodes[temp].data = num;
        VH->Nodes[temp].link = *A;
        *A = temp;
    }
}   

void display(VirtualHeap VH, List A) {
    int trav;
    for (trav = A; trav != -1; trav = VH.Nodes[trav].link) { 
        printf("%d\n", VH.Nodes[trav].data);
    }
}

void insertLast(VirtualHeap* VH, List* L, int num) {
    int temp = allocSpace(VH);
    List* trav;
    VH->Nodes[temp].data = num;
    VH->Nodes[temp].link = -1;
    if (*L == -1) {
        *L = temp;
    } else {
        for (trav = L; VH->Nodes[*trav].link != -1; trav = &VH->Nodes[*trav].link){}
        VH->Nodes[*trav].link = temp;
    }
}

void insertPos(VirtualHeap* VH, List* L, int num, int pos) {
    int temp = allocSpace(VH), counter = 0;
    List *trav;
    VH->Nodes[temp].data = num;
    for (trav = L; *trav != -1 && counter < pos; trav = &VH->Nodes[*trav].link, counter++){} 
    VH->Nodes[temp].link = *trav;
    *trav = temp;
}

void insertSorted(VirtualHeap* VH, List* L, int num) {
    int temp = allocSpace(VH);
    if (temp != -1) {
        List* trav;
        for (trav = L; *trav != -1 && num > VH->Nodes[*trav].data; trav = &VH->Nodes[*trav].link){}
        VH->Nodes[temp].data = num;
        VH->Nodes[temp].link = *trav;
        *trav = temp;    
    }
}