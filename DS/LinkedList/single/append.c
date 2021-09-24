/* Given a reference (pointer to pointer) to the head 
   of a list and an int, appends a new node at the end  */

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

/* Given a reference (pointer to pointer) to the head 
   of a list and an int, appends a new node at the end  */
void append(node** head_address, int new_data){
    // allocate new node
    node* new_node = (node*)malloc(sizeof(node));
    
    //insert data, and next pointer to NULL
    new_node->data = new_data;
    new_node->next = NULL;

    //if the list is empty, create the list starting with the new node as the head node
    if(*head_address == NULL){
        *head_address = new_node;
        return;
    }
    
    // if the list is not empty we traverse the list to the end
    // create a traversing node, which starts with the head address
    // is this true? we do not use malloc because we do not want to fill the traverse node with data, it is simply a pointer
    node* traverse = *head_address;
    
    //traversing algorithm
    while(traverse->next !=NULL){ // REMEMBER: last node points to  NULL
        traverse = traverse->next;
    }

    // when we reach the last node, point the last node the new last node
    traverse->next = new_node;

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
    append(&head, new_data);

    printList(head);

    printf("\n");
}