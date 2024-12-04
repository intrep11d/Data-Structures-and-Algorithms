#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define EMPTY '@'
#define DELETED '!'

typedef char Dictionary[MAX];
typedef enum {TRUE, FALSE} Boolean;

void initDictionary(Dictionary D);
void displayDictionary(Dictionary D);
int hash(char elem);
void insert(Dictionary D, char elem);
Boolean isMember(Dictionary D, char elem);
void checkBool(Boolean check);
void delete(Dictionary D, char elem);


int main(int argc, char *argv[]) {
    Dictionary D;
    initDictionary(D);
//    printf("%d", D);
    int x;
    char Element[] = {"abcdefghij"};
    for (x = 0; x < 10; x++) {
        insert(D, Element[x]);
    }
    delete(D, 'd');
    displayDictionary(D);
    checkBool(isMember(D, 'd'));
    return 0;
}

void initDictionary(Dictionary D) {
    int x;
    for (x = 0; x < MAX; x++) {
        D[x] = EMPTY;
    }
}

void displayDictionary(Dictionary D) {
    int x;
    printf("Index\tElements\n");
    for (x = 0; x < MAX; x++) {
        printf("%d\t", x);
        if (D[x] == EMPTY) {
            printf("EMPTY\n");
        } else if (D[x] == DELETED) {
            printf("DELETED\n");
        } else {
            printf("%c\n", D[x]);
        }
    }
}

int hash(char elem) {
    char Element[] = {"abcdefghij"};
    int Hash[] = {3, 9, 4, 3, 9, 0, 1, 3, 0, 3};
    int x;
    for (x = 0; x < 10 && Element[x] != elem; x++) {}
    return Hash[x];
    
}

void insert(Dictionary D, char elem) {
    int hashVal = hash(elem);
    int full = 0;
    while (D[hashVal] != EMPTY && D[hashVal] != elem && full != MAX && D[hashVal] != DELETED) {
        hashVal = (hashVal + 1) % MAX;
        full++;
    }
    if (full == MAX) {
        printf("\nThe dictionary is full!\n");
    }
    D[hashVal] = elem;
}

Boolean isMember(Dictionary D, char elem) {
    int hashVal, full;
    for (hashVal = hash(elem), full = 0; full < MAX && D[hashVal] != elem && D[hashVal] != EMPTY; hashVal = (hashVal + 1) % MAX, full++) {}
    return (D[hashVal] == elem) ? TRUE : FALSE;
}

void checkBool(Boolean check) {
    if (check == TRUE) {
        printf("\nThis is TRUE");
    } else {
        printf("This is FALSE");
    }
}

void delete(Dictionary D, char elem) {
    int hashVal;
    for (hashVal = hash(elem); hashVal < MAX && D[hashVal] != elem; hashVal = (hashVal + 1) % MAX) {}
    if (D[hashVal] == elem) {
        D[hashVal] = DELETED;
    }
}