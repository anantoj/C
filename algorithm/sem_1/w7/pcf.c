#include <stdio.h>
#include <string.h>

int main(void){
    FILE *fp;
    fp = fopen("testdata.in", "r");

    if (fp != NULL){
        int cases;
        fscanf(fp, "%d\n", &cases);

        for(int tc = 0; tc <cases; tc++){
            int n, min, max;

            fscanf(fp,"%d %d %d\n", &n, &min, &max);

            char str[100000];

            fscanf(fp,"%s\n",str);
            
            int lightning = 0;

            for (int i = 0; i < strlen(str);i++){
                int counter = 0;
                    if(str[i] == '1'){
                        i++;
                        counter++;
                        while(str[i]!= '0' && i < strlen(str)){
                            if (str[i] == '1'){
                                counter++;
                                i++;
                            }
                        }
                    }
                    if (counter <= max && counter >= min){
                        lightning++;
                    }
            }

            printf("Case #%d: %d\n", tc+1, lightning);
        }
    }
}