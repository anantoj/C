#include <stdio.h>

int main(void){
    int size, operation;
    scanf("%d %d", &size, &operation);

    int arr[1000000] = {};
    int left,right,num;

    for (int op= 0; op < operation; op++){
        scanf("%d %d %d", &left, &right, &num);

        for (int i = left -1; i < right; i++){
            arr[i] += num;
        }
    }

    int max = 0;

    for (int i = 0; i < size; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }

    printf("%d\n", max);
}