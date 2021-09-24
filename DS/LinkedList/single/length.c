#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

void push(node** head_ref, int new_data){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

int iterativeLength(node *n){
    int count = 0;
    while (n != NULL){
        count++;
        n = n->next;
    }
    return count;
}

int recursiveLength(node *n){
    if (n == NULL) 
        return 0;
    
    return 1 + recursiveLength(n->next);
}


int main(void){
    node* head = NULL;

    push(&head, 6);
    push(&head, 4);
    push(&head, 2);
    
    printf("%d %d\n", iterativeLength(head), recursiveLength(head));
}