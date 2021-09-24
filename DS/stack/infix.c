#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode{
    char c;
    struct StackNode* next;
}StackNode;

void push(StackNode** top, char c){
    StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));
    new_node->c = c;
    new_node->next = *top;
    *top = new_node;
    return;
}

void pop(StackNode** top){
    StackNode* tmp1 = *top;
    (*top) = (*top)->next;
    free(tmp1);
}

char peek(StackNode* stack){
    return stack->c;
}

int main(void){
    StackNode* stack = NULL;

    char str[101];
    scanf("%[^\n]", str);

    char postfix[101];
    int pf_index = 0;

    for (int i = 0; i < strlen(str); i++){
        if (str[i]>= 48 && str[i]<= 57){
            postfix[pf_index] = str[i];
            pf_index++;
            postfix[pf_index] = ' ';
            pf_index++;
        }
        else if(str[i] == '('){
            push(&stack, str[i]);
        }
        else if (str[i] == ')'){
            char check = ' ';
            while (check != '('){
                check = peek(&stack);
                pop(&stack);
                if (check != '('){
                    postfix[pf_index] = check;
                    pf_index++;
                    postfix[pf_index] = ' ';
                    pf_index++;
                }
            }
        }
        else if (str[i] == '+'|| str[i] == '-'){
            char check = peek(stack);
            while (check != '/' && check != '*'){
                pop(&stack);
                postfix[pf_index] = check;
                pf_index++;
                postfix[pf_index] = ' ';
                pf_index++;
                check = peek(stack);
            }
        }
        else if (str[i] == )
    }
}