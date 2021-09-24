#include <stdio.h>

void swap(int *num1, int *num2){
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void merge(int distance[], int start, int mid, int end){
	int x, y, counter;
	int leftSize = mid + 1 - start;
	int rightSize = end - mid;
	
	int leftArr[leftSize], rightArr[rightSize];
	
	counter = 0;
	for(x = 0; x < leftSize; x++){
		leftArr[counter] = distance[start + x];
		counter++;
	}
	
	counter = 0;
	for(y = 0; y < rightSize; y++){
		rightArr[counter] = distance[mid + 1 + y];
		counter++;
	}
	
	x = y = 0;
	counter = start;
	while(x < leftSize && y < rightSize){
		if(leftArr[x] <= rightArr[y]){
			distance[counter] = leftArr[x];
			x++;
		} else {
			distance[counter] = rightArr[y];
			y++;
		}
		counter++;
	}
	
	while(x < leftSize){
		distance[counter] = leftArr[x];
		x++;
		counter++;
	}
	
	while(y < rightSize){
		distance[counter]= rightArr[y];
		y++;
		counter++;
	}
	
}

void mergeSort(int distance[], int start, int end){
	if(start < end){
		int mid = (start + end) / 2;
		
		mergeSort(distance, start, mid);
		mergeSort(distance, mid + 1, end);
		
		merge(distance, start, mid, end);
	}
	return;
}

int quickSort(int distance[], int start, int end){
	int pivotVal = distance[end];
	int idxSorted = start - 1;
	
	for(int x = start; x < end; x++){
		if(distance[x] <= pivotVal){
			idxSorted++;
			swap(&distance[x], &distance[idxSorted]);
		}
	}
	swap(&distance[idxSorted + 1], &distance[end]);
	return idxSorted + 1;
	
}

void quick(int distance[], int start, int end){
	if(start < end){
		int pivot = quickSort(distance, start, end);
		
		quick(distance, start, pivot - 1);
		quick(distance, pivot + 1, end);
	}
	return;
}

int main(){
	int totalPpl, question;
	int distance[100005];
	int queue;
	
	
	scanf("%d %d", &totalPpl, &question);
	
	for(int loop = 0; loop < totalPpl; loop++){
		scanf("%d", &distance[loop]);
	}
	
//	mergeSort(distance, 0, totalPpl - 1);
	quick(distance, 0, totalPpl - 1);
	
	for(int x = 0; x < totalPpl; x++){
		printf("%d\n", distance[x]);
	}
	
	return 0;
}
