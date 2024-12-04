#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct { //List Version 1?
    int elem[MAX];
    int count;
}List;

typedef struct node {
    char String[50];
    struct node* link;
}*LinkedList;


void initList(List* A);
void insertLast(int elem, List* A);
void displayList(List A);
void initLinkedList(LinkedList* A);
void insertLastNode(char text[50], LinkedList* A);
void displayLinkedList(LinkedList A);
void updateNode(int pos, char text[50], LinkedList* A);

int main() {
    LinkedList L;
    L = NULL;
    insertLastNode("Hi Nigs!", &L);
    insertLastNode("Mwehehe", &L);
    updateNode(1, "Bruh", &L);
    displayLinkedList(L);
}

void initList(List* A) {
    A->count = 0;
}

void insertLast(int elem, List* A) {
   A->elem[A->count] = elem;
   A->count++; 
}

void displayList(List A) {
    int x;
    for (x = 0; x < A.count; x++) {
        printf("%d\n", A.elem[x]);
    }
    printf("Count: %d", A.count);
}

void initLinkedList(LinkedList* A) {
    *A = NULL;
}

void insertLastNode(char text[50], LinkedList* A) {
    LinkedList* trav;
    LinkedList temp = (LinkedList)malloc(sizeof(struct node));
    strcpy(temp->String, text);
    temp->link = NULL;
    for (trav = A; *trav != NULL; trav = &(*trav)->link){}
    *trav = temp;
}

void displayLinkedList(LinkedList A) {
    LinkedList curr;
    for (curr = A; curr != NULL; curr = curr->link) {
        printf("%s\n", curr->String);
    }
}

void updateNode(int pos, char text[50], LinkedList* A) {
    LinkedList* trav;
    int counter = 1;
    for (trav = A; *trav != NULL && counter < pos; trav = &(*trav)->link, counter++){}
    if (*trav == NULL || pos < 1) {
        printf("\nPosition out of bounds!\n");
    } else {
        strcpy((*trav)->String, text);
    }

}