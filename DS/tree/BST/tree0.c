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
    new_node->left = new_node->right  = NULL;
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

Node* search(Node* node, int data){
    if (node == NULL || node->data == data){
        return node;
    }

    if (data < node->data){
        return search(node->left, data);
    }
    return search(node->right, data);
}

Node* delete(Node* node, int data){
    if (node == NULL){
        return node;
    }

    if (data < node->data){
        node->left = delete(node->left, data);
    }
    else if (data > node->data){
        node->right = delete(node->right, data);
    }
    else{
        if (node->left == NULL){
            Node* tmp = node->right;
            free(node);
            return tmp;
        }
        else if (node->right == NULL){
            Node* tmp = node->left;
            free(node);
            return tmp;
        }

        Node* minNode = minValueNode(node->right);
        node->data = minNode->data;
        node->right = delete(node->right, minNode->data);
    }

    return node;
}

void inorder(Node* node){
    if (node != NULL){
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
    return;
}

int main(void){

}