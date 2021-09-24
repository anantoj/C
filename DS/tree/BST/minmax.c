#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

// recursive function to find the minimun element in a tree
Node* findMin(Node* node){
    if (node->left == NULL){
        return node;
    }
    
    return findMin(node->left);
}

// non-recursive function to find the maximum element in a given tree
Node* findMax(Node* root){
    Node* traverse = root;
    while (traverse->right != NULL){
        traverse = traverse->right;
    }
    return traverse;
}

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

int main(void){
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 2);
    root = insert(root, 11);

    Node* min = findMin(root);
    Node* max = findMax(root);

    printf("Min Value = %d\n", min->data);
    printf("Max Value = %d\n", max->data);
}