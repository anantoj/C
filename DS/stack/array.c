#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int top;
    unsigned capacity;
    int* array;
}Stack;

Stack* createStack(unsigned capacity){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1; // arr needs to start at 0 so, top needs to be -1
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(Stack* stack){
    if (stack->top == stack->capacity -1){
        return 1;
    }
    return 0;
}

int isEmpty(Stack* stack){
    if (stack->top == -1){
        return 1;
    }
    return 0;
}

void push(Stack* stack, int item){
    if (isFull(stack) == 1){
        return;
    }
    stack->top++;
    stack->array[stack->top] = item;
    printf("%d pushed to stack\n", item);
}

void pop(Stack* stack){
    if (isEmpty(stack) == 1){
        return;
    }
    stack->top--;
}

int peek(Stack* stack){
    // asssume not empty
    return stack->array[stack->top];
}

int main(void){
    Stack* stack = createStack(100);    

    push(stack, 10); 
    push(stack, 20); 
    push(stack, 30); 

    pop(stack);
  
    printf("%d\n", peek(stack));
}