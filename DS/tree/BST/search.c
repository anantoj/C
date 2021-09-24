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

Node* search(Node* node, int find){
    if (node == NULL || node->data == find){
        return node;
    }

   
    if (find > node->data){
        return search(node->right, find);
    }

    return search(node->left, find);  
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
    
    if ((search(root, 10)) == NULL){
        printf("Not Found\n");
    }
    else{
        printf("Found\n");
    }
}