#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char name[101];
    int age;
    struct Node* next;
    struct Node* prev; 
}Node;

// function to add a new node BEFORE the traverse node
void insertBefore(Node** head_ref, Node* traverse, Node* new_node){
    if (traverse->prev != NULL){
        traverse->prev->next = new_node;
    }
    new_node->prev = traverse->prev;
    new_node->next = traverse;
    traverse->prev = new_node;
    if (*head_ref == traverse){
        *head_ref = new_node;
    }
    return;
}

// function to add a new node AFTER the traverse node
void insertAfter(Node** tail_ref, Node* traverse, Node* new_node){
    new_node->next = traverse->next;
    new_node->prev = traverse;
    if (traverse->next != NULL){
        traverse->next->prev = new_node;
    }
    traverse->next = new_node;
    if (*tail_ref == traverse){
        *tail_ref = new_node;
    }
    return;
}

void add(Node** head_ref, Node** tail_ref, char* name, int age){
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->name, name); // masukin nama
    new_node->age = age; // masukin umur

    // CASE: list is empty
    if (*head_ref == NULL){
        *head_ref = new_node;
        *tail_ref = new_node;
  
        new_node->next = NULL;
        new_node->prev = NULL;
        return;
    }

    Node* traverse = *head_ref; // traversing node

    // CASE: insert at the beginning
    if (traverse->age > new_node->age){
        traverse->prev = new_node;
        new_node->next = traverse;
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    // traversing algorithm
    while(new_node->age >= traverse->age && traverse->next != NULL){
        if (traverse->age == new_node->age){
            break;
        }
        traverse = traverse->next;
    }

    // CASE: age is the same, sort lexicographically
    if (traverse->age == new_node->age){
        if (strcmp(new_node->name, traverse->name) < 0){
            insertBefore(head_ref, traverse, new_node);
        }
        else{
            while (traverse->next != NULL){
                if (traverse->age != new_node->age) break;

                if(strcmp(new_node->name, traverse->name) > 0){
                    traverse = traverse->next;
                }
                else break;
            }

            if (traverse->age != new_node->age){
                insertBefore(head_ref, traverse, new_node);
            }
            else{
                if (strcmp(traverse->name, new_node->name) < 0){

                insertAfter(tail_ref, traverse, new_node);
                }
                else{
                    insertBefore(head_ref, traverse, new_node);
                }    
            }
        }
        return;
    }
    // CASE: insert before the traverse node
    if (traverse->age > new_node->age){
        insertBefore(head_ref, traverse, new_node);
    }
    else{
    // CASE: insert after the traverse node
        insertAfter(tail_ref, traverse, new_node);
    }
    return;
    // Copyright Acip's Property
}

void delete(Node** head_ref, Node** tail_ref, int age){
    Node* traverse = *head_ref;

    while (traverse != NULL){
        // because sorted
        if (traverse->age > age){
            break;
        }

        // if age is equal, then delete
        if( traverse->age == age){
            // CASE: head is to be deleted
            if (*head_ref == traverse)
                *head_ref = traverse->next;
            
            // CASE: tail is to be deleted
            if (*tail_ref == traverse)
                *tail_ref = traverse->prev;
            
                
            Node* tmp = traverse;
            // if prev is not NULL, connect prev
            if (traverse->prev != NULL)
                traverse->prev->next = traverse->next;

            // if next is not NULL, connect next
            if (traverse->next != NULL)
                 traverse->next->prev = traverse->prev;

            free(tmp);
        }
        traverse = traverse->next;
    }
    
}

void printAscending(Node** head_ref){
    Node* n = *head_ref;
    while (n != NULL){
        printf("%s %d\n", n->name, n->age);
        n = n->next;
    }
}

void printDescending(Node** tail_ref){
    Node* n = *tail_ref;
    while (n != NULL){
        printf("%s %d\n", n->name, n->age);
        n = n->prev;
    }
}

void clearList(Node* n){
    while (n != NULL){
        Node* tmp = n;
        n = n->next;
        free(tmp);
    }
}

int main(void){
    Node* head = NULL;
    Node* tail = NULL;
    int menu = 0;
    do{
        printf("1. Add (sorted by age)\n");
        printf("2. Delete (by age)\n");
        printf("3. View (by age)\n");
        printf("4. Exit\n");
        printf("Choose menu: ");
        scanf("%d", &menu); getchar();

        if (menu == 1){
            char name[101];
            int age;
            printf("Input Name: ");
            scanf("%s", name);
            printf("Input Age: ");
            scanf("%d", &age);
    
            add(&head, &tail, name, age);
        }
        else if (menu == 2){
            int age;
            printf("Input Age: ");
            scanf("%d", &age);
            delete(&head, &tail, age);
        }
        else if (menu == 3){
            printf("1. Ascending\n");
            printf("2. Descending\n");
            printf(">>");
            int choice;
            scanf("%d", &choice);

            if (choice == 1){
                printAscending(&head);
            }
            else if (choice == 2){
                printDescending(&tail);
            }
        }
    }while (menu != 4);
    clearList(head);
    return 0;
}