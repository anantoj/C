#include <stdio.h>

int main(){
	int testcase;
	long long int input, output[10], temp;
	
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){ //testcase
		scanf("%lld", &input);
		for(int process = 0; process < 4; process++){ //processing the output
			if(process == 0){
				output[0] = input;
			} else if(process == 1 || process == 3){
				temp = output[process - 1];
				output[process] = 0;
				while(temp > 0){
					output[process] = output[process] * 10 + temp % 10;
					temp /= 10;
				}
			} else if(process == 2){
				output[2] = output [0] + output[1];
			}
			
		}
		printf("Case #%d: %lld %lld %lld %lld\n", loop, output[0], output[1], output[2], output[3]);
	}
	
	return 0;
}
