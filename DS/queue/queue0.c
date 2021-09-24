#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue{
    int front, rear, size;
    unsigned capacity;
    char** customer;
    char** dress;
    int* price;
}Queue;

Queue* createQueue(unsigned capacity){
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->front = 0;
    newQueue->rear = -1;
    newQueue->size = 0;
    newQueue->capacity = capacity;
    newQueue->price = (int*)malloc(sizeof(int) * capacity);
    newQueue->customer = (char**)malloc(sizeof(char*) * capacity);
    for (int i = 0; i < capacity; i++){
        newQueue->customer[i] = (char*)malloc(sizeof(char) * 21);
    }
    newQueue->dress = (char**)malloc(sizeof(char*) * capacity);
    for (int i = 0; i < capacity; i++){
        newQueue->dress[i] = (char*)malloc(sizeof(char) * 21);
    }
    return newQueue;
}

void enqueue(Queue* queue, char* customer, char* dress, int price){
    queue->rear = (queue->rear+1) % queue->capacity;
    strcpy(queue->customer[queue->rear], customer);
    strcpy(queue->dress[queue->rear], dress);
    queue->price[queue->rear] = price;
    queue->size++;
    return;
}

void dequeue(Queue* queue){
    printf("\n---%s has been served---\n", queue->customer[queue->front]); 
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return;
}

void viewQueue(Queue* queue){
    int index = queue->front;
    for (int i = 0; i < queue->size; i++){
        printf("| %3d. | %-20s | %-20s | $%4d |\n", i+1, queue->customer[index], queue->dress[index], queue->price[index]);
        index = (index + 1) % queue->capacity;
    }
    return;
}

int isFull(Queue* queue){
    return queue->size == queue->capacity;
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
                printf("Input Customer's Name [3..20]: ");
                char customer[21];
                scanf("%[^\n]", customer); getchar();
                printf("Input Dress Name [3..20]: ");
                char dress[21];
                scanf("%[^\n]", dress); getchar();
                printf("Input Dress Price [$50..$999]: ");
                int price;
                char dollar;
                scanf("%c%d", &dollar, &price); getchar();
                
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