#include <stdio.h>

int main(){
	int testcase, number, flag, prime[1000], counter, result[1000];
	
	scanf("%d", &testcase); //1
	
	for(int loop = 1; loop <= testcase; loop++){
		scanf("%d", &number); //4
		counter = 0;
		for(int reset = 0; reset < number; reset++){ // reset
			prime[reset] = 0;
			result[reset] = 0;
		}
		
		for(int x = 2; x <= number; x++){ //prime
			flag = 0;
			for(int y = 1; y <= x; y++){
				if(x % y == 0){
					flag++;
				}
				if(flag > 2){
					break;
				} else if(y == x){
					prime[counter] = x;
					counter++;
				}
			}
		}
		
		
		for(int i = 2; i <= number; i++){ //faktorial
			int temp = i;
			for(int j = 0; j < counter; ){
				if(temp % prime[j] == 0){
					temp /= prime[j];
					result[j]++;
				} else if(temp % 2 != 0){
					j++;
				}
			}
		}
		
		printf("Case #%d:\n", loop);
		for(int output = 0; output < counter; output++){
			if(result[output] != 0){
				printf("%d %d\n", prime[output], result[output]);
			}
		}
		
	}
	
	return 0;
}
