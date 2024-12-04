#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char letter;
    struct node* link;
} *STACK;

void insertString(char string[50], STACK* A);
void displayStack(STACK A);
void checkifPalindrome(char string[50]);

int main() {
    // STACK L = NULL;
    // insertString("Bye", &L);
    // displayStack(L);
    checkifPalindrome("wertrew");
}

void insertString(char string[50], STACK* A) {
    int x;
    STACK temp;
    for (x = 0; string[x] != '\0'; x++) {
        temp = (STACK)malloc(sizeof(struct node));
        temp->letter = string[x];
        temp->link = *A;
        *A = temp;
    }
}

void displayStack(STACK A) {
    STACK curr;
    for (curr = A; curr != NULL; curr = curr->link) {
        printf("%c", curr->letter);
    }
}

void checkifPalindrome(char string[50]) {
    STACK S = NULL;
    STACK curr;
    int x;
    insertString(string, &S);
    printf("Original String: %s\n", string);
    printf("Reversed String: ");
    displayStack(S);
    for (x = 0, curr = S; curr != NULL && string[x] == curr->letter; x++, curr = curr->link) {}
    if (curr == NULL) {
        printf("\nPalindrome!");
    } else {
        printf("\nNot a palindrome!");
    }
}