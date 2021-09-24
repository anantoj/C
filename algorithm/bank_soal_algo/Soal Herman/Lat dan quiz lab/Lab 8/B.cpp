#include <stdio.h>
#include <stdlib.h>

struct exam{
	int number;
	char answer;
};

void swap(struct exam &idx1, struct exam &idx2){
	struct exam temp = idx1;
	idx1 = idx2;
	idx2 = temp;
}

//int partition(struct exam answer[], int low, int high){
//	int pivot = answer[high].number;
//	int idxSimpan = low - 1;
//	
//	for(int x = low; x <= high - 1; x++){
//		if(answer[x].number < pivot){
//			idxSimpan++;
//			swap(answer[x], answer[idxSimpan]);
//		}
//	}
//	swap(answer[idxSimpan + 1], answer[high]);
//	return idxSimpan + 1;
//}
//
//void quick(struct exam answer[], int low, int high){
//	int pivot = partition(answer, low, high);
//	
//	partition(answer, low, pivot - 1);
//	partition(answer, pivot + 1, high);
//}

void bubble(struct exam answer[], int size){
	for(int x = 0; x < size - 1; x++){
		for(int y = x + 1; y < size; y++){
			if(answer[x].number > answer[y].number){
				struct exam temp = answer[x];
				answer[x] = answer[y];
				answer[y] = temp;
			}
		}
	}
}

int main(){
	exam answer[105];
//	char testcase[10];
	int testcase;
	int numAnswer;
	
	FILE *file = fopen("testdata.txt", "r");
	
	fscanf(file, "%d", &testcase);
	printf("%d\n", testcase);
	
	for(int loop = 1; loop <= testcase; loop++){
		fscanf(file, "%d", &numAnswer);
		printf("NumAnswer: %d\n", numAnswer);
		
		for(int x = 0; x < numAnswer; x++){
			fscanf(file, "%d. %c", &answer[x].number, &answer[x].answer);
			printf("%d. %c\n", answer[x].number, answer[x].answer);
		}
		
//		quick(answer, 0, numAnswer - 1);
		bubble(answer, numAnswer);
		printf("Sorted answer Number:\n");
		for(int y = 0; y < numAnswer; y++){
			printf("%d. %c\n", answer[y].number, answer[y].answer);
		}
		puts("\n");
		
	}
	
	fclose(file);
	
	return 0;
}
