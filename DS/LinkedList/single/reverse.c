#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void reverse(Node** head_ref){
    Node* traverse = *head_ref;
    Node* prev = NULL;
    Node* tmp = NULL;

    /*
    unoptimal
    prev = traverse;
    traverse = traverse->next;
    prev->next = NULL;
    
    while(traverse != NULL){
        tmp = traverse->next;
        traverse->next = prev;
        prev = traverse;
        traverse = tmp; 
    }
    */

   
   // optimal
   while(traverse != NULL){
        tmp = traverse->next;
        traverse->next = prev;
        prev = traverse;
        traverse = tmp;
   }

    *head_ref = prev;
}

void push(Node** head_ref, int new_data){
    Node* new_node = (Node*)malloc(sizeof(Node));

    new_node->data = new_data;
    new_node->next = *head_ref;

    *head_ref = new_node;
}

void printList(Node* n){
    while(n != NULL){
        printf("%d ",n->data);
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