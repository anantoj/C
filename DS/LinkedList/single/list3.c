#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Qnode{
    char* id;
    char* name;
    char* course;
    int price;
    struct Qnode* next;
}Qnode;

typedef struct Queue{
    Qnode* front;
    Qnode* rear;
}Queue;

Queue* createQueue(){
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->front = newQueue->rear = NULL;
    return newQueue;
}

void enqueue(Queue* queue, const char* id, const char* name, const char* course, int price){
    Qnode* new_node = (Qnode*)malloc(sizeof(Qnode));
    new_node->id = (char*)malloc(sizeof(id));
    new_node->name = (char*)malloc(sizeof(name));
    new_node->course = (char*)malloc(sizeof(course));
    strcpy(new_node->id, id);
    strcpy(new_node->name, name);
    strcpy(new_node->course, course);
    new_node->price = price;
    new_node->next = NULL;
    if (queue->rear == NULL){
        queue->rear = queue->front = new_node;
        return;
    }

    queue->rear->next = new_node;
    queue->rear = new_node;
    return;
}   

void dequeue(Queue* queue){
    if (queue->front == NULL){
        printf("No Food ordered!\n");
        return;
    }
    Qnode* tmp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL){
        queue->rear = NULL;
    } 
    free(tmp);
    printf("Food succesfully served\n");
    return;
}

void viewQueue(Queue* queue){
    if (queue->front == NULL) return;
    Qnode* traverse = queue->front;
    printf("====================================================================\n");
    printf("| %5s | %20s | %20s | %10s |\n", "ID", "Food Name", "Course", "Price");
    printf("====================================================================\n");
    while (traverse != NULL){
        printf("| %5s | %20s | %20s | %10d |\n", traverse->id, traverse->name, traverse->course, traverse->price);
        printf("====================================================================\n");
        traverse = traverse->next;
    }
}

int getMenu(){
    printf("Bluejack Restaurant Order\n");
    printf("=========================\n");
    printf("1. Make Order\n");
    printf("2. View Order\n");
    printf("3. Delete Order\n");
    printf("4. Exit\n");
    printf("Input : ");
    int menu;
    scanf("%d", &menu); getchar();
    return menu;
}

int main(void){
    Queue* queue = createQueue();
    int menu;
    do{
        menu = getMenu();
        if (menu == 1){
            char flag = 'Y';
            do{
                int a = rand() % 1000;
                char id[6];
                sprintf(id, "FD%03d", a);
                printf("Order ID: %s\n", id);
                printf("====================\n\n");
                char name[101] = "";
                do{
                    printf("Input food Name [Chicken Steak|Cheese Cake|Spiced Olives] : ");
                    scanf("%[^\n]", name); getchar();
                }while(strcmp(name, "Chicken Steak") != 0 && strcmp(name, "Cheese Cake") != 0&& strcmp(name, "Spiced Olives") != 0);
                char course[101];
                int price;
                if (strcmp(name, "Chicken Steak") == 0){
                    strcpy(course, "Main Course");
                    price = 250000;
                }
                else if (strcmp(name, "Cheese Cake") == 0){
                    strcpy(course, "Dessert");
                    price = 150000;
                }
                else if (strcmp(name, "Spiced Olives") == 0){
                    strcpy(course, "Appetizer");
                    price = 100000;
                }
                enqueue(queue, id, name, course, price);
                do{
                    printf("Do you want to add another food?[Y|N]: ");
                    scanf("%c", &flag); getchar();
                }while (flag != 'Y' && flag != 'N');
            }while (flag == 'Y');

        }
        else if (menu == 2){
            viewQueue(queue);
        }
        else if (menu == 3){
            dequeue(queue);
        }
    }while (menu != 4);
}