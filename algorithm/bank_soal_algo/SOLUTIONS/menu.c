/*
Menu

Jojo is going to a restaurant. There are N foods listed in the menu, and the items are sorted increasingly based on its price. Now Jojo is wondering how many foods are there with price P. As the number of food in the menu can be a lot, Jojo will need your help to answer his questions. Jojo knows you can count really fast, so he will give you M questions.
Format Input
Input begins with integer N and M, the number of food in the menu, and the number of query. The next line will consist of N integers, the prices of food in the menu sorted increasingly. Then followed by M lines, where each line consist an integer, the price of i-th query.
Format Output
The output consists of M lines, where each line is the answer to the i-th query, the number of food with price P​i.​
Constraints
1 <= N <= 100 000
1 <= M <= 100 000 1<=x​i​ <=1000000000

Sample Input​ (standard input)
4 3
1 2 2 3
1
2
5

Sample Output​ (standard output)
1
2
0
*/

#include <stdio.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;   
    *b = tmp;
}

int partition(int *arr, int low, int high){
    int pivot = arr[high];
    int i = low -1;

    for (int j = low; j < high; j++){
        if (arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quickSort(int *arr, int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low ,pi -1);
        quickSort(arr, pi+1, high);
    }
}

int binarySearch(int *arr, int find, int size){
    int left = 0;
    int right = size -1;

    while (left <= right){
        int mid = (right + left) / 2;

        if (arr[mid] == find) return mid;

        if (arr[mid] < find)
            left = mid + 1;
        else
            right = mid -1;
    }

    return -1;
}

int main(void){
    int size, questions;

    scanf("%d %d", &size, &questions);

    int arr[size]; 

    for (int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, size-1);

    for (int q = 0; q < questions; q++){
        int find;
        scanf("%d" , &find);

        int index = binarySearch(arr, find, size);

        if (index == -1){
            printf("0\n");
        }
        else{
            int count = 1;
            int left_idx = index;
            int right_idx = index;

            while (arr[left_idx] == arr[index] && left_idx > 0){
                left_idx--;
                if (arr[left_idx] == arr[index])
                    count++;
            }

            while (arr[right_idx] == arr[index] && right_idx < size-1){
                right_idx++;
                if (arr[right_idx] == arr[index])
                    count++;
            }

            printf("%d\n", count);
        }
    }
}