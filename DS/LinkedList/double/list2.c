/*
Ananto Joyoadikusumo
2301914434
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char name[101];
    int quantity;
    int price;
    struct Node* next;
    struct Node* prev;
}Node;

// sorted insert function
void insert(Node** head_ref, char* name, int quantity){
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->quantity = quantity;
    new_node->price = (rand() % (100000 - 1000 + 1) + 1000); // random price from 1000 - 100000

    // case: list is empty
    if (*head_ref == NULL){
        new_node->next = new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    
    Node* traverse = *head_ref;

    // case: insert at the beginning
    if (strcmp(new_node->name, traverse->name) < 0){
        new_node->next = traverse;
        new_node->prev = NULL;
        traverse->prev = new_node;
        *head_ref = new_node;
        return;
    }

    while (traverse->next != NULL){
        if (strcmp(new_node->name, traverse->name) > 0)
            break;
        
        traverse = traverse->next;
    }
    
    // case: insert after the traversing node
    if (strcmp(new_node->name, traverse->name) > 0){
        new_node->next = traverse->next;
        if (traverse->next != NULL){
            traverse->next->prev = new_node;
        }
        new_node->prev = traverse;
        traverse->next = new_node;
    }
    // case: insert before the traversing node
    else{
        new_node->next = traverse;
        new_node->prev = traverse->prev;
        if (traverse->prev != NULL){
            traverse->prev->next = new_node;
        }
        traverse->prev = new_node;
    }
    return;
}

void update(Node* node, char* name, int quantity){
    while (node != NULL){
        if (strcmp(node->name, name) == 0){
            break;
        }
        node = node->next;
    }
    if (node == NULL){
        printf("Product Not Found..\n");
        return;
    }

    node->quantity = quantity;
    printf("Product quantity has been updated..");
    return;
}

void deleteNode(Node** head_ref, char* name){
    Node* traverse = *head_ref;

    while (traverse != NULL){
        if (strcmp(traverse->name, name) == 0){
            // case: if head is to be deleted
            if (*head_ref == traverse){
                *head_ref = traverse->next;
            }

            // case: if tail is not to be deleted
            if (traverse->next != NULL){
                traverse->next->prev = traverse->prev;
            }
            // case: if head is not to be deleted
            if (traverse->prev != NULL){
                traverse->prev->next = traverse->next;
            }
            
            free(traverse);
            break;
        }
        traverse = traverse->next;
    }

    if (traverse == NULL){
        printf("Product Not Found..\n");
    }
    return;
}

int getMenu(){
    printf("\nMinimarket Product Note Program\n");
    printf("===============================\n");
    printf("1. Add product\n");
    printf("2. Update Product\n");
    printf("3. Delete Product\n");
    printf("4. Checkout\n");  
    printf(">> ");
    int menu;
    scanf("%d", &menu); getchar();
    return menu;
}

void printProduct(Node* node){
    printf("\n\n");
    if (node != NULL)
        printf("List of Products:\n");
    
    while (node != NULL){
        printf("%s\n", node->name);
        node = node->next;
    }
    return;
}

void printList(Node* node){
    printf("%-20s %-10s %-10s\n", "Product Name", "Quantity", "Price(Rp.)");
    int total = 0;
    while (node != NULL){
        printf("%-20s %-10d %-10d\n", node->name, node->quantity, (node->quantity)* (node->price));
        total += (node->quantity)* (node->price);
        node = node->next;
    }
    printf("Total = Rp. %d\n", total);
}

int main(void){
    Node* head = NULL;

    int menu = 0;
    do{
        printProduct(head);
        menu = getMenu();
        if (menu == 1){
            printf("Product Name: ");
            char name[101];
            scanf("%s", name); getchar();
            printf("Product Quantity: ");
            int quantity;
            scanf("%d", &quantity); getchar();
            insert(&head, name, quantity);
        }
        else if(menu == 2){
            printf("Product Name: ");
            char name[101];
            scanf("%s", name); getchar();
            printf("New Quantity: ");
            int quantity;
            scanf("%d", &quantity); getchar();
            update(head, name, quantity);
        }
        else if (menu == 3){
            printf("Product Name: ");
            char name[101];
            scanf("%s", name); getchar();
            deleteNode(&head, name);
        }
    }while(menu != 4);

    printList(head);
    printf("\"Kindness is free\"\n");

    return 0;
}