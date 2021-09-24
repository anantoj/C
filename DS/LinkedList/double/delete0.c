#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

void deleteNode(Node** head_ref, int position){
    if (*head_ref == NULL) return;

    Node* tmp = *head_ref;
    Node* prev = NULL;

    if (position == 0){
        tmp->next->prev = NULL;
        *head_ref = tmp->next;
        free(tmp);
        return;
    }

    for (int i = 0; i < position; i++){
        // the if statement must be on top
        // because it implies if we reach the tail node and the for loop is not done, 
        // then we will free NULL
        // if (tmp->next == NULL){ // NOTE: if we use tmp == NULL, tmp may reach NULL is pos(0-idx) = numNode  
        //     return;
        // }
        prev = tmp;
        tmp = tmp->next;
        // or we can use this condition at the bottom
        if (tmp == NULL){
            return;
        }
    }

    
    if (tmp->next != NULL){
        tmp->next->prev = prev;
        // tmp->next->prev = tmp ->prev
    }

    prev->next = tmp->next;
    // tmp->prev->next = tmp->next;

    free(tmp);
    
}

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
    while(traverse->next != NULL){
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
    append(&head, 8);
    append(&head, 10);

    deleteNode(&head, 5);

    printList(head);
}




