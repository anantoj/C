#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    int height;
    struct Node* left;
    struct Node* right;
}Node;

// function to get the height of the tree
int height (Node* node){
    if (node == NULL){
        return 0;
    }
    return node->height;
}

// function to compare 2 integers and return max 
int max(int a, int b){
    return (a > b)? a : b; 
}

// function to create a node
Node* createNode(int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->height = 1;
    new_node->left = new_node->right = NULL;
    return new_node;
}

// right rotate function
Node* rightRotate(Node* pivot){
    Node* leftChild = pivot->left;
    Node* leftRightSubtree = leftChild->right;

    // perform rotartion
    leftChild->right = pivot;
    pivot->left = leftRightSubtree;
    
    // update heights
    pivot->height = max(height(pivot->left), height(pivot->right))+1;
    leftChild->height = max(height(leftChild->left), height(leftChild->right))+1;

    return leftChild;
}

Node* leftRotate(Node* pivot){
    Node* rightChild = pivot->right;
    Node* rightLeftSubtree = rightChild->left;

    // perform rotartion
    rightChild->left = pivot;
    pivot->right = rightLeftSubtree;
    
    // update heights
    pivot->height = max(height(pivot->left), height(pivot->right))+1;
    rightChild->height = max(height(rightChild->left), height(rightChild->right))+1;

    return rightChild;
}

// get the balance factor of a node
int getBalance(Node* node){
    if (node == NULL){
        return 0;
    }
    return height(node->left) - height(node->right);
}

Node* insert(Node* node, int data){
    // normal BST insertion
    if (node == NULL){
        return createNode(data);
    }
    if (data < node->data){
        node->left = insert(node->left, data);
    }
    else if (data > node->data){
        node->right = insert(node->right, data);
    }
    else{
        return node;
    }
    //update height of this ancestor node
    node->height = max(height(node->left), height(node->right)) + 1;
    // get the balance factor of this ancestor node to check if becomes unbalanced
    int balance = getBalance(node);
    // LL
    if (balance > 1 && data < node->left->data){
        return rightRotate(node);
    }
    // RR
    if (balance < -1 && data > node->right->data){
        return leftRotate(node);
    }
    // LR
    if (balance > 1 && data > node->left->data){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // RL
    if (balance < -1 && data < node->right->data){
        node->right= rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preorder(Node *root) 
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
    /* Constructing tree given in the above figure */
    root = insert(root, 10); 
    root = insert(root, 20); 
    root = insert(root, 30); 
    root = insert(root, 40); 
    root = insert(root, 50); 
    root = insert(root, 25); 
    
    /* The constructed AVL Tree would be 
            30 
           /  \ 
         20   40 
        /  \     \ 
       10  25    50 
  */
    
    printf("Preorder traversal of the constructed AVL tree is\n"); 
    preorder(root); 
    printf("\n");
    
}
