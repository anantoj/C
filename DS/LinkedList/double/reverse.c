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
        new_node->next->prev = new_node;
    }

    *head_ref = new_node;
}

void reverse(Node** head_ref){
    if(*head_ref == NULL){
        return;
    }
    Node* traverse = *head_ref;
    Node* tmp = NULL;

    while(traverse->next != NULL){
        tmp = traverse->prev;
        traverse->prev = traverse->next;
        traverse->next = tmp;
        traverse = traverse->prev;
    }    
    
    tmp = traverse->prev;
    traverse->prev = traverse->next;
    traverse->next = tmp;

    *head_ref = traverse;
}

void printList(Node* n){
    while(n != NULL){
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}

int main(void){
    Node* head = NULL;

    push(&head, 8);
    push(&head, 6);
    push(&head, 4);
    push(&head, 2);

    printList(head);

    reverse(&head);

    printList(head);

}