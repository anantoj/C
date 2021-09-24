#include <stdio.h>

char map[100][100];

int floodFill(int x, int y, char map[100][100]);

int main(void){
    int cases;
    scanf("%d",&cases);

    for (int tc = 0; tc <cases; tc++){
        int x, y;
        scanf("%d %d", &x, &y);

        getchar();

        for (int i = 0; i < x; i++){
            for (int j = 0; j < y; j++){
                scanf("%c", &map[i][j]);
            }
            getchar();
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

        int total = floodFill(x,y,map);
        printf("Case #%d: %d\n", tc+1, total);
    }
}

int floodFill(int x, int y, char map[100][100]) {
    if (map[x][y] == '#') return 0;
    if (map[x][y] == '*') return 1;

    
    return floodFill(x + 1, y, map);
    return floodFill(x, y + 1, map);
    return floodFill(x - 1, y, map);
    return floodFill(x, y - 1, map);
}