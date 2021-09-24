#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

void append(Node** head_ref, int new_data){
    Node* new_node = (Node*)malloc(sizeof(Node));

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL){
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    
    Node* traverse = *head_ref;

    while (traverse->next != NULL){
        traverse = traverse->next;
    }

    traverse->next = new_node;
    new_node->prev = traverse;
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

    append(&head, 2);
    append(&head, 4);
    append(&head, 6);

    printList(head);
    
}