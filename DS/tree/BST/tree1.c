#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char* name;
    char* type;
    int level;
    int id;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(char* name, char* type, int level, int id){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->name = (char*)malloc(sizeof(name));
    new_node->type = (char*)malloc(sizeof(type));
    strcpy(new_node->name, name);
    strcpy(new_node->type, type);
    new_node->level = level;
    new_node->id = id;
    new_node->left = new_node->right = NULL;
    return new_node;
}

Node* insert(Node* node, char* name, char* type, int level, int id){
    if (node == NULL){
        return createNode(name, type, level, id);
    }

    if (strcmp(name, node->name) < 0){
        node->left = insert(node->left, name, type, level, id);
    }
    else if (strcmp(name, node->name) > 0){
        node->right = insert(node->right, name, type, level, id);
    }

    return node;
}

Node* search(Node* node, char* name){
    if (node == NULL || strcmp(name, node->name) == 0){
        return node;
    }

    if (strcmp(name, node->name) < 0){
        return search(node->left, name);
    }
    return search(node->right, name);
}

int getMenu(){
    printf("Digimon Online\n");
    printf("==============\n");
    printf("1. Add Digimon\n");
    printf("2. View Digimon\n");
    printf("3. Search Digimon\n");
    printf("4. Exit\n");
    int menu;
    do{
        printf(">> ");
        scanf("%d", &menu); getchar();
    }while (menu < 1 || menu > 4);
    return menu;
}

int getView(){
    printf("View\n");
    printf("====\n");
    printf("1. Preorder\n");
    printf("2. Inorder\n");
    printf("4. Cancel\n");
    int view;
    do{
        printf(">> ");
        scanf("%d", &view); getchar(); 
    }while (view < 1 || view > 4);
    return view;
}

void preorder(Node* node){
    if (node != NULL){
        printf("| %-5d | %-30s | %-10s | %-3d |\n", node->level, node->name, node->type, node->id);
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(Node* node){
    if (node != NULL){
        inorder(node->left);
        printf("| %-5d | %-30s | %-10s | %-3d |\n", node->level, node->name, node->type, node->id);
        inorder(node->right);
    }
}

void postorder(Node* node){
    if (node != NULL){
        postorder(node->left);
        postorder(node->right);
        printf("| %-5d | %-30s | %-10s | %-3d |\n", node->level, node->name, node->type, node->id);
    }
}

int main(void){
    Node* tree = NULL;
    int menu;
    do{
        menu = getMenu();
        if (menu == 1){
            char name[30] = "";
            do{
                printf("Input Digimon's Name [5 - 30 characters] : ");
                scanf("%s", name); getchar();
            }while (strlen(name) < 5 || strlen(name) > 30);
            char type[10];
            do{
                printf("Input Digimon's Type [Champion|Ultimate|Mega] : ");
                scanf("%s", type); getchar();
            }while(strcmp(type, "Champion") != 0 && strcmp(type, "Ultimate") != 0 && strcmp(type, "Mega") != 0);
            int level;
            do{
                printf("Input Digimon's level [1-100] : ");
                scanf("%d", &level); getchar();
            }while (level < 1 || level > 100);
            int id = rand() % 99 + 1;
            tree = insert(tree, name, type, level, id);
        }
        else if (menu == 2){
            if (tree == NULL){
                printf("-- There is No Digimon in The Tree --\n");
            }
            else{
                int view = getView();
                if (view == 1){
                    printf("Digimon LIST Preorder\n");
                    printf("=====================\n\n");
                    printf("=============================================================\n");
                    printf("| %s | %-30s | %-10s | %-3s |\n", "Level", "Name", "Type", "ID");
                    printf("=============================================================\n");
                    preorder(tree);
                    printf("=============================================================\n");
                }
                else if (view == 2){
                    printf("Digimon LIST InOrder\n");
                    printf("====================\n\n");
                    printf("=============================================================\n");
                    printf("| %s | %-30s | %-10s | %-3s |\n", "Level", "Name", "Type", "ID");
                    printf("=============================================================\n");
                    inorder(tree);
                    printf("=============================================================\n");
                }
                else if (view == 3){
                    printf("Digimon LIST PostOrder\n");
                    printf("======================\n\n");
                    printf("=============================================================\n");
                    printf("| %s | %-30s | %-10s | %-3s |\n", "Level", "Name", "Type", "ID");
                    printf("=============================================================\n");
                    postorder(tree);
                    printf("=============================================================\n");
                }
            }
            
        }
        else if (menu == 3){
            char name[30];
            printf("Input Digimon's Name : ");
            scanf("%[^\n]", name);
            Node* find = search(tree, name);
            if (find == NULL){
                printf("Digimon is not Available!!\n");
            }
            else{
                printf("Search Result\n");
                printf("=============\n");
                printf("%-30s : %d\n", "Pokemon's ID", find->id);
                printf("%-30s : %s\n", "Pokemon's Name", find->name);
                printf("%-30s : %s\n", "Pokemon's Type", find->type);
                printf("%-30s : %d\n", "Pokemon's Level", find->level);
            }
        }
    }while (menu != 4);
}