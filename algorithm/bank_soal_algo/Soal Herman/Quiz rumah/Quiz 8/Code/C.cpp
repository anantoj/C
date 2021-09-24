#include <stdio.h>

//void swap(int &number1, int &number2){
//	int temp = number1;
//	number1 = number2;
//	number2 = temp;
//}
//
//int partition(int arr[], int left, int right){ //return mid pivot index
//	int start = left;
//	int pivot = arr[right];
//	int i = start - 1;
//	
//	for(int x = start; x <= right - 1; x++){
//		if(arr[x] <= pivot){
//			i++;
//			swap(arr[x], arr[i]);
//		}
//	}
//	swap(arr[i + 1], arr[right]);
//	return i + 1;
//}
//
//void quickSort(int arr[], int left, int right){
//	if(left < right){
//		int pivot = partition(arr, left, right); //returning a pivot position
//		
//		quickSort(arr, pivot + 1, right);
//		quickSort(arr, left, pivot - 1);
//		
//	}
//}

int main(){
	int totalNumber, query;
	int number[1005];
	int queryNum[1005];
	int sum, idx = 0, mainIdx;
	int count;
	int totalSum[1005] = {};
	
	
	scanf("%d %d", &totalNumber, &query);
	
	for(int inputNum = 0; inputNum < totalNumber; inputNum++ ){
		scanf("%d", &number[inputNum]);
	}
	
	for(int start = 0; start < totalNumber; start++){ //starting idx to count
		count = 0;
		mainIdx = idx;
		
		for(int end = totalNumber - 1; end >= start; end--){ //end point of sum
			totalSum[mainIdx] += number[end];
		}
		printf("TotalSum mainIdx[%d]: %d\n", idx, totalSum[mainIdx]);
		idx++;
		count++;
		int temp = totalSum[mainIdx];
		while(count <= totalNumber - 1){
			temp -= number[totalNumber - (1 + count)]; //counting the rest of combination by decreasing the total with the last idx
			totalSum[idx] = temp;
			printf("TotalSum[%d]: %d\n", idx, totalSum[idx]);
			count++;
			idx++;
		}
		
	}
	
	quickSort(totalSum, 0, idx);
	for(int out = 0; out < idx; out++){
		printf("%d ", totalSum[out]);
	}
	puts("");
		
	for(int inputQuery = 0; inputQuery < query; inputQuery++){
		scanf("%d", queryNum[inputQuery]);
	}
	
	return 0;
}
