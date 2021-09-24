#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 97
#define LEN 69

typedef struct Node{
    char* data;
    struct Node* next;
}Node;

int getMenu(){
    printf("1. Input Data\n");
    printf("2. Search Data\n");
    printf("3. Exit\n");
    int menu;
    scanf("%d", &menu);
    return menu;
}

void insert(Node** head_ref, const char* buffer){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = (char*)malloc(sizeof(char) * LEN);
    strcpy(new_node->data, buffer);
    if (*head_ref == NULL){
        *head_ref = new_node;
    }
    else{
        // inserting at tail
        Node* traverse = *head_ref;
        while (traverse->next != NULL){
            traverse = traverse->next;
        }
        traverse->next = new_node;
    }
    return;
}

int isExist(Node** head_ref, const char* buffer){
    Node* traverse = *head_ref;
    
    while (traverse != NULL){
        if (strcmp(traverse->data, buffer) == 0){
            break;
        }
    }

    if (traverse != NULL){
        return 1;
    }
    return 0;
}

int hash(const char* buffer){
    int key = 0;
    for (int i = 0; i < strlen(buffer); i++){
        key += (key * 31) + (tolower(buffer[i]) - 'a' + 1);
        key = key % SIZE;
    }
    return (key * 31) % SIZE;
}

void clearList(Node** head_ref){
    Node* traverse = *head_ref;
    while (traverse != NULL){
        Node* tmp = traverse;
        traverse = traverse->next;
        free(tmp);
    }
    *head_ref = NULL;
    return;
}

void clearTable(Node* head[]){
    for(int i = 0; i < SIZE; i++){
        clearList(&head[i]);
    }
    return;
}

int main(void){
    Node* head[SIZE] = {NULL};
    int menu;
    do{
        menu = getMenu();
        if (menu == 1){
            char str[LEN];
            printf("Input String: ");
            scanf("%s", str);
            int key = hash(str);
            insert(&head[key], str);
        }
        else if (menu == 2){
            char str[LEN];
            printf("Input String to be searched: ");
            scanf("%s", str);
            int key = hash(str);
            if (isExist(&head[key], str)){
                printf("Data exists\n");
            }
            else{
                printf("Data does not exist\n");
            }
        }
    }while (menu != 3);
    clearTable(head);
}