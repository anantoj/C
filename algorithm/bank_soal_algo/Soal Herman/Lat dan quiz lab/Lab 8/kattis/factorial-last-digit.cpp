#include <stdio.h>
int main(){
	int test;
	scanf("%d", &test);
	for(int i = 0; i < test; i++){
		int factorial, sum = 1;
		scanf("%d", &factorial);
		for(int j = factorial; j > 0; j--){
			sum *= j;
			//printf("%d, ", sum);
		} printf("%d\n", sum%10);
	}
	return 0;
}
