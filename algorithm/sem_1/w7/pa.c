#include <stdio.h>
#include <string.h>


int main(void){
    FILE *fp;

    fp = fopen("testdata.in", "r");

    if (fp != NULL){
        int cases;
        fscanf(fp, "%d\n", &cases); 
        
        for (int tc = 0; tc <cases; tc++){
            char str[101];
            
            int process;
            fscanf(fp, "%[^\n]\n", str); 
        
            fscanf(fp, "%d\n", &process);
        
            int alpha[26] = {};
            int duplicate[26] = {};
            
            for (int p = 0; p < process; p++){
                char a, b;
                fscanf(fp, "%c %c\n", &a, &b); 

                if (duplicate[a - 65] == 0){
                    duplicate[a-65]++;
                }
                else{
                    continue;
                }
                
                for (int i = 0; i < strlen(str); i++){
                    if (str[i] == a){
                        str[i] = b;
                    }
                } 

            }

            for (int i = 0; i < 26; i++){
                for (int j = 0; j < strlen(str); j++){
                    if (str[j] == i+65)
                        alpha[str[j]- 65]++;

                }
            }
            for (int i = 0; i < 26; i++){
                if (alpha[i] != 0){
                    printf("%c %d\n", i+65, alpha[i]);
                }
            }  
        }
    }
}