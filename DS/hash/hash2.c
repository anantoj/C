#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node{
    char name[101];
    char phone[101];
    struct Node* next;
}Node;

Node* head[26] = {NULL};

int getMenu(){
    printf("Phone Book\n");
    printf("==========\n");
    printf("1. Add\n");
    printf("2. Search\n");
    printf("3. Display\n");
    printf("4. Delete\n");
    printf("5. Exit\n");
    printf(">> ");
    int menu;
    scanf("%d", &menu); getchar();
    return menu;
}

int hash(char* buffer){
    return toupper(buffer[0]) - 'A';
}

void insert(int key, char* buffer, char* bufferPhone){
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        return;
    }
    strcpy(new_node->name, buffer);
    strcpy(new_node->phone, bufferPhone);
    new_node->next = NULL;

    if (head[key] == NULL){
        head[key] = new_node;
        return;
    }
    else{
        Node* traverse = head[key];

        while (traverse->next != NULL){
            traverse = traverse->next;
        }

        traverse->next = new_node;

        return;
    }
}

void search(int key, char* buffer){
    if (head[key] == NULL){
        printf("Not Found\n");
        return;
    }

    Node* traverse = head[key];

    while (traverse->next != NULL){
        if (strcmp(traverse->name, buffer) == 0){
            break;
        }
        traverse = traverse->next;
    }

    if (strcmp(traverse->name, buffer) == 0){
        printf("Phone Number: %s\n", traverse->phone);
        return;
    }

    printf("Not Found\n");
    return;
}

void printList(int index){
    Node* n = head[index];
    while (n != NULL){
        printf("%s -> ", n->name);
        n = n->next;
    }
    printf("NULL");
}

void display(){
    for (int i = 0; i < 26; i++){
        printf("[%2d]", i);
        printList(i);
        printf("\n");
    }
    return;
}

void delete(int key, char* buffer){
    if (head[key] == NULL){
        printf("Name Does not exist\n");
        return;
    }

    Node* traverse = head[key];
    Node* prev = NULL;

    while (traverse->next != NULL){
        if (strcmp(traverse->name, buffer) == 0){
            break;
        }
        prev = traverse;
        traverse = traverse->next;
    }

    if (strcmp(traverse->name, buffer) == 0){
        if (prev != NULL){
            prev->next = traverse->next;
        }
        else{
            head[key] = traverse->next;
        }
        free(traverse);
    }

    printf("%s has been deleted\n", buffer);
    return;
}

void clear(){
    for (int i = 0; i < 26; i++){
        Node* traverse = head[i];
        while (traverse != NULL){
            Node* tmp = traverse;
            traverse = traverse->next;
            free(tmp);
        }
    }
}

int main(void){
    int menu;
    do{
        menu = getMenu();

        if (menu == 1){
            printf("Name: ");
            char name[101];
            scanf("%s", name); getchar();
            printf("Phone: ");
            char phone[101];
            scanf("%s", phone); getchar();
            int key = hash(name);
            insert(key, name, phone);
            printf("Success adding new contact\n");
        }
        else if (menu == 2){
            printf("Input name to be searched: ");
            char find[101];
            scanf("%s", find);
            int key = hash(find);
            search(key, find);    
        }
        else if (menu == 3){
            display();
        }
        else if (menu == 4){
            printf("Input name to be deleted: ");
            char del[101];
            scanf("%s", del);
            int key = hash(del);
            delete(key, del);
        }
        else if (menu == 5){
            clear();
        }
    }while (menu != 5);
}