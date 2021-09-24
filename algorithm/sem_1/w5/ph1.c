#include <stdio.h>

char map[101][101];

int n;
int m;
int counter = 0;

void floodFill(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m) {
        if (map[x][y] == '.') {
            map[x][y] = '#';
        } else if (map[x][y] == '*') {
            map[x][y] = '#';
            counter += 1;
        }
        
        if (x-1 >= 0 && x-1 < n) {
            if (map[x-1][y] != '#') { 
                floodFill(x - 1, y);
            }
        }
        
        if (x+1 >= 0 && x+1 < n) {
            if (map[x+1][y] != '#') {
               floodFill(x + 1, y);
            }
        }
        
        if (y-1 >= 0 && y-1 < m) {
            if (map[x][y - 1] != '#') {
                floodFill(x, y - 1);
            }
        }
        
        if (y+1 >= 0 && y+1 < m) {
            if (map[x][y+1] != '#') {
                floodFill(x, y + 1);
            }
        }
    } else {
        return;
    }
}

int main(void) {
    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc < cases; tc++) {
        counter = 0;
        int x, y;
        scanf("%d %d", &n, &m);

        for (int i = 0; i < n; i++) {
            scanf("%s", map[i]);
        }

        int xstart, ystart;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 'P') {
                    xstart = i;
                    ystart = j;
                }
            }
        }
        
        floodFill(xstart, ystart);
        printf("Case #%d: %d\n", tc+1, counter);
    }
    
    return 0;
}



