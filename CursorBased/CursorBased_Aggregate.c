#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
typedef struct {
    char FName[16], MI, LName[16];
}nameType;

typedef struct {
    nameType name;
    int age;
    char course[16];
}studRec;

typedef struct {
    studRec record;
    int next;
}studNode;

typedef struct {
    studNode VH_node[MAX];
    int avail;
}VirtualHeap;

typedef struct {
    int index;
    int count;
    VirtualHeap *VH;
}CursorList;

void initCList(CursorList *CS, VirtualHeap *VH);
void initVHeap(VirtualHeap *VH);
int allocSpace(VirtualHeap *VH);
void insertStud(CursorList *CS, studRec student);
void displayCursor(CursorList *CS);
void populateCursorList(CursorList *CS, studRec studArr[]);

int main() {
    CursorList cursList;
    VirtualHeap V;
    studRec students[] = {{{"Lawrence", 'A', "Tulod"}, 19, "BSCS"}, {{"Mary Chevel", 'P', "Modesto"}, 20, "BSCS"}};
    initCList(&cursList, &V);
    initVHeap(&V);
    // insertStud(&cursList, students[0]);
    populateCursorList(&cursList, students);
    displayCursor(&cursList);
}


void initCList(CursorList *CS, VirtualHeap* VH) {
    CS->index = -1;
    CS->count = 0;
    CS->VH = VH;
}

void initVHeap(VirtualHeap *VH) {
    int x;
    for (x = MAX - 1; x >= 0; x--) {
        VH->VH_node[x].next= x - 1;
    }
    VH->avail = MAX - 1;
}

int allocSpace(VirtualHeap *VH) {
    int ndx = VH->avail;
    VH->avail = VH->VH_node[ndx].next;
    return ndx;
}

void insertStud(CursorList *CS, studRec student) {
    int temp = allocSpace(CS->VH), x;
    if (temp != -1) {
        for (x = 0; x < CS->count && CS->VH->VH_node[temp].record.age > CS->VH->VH_node[x].record.age; x++) {}

        CS->VH->VH_node[temp].record = student;
        CS->VH->VH_node[temp].next = CS->index;
        CS->count++;
        CS->index = temp;
    }
}

void displayCursor(CursorList *CS) {
    int x;
    printf("\nSTUDENT RECORDS\n");
    for (x = CS->index; x != -1; x = CS->VH->VH_node[x].next) {
        printf("%s %c. %s %d %s\n", CS->VH->VH_node[x].record.name.FName,
                                 CS->VH->VH_node[x].record.name.MI,
                                 CS->VH->VH_node[x].record.name.LName,
                                 CS->VH->VH_node[x].record.age,
                                 CS->VH->VH_node[x].record.course);
    }
}

void populateCursorList(CursorList *CS, studRec studArr[]) {
    int temp = allocSpace(CS->VH), count;
    for (count = 0; CS->VH->avail != -1 && count < 2; temp = allocSpace(CS->VH), count++) {
        CS->VH->VH_node[temp].record = studArr[count];
        CS->VH->VH_node[temp].next = CS->index;
        CS->count++;
        CS->index = temp;
    }
}