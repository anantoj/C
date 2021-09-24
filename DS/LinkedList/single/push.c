/* Given a reference (pointer to pointer) to the head of a list 
   and an int,  inserts a new node on the front of the list. */

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
/* Given a reference (pointer to pointer) to the head of a list 
   and an int,  inserts a new node on the front of the list. */
void push(node** head_address, int new_data){
    // allocate new node
    node* new_node = (node*)malloc(sizeof(node));
    // insert the data of the new node
    new_node->data = new_data;
    // point the next address of the node to the previous head address
    new_node->next = *head_address;
    // move the "head" address to the new node
    *head_address = new_node;
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

    // printf("previous head address: %p\n", &head);
    // printf("previous head data = %d\n", head->data);
    // printf("previous head next pointer: %p\n", head->next);

    push(&head, new_data);

    // printf("new head address: %p\n", &head);
    // printf("new head data: %d\n", head->data);
    // printf("new head next pointer: %p\n", head->next);

    //after the push function is executed, new_node is now head

    printList(head);

    printf("\n");
}