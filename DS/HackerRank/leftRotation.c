#include <stdio.h>

int main(void){
    int size, rotation;

    scanf("%d %d", &size, &rotation);

    int arr[size];

    rotation = rotation % size;

    for (int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    for (int i = rotation; i < size; i++){
        if (i == rotation) 
            printf("%d", arr[i]);
        else 
            printf(" %d", arr[i]);
    }

    // if the second forloop will be executed, print a space
    if (rotation % size  != 0) printf(" ");

    for (int i = 0; i < rotation; i++){
        if (i == 0) 
            printf("%d", arr[i]);
        else 
            printf(" %d",arr[i]);
    }

    printf("\n");
    

}