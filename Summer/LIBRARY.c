#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {TRUE, FALSE} Boolean; 


typedef struct {
    int id;
    char title[50];
    char author[50];
    Boolean isAvailable;
} Book;

typedef struct {
    Book* collection;
    int count;
    int capacity; // Details how much can be stored in a collection
} BookArray;

void initBookArray(BookArray* B, int capacity);
void addBook(BookArray* B, char title[50], char author[50]);
void displayBookArray(BookArray B);
void deleteBook(BookArray* B, int id);
int findBook(BookArray B, int id); // Returns a positive integer that signifies a book's index. Otherwise, returns a negative number if book does not exist.


int main() {
    BookArray A;
    initBookArray(&A, 5);
    addBook(&A, "To Kill a Mockingbird", "Harper Lee");
    addBook(&A, "Bible", "Apostles");
    addBook(&A, "How to cook Adobo", "Lawrence Tulod");
    // deleteBook(&A, 0);
    displayBookArray(A);
    printf("\n%d", findBook(A, 2));
    if (findBook(A, 1) > 0) {
        printf("\nThis is True!");
    } else {
        printf("\nThis is False!");
    }
}

void initBookArray(BookArray* B, int capacity) {
    B->collection = (Book*)malloc(sizeof(Book) * capacity);
    B->count = 0;
    B->capacity = capacity;
}

void addBook(BookArray* B, char title[50], char author[50]) {
    if (B->count < B->capacity) {
        // Book temp;
        // temp.id = B->count + 1;
        // strcpy(temp.title, title);
        // strcpy(temp.author, author);
        // temp.isAvailable = TRUE; 
        // B->collection[B->count] = temp;
        // B->count++;
        int collectionCount = B->count;
        B->collection[collectionCount].id = B->count + 1;
        strcpy(B->collection[collectionCount].author, author);
        strcpy(B->collection[collectionCount].title, title);
        B->collection[collectionCount].isAvailable = TRUE;
        B->count++;
    } else {
        printf("\n\nBookArray is full!\n\n");
    }
} 

void displayBookArray(BookArray B) {
    int x;
    printf("BookArray retrieved!\nDisplaying %d counts of Books\n\n", B.count);
    for (x = 0; x < B.count; x++) {
        printf("ID: %d\n", B.collection[x].id);
        printf("Title: %s\n", B.collection[x].title);
        printf("Author: %s\n\n", B.collection[x].author);
    }
}

int findBook(BookArray B, int id) {
    int x;
    for (x = 0; x < B.count && B.collection[x].id != id; x++) {}
    return (B.collection[x].id == id) ? x : -1;   
}

void deleteBook(BookArray* B, int id) {
    if (findBook(*B, id) > 0) {
        int x;
        for (x = id; x + 1 < B->count; x++) {
            B->collection[x] = B->collection[x + 1];
        }
        B->count--;
    } else {
        printf("\nBook not found!");
    }
}

