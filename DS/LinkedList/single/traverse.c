#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

void printList(node* n){
    while (n != NULL){ // if the address is not NULL
        printf("%d ", n->data); // printing an element of a linked list
        n = n->next; // n points to the next address
    }
}

int main(void){
    node* head = NULL;
    node* second = NULL;
    node* third = NULL;

    head = (node*)malloc(sizeof(node));
    second = (node*)malloc(sizeof(node));
    third = (node*)malloc(sizeof(node));

    head->data = 2;
    head->next = second;

    second->data = 4;
    second->next = third;

    third->data = 6;
    third->next = NULL;

    printList(head);

    printf("\n");
}