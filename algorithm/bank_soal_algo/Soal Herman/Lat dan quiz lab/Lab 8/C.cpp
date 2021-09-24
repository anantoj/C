#include <stdio.h>

int binarySearch(long long int number[], int start, int end, long long int search){
	int mid = (start + end) / 2;
	
	if(search > number[end] || search < number[start]){
		return 0;
	}
	
	if(search == number[start] || search == number[mid] || search == number[end]){
		return 1;
	} else if(search > number[mid]){
		binarySearch(number, mid + 1, end, search);
	} else if(search < number[mid]){
		binarySearch(number, start, mid - 1, search);
	}
}

void swap(long long int &num1,long long int &num2){
	long long int temp = num1;
	num1 = num2;
	num2 = temp;
}

int partition(long long int number[], int low, int high){
	int pivot = number[high];
	int idxSimpan = low - 1;
	
	for(int x = low; x < high; x++){
		if(number[x] <= pivot){
			idxSimpan++;
			swap(number[x], number[idxSimpan]);
		}
	}
	swap(number[idxSimpan + 1], number[high]);
	return idxSimpan + 1;
}

void quickSort(long long int number[], int low, int high){
	if(low < high){
		int pivotPoint = partition(number, low, high);
	
		quickSort(number, low, pivotPoint - 1);
		quickSort(number, pivotPoint + 1, high);
	}
}

int main(){
	int numElement, numQuery;
	int existNum = 0;
	long long int query, number[100005];
	
	
	scanf("%d %d", &numElement, &numQuery);
	for(int x = 0; x < numElement; x++){
		scanf("%d", &number[x]);
	}
	quickSort(number, 0, numElement - 1);
	
	for(int y = 0; y < numQuery; y++){ //number to be searched
		scanf("%d", &query);
		existNum += binarySearch(number, 0, numElement - 1, query);
		printf("%d search reesult return %d\n", query, binarySearch(number, 0, numElement - 1, query));
	}
	printf("%d\n", existNum);
	
	
	return 0;
}
