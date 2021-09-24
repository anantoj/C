/* Given a node prev_node, insert a new node after the given 
   prev_node */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

void printList(node* n){
    while (n != NULL){ 
        printf("%d ", n->data); 
        n = n->next; 
    }
    return;
}

void insertAfter(node* prev_node, int new_data){
    // check if previous node is NULL
    if (prev_node == NULL){
        return;
    }

    // allocate memory for new node
    node* new_node = (node*)malloc(sizeof(node));
    // insert data of new node
    new_node->data = new_data;
    // make the new_node point to the address of the next node
    new_node->next = prev_node->next;
    // make the previous node point to the new node
    prev_node->next = new_node;

    return;
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

    int new_data = 10;

    insertAfter(second, new_data);

    printList(head);

    printf("\n");
}