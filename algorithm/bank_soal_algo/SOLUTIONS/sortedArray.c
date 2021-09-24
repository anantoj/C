/*
Sorted Array

Given a sorted array of numbers. Count the number given in each query that exists in the array.
Format Input
The first line of the input contains 2 integers N and Q, number of elements in the array and number of queries. Second line contains N numbers Ai, the element of the array. The next Q lines contains an integer Z, the number to be searched.
Format Output
Output the count of existance number of the queries.
Constraints
1 <= N <= 100 000
1 <= Q <= 100 000
-1 000 000 000 <= Number <= 1 000 000 000

Sample Input​​ (standard input)
5 5 
1 2 3 3 4 
0
10
1
3
4

Sample Output​​ (standard output)
3

*/

#include <stdio.h>

int binarySearch(int *arr, int x, int size){
    int left = 0;
    int right = size - 1;
    
    while (left <= right){
        int mid = (right + left) / 2; // remember its (right + left) not right - left

        if (arr[mid] == x){
            return 1;
        }

        if (arr[mid] < x){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }

    return -1;
}
int main(void){
    int size, query;
    scanf("%d %d", &size, &query);

    int arr[size];

    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    int count = 0;

    for (int i = 0; i < query; i++){
        int find;
        scanf("%d", &find);

        int isfound = binarySearch(arr,find,size);

        if (isfound == 1){
            count++;
        }

    }

    printf("%d\n", count);
}

