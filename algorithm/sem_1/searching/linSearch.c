#include <stdio.h>

int linSearch(int *arr,int x, int size){
    for (int i = 0; i < size; i++){
        if (arr[i] == x){
            return i;
        } 
        // else if (arr[i] != x && i == size-1) return -1;  NO NEED TO USE THIS ELIF STATEMENT JUST PUT RETURN -1 OUTSIDE THE LOOP, JUST THE SAME THING BUT BETTER CODE DESIGN
    }
    return -1;
}

int main(void){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    int index = linSearch(arr,7, 10);

    printf("%d\n", index);
}