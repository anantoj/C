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
    if (*head_ref != NULL){
        (*head_ref)->prev = new_node;
    }
    *head_ref = new_node;
}

void insertAfter(Node* prev_node, int new_data){
    if (prev_node == NULL){
        return;
    }

    Node* new_node = (Node*)malloc(sizeof(Node));

    new_node->data = new_data;
    new_node->next = prev_node->next;
    new_node->prev = prev_node;

    // NOTE: ORDER MATTERS!
    // if the next node of prev_node is not null then we need to connect it with the new node
    if(prev_node->next != NULL)
        prev_node->next->prev = new_node;
    
    prev_node->next = new_node;
    
    return;
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

    insertAfter(head->next->next, 7);

    printList(head);
    
}