/*
Dragon

An evil dragon just wakes up from his slumber, he is so powerful that if he uses all his might, all the kingdom will perish. Of course, he won't do it because he wants to toy with mankind first. He knows that if he uses Y power, then all life Y meter around him will turn to dust in an instant. He wonders what is the minimum power should he use if he wants at least Y people die.
Format Input
The first line will contain N and M, each denoting the number of people in the surrounding area and the number of question that the dragon will ask. The next line will consist of N integers a​i,​ each denoting the distance between them and the dragon. The next M lines consist of an integer Y, denoting the dragon's question "If I want Y people die, what is the minimum power should I use?".
Format Output
For each question, print the answer of the dragon's question.
Constraints
1 <= N <= 1000
1 <= M <= 100 000 1<=a​i​ <=1000000000 1 <= Y <= N

Sample Input​ (standard input)
15 5
1002 19 3 8 22 123 14 5234 123 657 41 829 34 2314 15
1
2
3
4
10

Sample Output​ (standard output)
3 
8 
14 
15 
123
*/

#include <stdio.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;

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
    int num, questions;
    scanf("%d %d", &num, &questions);

    int arr[num];

    for (int i = 0; i < num; i++){
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, num-1);

    for (int q = 0; q < questions; q++){
        int people;
        scanf("%d", &people);

        printf("%d", arr[people-1]);
    }
}