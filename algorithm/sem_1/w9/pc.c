#include <stdio.h>

char map[100][101];

int max_x;
int max_y;
int counter = 0;

int inmap(int coordinate, int max){
    if (coordinate >= 0 && coordinate < max){
        return 1;
    }
    return 0;
}

void floodfill(int x, int y){
    if (inmap(x,max_x) == 1 && inmap(y,max_y) == 1){
        if (map[x][y] == 'L'){
            map[x][y] = 'S';
        }
        else if(map[x][y] == 'K'){
            counter++;
            map[x][y] = 'S';
        }
        if (inmap(x-1,max_x) == 1){
            if (map[x-1][y] == 'K' || map[x-1][y] == 'L'){
                floodfill(x-1,y);
            }
        }

        if (inmap(x+1, max_x) == 1){
            if (map[x+1][y] == 'K' || map[x-1][y] == 'L'){
                floodfill(x+1,y);
            }
        }

        if (inmap(y-1,max_y) == 1){
            if (map[x][y-1] == 'K' || map[x][y-1] == 'L'){ 
            // there used to be a plus sign here that wasted your goddamn fucking time
                floodfill(x,y-1);
            }
        }

         if (inmap(y+1,max_y) == 1){
            if (map[x][y+1] == 'K' || map[x][y+1] == 'L'){
                floodfill(x,y+1);
            }
        }

        
    }
    else return;
}

int main(void){
    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc < cases; tc++){
        counter = 0;
        for (int i = 0; i < 100; i++){
            for (int j = 0; j < 101; j++){
                map[i][j] = '-';
            }
        }
        int row, col;
       
        scanf("%d %d", &row, &col); getchar();

        max_x = row;
        max_y = col;

        int xstart, ystart;

        for (int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                scanf("%c", &map[i][j]);
                if (map[i][j] == 'H'){
                    map[i][j] = 'S';
                    xstart = i;
                    ystart = j;
                }
            }
            getchar(); // dont forget this getchar!!
        }
        

        floodfill(xstart, ystart);

        printf("Case #%d: %d\n", tc+1, counter);
    }
}