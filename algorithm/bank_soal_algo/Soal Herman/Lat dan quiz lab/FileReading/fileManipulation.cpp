#include <stdio.h>
#include <stdlib.h>



int main(){
	char data[100][100];
	char newData[100];
	int x = 0, idx;
	
	FILE *file = fopen("file.txt", "r");
	while(fscanf(file, "%s\n", data[x]) != EOF){
		x++;
	}
	fclose(file);
	
	for(int i = 0; i < x; i++){
		printf("%s\n", data[i]);
	}
	
	FILE *file2 = fopen("file.txt", "w");
	puts("Add data");
	printf("input the new data: ");
	scanf("%s", newData);
	printf("Input the index of the new data Data: ");
	scanf("%d", &idx);
	
	for(int y = 0; y < x; y++){
		if(y == idx - 1){
			fprintf(file2, "%s\n", newData);
		}
		fprintf(file2, "%s\n", data[y]);
	}
	
	fclose(file2);
	printf("---------------------\n");
	file2 = fopen("file.txt", "r");
	x = 0;
	while(fscanf(file, "%s\n", data[x]) != EOF){
		x++;
	}
	
	for(int j = 0; j < x; j++){
		printf("%s\n", data[j]);
	}
	fclose(file2);
}
