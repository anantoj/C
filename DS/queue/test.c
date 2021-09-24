#include <stdio.h>
#include <stdlib.h>

typedef struct Qnode{
    int data;
    struct Qnode* next;
}Qnode;

typedef struct Queue{
    Qnode* front;
    Qnode* rear;
}Queue;

Queue* createQueue(){
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

Qnode* newNode(int data){
    Qnode* new_node = (Qnode*)malloc(sizeof(Qnode));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void enqueue(Queue* queue, int data){
    Qnode* new_node = newNode(data);

    if (queue->rear == NULL){
        queue->front = new_node;
        queue->rear = new_node;
        return;
    }

    queue->rear->next = new_node; // previously 
    queue->rear = new_node;
    
}

void dequeue(Queue* queue){
    if (queue->front == NULL){
        return;
    }

    Qnode* tmp = queue->front;
    queue->front = queue->front->next;
    
    if (queue->front == NULL){
        queue->rear = NULL;
    }

    free(tmp);
}

int main(void){

}