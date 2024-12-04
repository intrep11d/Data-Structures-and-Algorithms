#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node {
    int elem;
    struct node * link;
} *SET;

typedef SET Dictionary[MAX];

typedef enum {TRUE, FALSE} Boolean;

void initDictionary(Dictionary D);
int Hash(int x);
void insert(Dictionary D, int elem);
Boolean isMember(Dictionary D, int elem);
void displayDictionary(Dictionary D);
void delete(Dictionary D, int elem);


int main() {
    Dictionary D;
    initDictionary(D);
    insert(D, 10);
    insert(D, 65);
    insert(D, 123);
    delete(D, 10);
    displayDictionary(D);
    // printf("%d", D[1]->elem);
    // printf("%d", Hash(65));
}


int Hash(int x) {
    int sum = 0;
    while (x != 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum % 10;
}

void initDictionary(Dictionary D) {
    int x;
    for (x = 0; x < MAX; x++) {
        D[x] = NULL;
    }
}

void insert(Dictionary D, int elem) {
    int hashVal = Hash(elem);
    SET temp = (SET)malloc(sizeof(struct node));
    temp->elem = elem;
    temp->link = D[hashVal];
    D[hashVal]= temp;
}

Boolean isMember(Dictionary D, int elem) {
    int hashVal;
    SET trav;
    for (hashVal = Hash(elem), trav = D[hashVal]; trav != NULL && trav->elem != elem; trav = trav->link){}
    return (trav != NULL) ? TRUE : FALSE;
}

void displayDictionary(Dictionary D) {
    int x;
    SET trav;
    printf("INDEX\tVALUES\n");
    for (x = 0; x < MAX; x++) {
        printf("%d\t", x);
        for (trav = D[x]; trav != NULL; trav = trav->link) {
            printf(" %d", trav->elem);
        }
        printf("\n");
    }
}

void delete(Dictionary D, int elem) {
    if (isMember(D, elem) == TRUE) {
        SET temp, *trav;
        for (trav = &D[Hash(elem)]; *trav != NULL && (*trav)->elem != elem; trav = &(*trav)->link){}
        temp = *trav;
        *trav = (*trav)->link;
        free(temp);
    } else {
        printf("\nElement does not exist!\n");
    }
}
