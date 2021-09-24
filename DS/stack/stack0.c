#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct StackNode{
    char c;
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
    return stack->data;
}

void pushChar(StackNode** root, char c){
    StackNode*  new_node = (StackNode*)malloc(sizeof(StackNode));
    new_node->c = c;
    new_node->next = *root;
    *root = new_node;

    return;
}

char peekChar(StackNode* stack){
    return stack->c;
}

void displayStack(StackNode* stack){
    while (stack != NULL){
        printf("%d ", stack->data);
        stack = stack->next;
    }
    printf("\n");
    return;
}

int main(void){
    int menu;

    do{
        StackNode* stack = NULL;
        printf("1. Convert from infix to prefix and postfix\n");
        printf("2. Evaluate prefix notation\n");
        printf("3. Evaluate postfix notation\n");
        printf("4. Exit\n");
        printf(">> ");
        scanf("%d", &menu); getchar();

        if (menu == 1){
            printf("1. Infix to Prefix\n");
            printf("2. Infix to Postfix\n");
            printf(">> ");
            int choice;
            scanf("%d", &choice); getchar();

            printf("Input Infix String (put space between each char): ");
            char infix[101];
            scanf("%[^\n]", infix); getchar();

            if (choice == 1){
                char prefix[101];
                int index = 0;
                for (int i = strlen(infix)-1; i >= 0; i--){
                    if (infix[i] >= '0' && infix[i] <= '9'){
                        while (infix[i] != ' ' && i >= 0){
                            prefix[index] = infix[i];
                            index++;
                            i--;
                        }
                        prefix[index] = ' ';
                        index++;
                    }
                    else if (infix[i] == ')'){
                        pushChar(&stack, infix[i]);
                    }
                    else if (infix[i] == '('){
                        char c = 'a';
                        while (c != ')'){
                            c = peekChar(stack);
                            pop(&stack);

                            if (c != ')'){
                                prefix[index] = c;
                                index++;
                                prefix[index] = ' ';
                                index++;
                            }
                        }
                    }
                    else if (infix[i] != ' '){
                        if (infix[i] == '+' || infix[i] == '-'){
                            while (stack != NULL){
                                char check = peekChar(stack);
                                if (check == ')'){
                                    break;
                                }
                                else{
                                    pop(&stack);
                                    prefix[index] = check;
                                    index++;
                                    prefix[index] = ' ';
                                    index++;
                                }
                            }
                            pushChar(&stack, infix[i]);
                        }
                        else if (infix[i] == '*' || infix[i] == '/' || infix[i] == '%'){
                            while (stack != NULL){
                                char check = peekChar(stack);
                                if (check == ')' || check == '+' || check == '-'){
                                    break;
                                }
                                else{
                                    pop(&stack);
                                    prefix[index] = check;
                                    index++;
                                    prefix[index] = ' ';
                                    index++;
                                }
                            }
                            pushChar(&stack, infix[i]);
                        }
                        else if (infix[i] == '^'){
                             while (stack != NULL){
                                char check = peekChar(stack);
                                if (check == ')' || check == '+' || check == '-' || check == '*' || check == '/' || check == '%'){
                                    break;
                                }
                                else{
                                    pop(&stack);
                                    prefix[index] = check;
                                    index++;
                                    prefix[index] = ' ';
                                    index++;
                                }
                            }
                            pushChar(&stack, infix[i]);
                        }
                    } // 1 * ( ( 2 - 3 ) / 4 + 5 ) + ( 6 * 7 - 8 * 9 ) / 10 + 11
                }
                while (stack != NULL){
                    prefix[index] = peekChar(stack);
                    index++;
                    prefix[index] = ' ';
                    index++;
                    pop(&stack);
                }
                printf("Result: ");
                for (int i = index-1; i >=0; i--){
                    printf("%c", prefix[i]);
                }
                printf("\n");
            }
            else if (choice == 2){
                char postfix[101];
                int index = 0;
                for (int i = 0; i < strlen(infix); i++){
                    if (infix[i] >= '0' && infix[i] <= '9'){
                        while (infix[i] != ' ' && infix[i] != '\0'){
                            postfix[index] = infix[i];
                            index++;
                            i++;
                        }
                        postfix[index] = ' ';
                        index++;
                    }
                    else if (infix[i] == '('){
                        pushChar(&stack, infix[i]);
                    }
                    else if (infix[i] == ')'){
                        char c = 'a';
                        while (c != '('){
                            c = peekChar(stack);
                            pop(&stack);

                            if (c != '('){
                                postfix[index] = c;
                                index++;
                                postfix[index] = ' ';
                                index++;
                            }
                        }
                    }
                    else if (infix[i] != ' '){
                        if (infix[i] == '+' || infix[i] == '-'){
                            while (stack != NULL){
                                char check = peekChar(stack);
                                if (check == '('){
                                    break;
                                }
                                else{
                                    pop(&stack);
                                    postfix[index] = check;
                                    index++;
                                    postfix[index] = ' ';
                                    index++;
                                }
                            }
                            pushChar(&stack, infix[i]);
                        }
                        else if (infix[i] == '*' || infix[i] == '/' || infix[i] == '%'){
                            while (stack != NULL){
                                char check = peekChar(stack);
                                if (check == '(' || check == '+' || check == '-'){
                                    break;
                                }
                                else{
                                    pop(&stack);
                                    postfix[index] = check;
                                    index++;
                                    postfix[index] = ' ';
                                    index++;
                                }
                            }
                            pushChar(&stack, infix[i]);
                        }
                        else if (infix[i] == '^'){
                            while (stack != NULL){
                                char check = peekChar(stack);
                                if (check == ')' || check == '+' || check == '-' || check == '*' || check == '/' || check == '%'){
                                    break;
                                }
                                else{
                                    pop(&stack);
                                    postfix[index] = check;
                                    index++;
                                    postfix[index] = ' ';
                                    index++;
                                }
                            }
                            pushChar(&stack, infix[i]);
                        }
                    }
                }
                while (stack != NULL){
                    postfix[index] = peekChar(stack);
                    index++;
                    postfix[index] = ' ';
                    index++;
                    pop(&stack);
                }
                printf("Result: %s\n", postfix);
            }
        }
        else if (menu == 2){
            printf("Input Prefix String (put 1 space between each char): ");
            char str[101];
            scanf("%[^\n]", str);
            for (int i = strlen(str)-1; i >= 0; i-=2){
                if (str[i] == '-'){
                    int num = peek(stack);
                    pop(&stack);
                    num = num - peek(stack);
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
                    num = num / peek(stack);
                    pop(&stack);
                    push(&stack, num);
                }
                else if (str[i] == '%'){
                    int num = peek(stack);
                    pop(&stack);
                    num = num % peek(stack);
                    pop(&stack);
                    push(&stack, num);
                }
                else{
                    int digit = 0;
                    int num = 0;
                    while (str[i] != ' '){
                        num += ((str[i] - 48) * pow(10, digit));
                        digit++;
                        i--;
                    }
                    i++;
                    push(&stack, num); 
                }
                displayStack(stack);
            }
            printf("Result = %d\n", peek(stack));
        }
        else if (menu == 3){
            printf("Input Postfix String (put 1 space between each char): ");
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
                else if (str[i] == '%'){
                    int num = peek(stack);
                    pop(&stack);
                    num = peek(stack) % num;
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
                    push(&stack, num);
                }
                displayStack(stack);
            }
            printf("Result = %d\n", peek(stack));
        }
    }while (menu != 4);
}