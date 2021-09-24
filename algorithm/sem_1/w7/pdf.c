#include <stdio.h>
#include <string.h>

char map[100][101];

int inmap (int x, int y,int size){
    if (x >= 0 && x < size && y >= 0 && y < size) {
        return 1;
    } else {
        return 0;
    }
}

int inbound (int i, int j, int xa, int ya, int xb, int yb, int xc, int yc, int xd, int yd){
    if ( i >= xa && j >= ya && i <= xb && j>= yb && i >= xc && j <= yc && i <=xd && j <= xd){
        return 1;
    }
    else return 0;
}

int main(void){
    FILE *fp;
    fp = fopen("testdata.in", "r");

    if (fp != NULL){
        int cases;
        fscanf(fp, "%d\n", &cases);

        for (int tc = 0; tc <cases; tc++){
            for(int j = 0; j < 100; j++) {
                strcpy(map[j], "........");
            }
            int size, sec;
            fscanf(fp, "%d %d\n", &size, &sec);
            
            for (int i = 0; i < size; i++){
                fscanf(fp, "%s\n", map[i]);
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
            int moves[2][8] = {
                {1, 1, 1, 0, 0,-1,-1,-1}, // i
                {1, 0,-1, 1,-1, 1, 0,-1} // j
            };

            // spread
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

            

            // int radius = sec -1;
            // int xa,ya,xb,yb,xc,yc,xd,yd;

            // xa = xstart - radius;
            // ya = ystart - radius;

            // xb = xstart + radius;
            // yb = ya;

            // xc = xa;
            // yc = ystart + radius;

            // xd = xb;
            // yd = yc;

            // for (int i = 0; i < size; i++){
            //     for (int j = 0; j < size; j++){
            //         if (inbound (i, j, xa,  ya, xb, yb,  xc,  yc,  xd,  yd)){
            //             map[i][j] = 'F';
            //         }
            //     }
            // }
        
            printf("Case #%d:\n", tc+1);
            for (int i = 0; i < size; i++){
                for (int j = 0; j < size; j++){
                    printf("%c", map[i][j]);
                }
                printf("\n");
            }
            
            printf("\n");
        }
    }
}