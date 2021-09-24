/*
Implementation of Queues using Linked List 
    NULL <-[]<-[]<-[]<-[]<-[]<-[]
        rear                   front
data is enqueued through rear
data is dequeued through front
*/

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

Qnode* newNode(int data){
    Qnode* new_node = (Qnode*)malloc(sizeof(Qnode));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Queue* createQueue(){
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

void enqueue(Queue* queue, int data){
    Qnode* tmp = newNode(data);

    // if queue is empty, then new node is front and rear both
    if (queue->rear == NULL){
        queue->front = queue->rear = tmp;
        return;
    }

    // Add the new node at the end of queue and chare rear
    queue->rear->next = tmp; // previously pointed to NULL
    queue->rear = tmp;
    return;
}

void dequeue(Queue* queue){
    // if queue is empty return
    if (queue->front == NULL) return;

    // Store previous front and move front one node ahead
    Qnode* tmp = queue->front;
    queue->front = queue->front->next;

    // If front becomes NULL, then change the rear also as NULL
    if (queue->front == NULL){
        queue->rear = NULL;
    }

    free(tmp);
}

int main(void){
    Queue* queue = createQueue();

    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 15);
    enqueue(queue, 23);
    enqueue(queue, 7);
    enqueue(queue, 41);
    enqueue(queue, 12);
    
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    enqueue(queue, 10);
    printf("Front Item: %d\n", queue->front->data);
    printf("Rear Item: %d\n", queue->rear->data);
    enqueue(queue, 3);
    printf("Front Item: %d\n", queue->front->data);
    printf("Rear Item: %d\n", queue->rear->data);
    dequeue(queue);
    printf("Front Item: %d\n", queue->front->data);
    printf("Rear Item: %d\n", queue->rear->data);
    dequeue(queue);
    printf("Front Item: %d\n", queue->front->data);
    printf("Rear Item: %d\n", queue->rear->data);
    dequeue(queue);
    printf("Front Item: %d\n", queue->front->data);
    printf("Rear Item: %d\n", queue->rear->data);
    dequeue(queue);
    printf("Front Item: %d\n", queue->front->data);
    printf("Rear Item: %d\n", queue->rear->data);
    enqueue(queue, 9);
    printf("Front Item: %d\n", queue->front->data);
    printf("Rear Item: %d\n", queue->rear->data);

}