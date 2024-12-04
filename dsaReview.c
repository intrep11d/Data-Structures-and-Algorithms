#include <stdio.h>

typedef struct {
    int number;
} Structure;

void test(Structure *T);
int Hash(char name[]);
int openHash(char *IDen);

int main() {
    
    // test(&S);
    char IDen[] = "1204";
    printf("%d", openHash(IDen));
    // printf("%d", S.number);
}

void test(Structure *T) {
    int *fptr;
    fptr = &T->number;
    printf("%d", *fptr);
}

int Hash(char name[]) {
    int x;
    char letter;
    for (x = 0, letter = 'A'; name[0] != letter && letter <= 'Z'; letter++, x++){}
    return x;
}

int openHash(char *IDen) {
    int x = 0, sum = 0;
    while (IDen[x] != '\0') {
        sum += IDen[x];
        x++;
    }
    return sum % 9;
}