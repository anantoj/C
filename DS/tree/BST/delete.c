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

// function to find minimum to find node with minimum data
Node* minValueNode(Node* node){
    Node* traverse = node;

    while (traverse != NULL && traverse->left != NULL){
        printf("%d ",traverse->data);
        traverse = traverse->left; // we search left because we are finding for the smallest data
    }
    printf("%d ",traverse->data);
    return traverse;
}

Node* deleteNode(Node* node, int data){
    // base case
    if (node == NULL) return node;

    // if data is smaller, it lies in the LEFT subtree
    if (data < node->data){
        node->left = deleteNode(node->left, data); // this is done to connect to nodes in case of deletion
    }
    // lies on the right subtree
    else if (data > node->data){
        node->right = deleteNode(node->right, data);
    }
    // data is found
    else{
        // CASE: node to be deleted has ONE child or NO child
        if (node->left == NULL){
            Node* tmp = node->right;
            free(node);
            return tmp;
            // NOTE that this will directly connect the right node because we return the right node
        }
        else if (node->right == NULL){
            Node* tmp = node->left;
            free(node);
            return tmp;
        }
        // we need to find the minimum value node on the right subtree to replace with the deleted node
        printf("\nminValueNode function traversal: ");
        Node* tmp = minValueNode(node->right);
        printf("\n\n");
        
        node->data = tmp->data;
        node->right = deleteNode(node->right, tmp->data);
    }
    return node;
}

void inorder(Node* node){
    if (node != NULL){
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

int main(void){
    Node* root = NULL;
    root = insert(root, 50); 
   
  
    printf("Inorder traversal of the given tree \n"); 
    inorder(root); 
    
    printf("\nDelete 20\n"); 
    root = deleteNode(root, 20); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
  
    printf("\nDelete 30\n"); 
    root = deleteNode(root, 30); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
  
    printf("\nDelete 50\n"); 
    root = deleteNode(root, 50); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root);
    printf("\n");
}