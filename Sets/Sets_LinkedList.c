#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int elem;
    struct node* next;
} *SET;

typedef enum {TRUE, FALSE} Boolean;

SET newUnion(SET A, SET B);
SET unionList(SET ahead, SET bhead);
SET createNode(int elem);
SET intersection(SET ahead, SET bhead);
void insertFront(SET *A, int X);
void insertLast(SET *A, int X);
void display(SET A); 
SET unionSorted(SET A, SET B);
SET Union(SET A, SET B);
SET unionKat(SET A, SET B);

int main() {
    SET L = NULL;
    insertLast(&L, 2);
    insertLast(&L, 4);
    insertLast(&L, 6);
    insertLast(&L, 8);
    insertLast(&L, 10);
    SET Z = NULL;
    insertLast(&Z, 1);
    insertLast(&Z, 3);
    insertLast(&Z, 4);
    insertLast(&Z, 5);
    insertLast(&Z, 6);
    SET C = NULL;
    // C = unionSorted(L, Z);
    // C = intersection(L, Z);
    // C = Union(L, Z);
    // C = unionList(L, Z);
    // C = newUnion(L, Z);
    C = unionKat(L, Z);
    display(C);
}
void insertFront(SET *A, int X) {
    SET temp = (SET)malloc(sizeof(struct node));
    if (temp != NULL) {
        temp->elem = X;
        temp->next = *A;
        *A = temp;
    }
}

void insertLast(SET *A, int X) {
    SET temp = (SET)malloc(sizeof(struct node));
    SET *trav;
    if (temp != NULL) {
        for (trav = A; *trav != NULL; trav = &(*trav)->next){}
        temp->elem = X;
        temp->next = NULL;
        *trav = temp;
    }
}

void display(SET A) {
    SET curr;
    for (curr = A; curr != NULL; curr = curr->next) {
        printf("%d\n", curr->elem);
    }
}

SET unionSorted(SET A, SET B) {
    SET C = NULL;
    SET trav, temp, *curr, check;
    Boolean found;
    for (trav = A, curr = &C; trav != NULL; trav = trav->next) {
        temp = (SET)malloc(sizeof(struct node));
        temp->elem = trav->elem;
        temp->next= NULL;
        *curr = temp;
        curr = &(*curr)->next;
    }

    for (trav = B; trav != NULL; trav = trav->next) {
        found = FALSE;
        check = A; 
            while (check != NULL && !found) {
                if (check->elem == trav->elem) {
                    found = TRUE;
                }
                check = check->next;
            }
        
            if (found == FALSE) {
                temp = (SET)malloc(sizeof(struct node));
                temp->elem = trav->elem;
                temp->next = NULL;
                *curr = temp; 
                curr = &(*curr)->next;
            }
        }
    return C;
} 

SET createNode(int elem) {
    SET newNode = (SET)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->elem = elem;
    newNode->next = NULL;
    return newNode;
}

// Function to find the intersection of two sorted lists
SET intersection(SET ahead, SET bhead) {
    SET acurrent, bcurrent, ccurrent, chead;
    chead = createNode(0); // Create a dummy head for the result list
    ccurrent = chead;

    acurrent = ahead; // Assuming ahead and bhead are the heads of the lists A and B
    bcurrent = bhead;

    while (acurrent != NULL && bcurrent != NULL) {
        if (acurrent->elem == bcurrent->elem) {
            ccurrent->next = createNode(acurrent->elem);
            ccurrent = ccurrent->next;
            acurrent = acurrent->next;
            bcurrent = bcurrent->next;
        } else {
            if (acurrent->elem < bcurrent->elem) {
                acurrent = acurrent->next;
            } else {
                bcurrent = bcurrent->next;
            }
        }
    }

    SET temp = chead;
    chead = chead->next; // Skip the dummy head
    free(temp); // Free the dummy head
    return chead;
}

SET unionList(SET ahead, SET bhead) {
    SET acurrent = ahead, bcurrent = bhead, ccurrent, chead;
    chead = createNode(0); // Create a dummy head for the result list
    ccurrent = chead;

    while (acurrent != NULL && bcurrent != NULL) {
        if (acurrent->elem == bcurrent->elem) {
            ccurrent->next = createNode(acurrent->elem);
            acurrent = acurrent->next;
            bcurrent = bcurrent->next;
        } else if (acurrent->elem < bcurrent->elem) {
            ccurrent->next = createNode(acurrent->elem);
            acurrent = acurrent->next;
        } else {
            ccurrent->next = createNode(bcurrent->elem);
            bcurrent = bcurrent->next;
        }
        ccurrent = ccurrent->next;
    }

    // Add remaining elements from list A, if any
    while (acurrent != NULL) {
        ccurrent->next = createNode(acurrent->elem);
        acurrent = acurrent->next;
        ccurrent = ccurrent->next;
    }

    // Add remaining elements from list B, if any
    while (bcurrent != NULL) {
        ccurrent->next = createNode(bcurrent->elem);
        bcurrent = bcurrent->next;
        ccurrent = ccurrent->next;
    }

    SET temp = chead;
    chead = chead->next; // Skip the dummy head
    free(temp); // Free the dummy head
    return chead;
}

SET newUnion(SET A, SET B) {
    SET C, aptr, bptr, *cptr;
    C = NULL;
    aptr = A;
    bptr = B;
    cptr = &C;
    while (aptr != NULL && bptr != NULL) {
        *cptr = (SET)malloc(sizeof(struct node));
        if (aptr->elem < bptr->elem) {
            (*cptr)->elem = aptr->elem;
            aptr = aptr->next;
        } else if (aptr->elem > bptr->elem) {
            (*cptr)->elem = bptr->elem;
            bptr = bptr->next;
        } else {
            (*cptr)->elem = aptr->elem;
            aptr = aptr->next;
            bptr = bptr->next;
        }
        cptr = &(*cptr)->next;
    }
    return C;
}

SET unionKat(SET A, SET B) {
    SET C = NULL, aptr, bptr;

    for (aptr = A; aptr != NULL; aptr = aptr->next) {
        SET temp = (SET)malloc(sizeof(struct node));
        temp->elem = aptr->elem;
        temp->next = C;
        C = temp;
    }

    for (bptr = B; bptr != NULL; bptr = bptr->next) {
        for (aptr = A; aptr != NULL && aptr->elem != bptr->elem;) {
            aptr = aptr->next;
        }
        if (aptr == NULL) {
            SET temp = (SET)malloc(sizeof(struct node));
            temp->elem = bptr->elem;
            temp->next = C;
            C = temp;
        }
    }
    return C;
}



