#include <stdio.h>
//perpangkatan

int main(){
	long long int number = 2 , square = 6;
	long long int result = 1;
	
	for(int x = 0; x <= square; x++){
		
		if(x == 0){
			result = 1;
		} else {
			result = (result * number) % 1000000007;
		}
	}
	
	printf("%lld", result);
	return 0;
}
