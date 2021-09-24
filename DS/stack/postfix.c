#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackNode{
    int data;
    struct StackNode* next;
}StackNode;

void push(StackNode** root, int new_data){
    StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));

    new_node->data = new_data;
    new_node->next = *root;
    *root = new_node;

    return;
}

void pop(StackNode** root){
    if (*root == NULL) return;

    StackNode* tmp = *root;
    (*root) = (*root)->next;
    
    free(tmp);
}

int peek(StackNode* stack){
    int num = stack->data;
    return num;
}

int main(void){
    StackNode* stack =  NULL;

    char str[101];

    scanf("%[^\n]", str);

    for (int i = 0; i < strlen(str); i+=2){
        if (str[i] == '-'){
            int num = peek(stack);
            pop(&stack);
            num = peek(stack) - num;
            pop(&stack);
            push(&stack, num);
        }
        else if (str[i] == '*'){
            int num = peek(stack);
            pop(&stack);
            num *= peek(stack);
            pop(&stack);
            push(&stack, num);
        }
        else if (str[i] == '+'){
            int num = peek(stack);
            pop(&stack);
            num += peek(stack);
            pop(&stack);
            push(&stack, num);
            
        }
        else if (str[i] == '/'){
            int num = peek(stack);
            pop(&stack);
            num = peek(stack) / num;
            pop(&stack);
            push(&stack, num);
        }
        else{
            int digit = 1;
            int num = 0;
            while (str[i]!= ' '){
                if (digit != 1) num = num * 10;
                num += str[i] - 48;
                digit++;
                i++;
            }
            i--;
            // int num = str[i] - 48;
            push(&stack, num);
        }
    }
    
    printf("Result = %d\n", peek(stack));
}