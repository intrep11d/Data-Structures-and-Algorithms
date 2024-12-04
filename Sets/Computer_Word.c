#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char Word;

void displayBits(char A);
// void displayBits(int A);
int returnThirdBit(char A);
char* getProgram(unsigned char A);
void changeBit(Word *W);

int main() {    

    
    unsigned char var = 0b01001011;
    // displayBits(var);
    // printf("%d", var & 3);
    // char val = returnThirdBit('A');
    // printf("%d", val);
    Word compWord = 0b01001110;
    changeBit(&compWord);
    displayBits(compWord);
    // printf("%s", getProgram(var));

}

void displayBits(char A){
    unsigned char numBits = sizeof(char) * 8;
    unsigned char mask;
    for (mask = 1 << (numBits - 1); mask != 0; mask >>= 1) {
        printf("%d", (A & mask) ? 1 : 0);
    }
}

// void displayBits(int A){
//     unsigned int numBits = sizeof(int) * 8;
//     unsigned int mask;
//     for (mask = 1 << (numBits - 1); mask != 0; mask >>= 1) {
//         printf("%d", (A & mask) ? 1 : 0);
//     }
// }

int returnThirdBit(char A) {
    unsigned char numBits = sizeof(char) * 8, mask;
    mask = 1 << 5;
    return (A & mask) ? 1 : 0;
}

char* getProgram(unsigned char A) {
    char* retString = (char*)malloc(sizeof(char) * 5);
    switch (A & 3) {
        case 0:
            strcpy(retString, "CS");
            break;
        case 1:
            strcpy(retString, "IT");
            break;
        case 2:
            strcpy(retString, "IS");
            break;
        case 3:
            strcpy(retString, "MATH");
            break;
    }
    
    return retString;
}

void changeBit(Word *W) {
    if ((*W & 4) == 4) {
        printf("Third bit is already on!");
    } else {
        *W = *W + 4;
    }
}