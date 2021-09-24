#include <stdio.h>
#include <stdlib.h>

struct exam{
	int number;
	char answer;
};

void swap(exam *sheet1, exam *sheet2){
	exam temp = *sheet1;
	*sheet1 = *sheet2;
	*sheet2 = temp;
}

void bubble(exam sheet[], int totalSheet){
	for(int i = 0; i < totalSheet - 1; i++){
		for(int j = i + 1; j < totalSheet; j++){
			if(sheet[j].number < sheet[i].number){
				swap(&sheet[j], &sheet[i]);
			}
		}
	}
	return;
}

int main(){
	FILE *file = fopen("testdata.txt", "r");
	exam sheet[105];
	int testcase, totalSheet;
	
	fscanf(file, "%d\n", &testcase);
	for(int loop = 1; loop <= testcase; loop++){
		fscanf(file, "%d\n", &totalSheet);
		for(int x = 0; x < totalSheet; x++){
			fscanf(file, "%d. %c\n", &sheet[x].number, &sheet[x].answer);
		}
		
		bubble(sheet, totalSheet);
		printf("Case #%d:\n", loop);
		for(int i = 0; i < totalSheet; i++){
			printf("%d. %c\n", sheet[i].number, sheet[i].answer);
		}
		
	}
	fclose(file);
	return 0;
}
