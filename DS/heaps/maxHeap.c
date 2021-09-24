#include <stdio.h>

int arr[100];
int n = 0;

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void upheap(int index){
    if (index == 1) return;

    int parentIndex = index / 2;

    if (arr[index] > arr[parentIndex]){
        swap(&arr[index], &arr[parentIndex]);
        upheap(parentIndex);
    }
    return;
}

void downheap(int index){
    int left = 2 * index;
    int right = 2 * index + 1;
    int toIndex = index;
    if (left <= n){
        if (arr[left] > arr[toIndex]){
            toIndex = left;
        }
    }
    if (right <= n){
        if (arr[right] > arr[toIndex]){
            toIndex = right;
        }
    }
    if (toIndex != index){
        swap(&arr[index], &arr[toIndex]);
        downheap(toIndex);
    }
    return;
}

void insertHeap(int data){
    n++;
    arr[n] = data;
    upheap(n);
    return;
}

void deleteMax(){
    if (n == 0) return;

    arr[1] = arr[n];
    n--;

    downheap(1);
    return;
}

int getMax(){
    return arr[1];
}

int main(void){
    insertHeap(28);
    insertHeap(10);
    insertHeap(15);
    insertHeap(18);
    insertHeap(7);

    printf("%d\n", getMax());
    deleteMax();
    printf("%d\n", getMax());
    deleteMax();
    printf("%d\n", getMax());
    deleteMax();
    printf("%d\n", getMax());
    return 0;
}