#include <stdio.h>
#include <stdlib.h>

int sqrCheck(int num){
	int tmp, res, counter = 0;
	
	do{
		counter++;
		res = counter * counter;
	}while(!(res >= num));
	
	if(res == num){
		return 0 - num;
	} else {
		return num;
	}
	
}

int main(){
	FILE *file = fopen("testdata.txt", "r");
	int result = 0;
	int num, counter = 0;
	
	while(!feof(file)){
		fscanf(file, "%d ", &num);
		result += sqrCheck(num);
		counter++;
	}
	
	printf("Special sum of %d datas is %d\n", counter, result);
	fclose(file);
	
	return 0;
}
