#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char eng[101];
    char indo[101];
    struct Node* next;
}Node;

void add(Node** head_ref, char* buffer_eng, char* buffer_indo){
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->eng, buffer_eng);
    strcpy(new_node->indo, buffer_indo);

    // CASE 1: if empty
    if (*head_ref == NULL){
        *head_ref = new_node;
        new_node->next = NULL;
        return;
    }

    Node* traverse = *head_ref;

    // if beginning
    if (strcmp(new_node->eng, traverse->eng) < 0){
        new_node->next = traverse;
        *head_ref = new_node;
        return;
    }

    Node* prev = NULL;

    // traversing algo
    while (strcmp(new_node->eng, traverse->eng) > 0){
        if (traverse->next == NULL) break;
        if (strcmp(new_node->eng, traverse->eng) == 0){
            break;
        }
        prev = traverse;
        traverse = traverse->next;
    }

    if (strcmp(new_node->eng, traverse->eng) == 0){
        printf("Word already exists\n");
        return;
    }    

    // insert after
    if (strcmp(new_node->eng, traverse->eng) > 0){
        new_node->next = traverse->next;
        traverse->next = new_node;
        return;
    }
    else{
        new_node->next = traverse;
        prev->next = new_node;
        return;
    }
}

void printList(Node* node){
    while (node != NULL){
        printf("%s %s\n", node->eng, node->indo);
        node = node->next;
    }
    return;
}

int main(void){
    Node* head = NULL;
    int menu = 0; 
    do{
        printf("1. Insert\n");
        printf("2. Exit\n");
        scanf("%d", &menu); 
        printf("English: ");
        char eng[101];
        scanf("%s", eng); getchar();
        printf("Indo: ");
        char indo[101];
        scanf("%s", indo); getchar();


        add(&head, eng, indo);

        printList(head);
    }while (menu != 2);

}