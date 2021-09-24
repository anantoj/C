#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Qnode{
    char customer[21];
    char dress[21];
    int price;
    struct Qnode* next;
}Qnode;

typedef struct Queue{
    Qnode* front;
    Qnode* rear;
    int size;
    int capacity;
}Queue;

Queue* createQueue(unsigned capacity){
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    newQueue->size = 0;
    newQueue->capacity = capacity;
    return newQueue;
}

Qnode* createNode(char* customer, char* dress, int price){
    Qnode* new_node = (Qnode*)malloc(sizeof(Qnode));
    strcpy(new_node->customer, customer);
    strcpy(new_node->dress, dress);
    new_node->price = price;
    new_node->next = NULL;
    return new_node;
}

void enqueue(Queue* queue, char* customer, char* dress, int price){
    Qnode* new_node = createNode(customer, dress, price);
    queue->size++;

    // if queue is empty
    if (queue->front == NULL){
        queue->front = queue->rear = new_node;
        return;
    }

    queue->rear->next = new_node;
    queue->rear = new_node;

    return;
}

void dequeue(Queue* queue){
    printf("\n---%s has been served---\n", queue->front->customer);
    queue->size -= 1; 

    Qnode* tmp = queue->front;
    queue->front = queue->front->next;
    free(tmp);

    return;
}

void viewQueue(Queue* queue){
    Qnode* traverse = queue->front;
    int count = 1;
    while (traverse != NULL){
        printf("| %3d. | %-20s | %-20s | $%4d |\n", count, traverse->customer, traverse->dress, traverse->price);
        traverse = traverse->next;
        count += 1;
    }
}

void printLine(){
    printf("+");
    for (int i = 0; i < 6; i++){
        printf("-");
    }
    printf("+");
    for (int i = 0; i < 22; i++){
        printf("-");
    }
    printf("+");
    for (int i = 0; i < 22; i++){
        printf("-");
    }
    printf("+");
    for (int i = 0; i < 8; i++){
        printf("-");
    }
    printf("\n");
}

int isFull(Queue* queue){
    return queue->size == queue->capacity;
}

int main(void){
    Queue* queue = createQueue(10);

    int menu;
    do{
        printf("\n\n\n\n\n");
        printf("BLUE DRESS SHOP CASHIER QUEUE\n");
        printf("#############################\n\n");
        printf("1. View Queue\n");
        printf("2. Add Customer to Queue\n");
        printf("3. Serve Customer\n");
        printf("4. Exit\n\n");

        printf(">> Input choice: ");

        scanf("%d", &menu); getchar();

        if (menu == 1){
            printf("%40s\n\n", "--- QUEUE VIEW ---");
            printLine();
            printf("| No.  | %-20s | %-20s | Price |\n", "Customer's Name", "Dress Name");
            printLine();
            viewQueue(queue);
            printLine();
        }
        else if (menu == 2){
            if (isFull(queue)){
                printf("\n---Maximum Cusotomer in Queue is 10---\n");
            }
            else{
                char customer[21];
                printf("Input Customer's Name [3..20]: ");
                scanf("%[^\n]", customer); getchar();
                do{
                    printf("Input Customer's Name [3..20]: ");
                    scanf("%[^\n]", customer); getchar();
                }while (strlen(customer) < 3 || strlen(customer) > 20);

                char dress[21];
                printf("Input Dress Name [3..20]: ");
                scanf("%[^\n]", dress); getchar();
                do{
                    printf("Input Dress Name [3..20]: ");
                    scanf("%[^\n]", dress); getchar();  
                }while (strlen(dress) < 3 || strlen(dress) > 20);
                
                int price;
                char dollar;
                printf("Input Dress Price [$50..$999]: ");
                scanf("%c%d", &dollar, &price); getchar();
                do{
                    printf("Input Dress Price [$50..$999]: ");
                    scanf("%c%d", &dollar, &price); getchar();
                }while (price < 50 || price > 999);
                
                enqueue(queue, customer, dress, price);
                printf("\n---Success to Add Customer into Queue List---\n");
            }
            
        }
        else if (menu == 3){
            if (queue->size == 0){
                printf("\n---There is No Customer in Queue---\n");
            }
            else{
                dequeue(queue);
            }
        }
    }while (menu != 4);

}