#include <stdio.h>

int binarySearch(int *arr, int size, int find){
    int left = 0;
    int right = size -1;

    while (left <= right){
        int mid = (high + low) / 2;

        if (arr[mid] == find)
            return mid;

        if (arr[mid] < find)
            left = mid +1;
        else if (arr[mid] > find)
            right = mid - 1;
    }
    return -1;
}

int main(void){
    int arr[] = {1,2,3,4,7,9,10,13,14,21};

    int size = sizeof(arr) / sizeof(int);

    int find =  2

    int index = binarySearch(arr, size, find);

}