#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

void append(node** head_ref, int new_data){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL){
        *head_ref = new_node;
        return;
    }

    node* traverse = *head_ref;
    while(traverse->next != NULL){
        traverse = traverse->next; 
    }

    traverse->next = new_node;
}

void deleteList(node** head_ref){
    // if list is already empty just return
    if (*head_ref == NULL){
        return;
    }
    
    node* track = *head_ref;
    node* throw = NULL;

    while(track != NULL){            // OR 
        throw = track;              // tmp2 = tmp1->next
        free(throw);                // free(tmp1);
        track = track->next;        // tmp1 = tmp2 
    }
    // head_ref needs to point to NULL after deletion, REMEMBER!
    *head_ref = NULL;

    return;

}

void printList(node *n){
    while(n != NULL){
        printf("%d ",n->data);
        n = n->next;
    }
}


int main(void){
    node* head = NULL;
    
    append(&head, 2);
    append(&head, 4);
    append(&head, 6);
    printList(head);
    printf("\n");
    deleteList(&head);
    printList(head);
    printf("\n");

}