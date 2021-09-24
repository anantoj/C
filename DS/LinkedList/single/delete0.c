/* Given a reference (pointer to pointer) to the head of a list 
   and a position, deletes the node at the given position */

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
    return;
}

void printList(node* n){
    while(n != NULL){
        printf("%d ", n->data);
        n = n->next;
    }
}

// NOTE: position to be deleted is zero-indexed!
void deleteNode(node** head_ref, int position){
    // if linked list is empty, return
    if (*head_ref == NULL){
        return;
    }

    node* tmp = *head_ref;
    // if head node is to be deleted
    if (position == 0){
        *head_ref = tmp->next; // make the next element become the head node
        free(tmp);
        return;
    }

    // we need to create a node variable that keeps track of the previous node
    node* prev = NULL;

    // find the position node that wants to be deleted
    for (int i = 0; i < position; i++){
        prev = tmp;
        tmp = tmp->next;
        if (tmp == NULL) return; // if position is more than number of nodes in the list
    }


    // the previous node (of the wanted deleted node) will now point to the next node (of the wanted deleted node)
    prev->next = tmp->next;
    
    // delete the node
    free(tmp);
}




int main(void){
    node* head = NULL;

    append(&head, 2);
    append(&head, 4);
    append(&head, 6);
    append(&head, 8);
    append(&head, 10);

    printf("Before:\n");
    printList(head);
    printf("\n");

    printf("After:\n");
    // NOTE: position to be deleted is zero-indexed!
    deleteNode(&head, 4);
    printList(head);
    printf("\n");
}