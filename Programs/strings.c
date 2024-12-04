#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseString(char string[]);

int main() {
    // char string[] = "";
    // char catcher[50];
    // strcpy(catcher, reverseString(string));
    // printf("%s", catcher );
   int arr[3][3] = {{0,1,2}, {3,4,5}, {6,7,8}};
   printf("%d", arr[0][1]); 
}


char* reverseString(char string[]) {
    int x, y = 0;
    char* mallocString = (char*)malloc(sizeof(char) * strlen(string) + 1);
    for (x = strlen(string) - 1; x > -1; x--) {
        mallocString[y] = string[x];
        y++;
    }
    return mallocString;
}