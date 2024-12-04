#ifndef ADTLISTVERSION4_IMPLEMENTATIONS_C
#define ADTLISTVERSION4_IMPLEMENTATIONS_C
#include "ADTListVersion4.h"
#include <stdio.h>
#include <string.h>

void initList(LIST* L) {
    (*L) = (LIST)malloc(sizeof(struct node));
    if (*L != NULL) {
        (*L)->elemptr = (char*)calloc(MAX, sizeof(char));
        (*L)->count = 0;
    }
}

void insertRear(LIST L, char C) {
    L->elemptr[L->count] = C;
    L->count++;
}

void display(LIST L) {
    int x;
    for (x = 0; x < L->count; x++) {
        printf("%c\n", L->elemptr[x]);
    }
}

Boolean member(LIST L, char C) {
    int x;
    for (x = L->count - 1; x >= 0 && L->elemptr[x] != C; x--) {}
    return (L->elemptr[x] == C) ? TRUE : FALSE;
}

void insertFront(LIST L, char C) {
    if (L->count != MAX) {
        int x;
        for (x = L->count; x > 0; x--) {
            L->elemptr[x] = L->elemptr[x - 1];
        }
        L->elemptr[0] = C;
        L->count++;
    } else printf("List is full!");
}

void deleteFront(LIST L) {
    int x;
    for (x = 0; x < L->count - 1; x++) {
        L->elemptr[x] = L->elemptr[x + 1]; 
    }
    if (L->count > 0) {
        L->count--;
    }
}

void deleteLast(LIST L) {
    if (L->count != 0) {
        L->count--;
    }
}

void insertSorted(LIST L, char C) {
    int x;
    if (L->count != MAX) {
        for (x = 0; L->elemptr[x] < C && x < L->count; x++){}
        L->count++;
        L->elemptr[x+1] = L->elemptr[x];
        L->elemptr[x] = C;
    }  else printf("List is full!");
}

#endif