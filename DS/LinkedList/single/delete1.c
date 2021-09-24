/* Given a reference (pointer to pointer) to the head of a list 
   and a key, deletes the first occurrence of key in linked list */

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

void deleteNode(node** head_ref, int key){
    if (*head_ref == NULL){
        return;
    }

    node* tmp = *head_ref;

    if (tmp->data == key){
        *head_ref = tmp->next;
        free(tmp);
        return;
    }

    node* prev = NULL;

    while (tmp != NULL && tmp->data != key){
        prev = tmp;
        tmp = tmp->next;
    }
    
    prev->next = tmp->next;

    free(tmp);

    return;

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
    deleteNode(&head, 10);
    printList(head);
    printf("\n");
}