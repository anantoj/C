#include <stdio.h>
#include <string.h>

int main(void){
    int strings;
    scanf("%d", &strings); getchar();

    char str[strings][21];

    for (int i = 0; i < strings; i++){
        scanf("%s", str[i]); getchar();
    }

    int queries;
    scanf("%d", &queries);

    char query[queries][21];
    int count[queries];
    for (int i = 0; i < queries; i++){
        count[i] = 0;
    }

    for (int i = 0; i < queries; i++){
        scanf("%s", query[i]); getchar();
    }

    for (int i = 0; i < queries; i++){
        for (int j = 0; j < strings; j++){
            if(strcmp(query[i], str[j]) == 0){
                count[i]++;
            }
        }
    }

    for (int i = 0; i < queries; i++){
        printf("%d\n", count[i]);
    }

}