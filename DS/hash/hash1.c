/*
A simple program that illustrates a hash table, a simple hash function, and a chaining
with a local array of head pointers
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char name[101];
    struct Node* next;
}Node;

void insert(Node** head_ref, const char* buffer){
    // allocate new node
    Node* new_node = (Node*)malloc(sizeof(Node));

    // insert data
    strcpy(new_node->name, buffer);
    new_node->next = NULL;
    
    // in case the list is empty we need to change the head pointer
    // that is why we bring *head_ref in the parameter
    if (*head_ref == NULL){
        *head_ref = new_node;
    }
    else{
        // chaining
        Node* traverse = *head_ref;
        while(1){
            if (traverse->next == NULL){
                traverse->next = new_node;
                break;
            }
            traverse = traverse->next;
        }
    }
}

// hash function
int hash(const char* buffer){
    return tolower(buffer[0]) - 'a';
}

void printList(Node* node){
    while(node != NULL){
        printf("%s ", node->name);
        node = node->next;
    }
}

void display(Node* head[]){
    for (int i = 0; i < 26; i++){
        printf("[%d] ", i);
        printList(head[i]);
        printf("\n");
    }
}

int main(void){
    Node* head[26] = {NULL};

    int num;
    scanf("%d", &num); getchar();
    for (int i = 0; i < num; i++){
        char name[101];
        scanf("%s", name); getchar();

        int key = hash(name);

        insert(&head[key], name);
    }

    display(head);
}