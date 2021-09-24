#include <stdio.h>
#include <string.h>

typedef struct{
    char name[51];
    int number;
}data;

int main(void){
    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc < cases; tc++){
        int size;
        scanf("%d", &size); getchar();

        data arr[size];

        for (int i = 0; i < size; i++){
            scanf("%[^#]#%d", arr[i].name, &arr[i].number); getchar();
        }

        for (int i = 0; i < size-1; i++){
            for (int j = 0; j < size - i - 1; j++){
                if (arr[j].number > arr[j+1].number){
                    char tmp[101];
                    strcpy(tmp,arr[j].name);
                    strcpy(arr[j].name,arr[j+1].name);
                    strcpy(arr[j+1].name, tmp);

                    int temp = arr[j].number;
                    arr[j].number = arr[j+1].number;
                    arr[j+1].number = temp;
                }
                else if (arr[j].number == arr[j+1].number){
                    if (strcmp(arr[j].name, arr[j+1].name) > 0){
                        char tmp[101];
                        strcpy(tmp,arr[j].name);
                        strcpy(arr[j].name,arr[j+1].name);
                        strcpy(arr[j+1].name, tmp);

                        int temp = arr[j].number;
                        arr[j].number = arr[j+1].number;
                        arr[j+1].number = temp;
                    }
                }
            }
        }
        printf("Case #%d:\n", tc+1);
        for (int i = 0; i < size; i++){
            printf("%s - %d\n", arr[i].name, arr[i].number);
        }

    }
}