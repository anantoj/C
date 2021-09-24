/*
Implementation of Queues using Arrays
    [][][][][][][]
Front             Rear      (index)
Data is enqueued through rear, and so rear_index increases
Data is dequeued throught rear, and front_index will increase
rear_index and front_index both starts at 0
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    int front, rear, size;
    unsigned capacity;
    int *array;
}Queue;

Queue* createQueue(unsigned capacity){
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));

    newQueue->capacity = capacity;
    newQueue->rear = capacity-1;
    newQueue->front = 0;
    newQueue->size = 0;
    newQueue->array = (int*)malloc(capacity * sizeof(int));

    return newQueue;
}

int isFull(Queue* queue){
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue){
    return (queue->size == 0);
}

void enqueue(Queue* queue, int data){
    if (isFull(queue)){
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity; 

    queue->array[queue->rear] = data;
    queue->size += 1;

    return;
}

void dequeue(Queue* queue){
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return;
}

int front(Queue* queue){
    return queue->array[queue->front];
}

int rear(Queue* queue){
    return queue->array[queue->rear];
}

int main(void){
    Queue* queue = createQueue(8);

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
    printf("Front Item: %d\n", front(queue));
    printf("Rear Item: %d\n", rear(queue));
    enqueue(queue, 3);
    printf("Front Item: %d\n", front(queue));
    printf("Rear Item: %d\n", rear(queue));
    dequeue(queue);
    printf("Front Item: %d\n", front(queue));
    printf("Rear Item: %d\n", rear(queue));
    dequeue(queue);
    printf("Front Item: %d\n", front(queue));
    printf("Rear Item: %d\n", rear(queue));
    dequeue(queue);
    printf("Front Item: %d\n", front(queue));
    printf("Rear Item: %d\n", rear(queue));
    dequeue(queue);
    printf("Front Item: %d\n", front(queue));
    printf("Rear Item: %d\n", rear(queue));
    enqueue(queue, 9);
    printf("Front Item: %d\n", front(queue));
    printf("Rear Item: %d\n", rear(queue));
}