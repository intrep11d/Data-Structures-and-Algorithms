#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct {
    char FName[24], MI, LName[16];
} nameType;

typedef struct{
    nameType name;
    char ID[10];
    char course[8];
    int yrLevel;
} studRec;

typedef struct node{
    studRec stud;
    struct node* sLink;
} *studLink;

typedef struct {
    nameType names[MAX];
    int lastNdx;
} *studArr;

void insertStud(studLink* A, nameType name, char ID[], char course[], int yearLvl);
void insertStudLast(studLink* A, nameType name, char ID[], char course[], int yearLvl);
studArr deleteBSCS(studLink* A); //deletes students with course BSCS and returns their names then places it in studArr
void displayStudLink(studLink A);
void displayStudArr(studArr A);

int main() {
    studLink L = NULL;
    studArr P;
    insertStud(&L, (nameType){"Lawrence", 'A', "Tulod"}, "20103288", "BSCS", 2);
    insertStud(&L, (nameType){"Esky", 'A', "Sayson"}, "20101768", "BSPsych", 2);
    insertStud(&L, (nameType){"Mary Chevel", 'P', "Modesto"}, "2093455", "BSCS", 2);
    P = deleteBSCS(&L);
    displayStudLink(L);
    displayStudArr(P);
}

void insertStud(studLink* A, nameType name, char ID[], char course[], int yearLvl) {
    // studLink temp = (studLink)malloc((sizeof(char) * 59) + sizeof(int) + 8);
    studLink temp = (studLink)malloc(sizeof(struct node));
    if (temp != NULL) {
        temp->stud.name = name;
        strcpy(temp->stud.ID, ID);
        strcpy(temp->stud.course, course);
        temp->stud.yrLevel = yearLvl;
        temp->sLink = *A;
        *A = temp;
    }
}

void insertStudLast(studLink* A, nameType name, char ID[], char course[], int yearLvl) {
    studLink temp = (studLink)malloc(sizeof(struct node));
    studLink* trav;
    if (temp != NULL) {
        temp->stud.name = name;
        strcpy(temp->stud.ID, ID);
        strcpy(temp->stud.course, course);
        temp->stud.yrLevel = yearLvl;
        for (trav = A; *trav != NULL; trav = &(*trav)->sLink) {}
        *trav = temp;
    }
}



void displayStudLink(studLink A) {
    studLink trav;
    for (trav = A; trav != NULL; trav = trav->sLink) {
        printf("Name: %s %c. %s\n", trav->stud.name.FName, trav->stud.name.MI, trav->stud.name.LName);
        printf("ID#: %s\n", trav->stud.ID);
        printf("Program: %s\n", trav->stud.course);
        printf("Year Level: %d\n\n", trav->stud.yrLevel);
    }
}



studArr deleteBSCS(studLink* A) {
    studLink* trav;
    studArr csArr = (studArr)malloc(sizeof(*csArr));
    // studArr csArr = (studArr)malloc((sizeof(studRec) * MAX) + sizeof(int));
    csArr->lastNdx = -1;
    for (trav = A; *trav != NULL; ) {
        if (strcmp((*trav)->stud.course, "BSCS") == 0) {
            studLink temp = *trav;
            csArr->names[++csArr->lastNdx] = (*trav)->stud.name;
            *trav = (*trav)->sLink;
            free(temp);
        } else {
            trav = &(*trav)->sLink;
        }
    }
    return csArr;
}


void displayStudArr(studArr A) {
    int x;
    for (x = 0; x <= (A->lastNdx); x++) {
        printf("%s %c %s\n", A->names[x].FName, A->names[x].MI, A->names[x].LName);
    }
    printf("%d", A->lastNdx);
}
