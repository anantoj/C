#include <stdio.h>
#include <string.h>

char map[100][101];

int inmap(int x, int y,int size){
    if (x >= 0 && x < size && y >= 0 && y < size) {
        return 1;
    } else {
        return 0;
    }
}

void spread(int time, int xstart, int ystart, int size){
    if (time < 0){
        return;
    }
    if (inmap(xstart, ystart, size) && map[xstart][ystart] == '#'){
        map[xstart][ystart] = 'F';
    }

    spread(time-1,xstart +1, ystart +1,size);
    spread(time-1,xstart+1, ystart + 0 , size);
    spread(time-1,xstart+1, ystart -1, size);
    spread(time-1,xstart + 0, ystart + 1,size);
    spread(time-1,xstart + 0, ystart - 1,size);
    spread(time-1,xstart -1, ystart +1,size);
    spread(time-1,xstart -1, ystart + 0,size);
    spread(time-1,xstart -1, ystart +1, size);
}

int main(void){
    int cases;
    scanf("%d", &cases); getchar();
    // printf("works\n");

    for (int tc = 0; tc <cases;tc++){

        for(int j = 0; j < 100; j++) {
            strcpy(map[j], "........");
        }

        int size, sec;
        scanf("%d %d", &size, &sec);
        // char map[size][size];

        for (int i = 0; i < size; i++){
            scanf("%s", map[i]);
            getchar();
        }

        int xstart;
        int ystart;
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                if (map [i][j] == 'F'){
                    xstart = i;
                    ystart = j;
                    break;
                }
            }
        }

        // spread(sec,xstart, ystart, size);

        int moves[2][8] = {
            {1, 1, 1, 0, 0,-1,-1,-1}, // i
            {1, 0,-1, 1,-1, 1, 0,-1} // j
        };


        for (int t = 1; t < sec; t++){
            for (int i = 0; i < size; i++){
                for (int j = 0; j < size; j++){
                    if (map[i][j] == 'F'){
                        // fire spread through "moves" array
                        for (int y =0; y < 8; y++){
                            if (inmap(i+moves[0][y], j+moves[1][y], size)){ // if moves are not OOB
                                if (map[i+moves[0][y]][j+moves[1][y]] != 'F'){ // if moves will not overwrite neighbouring F blocks
                                    map[i+moves[0][y]][j+moves[1][y]] = '*'; // change to . to *
                                }
                            }
                        }
                    }
                }
            } 

            for (int i = 0; i < size; i++){
                for (int j = 0; j < size; j++){
                    if (map[i][j] == '*') map[i][j] = 'F';
                }
            } 
            
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
        }



        printf("Case #%d:\n", tc+1);
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                printf("%c", map[i][j]);
            }
            printf("\n");
        }
        // printf("\n");
    }
}