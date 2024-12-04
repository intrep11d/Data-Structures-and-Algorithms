#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char name[25];
    char size;
}Customer;

typedef struct {
    char description[25];
    float price;
    char size;
}Clothing;

Customer addCustomer(char addName[25], char addSize);

int main() {
    int size = 3;
    float total = 0.0;
    Customer c1 = {"Pinky", 'S'};
    
    Clothing item1 = {"Blue Jacket", 20.9, 'M'};
    Clothing item2 = {"Orange T-shirt", 10.5, 'S'};
    Clothing item3 = {"Green Scarf", 5, 'S'};

    Customer c2 = addCustomer("Blue Balls", 'L');
    printf("%s, %c\n", c2.name, c2.size);
    Clothing items[] = {item1, item2, item3};
    // strcpy(c1.name, "Pinky");
    // c1.size = 'S';
    // printf("%s\n", c1.name);
    // printf("%c\n", c1.size);

    // printf("%s", item1.description);
    for (int idx = 0; idx < size; idx++) {
        printf("%s\n", items[idx].description);
    }

    // for (int idx = 0; idx < size; idx++) {
    //     total += items[idx].price;
    // }
    // printf("%.2f", total); 
}

Customer addCustomer(char addName[25], char addSize) {
    Customer newCustomer;
    strcpy(newCustomer.name, addName);
    newCustomer.size = addSize;
    return newCustomer;
}