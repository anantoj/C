#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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

int getNth(node* n, int position){
    // this algorithm will work for position 0 and if the list is empty
    // we do not need to use node* tmp because we are given the head node
    // if we are given the *head_ref (which means we need to manipulate the list), then we need tmp
    node* prev = NULL;

    for (int i = 0; i < position; i++){
        if (n == NULL) break;

        prev = n;
        n = n->next;
    }

    if (n == NULL) assert(0);

    return n->data;

}


int main(void){
    node* head = NULL;
    
    push(&head, 8);
    push(&head, 6);
    push(&head, 4);
    push(&head, 2);

    int num = getNth(head, 0);

    printf("%d\n", num);
}