#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char* data;
    struct Node* next;
}Node;

void insert(Node** head_ref, char* data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->data, data);
    new_node->next = NULL;
    if (*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    else{
        Node* traverse = *head_ref;
        while(traverse->next != NULL){
            traverse = traverse->next;
        }
        traverse->next = new_node;
    }
    return;
}

int hash(char* data){
    return toupper(data[0]) - 'A';
}

void printList(Node* node){
    while (node != NULL){
        printf("%s ", node->data);
        node = node->next;
    }
    return;
}

void display(Node* head[]){
    for (int i = 0; i < (sizeof(head) / sizeof(Node)); i++){
        printList(head[i]);
    }
}

int main(void){
    Node* head[26] = {NULL};
    
}