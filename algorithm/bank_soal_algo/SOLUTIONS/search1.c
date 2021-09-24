#include <stdio.h>

int binarySearchGT(int *arr, int size, int find){
    int left = 0;
    int right = size -1;

    int ans = size; //!

    while(left <= right){
        int mid = (right - left) / 2 + left;

        // if (arr[mid] == find){
        //     return mid;
        // }

        if (arr[mid] > find){
            right = mid -1;
            ans = mid; //!
        }
        else left = mid +1;
    }
    return ans;
}

int binarySearch(int *arr, int size, int find){
    int left = 0;
    int right = size -1;

    while (left <= right){
        int mid = (right - left) / 2 + left;

        if (arr[mid] == find){
            return mid;
        }
        
        if (arr[mid] > right)
            right = mid -1;
        else
            left = mid + 1;
    }
    return -1;
}

int main(void){
    int arr[] = {1,3,5,6,9,10,15,69};

    int size = sizeof (arr) / sizeof(int);

    int find = 10;

    int ans = binarySearch(arr,size, find);

    printf("%d\n", ans);
}