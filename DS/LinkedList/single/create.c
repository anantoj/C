#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data; // data to be stored
    struct node* next; // pointer address to the next node in the list
}node;

int main(void){
    node * A; // A keeps the address of the head node

    A = NULL; // A has not pointed to the head node, the list is empty

    // creating the head node
    node *tmp = (node*)malloc(sizeof(node)); // create a memory block with the size of a node variable
    /*
        we do not use 
        node* tmp = NULL;
        because we actually want to fill in tmp with data
    */

    tmp->data = 2;
    tmp->next = NULL;

    A = tmp; // a points to the tmp variable, making tmp the head node
}   