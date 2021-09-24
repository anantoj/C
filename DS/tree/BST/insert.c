#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int new_data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

Node* insert(Node* node, int data){
    if (node == NULL) 
        return createNode(data);

    if (data < node->data){
        node->left = insert(node->left, data);
    }
    else if (data > node->data){
        node->right = insert(node->right, data);
    }
    return node;
}

void inorder(Node* node){
    if (node != NULL){
        inorder(node->left);
        printf("%d\n", node->data);
        inorder(node->right);
    }
    return;
}

int main(void){
    Node* root = NULL;
    root = insert(root, 1);
    insert(root, 7);
    insert(root, 6);
    insert(root, 5);
    insert(root, 4);
    insert(root, 3);
    insert(root, 2);

    inorder(root);
}