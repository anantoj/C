#include <stdio.h>
#include <stdlib.h>

typedef struct Tnode{
    char c;
    struct Tnode* left;
    struct Tnode* right;
}Tnode;

int idx = 0;

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

void traversal(Tnode* tnode){
    if (tnode != NULL){
        traversal(tnode->left);
        traversal(tnode->right);
        printf("%c ", tnode->c); // processing 
    }
    return;
}

int main(void){
    char prefix[101];
    printf("Input Prefix String: ");
    scanf("%s", prefix);

    Tnode* root = createNode(prefix);

    expTree(root, prefix);
    traversal(root);
    printf("\n");
}