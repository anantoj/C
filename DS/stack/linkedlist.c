#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode{
    int data;
    struct StackNode* next;
}StackNode;

void push(StackNode** top, int data){
    StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));
    new_node->data = data;
    new_node->next = *top;
    *top = new_node;
    return;
}

void pop(StackNode** top){
    StackNode* tmp = *top;

    *top = (*top)->next;
    
    free(tmp);
}

int peek(StackNode* stack){
    return stack->data;
}

int isEmpty(StackNode** top){
    if (*top == NULL) return 1;
    return 0; 
}

int main(void){
    StackNode* top = NULL;

    push(&top, 10);
    push(&top, 20);
    push(&top, 30);

    pop(&top);
    
    printf("%d\n", peek(top));

}