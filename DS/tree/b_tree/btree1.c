#include <stdio.h>
#include <stdlib.h>

#define M 3

typedef struct Node{
    int n; // number of keys
    int keys[M-1];
    struct Node* ptr[M];
}Node;

Node* root = NULL;

int searchPos(int key, int *key_arr, int n) {
        int pos = 0;
        while (pos < n && key > key_arr[pos])
                pos++;
        return pos;
}

void insert(int key){
    Node* new_node;
    int upKey;
    Node* newPtr;
    Node* lastPtr;
    int pos, i ,n, splitPos;
    int newKey, lastKey;
    if (root == NULL){
        new_node = NULL;
        upKey = key;
        Node* uproot = root;
        root = (Node*)malloc(sizeof(Node));
        root->n = 1;
        root->keys[0] = upKey;
        root->ptr[1] = new_node;
        return;
    }
    n = root->n;
    pos = searchPos(key, root->ptr)
}

int main(void){

}