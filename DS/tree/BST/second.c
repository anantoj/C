#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

Node* insert(Node* node, int data){
    if (node == NULL){
        return createNode(data);
    }

    if (data < node->data){
        node->left = insert(node->left, data);
    }
    else if (data > node->data){
        node->right = insert(node->right, data);
    }
    return node;
}

Node* secondRec(Node* node){
    if (node->right->right == NULL){
        return node;
    }

    return secondRec(node->right);
}

Node* secondNonRec(Node* node){
    Node* traverse = node;
    if (traverse->right == NULL){
        return node;
    }
    
    while (traverse->right->right != NULL){
        traverse = traverse->right;
    }
    return traverse;
}

int main(void){
    Node* root = NULL;
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 

    printf("Recursive: %d\n", (secondRec(root))->data);
    printf("Non-Recursive: %d\n", (secondNonRec(root))->data);
}