#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char name[101];
    int age;
    struct Node* next;
}Node;

Node* head = NULL;

void add(Node** head_ref, char* name, int age){
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->age = age;

    // CASE: list is empty
    if (*head_ref == NULL){
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }

    Node* traverse = *head_ref;
    Node* prev = NULL;

    // CASE: insert at the beginning of the list
    if (traverse->age > new_node->age){
        new_node->next = traverse;
        *head_ref = new_node;
        return;
    }
    
    // traversing algorithm
    while(new_node->age >= traverse->age && traverse->next != NULL){
        if (traverse->age == new_node->age){
            break;
        }
        prev = traverse;
        traverse = traverse->next;
    }

    // CASE: if age is equal, sort lexicographically
    if (traverse->age == new_node->age){
        if (strcmp(traverse->name, new_node->name) < 0){
            // insert after
            new_node->next = traverse->next;
            traverse->next = new_node;
        }
        else{
            // insert before
            prev->next = new_node;
            new_node->next = traverse;
        }
        return;
    }

    // CASE: insert before traverse node
    if (traverse->age > new_node->age){
        prev->next = new_node;
        new_node->next = traverse;
        return;
    }

    // CASE: insert after traverse node
    new_node->next = traverse->next;
    traverse->next = new_node;
}

void delete(Node** head_ref, int age){
    Node* traverse = *head_ref;
    Node* prev = NULL;

    while (traverse != NULL){
        // because sorted
        if (traverse->age > age) break;
        if (traverse->age == age){
            Node* tmp = traverse;
            // if the head node is to be deleted
            if (*head_ref == traverse){
                *head_ref = traverse->next; // move the head pointer to the next node
                traverse = traverse->next;
                free(tmp);
            }
            // if the node to be deleted is NOT a head node
            else{
                prev->next = traverse->next; // connect previous node with next node (of traverse node)
                // NOTE: if head node is to be deleted then prev will be pointing NULL, hence the statement results in seg-fault
                traverse= traverse->next;
                free(tmp);
            }
            
        }
        else{
            prev = traverse;
            traverse = traverse->next;
        }
    }
}

void printList(Node* n){
    while (n != NULL){
        printf("%s %d\n", n->name, n->age);
        n = n->next;
    }
    printf("\n");
}

int main(void){
   
    int menu = 0;

    do{
        printf("1. Add (sorted by age)\n");
        printf("2. Delete (by age)\n");
        printf("3. Exit\n");
        printf("Choose menu: ");
        scanf("%d", &menu); getchar();

        if (menu == 1){
            char name[101];
            int age;
            printf("Input Name: ");
            scanf("%s", name);
            printf("Input Age: ");
            scanf("%d", &age);

            add(&head, name, age);
        }
        else if (menu == 2){
            int age;
            printf("Input Age: ");
            scanf("%d", &age);
            delete(&head, age);
        }
    }while (menu != 3);

    printList(head);
}