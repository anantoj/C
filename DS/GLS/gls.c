#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32 // for windows
#include <conio.h>
#define cls() system("cls");
#else // for macOS
#define cls() system("clear");
#endif

typedef struct Node{
    char* menu;
    int isCoffee;
    int quantity;
    int price;
    struct Node* next;
}Node;

Node* head = NULL;

int MENU_SIZE = 0;

void insert(char* menu, int isCoffee, int quantity, int price){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->menu = (char*)malloc(sizeof(char) * 21);
    new_node->next = NULL;
    strcpy(new_node->menu, menu);
    new_node->isCoffee = isCoffee;
    new_node->quantity = quantity;
    new_node->price = price;
    
    if (head == NULL){
        head = new_node;
        MENU_SIZE = MENU_SIZE + 1;
        return;
    }
    Node* traverse = head;
    while (traverse->next != NULL){
        if (strcmp(traverse->menu, menu) == 0 && traverse->isCoffee == isCoffee && traverse->price == price){
            break;
        }
        traverse = traverse->next;
    }
    if (strcmp(traverse->menu, menu) == 0 && traverse->isCoffee == isCoffee && traverse->price == price){
        traverse->quantity += quantity;
        return;
    }
    traverse->next = new_node;
    MENU_SIZE = MENU_SIZE + 1;
    return;
}

void deleteNode(int index){
    MENU_SIZE = MENU_SIZE - 1;
    if (index == 1){
        Node* tmp = head;
        head = head->next;
        free(tmp);
        return;
    }
    int count = 1;
    Node* traverse = head;
    Node* prev = NULL;
    while (count != index){
        prev = traverse;
        traverse = traverse->next;
        count++;
    }
    prev->next = traverse->next;
    free(traverse);
    return;
} 

void clearList(Node** head_ref){
    Node* traverse = *head_ref;
    while (traverse != NULL){
        insert(traverse->menu, traverse->isCoffee, traverse->quantity, traverse->price);
        Node* tmp = traverse;
        traverse = traverse->next;
        free(tmp);
    }
    *head_ref = NULL;
    return;
}

void printTable(const char* username){
    cls();
    printf("=================================================================\n");
    printf("\t\t+++++ Brew Coffee Shop +++++\n\n");
    printf("Welcome, Mr./Mrs. %s\n\n", username);
    if (head == NULL){
        printf("There are currently no items..\n\n");
    }
    else{
        printf("=================================================================\n");
        printf("%-3s | %-20s | %-10s | %-8s | %-10s |\n", "No.", "Menu", "Type", "Quantity", "Price");
        printf("-----------------------------------------------------------------\n");
        Node* traverse = head;
        int num = 1;
        while (traverse != NULL){
            char type[101];
            if (traverse->isCoffee){
                strcpy(type, "Coffee");
            }
            else{
                strcpy(type, "Non-coffee");
            }
            printf("%-3d | %-20s | %-10s | %-8d | %-10d |\n", num, traverse->menu, type, traverse->quantity, traverse->price);
            num++;
            traverse = traverse->next;
        }
        printf("-----------------------------------------------------------------\n");
    }
    return;
}

int getMenu(){
    cls();
    printf("1. Enter program\n");
    printf("2. Exit program\n");
    int menu = 0;
    do{
        printf(">> ");
        scanf("%d", &menu);getchar();
    } while (menu < 1 || menu > 2);
    return menu;
}

char* getUserName(){
    printf("Enter username (type \"Admin\" to enter as Administrator): ");
    char* username;
    username = (char*)malloc(sizeof(char) * 101);
    scanf("%[^\n]", username); getchar();
    return username;
}

int checkAdmin(const char* username){
    return strcmp(username, "Admin") == 0;
}

int getAdminMenu(){
    printf("1. Add item\n");
    printf("2. Remove item\n");
    printf("3. Exit\n");
    int menu = 0;
    do{
        printf("Enter your action: ");
        scanf("%d", &menu); getchar();
    } while(menu < 1 || menu > 3);
    return menu;
}

int getQuantity(int max){
    int quantity = 0;
    do{
        printf("enter the quantity [1 - %d]: ", max);
        scanf("%d", &quantity); getchar();
    }while (quantity < 1 || quantity > max);
    return quantity;
}

void printOrder(Node* head){
    if (head == NULL){
        return;
    }
    printf("your orders:\n");
    printf("==================================================================\n");
    printf("%-3s | %-20s | %-10s | %-8s | %-s |\n", "No.", "Menu", "Type", "Quantity", "Total Price");
    printf("------------------------------------------------------------------\n");
    Node* traverse = head;
    int num = 1;
    while (traverse != NULL){
        char type[101];
        if (traverse->isCoffee){
            strcpy(type, "Coffee");
        }
        else{
            strcpy(type, "Non-coffee");
        }
        printf("%-3d | %-20s | %-10s | %-8d | %-11d |\n", num, traverse->menu, type, traverse->quantity, traverse->price *traverse->quantity);
        num++;
        traverse = traverse->next;
        
    }
    printf("------------------------------------------------------------------\n");
    return;
}

