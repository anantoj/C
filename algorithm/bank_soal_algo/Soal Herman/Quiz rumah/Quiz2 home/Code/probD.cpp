#include <stdio.h>

int main(){
	int number[5];
	double result[5];
	char out[20];
	
	
	for(int loop = 0; loop < 3; loop++){ //calculate the result
		scanf("%d", &number[loop]);
		result[loop] = (double) number[loop] / 999;
		sprintf(out, "%.12lf", result[loop]);
		//checking
		if(out[2] == out[3] && out[2] == out[4]){
			printf("%.3s...\n", out);
		} else if(out[2] == out[5] && out[3] == out[6] && out[4] == out[7]){
			printf("%.5s...\n", out);
		} else {
			printf("%s\n", out);
		}
		
	}
	
	return 0;
}
