#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

int nthFromLast(node* head, int pos){
    node* tmp1 = head;
    node* tmp2 = head;

    int count = 0;
    while (count < pos){
        if (tmp2 == NULL){
            // we do not need to use to condition if(count != pos)
            // because if pos is not out of bounds, the while loop will break just when tmp2 reaches null
            // and this condition will not be checked
            printf("Greater than size of linked list\n");
            assert(0);
            break;
        }
        count++;
        tmp2 = tmp2->next;
    }

    while (tmp2 != NULL){
        tmp2 = tmp2->next;
        tmp1 = tmp1->next;
    }

    return tmp1->data;
}

void append(node** head_ref,int new_data){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL){
        *head_ref = new_node;
        return;
    }  

    node* traverse = *head_ref;
    while(traverse->next != NULL){
        traverse = traverse->next;
    }

    traverse->next = new_node;
}

void push(node** head_ref, int new_data){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

int main(void){
    node* head = NULL;

    append(&head,2);
    append(&head,4);
    // append(&head,6);
    // append(&head,8);
    // append(&head,10);
    
    // nth from last is zero-indexed
    int ans = nthFromLast(head, 2);

    printf("%d\n", ans);

}