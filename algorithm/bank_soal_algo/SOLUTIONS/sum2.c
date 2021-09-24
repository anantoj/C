/*
Sum 2

In this problem, you are told to calculate the sum of all integers in "​testdata.in​" file, but you should take all
the squared number as a negative in the sum. For example, the sum of "1 2 3" is equal to -1 + 2 + 3 = 4.
Format Input
The input will consist of a line contains a lot of numbers in ​testdata.in file. Please read all the numbers inside this file as the data.
Format Output
Output "Special sum of X datas is Y." with N as the number of data and Y as the sum of the data with the specified rules.
Constraints
1 <= data <= 1 000 000
The number of data will not exceed 1000.
It is guaranteed at least 1 data inside testdata.in file.

Sample Input 1​ (testdata.in)
1 2 3 4 5

Sample Output 1​ (standard output)
Special sum of 5 datas is 5.

Sample Input 2 (testdata.in)
3 5 7 6 1 4

Sample Output 2​ (standard output)
Special sum of 6 datas is 16.

Sample Input 3 (testdata.in)
15 318 48 46584 18 13

Sample Output 3​ (standard output)
Special sum of 6 datas is 46996.

*/
#include <stdio.h>
#include <math.h>

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
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main(void){

    FILE *fp;
    fp = fopen("sum2.in", "r");

    int whole[10000];

    for (int i = 1; i < sqrt(1002001); i++){
        whole[i-1] = i;
    }
    if (fp != NULL){
        int arr[1000];
        int idx = 0;
        while (!feof(fp)){
            fscanf(fp, "%d ", &arr[idx]);
            idx++;
        }

        quickSort(arr, 0, idx-1);

        int indexWhole = 0;

        int sum = 0;
        for (int i = 0; i < idx; i++){
            int IS_SQUARE = 0;

            double root = sqrt(arr[i]);

            if (root == whole[indexWhole]) IS_SQUARE = 1;

            // if whole number is greater than root
            else if (whole[indexWhole] > root){
                // decrement the whole number
                while (whole[indexWhole] > root && indexWhole > 0){
                    indexWhole--;
                    if (root == whole[indexWhole]) IS_SQUARE = 1;
                }
            }
            // if the whole number is less the the root
            else{
                // increment the whole number
                while (whole[indexWhole] < root){
                    indexWhole++;
                    if (root == whole[indexWhole]) IS_SQUARE = 1;
                }
            }

            if (IS_SQUARE == 0){
                sum += arr[i];
            }
            else{
                sum -= arr[i];
            }
        }
        printf("Special sum of %d datas is %d.\n", idx, sum);

    }
}