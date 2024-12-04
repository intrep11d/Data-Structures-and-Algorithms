#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "LinkedList_Implementations.c"

int main() {
    LIST L = NULL;
    // insertFirst(&L, 10);
    // insertFirst(&L, 20);
    insertLast(&L, 40);
    insertLast(&L, 50);
    insertFirst(&L, 2);
    insertPos(&L, 100, 3);
    checkBool(deleteElem(&L, 2));
    display(L);
}