#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char name[101];
    struct Node* next;
}Node;

Node* head[26] = {NULL};

int hash(const char* buffer){
    return toupper(buffer[0]) - 'A';
}

void insert(const char* buffer){
    Node* new_node = (Node*)malloc(sizeof(Node));

    strcpy(new_node->name, buffer);
    new_node->next = NULL;

    int key = hash(buffer);

    if (head[key] == NULL){
        head[key] = new_node;
    }
    else{
        Node* traverse = head[key];
        while (traverse->next != NULL){
            traverse = traverse->next;
        }
        traverse->next = new_node;
    }
}

void search(const char* buffer){
    int key = hash(buffer);
    
    Node* traverse = head[key];
    while (traverse != NULL){
        if (strcmp(traverse->name, buffer) == 0){
            printf("Found\n");
            break;
        }
        traverse = traverse->next;
    }

    if (traverse == NULL){
        printf("Not Found\n");
    }
}

void printList(Node* n){
    while (n != NULL){
        printf("%s ", n->name);
        n = n->next;
    }
}

void display(){
    for (int i = 0; i < 26; i++){
        if (head[i] == NULL){
            continue;
        }
        else{
            printf("[%d] ", i);
            printList(head[i]);
            printf("\n");
        }
    }
}

int main(void){
    int menu;
    do{
        printf("1. Add data\n");
        printf("2. Search data\n");
        printf("3. Display data\n");
        printf("4. Exit\n");

        scanf("%d", &menu);

        if (menu == 1){
            printf("Input Name: ");
            char name[101]; 
            scanf("%s", name);
            insert(name);
        }
        else if (menu == 2){
            printf("Input Name: ");
            char name[101];
            scanf("%s", name);
            search(name);
        }
        else if (menu == 3){
            display();
        }
    }while (menu != 4);
}