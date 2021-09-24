#include <stdio.h>
#include <stdlib.h>

typedef struct Qnode{
    int data;
    struct Qnode next;
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

void enqueue(Queue* queue, int new_data){
    Qnode* new_node = (Qnode*)malloc(sizeof(Qnode));
    new_node->data = new_data;
    new_node->next = NULL;

    if (queue->rear == NULL){
        queue->front = queue->rear = new_node;
        return;
    }

    queue->rear->next = new_node;
    queue->rear = new_node;
    return;
}

void dequeue(Queue* queue, int new_data){
    if (queue->front == NULL) return;
    Qnode* tmp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL){
        queue->rear = NULL;
    }
    free(tmp);
    return;
}

int main(void){
    
}