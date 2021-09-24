#include <stdio.h>
typedef struct grades{
	int id;
	char grade[2];
} Grade;

void insertionSort(Grade data[], int n){
	for(int i = 1; i < n; i++){
		Grade temp = data[i];
		for(int j = i - 1; j >= 0 && data[j].id > temp.id; j--){
			data[j+1] = data[j];
			data[j] = temp;
		}
	}
}

int main(){
	int tc;
	FILE *file = fopen("testdata.in", "r");
	fscanf(file, "%d\n", &tc);
	
	for(int i = 0; i < tc; i++){
		int size, points;
		fscanf(file, "%d", &size);
		Grade grade[size];
		for(int j = 0; j < size; j++){
			fscanf(file, "%d. %s\n", &grade[j].id, grade[j].grade);
		}
		insertionSort(grade, size);
		
		printf("Case #%d:\n", i+1);
		for(int j = 0; j < size; j++){
			printf("%d. %s\n", grade[j].id, grade[j].grade);
		}
	}
	fclose(file);
	return 0;
}
