/*
A simple program that illustrates a hash table, a simple hash function, and a chaining
with a global array of head pointers
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char name[101];
    struct Node* next;
}Node;

Node* head[26] = {NULL};

void insert(int key, const char* buffer){
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        return;
    }

    strcpy(new_node->name, buffer);

    new_node->next = NULL;

    if (head[key] == NULL){
        head[key] = new_node;
    }
    else{
        Node* traverse = head[key];
        while(traverse->next !=NULL){
            traverse = traverse->next;
        }
        traverse->next = new_node;
    }
}

int hash(const char* buffer){
    return tolower(buffer[0]) - 'a';
}

void printList(Node* node){
    while(node != NULL){
        printf("%s-> ", node->name);
        node = node->next;
    }
}

void display(){
    for (int i = 0; i < 26; i++){
        printf("[%d]->", i);
        printList(head[i]);
        printf("NULL");
        printf("\n");
    }
}

int main(void){

    int num;
    scanf("%d", &num); getchar();
    for (int i = 0; i < num; i++){
        char name[101];
        scanf("%s", name); getchar();

        int hashedValue = hash(name);

        insert(hashedValue, name);
    }

    display();
}