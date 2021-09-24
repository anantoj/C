#include <stdio.h>
#include <stdlib.h>

int main(){
	int idx = 0; //counter
	char breaker;
	long long int data[1005];
	long long int min = 2000000, max = 0, sum = 0, range;
	double mean;
	
	FILE *file = fopen("testdata.txt", "r");
	
	while(!feof(file)){
		fscanf(file, "%lld%c", &data[idx], &breaker);
		
		sum += data[idx];
		if(data[idx] < min){
			min = data[idx];
		}
		if(data[idx] > max){
			max = data[idx];
		}
		idx++;
		if(breaker == '\n'){
			break;
		}
	}
	fclose(file);
	
	mean = (double) sum / idx;
	range = max - min;
	
	printf("Count : %d\n", idx);
	printf("Sum   : %lld\n", sum);
	printf("Mean  : %.2lf\n", mean);
	printf("Min   : %lld\n", min);
	printf("Max   : %lld\n", max);
	printf("Range : %lld\n", range);
	
	return 0;
}
