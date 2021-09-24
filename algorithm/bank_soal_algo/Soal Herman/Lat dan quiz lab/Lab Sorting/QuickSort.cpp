#include <stdio.h>

int partition(int arr[], int low, int high){
	int pivot = arr[high]; //the righmost number is pivot
	int simpan = low - 1; //menunjuk angka pertama yang lebih besar dari pivot
	
	for(int x = low, x < high, x++){
		if()
	}
}

void quick(int arr[], int low, int high){
	if(low < high){
		int pivot = partition(arr, low, high);
		
		quick(arr, low, pivot - 1);
		quick(arr, pivot + 1, high);
	}
}

int main(){
	int arr[] = {4, 2, 7, 9, 5, 6}; //6 elemen
	quick(arr, 0, 5);
	
	return 0;
}
