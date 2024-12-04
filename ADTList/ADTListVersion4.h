#ifndef ADTLISTVERSION4_H
#define ADTLISTVERSION4_H
#define MAX 10

typedef struct node{
    char* elemptr;
    int count;
}*LIST;

typedef enum {TRUE, FALSE} Boolean;

void initList(LIST* L);
void insertRear(LIST L, char C);
void display(LIST L);
Boolean member(LIST L, char C);
void insertFront(LIST L, char C);
void deleteFront(LIST L);
void deleteLast(LIST L);
void insertSorted(LIST L, char C);


#endif