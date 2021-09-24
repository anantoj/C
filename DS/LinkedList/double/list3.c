#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char* task;
    int priority;
    struct Node* next;
    struct Node* prev;
}Node;

void insert(Node** head_ref, char* task, int priority){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->task = (char*)malloc(sizeof(char) * sizeof(task));
    strcpy(new_node->task, task);
    new_node->priority = priority;
    
    if (*head_ref == NULL){
        new_node->next = new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    Node* traverse = *head_ref;
    if (new_node->priority < traverse->priority){
        new_node->next = traverse;
        traverse->prev = new_node;
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (traverse->next != NULL){
        if (new_node->priority < traverse->priority){
            break;
        }
        traverse = traverse->next;
    }

    if (new_node->priority > traverse->priority){
        new_node->next = traverse->next;
        if (traverse->next != NULL){
            traverse->next->prev = new_node;
        }
        new_node->prev = traverse;
        traverse->next = new_node;
    }
    else{
        new_node->next = traverse;
        if (traverse->prev != NULL){
            traverse->prev->next = new_node;
        }
        new_node->prev = traverse->prev;
        traverse->prev = new_node;
    }
    return;
}

void pop(Node** head_ref){
    if (*head_ref == NULL){
        printf("There is no task\n");
        return;
    }
    Node* tmp = *head_ref;
    (*head_ref) = (*head_ref)->next;
    free(tmp);
    return;
}

void search(Node* node, int priority){
    while (node != NULL){
        if (node->priority == priority || node->priority > priority) break;
        node = node->next;
    }
    if (node == NULL || node->priority > priority){
        printf("Not Found\n");
        return;
    }
    while (node != NULL){
        if (node->priority > priority) break;
        printf("%s\n", node->task);
        node = node->next;
    }
    return;
}

Node* delete(Node** head_ref, char* task){
    if (*head_ref == NULL){
        return NULL;
    }
    Node* traverse = *head_ref;
    if (strcmp(traverse->task, task) == 0){
        Node* tmp = traverse;
        *head_ref = traverse->next;
        traverse->next->prev = NULL;
        free(traverse);
        return tmp;
    }
    
    while (traverse != NULL){
        if (strcmp(traverse->task, task) == 0){
            if (traverse->next != NULL){
                traverse->next->prev = traverse->prev;
            }
            if (traverse->prev != NULL){
                traverse->prev->next = traverse->next;
            }   
            Node* tmp = traverse;
            free(traverse);
            return tmp;
        }   
        traverse = traverse->next;
    }
    return traverse;
}

int getSubMenu(){
    printf("1. Insert urgent task\n");
    printf("2. Insert task\n");
    printf("3. Insert extra task\n");
    printf(">> ");
    int subMenu;
    scanf("%d", &subMenu); getchar();
    return subMenu;
}

int getMenu(){
    printf("To Do List\n");
    printf("==========\n");
    printf("1. Insert new task\n");
    printf("2. Do task\n");
    printf("3. Search task on priority\n");
    printf("4. Update an existing task\n");
    printf("5. Exit\n");
    printf(">> ");
    int menu;
    scanf("%d", &menu); getchar();
    return menu;
}

void printList(Node* node){
    while (node != NULL){
        printf("%s %d\n", node->task, node->priority);
        node = node->next;
    }
    return;
}

void clearList(Node** head_ref){
    Node* traverse = *head_ref;
    *head_ref = NULL;
    while (traverse != NULL){
        Node* tmp = traverse;
        free(tmp);
        traverse = traverse->next;
    }
    return;
}

int main(void){
    Node* head = NULL;
    int menu;
    do{
        printList(head);
        menu = getMenu(); 
        if (menu == 1){
            int subMenu = getSubMenu();
            if (subMenu == 1){
                char task[101];
                printf("Input task name: ");
                scanf("%s", task);
                insert(&head, task, 1);
            }
            else if (subMenu == 2){
                char task[101];
                printf("Input task name:");
                scanf("%s", task);
                int priority;
                do{
                    printf("Input task priority: ");
                    scanf("%d", &priority); getchar();
                }while (priority < 1 || priority > 100);
                insert(&head, task, priority);
            }
            else if (subMenu == 3){
                char task[101];
                printf("Input task name:");
                scanf("%s", task);
                insert(&head, task, 99);
            }
        }   
        else if (menu == 2){
            pop(&head);
        }
        else if (menu == 3){
            int priority;
            printf("Input priority to be searched: ");
            scanf("%d", &priority);
            search(head, priority);
        }
        else if (menu == 4){
            char task[101];
            printf("Input task name: ");
            scanf("%s", task);
            Node* check = delete(&head, task);
            if (check == NULL){
                printf("Not Found\n");
            }
            else{
                printf("Input new task name: ");
                scanf("%s", check->task);
                int priority;
                do{
                    printf("Input new task priority: \n");
                    scanf("%d", &priority);
                }while (priority < 1 || priority > 100);
                insert(&head, check->task, priority);
            } 
        }
    }while (menu != 5);
    clearList(&head);
}