int getUserMenu(){
    printf("1. Buy item\n");
    printf("2. Cancel item\n");
    printf("3. Exit\n");
    int menu = 0;
    do{
        printf("Enter your action: ");
        scanf("%d", &menu); getchar();
    } while(menu < 1 || menu > 3);
    return menu;
}

void buy(Node** head_ref, int index){
    int count = 1;
    Node* traverse = head;
    Node* prev = NULL;
    while (count != index){
        prev = traverse;
        traverse = traverse->next;
        count++;
    }
    int quantity = getQuantity(traverse->quantity);
    
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->menu = (char*)malloc(sizeof(char) * 21);
    new_node->next = NULL;
    strcpy(new_node->menu, traverse->menu);
    new_node->isCoffee = traverse->isCoffee;
    new_node->quantity = quantity;
    new_node->price = traverse->price;

    if (*head_ref == NULL){
        *head_ref = new_node;
    }
    else{
        Node* curr = *head_ref;
        while (curr->next != NULL){
            if (strcmp(curr->menu, new_node->menu) == 0 && curr->isCoffee == new_node->isCoffee && curr->price == new_node->price){
                break;
            }
            curr = curr->next;
        }
        if (strcmp(curr->menu, new_node->menu) == 0 && curr->isCoffee == new_node->isCoffee && curr->price == new_node->price){
            curr->quantity += quantity;
        }
        else{
            curr->next = new_node;
        }
        
    }
    if (quantity == traverse->quantity){
        deleteNode(index);
    }
    else{
        traverse->quantity -= quantity;
    }
    return;
}

void adminMenu(const char* username){
    int menu = 0;
    do{
        printTable(username);
        menu = getAdminMenu();
        if (menu == 1){
            char menu[101] = "";
            do{
                printf("Insert item name: ");
                scanf("%[^\n]", menu); getchar();
            }while (strlen(menu) < 5 || strlen(menu) > 20);
            char type[101] = "";
            do{
                printf("Type of Coffee[yes/no]: ");
                scanf("%s", type); getchar();
            }while (strcmp(type, "yes") != 0 && strcmp(type, "no") != 0);
            int isCoffee;
            if (strcmp(type, "yes") == 0){
                isCoffee = 1;
            }
            else{
                isCoffee = 0;
            }
            int quantity = 0;
            do{
                printf("Insert the quantity of the item: ");
                scanf("%d" ,&quantity); getchar();
            }while (quantity < 1 || quantity > 100);
            int price = 0;
            do{
                printf("Insert the price of the item: ");
                scanf("%d", &price); getchar();
            }while (price < 10000 || price > 200000);
            insert(menu, isCoffee, quantity, price);
        }
        else if (menu == 2){
            if (head == NULL){
                printf("There are no items to be removed!\n");
                printf("Press enter to continue..");
                getchar();
            }
            else{
                int index = 0;
                do{
                    printf("Choose the number of the item to be removed[1 - %d]: ", MENU_SIZE);
                    scanf("%d", &index); getchar();
                }while (index < 1 || index > MENU_SIZE);
                deleteNode(index);
            }
        }
    }while (menu != 3);
    return;
}

void customerMenu(const char* username){
    printf("\n");
    Node* headOrder = NULL;
    int menu = 0;
    if (head == NULL){
        printf("There are no menus yet, press Enter to return to main menu..");
        getchar();
        return;
    }
    do{
        printTable(username);
        printOrder(headOrder);
        menu = getUserMenu();
        if (menu == 1 && head != NULL){
            int index = 0;
            do{
                printf("Choose your menu [1 - %d]: ", MENU_SIZE);
                scanf("%d", &index);
            }while (index < 1 || index > MENU_SIZE);
            buy(&headOrder, index);
        }
        else if (menu == 2){
            clearList(&headOrder);
            printf("\nAll of your orders has been cleared! Items have been put back to the menu!\n");
            printf("Press Enter to continue..");
            getchar();
        }
    }while (menu != 3);
    if (headOrder != NULL){
        printf("\nThank you for shopping in Brew Coffee Shop!!\n");
        printf("Press Enter to back to main menu..");
        getchar();
    }
    return;
}

int main(void){
    int menu1 = 0;
    do{
        menu1 = getMenu();
        if (menu1 == 1){
            char* username = getUserName();
            int isAdmin = checkAdmin(username);
            if (isAdmin){
                adminMenu(username);
            }
            else{
                customerMenu(username);
            }
        }
    }while (menu1 != 2);
}
