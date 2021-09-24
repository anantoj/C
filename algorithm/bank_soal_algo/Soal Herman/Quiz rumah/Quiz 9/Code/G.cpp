#include <stdio.h>

void swap(int &ppl1, int &ppl2){
	int temp = ppl1;
	ppl1 = ppl2;
	ppl2 = temp;
}

int partition(int ppl[], int start, int end){
	int pivotVal = ppl[end];
	int idx = start - 1;
	
	for(int x = start; x < end; x++){
		if(ppl[x] <= pivotVal){
			idx++;
			swap(ppl[x], ppl[idx]);
		}
	}
	swap(ppl[idx + 1], ppl[end]);
	return idx + 1;
}

void quick(int ppl[], int start, int end){
	if(start < end){
		int pivot = partition(ppl, start, end);
		
		quick(ppl, start, pivot - 1);
		quick(ppl, pivot + 1, end);
	}
	return;
}

int binarySearch(int ppl[], int start, int end, int wanted){
	if(start < end){
		int mid = (start + end) / 2;
		if(wanted == ppl[mid]){
			return ppl[mid];
		} else if(wanted == ppl[start]){
			return ppl[start];
		} else if(wanted == ppl[end]){
			return ppl[end];
		} else {
			if(wanted < ppl[mid]){
				return binarySearch(ppl, start, mid  - 1, wanted);
			} else if(wanted > ppl[mid]){
				return binarySearch(ppl, mid + 1, end, wanted);
			}
		}
	} else {
		return -1;
	}
}

int main(){
	int numPpl, question;
	int ppl[1005], queue;
	int search;
	
	scanf("%d %d", &numPpl, &question);
	for(int x = 0; x < numPpl; x++){
		scanf("%d", &ppl[x]);
	}
	
	quick(ppl, 0, numPpl - 1);
//	for(int y = 0; y < numPpl; y++){
//		printf("%d\n", ppl[y]);
//	}
	for(int y = 0; y < question; y++){
		scanf("%d", &queue);
		search = ppl[queue - 1];
//		printf("search = %d\n", search);
		printf("%d\n", binarySearch(ppl, 0, numPpl - 1, search));
	}
	
	
	
	return 0;
}
