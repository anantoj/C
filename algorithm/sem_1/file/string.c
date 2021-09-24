#include <stdio.h>
#include <string.h>

int main(void){
    FILE *fp;

    fp = fopen("testdata.in", "r");

    if (fp != NULL){
        while(!feof(fp)){
            char str[101];

            fscanf(fp, "%[^\n]\n", str);

            for (int i = strlen(str)-1; i >= 0; i--){
                printf("%c", str[i]);
            }
            printf("\n");
        }
        fclose(fp);
    }
}