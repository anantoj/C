#include <stdio.h>

struct data{
	int num;
	int day, month, year;
	char name[15];
	char address[15];
};

void printData(data students[], int idx){
	printf("%d. %s was born on %d/%d/%d and live at %s\n", students[idx].num, students[idx].name, 
	students[idx].day, students[idx].month, students[idx].year, students[idx].address);
}

void binarySearch(data students[], int start, int end, int wanted){
	if(start <= end){
		int mid = (start + end) / 2;
		if(students[mid].num == wanted){
			printData(students, mid);
		} else {
			if(wanted < students[mid].num){
				end  = mid - 1;
			} else if(wanted > students[mid].num){
				start = mid + 1;
			}
			binarySearch(students, start, end, wanted);
		}
	} else {
		printf("No data found!\n");
	}
}

int main(){
	data students [55];
	int numOfStudent, question;
	FILE *file = fopen("testdata.txt", "r");
	
	fscanf(file, "%d\n", &numOfStudent);
	for(int x = 0; x < numOfStudent; x++){
		fscanf(file, "%d %d %d %d %s %s\n", &students[x].num, &students[x].day, &students[x].month, &students[x].year, &students[x].name, &students[x].address);
	}
	
	int queue;
	fscanf(file, "%d\n", &question);
	for(int y = 0; y < question; y++){
		fscanf(file, "%d\n", &queue);
		binarySearch(students, 0, numOfStudent - 1, queue);
	}
	
	fclose(file);
	return 0;
}
