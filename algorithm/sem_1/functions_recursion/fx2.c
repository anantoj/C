#include <stdio.h>

void display(int *num, int size){
    printf("\nNumbers inside array: \n");    
    for (int i = 0; i < size; i++){
        printf("%d ", num[i]);
    }
    printf("\n\n");
}

int main(void){
    int num[5] = {1,2,3,4,5};

    int size = sizeof(num)/ sizeof(int);

    display(num, size);
    // array is passed by reference BY DEFAULT
    // becuase it tkaes time to copy many data if it is passed by value
}