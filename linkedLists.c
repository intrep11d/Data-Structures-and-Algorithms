#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node, *NodePtr;

Node* createNode(int data) {
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

void printList(NodePtr head);

int main() {
//    Node* head = createNode(1);
//    Node* second = createNode(2);
//    Node* third = createNode(3);
    char message[20] = "Hello, I'm Lawrence";
    NodePtr head = createNode(1);
    NodePtr node1 = createNode(10);
    NodePtr node2 = createNode(20);
    NodePtr node3 = createNode(30);
    NodePtr node4 = createNode(40);
    head -> next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next= node4;
    node4->next= NULL;
    printList(head);
    
}

void printList(NodePtr head) {
    NodePtr current = head->next;
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
        printf("\n");
    }
    
}

