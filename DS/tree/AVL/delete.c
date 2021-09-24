#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    int height;
    struct Node* left;
    struct Node* right;
}Node;

int height(Node* node){
    if (node == NULL){
        return 0;
    }
    return node->height;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

Node* rightRotate(Node* pivot){
    Node* x = pivot->left;
    Node* T2 = x->right;

    x->right = pivot;
    pivot->left = T2;

    pivot->height = max(height(pivot->left), height(pivot->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* pivot){
    Node* y = pivot->right;
    Node* T2 = y->left;

    y->left = pivot;
    pivot->right = T2;
    
    pivot->height = max(height(pivot->left), height(pivot->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* createNode(int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->height = 1;
    new_node->left = new_node->right = NULL;
    return new_node;
}

int getBalance(Node* node){
    if (node == NULL){
        return 0;
    }
    return height(node->left) - height(node->right);
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
    
    node->height = max(height(node->left), height(node->right)) + 1;
    
    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data){
        return rightRotate(node);
    }
    if (balance < -1 && data > node->right->data){
        return leftRotate(node);
    }
    if (balance > 1 && data > node->left->data){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && data < node->right->data){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

Node* minValueNode(Node* node){
    Node* traverse = node;

    while (traverse->left != NULL){
        traverse = traverse->left;
    }

    return traverse;
}

Node* deleteNode(Node* node, int data){
    if (node == NULL){
        return node;
    }
    if (data < node->data){
        node->left = deleteNode(node->left, data);
    }
    else if (data > node->data){
        node->right = deleteNode(node->right, data);
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
        node->right = deleteNode(node->right, minNode->data);
    }
    
    node->height = max(height(node->left), height(node->right)) + 1;

    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0){
        return rightRotate(node);
    }
    if (balance < -1 && getBalance(node->right) <= 0){
        return leftRotate(node);
    }
    if (balance > 1 && getBalance(node->left) < 0){
        node->left = leftRotate(node);
        return rightRotate(node);
    }
    if (balance < -1 && getBalance(node->right) > 0){
        node->right = rightRotate(node);
        return leftRotate(node);
    }
    return node;
}

void preorder(struct Node *root) 
{ 
    if(root != NULL) 
    { 
        printf("%d ", root->data); 
        preorder(root->left); 
        preorder(root->right); 
    } 
} 

int main(void){
    Node* root = NULL;
    root = insert(root, 9); 
    root = insert(root, 5); 
    root = insert(root, 10); 
    root = insert(root, 0); 
    root = insert(root, 6); 
    root = insert(root, 11); 
    root = insert(root, -1); 
    root = insert(root, 1); 
    root = insert(root, 2); 
    root = insert(root, 11);
    root = insert(root, 10);
    root = insert(root, 69);
    preorder(root); 
    printf("\n");
    root = deleteNode(root, 10); 
    root = deleteNode(root, 3);
    root = deleteNode(root, 2);
    preorder(root); 
    printf("\n");
}
