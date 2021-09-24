#include <stdio.h>
#include <string.h>

void swap(char *a, char *b){
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void){
    int cases;
    scanf("%d", &cases); getchar();

    for (int tc = 0; tc < cases; tc++){
        char str[101];
        char check[101];

        scanf("%s", str); getchar();
        scanf("%s", check); getchar();

        int len = strlen(str);

        int flag = 0;

        if (strcmp(str,check) == 0){ 
            printf("Case #%d: YES\n", tc+1);
        }
        else{
            for (int t = 0; t < len-1; t++){ // len - 1 because we don't have to check the last rotation, it is the same as the original
                for (int i = len -1; i > 0 ;i--){ // remember i-- and not >= because we must not swap i = 0 with i = -1
                    swap(&str[i], &str[i-1]);
                }

                if (strcmp(str,check) == 0){
                    printf("Case #%d: YES\n", tc+1);
                    flag = 1;
                    break;
                }
            }

            if (flag == 0) printf("Case #%d: NO\n", tc+1);
        }

    }
}