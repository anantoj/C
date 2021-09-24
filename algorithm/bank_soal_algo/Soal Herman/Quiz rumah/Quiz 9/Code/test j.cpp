#include <stdio.h>
#include <time.h>
#include <unistd.h>

int search(int arr[], int start, int wanted){
	int res = 0;
	start++;
	while(arr[start] == wanted){
		res++;
		start++;
	}
	
	return res;
}

//void swap(int &arr1, int &arr2){
//	int temp = arr1;
//	arr1 = arr2;
//	arr2 = temp;
//}
//
//int partition(int distance[], int start, int end){
//	int pivotVal = distance[end];
//	int idx = start - 1;
//	
//	for(int x = start; x < end; x++){
//		if(distance[x] < pivotVal){
//			idx++;
//			swap(distance[x], distance[idx]);
//		}
//	}
//	swap(distance[idx + 1], distance[end]);
//	return idx + 1;
//}
//
//void quick(int distance[], int start, int end){
//	if(start < end){
//		int pivot = partition(distance, start, end);
//	
//		quick(distance, start, pivot - 1);
//		quick(distance, pivot + 1, end);
//	}
//}

void merge(int distance[], int start, int mid, int end){
	int i, j, mergeIdx;
	int leftSize = mid - start + 1;
	int rightSize = end - mid;
	
	int leftArr[leftSize], rightArr[rightSize];
	
	for(int i = 0; i < leftSize; i++){
		leftArr[i] = distance[start + i];
	}
	for(int j = 0; j < rightSize; j++){
		rightArr[j] = distance[mid + 1 + j];
	}
	
	i = j = 0;
	mergeIdx = start;
	while(i < leftSize && j < rightSize){
		if(leftArr[i] <= rightArr[j]){
			distance[mergeIdx] = leftArr[i];
			i++;
		} else {
			distance[mergeIdx] = rightArr[j];
			j++;
		}
		mergeIdx++;
	}
	
	while(i < leftSize){
		distance[mergeIdx] = leftArr[i];
		i++;
		mergeIdx++;
	}
	
	while(j < rightSize){
		distance[mergeIdx] = rightArr[j];
		j++;
		mergeIdx++;
	}
	
}

void mergeSort(int distance[], int start, int end){
	if(start < end){
		int mid = (start + end) / 2;
		
		mergeSort(distance, start, mid);
		mergeSort(distance, mid + 1, end);
		
		merge(distance, start, mid, end);
	}
}

int binarySearch(int distance[], int start, int end, int wanted){
	if(start <= end){
		int mid = (start + end) / 2;
		
		if(wanted == distance[mid]){
			return mid + 1;
		}
		
		if(wanted > distance[mid]){
			if(wanted == distance[mid + 1]){
				mid += search(distance, mid + 1, distance[mid + 1]);
				return mid + 2;
			} else if(wanted < distance[mid + 1]){
				return mid + 1;
			} else {
				return binarySearch(distance, mid + 1, end, wanted);
			}
		}
		
		if(wanted < distance[mid]){
			if(wanted >= distance[mid - 1]){
				return mid;
			} else {
				return binarySearch(distance, start, mid - 1, wanted);
			}
		}
		
	} else {
//		printf("No Data found\n");
		return -1;
	}
	
}

int main(){
	int human = 15, question = 10;
	int distance[100005], power[100005];
	int victim;
	
	scanf("%d %d", &human, &question);
	for(int x = 0; x < human; x++){
		scanf("%d", &distance[x]);
	}

	mergeSort(distance, 0, human - 1);

	for(int loop = 0; loop < human; loop++){
		printf("%d\n", distance[loop]);
	}
	
	for(int y = 0; y < question; y++){
		scanf("%d", &power[y]);
		if(power[y] > distance[human - 1]){
			victim = human;
		} else if(power[y] < distance[0]){
			victim = 0;
		} else {
			victim = binarySearch(distance, 0, human - 1, power[y]);
		}
		printf("%d\n", victim);	
	}
	
	return 0;
}
