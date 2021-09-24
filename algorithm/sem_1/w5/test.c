#include <stdio.h>

char map[100][100];

void printarray(int x, int y, char map[][100]);

void printarray(int x, int y, char map[][100]){
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            printf("%c", map[i][j]);
        }
    }
}

int main(void){
    int x = 2;
    int y = 2;

    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            scanf("%c", &map[i][j]);
        }
        getchar();
    }

    printarray(x,y, map);


}