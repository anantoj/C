// Create a program which finds @ in a 2d array input from a file
// and outputs the coordinates of the @ symbol

char map[101][101];

#include <stdio.h>
#include <string.h>

int main(void){
    FILE *fp;

    fp = fopen("testdata.in", "r");

    if (fp != NULL){
        int i = 0;
        while (!feof(fp)){
            fscanf(fp, "%s\n", map[i]);
            i++;
        }
        // int start = 0;
        int xcor = 0;
        int ycor = 0;

        for (int y = 0; y < i; y++){
            for (int x = 0; x < strlen(map[y]); x++){
                if (map[x][y] == '@'){
                    xcor = x;
                    ycor = y;
                    break;
                }
            }
            if (map[xcor][ycor] == '@'){
                break;
            }
        }
        printf("%d %d\n", xcor, ycor);
    }
}