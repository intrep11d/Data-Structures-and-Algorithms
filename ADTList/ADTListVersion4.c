#include <stdio.h>
#include <stdlib.h>
#include "ADTListVersion4.h"
#include "ADTListVersion4_Implementations.c"

int main() {
    LIST A = NULL;

    initList(&A);
    // insertRear(A, 'A');
    insertRear(A, 'B');
    insertRear(A, 'E');
    insertSorted(A, 'C');
    insertSorted(A, 'D');
    insertSorted(A, 'Z');
    insertSorted(A, 'T');
    insertSorted(A, 'W');
    insertSorted(A, 'A');
    // insertFront(A, 'Z');
    // deleteFront(A);
    // deleteLast(A);
    display(A);
    // if (member(A, 'P') == TRUE) {
    //     printf("This is true");
    // } else {
    //     printf("This is false");
    // }
    
}


