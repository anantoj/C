#include <stdio.h>

int main(void){
    FILE *fp;
    fp = fopen("testdata.in", "r");

    if (fp != NULL){
        int cases;
        fscanf(fp, "%d\n", &cases);

        for (int tc = 0; tc <cases; tc++){
            
            int size, sec;
            fscanf(fp, "%d %d\n", &size, &sec);

            char map[size][size];
            
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
            int radius = sec - 1;

            int xa,ya,xb,yb,xc,yc,xd,yd;

            // find 4 radius points
            xa = xstart - radius;
            ya = ystart - radius;

            xb = xstart + radius;
            yb = ya;

            xc = xa;
            yc = ystart + radius;

            xd = xb;
            yd = yc;

            printf("Case #%d:\n", tc+1);
            for (int i = 0; i < size; i++){
                for (int j = 0; j < size; j++){
                    // check if coordinate is in radius
                    if ( i >= xa && j >= ya && i <= xb && j>= yb && i >= xc && j <= yc && i <=xd && j <= yd)
                        printf("F");
            
                    else printf("#");
                } 
                printf("\n");
            }
            printf("\n");
        }      
    }
}