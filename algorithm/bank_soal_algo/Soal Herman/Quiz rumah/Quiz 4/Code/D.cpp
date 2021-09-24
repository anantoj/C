#include <stdio.h>

int main(){
	int testcase , a, b , max;
	long long int num1 = 2, num2 = 3, res1, res2, finalres;
	
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){
		scanf("%d %d", &a, &b);
		res1 = num1, res2 = num2;
		max = a;
		if(max < b){
			max = b;
		}
		
		for(int x = 2; x <= max; x++){
			if(x <= a){
				res1 = (res1 * num1) % 1000000007;
			}
			
			if(x <= b){
				res2 = (res2 * num2) % 1000000007;
			}
			
			if(x == max){
				finalres = (res1 * res2) % 1000000007;
			}
		}
		
		
		printf("%d\n", finalres);
		
	}
	
	return 0;
}
