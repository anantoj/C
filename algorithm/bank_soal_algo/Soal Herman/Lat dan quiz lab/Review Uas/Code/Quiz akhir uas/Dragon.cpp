#include <stdio.h>

void merge(int distance[], int start, int mid, int end){
	int x, y, counter;
	int leftSize, rightSize;
	
	leftSize = mid + 1 - start;
	rightSize = end - mid;
	
	int arrL[leftSize], arrR[rightSize];
	
	counter = 0;
	for(x = 0; x < leftSize; x++){
		arrL[counter] = distance[start + x];
		counter++;
	}
	
	counter = 0;
	for(y = 0; y < rightSize; y++){
		arrR[counter] = distance[mid + 1 + y];
		counter++;
	}
	
	x = y = 0;
	counter = start;
	while(x < leftSize && y < rightSize){
		if(arrL[x] <= arrR[y]){
			distance[counter] = arrL[x];
			x++;
		} else {
			distance[counter] = arrR[y];
			y++;
		}
		counter++;
	}
	
	while(x < leftSize){
		distance[counter] = arrL[x];
		x++;
		counter++;
	}
	
	while(y < rightSize){
		distance[counter] = arrR[y];
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
		
	} else {
		return;
	}
}

int binarySearch(int distance[], int start, int end, int wanted){
	if(start <= end){
		int mid = (start + end) / 2;
		
		if(distance[mid] == wanted){
			return distance[mid];
		} else {
			if(wanted < distance[mid]){
				end = mid - 1;
			} else if(wanted > distance[mid]){
				start = mid + 1;
			}
			return binarySearch(distance, start, end, wanted);
		}
		
	} else {
		return -1;
	}
}

int main(){
	int human, question;
	int distance[1005], queue;
	
	scanf("%d %d", &human, &question);
	
	for(int x = 0; x < human; x++){
		scanf("%d", &distance[x]);
	}
	
	mergeSort(distance, 0, human - 1);
	
	int res;
	for(int y = 0; y < question; y++){
		scanf("%d", &queue);
		res = binarySearch(distance, 0, human - 1, distance[queue - 1]);
		printf("%d\n", res);
	}
	return 0;
}
