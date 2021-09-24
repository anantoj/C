#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

void push(Node** head_ref, int new_data){
    Node* new_node = (Node*)malloc(sizeof(Node));

    new_node->data = new_data;
    new_node->next = *head_ref;
    new_node->prev = NULL;

    // if the list is not empty
    if (*head_ref != NULL){
        (*head_ref)->prev = new_node; // point the prev of the ex-head node to the new head node instead of NULL
    }

    *head_ref = new_node;
}

void printList(Node* n){
    while (n != NULL){
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}

int main(void){
    Node* head = NULL;

    push(&head, 2);
    push(&head, 4);
    push(&head, 6);

    printList(head);
}