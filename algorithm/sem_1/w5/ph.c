#include <stdio.h>
#include <stdlib.h>

int counter = 0;

void floodFill (int x, int y, char** map);

int main(void){
    int cases;
    scanf("%d",&cases);

    for (int tc = 0; tc <cases; tc++){
        int x, y;
        scanf("%d %d", &x, &y);

        getchar();

        char **map;

        map = (char **) malloc(x * sizeof(char*)); // check if this is x or y LATER

        for (int row = 0; row<x; row++) {
            // map[row] = (char *) malloc(x * sizeof(char));
            map[row] = malloc(y * sizeof (char*));
        }


        for (int i = 0; i < x; i++){
            for (int j = 0; j < y; j++){
                scanf("%c", &map[i][j]);
            }
            getchar();
        }

        for (int i = 0; i < x; i++){
            for (int j = 0; j < y; j++){
                printf("%c", map[i][j]);
            }
            // getchar();
        }
        

        

        int pfound = 0;
        int xstart;
        int ystart;
        for (int i = 0; i < x; i++){
            if (pfound == 1) break;
            for (int j = 0; j < y; j++){
                if(map[i][j] == 'P'){
                    xstart = i;
                    ystart = j;
                    pfound = 1;
                    break;
                }
                else continue;
            }
        }

        
        floodFill(xstart, ystart,map);

        printf("Case #%d: %d\n",tc+1, counter);
        counter = 0;
    }
}

void floodFill(int x, int y, char** map){

    if (map[x][y] != '.' && map[x][y] != '*' && map[x][y]!= 'P'){
        return;
    }
    else if (map[x][y] == '.'){
        map[x][y] = '#';
    }
    else if (map[x][y] == '*'){
        map[x][y] = '#';
        counter++;
    }
    
    if (map[x+1][y] == '*'|| map[x+1][y] == '.'){
        floodFill(x+1,y, map);
    }
    if (map[x][y+1] == '*'|| map[x][y+1]== '.'){
        floodFill(x,y+1, map);
    }
    if (map[x-1][y] == '*'|| map[x-1][y] == '.'){
        floodFill(x-1,y, map);
    }
    if (map[x][y-1] == '*'|| map[x][y-1] == '.'){
        floodFill(x,y-1, map);
    }
}

