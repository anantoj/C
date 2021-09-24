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
    newQueue->rear = 0; // rear starts at -1 because array insertion and tracking
    newQueue->front = 0; // front starts at 0 because the front index needs to be immediately 0 when the queue is created
    // newQueue->size = 0; we do not need this variable
    newQueue->array = (int*)malloc(capacity * sizeof(int));

    return newQueue;
}

void enqueue(Queue* queue, int data){
    if (queue->rear == queue->capacity){
        printf("Overflow\n");
        return;
    }
    
    queue->array[queue->rear] = data;
    queue->rear++; // queue rear needs to point to the next array instead of the current array

    return;
}


void dequeue(Queue* queue){
    if (queue->front == queue->rear || queue->front == queue->capacity){
        // if front and rear is equal, then both are pointing at an empty array which cannot be dequeued
        printf("Underflow\n");
        return;
    }
    queue->front++;
}



int main(void){
    Queue* queue = createQueue(5);

    enqueue(queue, 10);
    enqueue(queue, 10);
    enqueue(queue, 10);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue); // array is empty
    enqueue(queue, 40);
    enqueue(queue, 50);
    // array is already full
    enqueue(queue, 60);
    dequeue(queue);
    enqueue(queue, 60);
    dequeue(queue);
    dequeue(queue); // array is empty


}