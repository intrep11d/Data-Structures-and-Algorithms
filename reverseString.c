#include <stdio.h>

void reverseString(char *s, int sSize);

int main() {
    char string[] = "Hello";
    int size = sizeof(string);
    //printf("%d", size);

    reverseString(string, size);
    printf("%s", string);
}

void reverseString(char *s, int sSize) {
    char tempArr[sSize];
    int z = sSize - 2;
    for(int x = 0; x < sSize; ++x){
        tempArr[x] = s[x];
        //printf("%c", s[x]);
    }
    for(int y = 0; y < sSize && z > -1; ++y && z--) {
        s[y] = tempArr[z];
    }
    
}