#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char* file;
    struct Node* next;
    struct Node* prev;
}Node;

typedef struct Queue{
    Node* front;
    Node* rear;
}Queue;

Queue* createQueue(){
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->front = newQueue->rear = NULL;
    return newQueue;
}

void enqueue(Queue* queue, const char* file){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->file = (char*)malloc(sizeof(file));
    strcpy(new_node->file, file);
    new_node->next = new_node->prev = NULL;
    if (queue->rear == NULL){
        queue->front = queue->rear = new_node;
        return;
    }

    queue->rear->next = new_node;
    new_node->prev = queue->rear;
    queue->rear = new_node;
    return;
}

int isEmpty(Queue* queue){
    return (queue->front == NULL);
}

void dequeue(Queue* queue){
    
    Node* tmp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL){
        queue->rear = NULL;
    }
    printf("Downloading file: %s...\n", tmp->file);
    free(tmp);
    return;
}

void deleteNode(Queue* queue, const char* file){
    Node* traverse = queue->front;
 
    if (strcmp(traverse->file, file) == 0) {
        dequeue(queue);
        return;
    }
    
    while (traverse != NULL){
        if (strcmp(traverse->file, file) == 0){
            break;
        }
        traverse = traverse->next;
    }
    if (traverse == NULL){
        printf("File not found...\n");
        return;
    }
    
    traverse->prev->next = traverse->next;
    if (queue->rear == traverse){
        queue->rear = traverse->prev;
    }
    else{
        traverse->next->prev = traverse->prev;
    }
    printf("Sucess to delete file \"%s\" from the download list\n", traverse->file);
    free(traverse);
    return;
} 

void viewQueue(Queue* queue){
    Node* traverse = queue->front;
    int num = 1;
    while (traverse != NULL){
        printf("%02d. %s\n", num, traverse->file);
        num++;
        traverse = traverse->next;
    }
    return;
}

void clearQueue(Queue* queue){
    if (queue->front == NULL){
        return;
    }
    Node* traverse = queue->front;
    while (traverse != NULL){
        Node *tmp = traverse;
        traverse = traverse->next;
        free(tmp);
    }
    queue->front = queue->rear = NULL;
}

int getMenu(){
    printf("1. Queue file\n");
    printf("2. Download file\n");
    printf("3. Remove file\n");
    printf("4. View download list\n");
    printf("5. Exit\n");
    int menu;
    do{
        printf("Please choose: ");
        scanf("%d", &menu); getchar();
    }while (menu < 1 || menu > 5);
    return menu;
}

int main(void){
    Queue* queue = createQueue();
    int menu;
    do{
        menu = getMenu();
        if (menu == 1){
            char str[101];
            do{     
                printf("Input file name [1..100]: ");
                scanf("%[^\n]", str); getchar();
            }while (strlen(str) < 1 || strlen(str) > 100);
            enqueue(queue, str);
        }
        else if (menu == 2){
            if (isEmpty(queue)){
                printf("Download list is empty...\n");
            }
            else
                dequeue(queue);
        }
        else if (menu == 3){
            if (isEmpty(queue)){
                printf("File not found...\n");
            }
            else{
                char str[101] = "";
                do{     
                    printf("Input file name [2..100]: ");
                    scanf("%[^\n]", str); getchar();
                }while (strlen(str) < 2 || strlen(str) > 100);
                deleteNode(queue, str);
            }
            
        }
        else if (menu == 4){
            viewQueue(queue);
        }
    }while (menu != 5);
    clearQueue(queue);
}