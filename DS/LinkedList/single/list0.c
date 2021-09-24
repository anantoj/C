#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void push(Node** head_ref, int new_data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
    return;
}

void append(Node** head_ref, int new_data){
    Node* new_node = (Node*)malloc(sizeof(Node));

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL){
        *head_ref = new_node;
        return;
    }

    Node* traverse = *head_ref;

    while (traverse->next != NULL){
        traverse = traverse->next;
    }
    traverse->next = new_node;

    return;
}

void insertAfter(Node* prev_node, int new_data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    return;
}

void printList(Node* n){
    while(n != NULL){
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}

int main(void){
    /* Start with the empty list */
  Node* head = NULL; 
  
  // Insert 6.  So linked list becomes 6->NULL 
  append(&head, 6); 
  
  // Insert 7 at the beginning. So linked list becomes 7->6->NULL 
  push(&head, 7); 
  
  // Insert 1 at the beginning. So linked list becomes 1->7->6->NULL 
  push(&head, 1); 
  
  // Insert 4 at the end. So linked list becomes 1->7->6->4->NULL 
  append(&head, 4); 
  
  // Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL 
  insertAfter(head->next, 8); 
  
  printList(head); 
  
  return 0; 
}