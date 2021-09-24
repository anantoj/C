#include <stdio.h>
#include <string.h>

int main(void){
    FILE *fp;
    fp = fopen("testdata.in", "r");

    if (fp != NULL){
        int cases;
        fscanf(fp, "%d\n", &cases);

        for (int tc = 0; tc <cases; tc++){
            int alpha[26] = {};
            int nodup[26] = {};

            char str[101];
            fscanf(fp, "%[^\n]s\n", str);

            for (int i = 0; i < strlen(str); i++){
                if (str[i] != ' '){
                    alpha[str[i]-65]++;
                }
            }

            int process;
            fscanf(fp, "%d\n", &process);

            for (int i = 0; i < process; i++){
                char a, b;

                fscanf(fp, "%c %c\n", &a, &b);

                if (nodup[a-65] == 0){
                    nodup[a-65]++;
                }
                else{
                    continue;
                }

                int num = alpha[a-65];
                alpha[a-65] -= num;
                alpha[b-65] += num;
    
            }
            
            for (int i = 0; i < 26; i++){
                if (alpha[i] != 0){
                    printf("%c %d\n", i+65, alpha[i]);
                }
            }
    }
}