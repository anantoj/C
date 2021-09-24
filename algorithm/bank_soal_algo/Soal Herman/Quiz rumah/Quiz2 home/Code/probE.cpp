#include <stdio.h>

int main(){
	int testcase;
	int input[4], output[4];
	
	scanf("%d", &testcase);
	
	for(int x = 0; x < testcase ; x++){ //testcase loop
		scanf("%d", &input[x]);
		for(int y = 0; y < 4; y++){ //processing and output
		
			if(y == 1 || y == 3){ //reverse
				while(input[y] > 0){
				output[y] = (output[y] * 10) + (input[y] % 10);
				input[y] /= 10;
				}
			} else if(y == 2){
				output[y] = output[y - 2] + output[y - 1];
			}	
		}
		printf("Case #%d: %d %d %d %d\n", x + 1, output[0], output[1], output[2], output[3]);
	}
	
	return 0;
}
