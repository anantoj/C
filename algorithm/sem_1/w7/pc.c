#include <stdio.h>
#include <string.h>

int main(void){
    int cases;
    scanf("%d", &cases);

    for(int tc = 0; tc <cases; tc++){
        int n, min, max;

        scanf("%d %d %d", &n, &min, &max); getchar();

        char str[10001];

        scanf("%s",str);

        
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

        printf("%d\n", lightning);
    }

    
}