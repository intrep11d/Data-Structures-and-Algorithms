#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct {
    char FName[16], MI, LName[16];
} nameType;

typedef struct {
    nameType name;
    int age;
    char course[16];
} studRec;

typedef struct node {
    studRec elem;
    struct node * link;
} *SET;

typedef SET Dictionary[MAX];

typedef enum {TRUE, FALSE} Boolean;

void initDictionary(Dictionary D);
int hash(char name[]);
void insert(Dictionary D, studRec record);
void display(Dictionary D);
Boolean isMember(Dictionary D, char name[]);
void checkBool(Boolean sign);
void delete(Dictionary D, char name[]);



int main() {
    Dictionary D;
    initDictionary(D);              
    studRec stud[] = {{(nameType) {"Lawrence", 'A', "Tulod"}, 19, "BSCS"}, {(nameType) {"Anjea Carylle", 'R', "Kilantang"}, 20, "BS Psych"},
                      {(nameType) {"Thristan Jay", 'T', "Nakila"}, 20, "BSCS"}, {(nameType) {"Katrina Elyza", 'M', "Ventura"}, 21, "BSCS"},
                      {(nameType) {"Christian Kent", 'A', "Abay-abay"}, 20, "BSCS"}, {(nameType) {"Christine", 'F', "Peña"}, 59, "BS Math"},
                      {(nameType) {"Mary Chevel", 'P', "Modesto"}, 20, "BSCS"}};
    int x;
    for (x = 0; x < 7; x++) {
        insert(D, stud[x]);
    }
    delete(D, "Christine");
    display(D);

    // printf("%d", hash(stud[3]));
    
}

void initDictionary(Dictionary D) {
    int x;
    for (x = 0; x < MAX; x++) {
        D[x] = NULL;
    }
}

int hash(char name[]) {
    int sum = 0, x = 0;
    while (x < MAX && name[x] != '\0') {
        sum += name[x];
        x++;
    }
    return sum % 10;
}

void insert(Dictionary D, studRec record) {
    int hashVal = hash(record.name.FName);
    SET temp = (SET)malloc(sizeof(struct node));
    temp->elem = record;
    temp->link = D[hashVal];
    D[hashVal] = temp;
}

void display(Dictionary D) {
    int x;
    SET trav;
    printf("INDEX\tNAME\t\t\t\t\tAGE\tCOURSE\n");
    for (x = 0; x < MAX; x++) {
        printf("%-5d\t", x + 1);
        for (trav = D[x]; trav != NULL; trav = trav->link) {
            printf("%s %c. %-20s\t", trav->elem.name.FName, trav->elem.name.MI, trav->elem.name.LName);
            printf("%d\t", trav->elem.age);
            printf("%-10s", trav->elem.course);
            if (trav->link != NULL) {
                printf("\n\t");
            }
        }
        printf("\n");
    }
}

Boolean isMember(Dictionary D, char name[]) {
    int hashVal = hash(name);
    SET trav;
    for (trav = D[hashVal]; trav != NULL && strcmp(trav->elem.name.FName, name) != 0 ; trav = trav->link) {}
    return (trav != NULL) ? TRUE : FALSE;
}

void checkBool(Boolean sign) {
    if (sign == TRUE) {
        printf("\nTRUE");
    } else {
        printf("\nFALSE");
    }
}

void delete(Dictionary D, char name[]) {
    int hashVal = hash(name);
    SET *trav, temp;
    for (trav = &D[hashVal]; *trav != NULL && strcmp((*trav)->elem.name.FName, name) != 0; trav = &(*trav)->link){}
    if (*trav != NULL) {
        temp = *trav;
        *trav = (*trav)->link;
        free(temp);
    }
}