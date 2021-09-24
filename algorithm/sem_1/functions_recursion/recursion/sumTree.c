#include <stdio.h>

void foo(int index, int *arr, int size, int carry){

    carry += arr[index-1];
    
    if (2*index > size)
        printf("%d\n", carry);

    if (2*index <= size)
        foo(2*index, arr,size, carry);

    if (2*index+1 <= size)
        foo(2*index+1, arr, size, carry);

    return;

}

int main(void){
    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc <cases; tc++){
        int size;
        scanf("%d", &size);

        int arr[size];

        for (int i = 0; i < size; i++){
            scanf("%d", &arr[i]);
        }

        printf("Case #%d:\n",tc+1);

        int index = 1;
        int carry = 0;
        
        foo(index, arr, size, carry);
    }
}