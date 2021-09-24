#include <stdio.h>

void swap(int &rank1, int &rank2){
	int temp = rank1;
	rank1 = rank2;
	rank2 = temp;
}

int partition(int rank[], int start, int end){
	int pivotVal = rank[end];
	int idx = start - 1;
	
	for(int x = start; x < end; x++){
		if(rank[x] < pivotVal){
			idx++;
			swap(rank[x], rank[idx]);
		}
	}
	swap(rank[idx + 1], rank[end]);
	return idx + 1;
}

void quick(int rank[], int start, int end){
	if(start < end){
		int pivot = partition(rank, start, end);
	
		quick(rank, start, pivot - 1);
		quick(rank, pivot + 1, end);
	}
}

int main(){
	int testcase, student;
	int rank[1005], score[1005];
	
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){
		scanf("%d", &student);
		
		for(int x = 0; x < student; x++){
			scanf("%d", &score[x]);
		}
		
//		quick(score, 0, student - 1);
		
		for(int reset = 0; reset < 1005; reset++){
			rank[reset] = 1;
		}
		
		for(int i = 0; i < student; i++){
			for(int j = 0; j < student; j++){
				if(score[i] < score[j]){
					rank[i]++;
				}
			}
		}
		
		printf("Case #%d:", loop);
		for(int y = 0; y < student; y++){
			if(y == student - 1){
				printf(" %d\n", rank[y]);
			} else {
				printf(" %d", rank[y]);
			}
		}
		
	}
	
	return 0;
}
