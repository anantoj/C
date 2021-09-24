// a program to convert a prefix string to an expression tree

#include <stdio.h>
#include <stdlib.h>

int idx = 0;

typedef struct Tnode{
    char c;
    struct Tnode* left;
    struct Tnode* right;
}Tnode;

Tnode* createNode(char* prefix){
    Tnode* new_node = (Tnode*)malloc(sizeof(Tnode));
    new_node->c = prefix[idx];
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

int isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

// recursive function to create the Expression Tree
void expTree(Tnode* traverse, char* prefix){
    if (isOperator(prefix[idx])){
        idx++;
        traverse->left = createNode(prefix);
        expTree(traverse->left, prefix);
        idx++;
        traverse->right = createNode(prefix);
        expTree(traverse->right, prefix);
    }
    return;
}

int main(void){
    char prefix[101];
    scanf("%s", prefix);
    
    Tnode* root = createNode(prefix);

    expTree(root, prefix);
}