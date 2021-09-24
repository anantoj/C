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
    while (traverse->next != NULL){
        traverse = traverse->next;
    }
    
    traverse->next = new_node;
}

int iterativeSearch(node *n, int key){
    while(n != NULL){
        if (n->data == key) return 1;

        n = n->next;
    }
    return 0;
}

int recursiveSearch(node* n, int key){
    if (n->data == key){
        return 1;
    }
    else if (n->next == NULL){
        return 0;   
    }

    return recursiveSearch(n->next, key);
}

void printList(node *n){
    while (n != NULL){
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}

int main(void){
    node* head = NULL;

    append(&head, 2);
    append(&head, 4);
    append(&head, 6);
    append(&head, 8);
    append(&head, 10);
    printList(head);

    printf("key = ");
    int key;
    scanf("%d", &key);

    int flag = recursiveSearch(head, key);

    if (flag == 0){
        printf("Element Does Not Exist\n");
    }
    else{
        printf("Element Exists\n");
    }
}