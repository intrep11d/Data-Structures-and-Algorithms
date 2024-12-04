#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Define a structure for key-value pairs
struct KeyValue {
    int key;
    char value[50];
};

// Define the hash table as an array of key-value pairs
struct KeyValue hashTable[TABLE_SIZE];

// Initialize the hash table
void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].key = -1; // Initialize keys to -1 (indicating empty)
        strcpy(hashTable[i].value, "");
    }
}

// Hash function to calculate the index in the hash table
int hash(int key) {
    return key % TABLE_SIZE;
}

// Insert a key-value pair into the hash table
void insert(int key, const char* value) {
    int index = hash(key);

    // Linear probing to handle collisions
    while (hashTable[index].key != -1) {
        index = (index + 1) % TABLE_SIZE;
    }

    hashTable[index].key = key;
    strcpy(hashTable[index].value, value);
}

// Search for a value based on a key
const char* search(int key) {
    int index = hash(key);

    // Linear probing to find the key
    while (hashTable[index].key != key) {
        if (hashTable[index].key == -1) {
            return "Key not found";
        }
        index = (index + 1) % TABLE_SIZE;
    }

    return hashTable[index].value;
}

int main() {
    initializeTable();

    // Insert key-value pairs
    insert(1, "Alice");
    insert(11, "Bob");
    insert(21, "Charlie");
    insert(2, "David");

    // Search for values based on keys
    printf("Key 1: %s\n", search(1));
    printf("Key 11: %s\n", search(11));
    printf("Key 21: %s\n", search(21));
    printf("Key 2: %s\n", search(2));

    return 0;
}
