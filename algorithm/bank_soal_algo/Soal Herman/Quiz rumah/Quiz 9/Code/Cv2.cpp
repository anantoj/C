#include <stdio.h>

int gcd(int a, int b){
	if(a == b){
		return a;
	}else if(a < b){
//		printf("a < b\n");
		return gcd(b, a);
	} else if(a > b && b != 0){
//		printf("a > b && b != 0\n");
		return gcd(b, a % b);
	} 	if(b == 0){
//		printf("b == 0\n");
		return a;
	} 
}

int main(){
	int testcase, max;
	int totalNum, number[105];
	int gcdTotal[5000], counter;
	
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){
		counter = 0;
		
		scanf("%d", &totalNum);
		for(int x = 0; x < totalNum; x++){
			scanf("%d", &number[x]);
		}
		
		for(int i = 0; i < totalNum - 1; i++){
			for(int j = i + 1; j < totalNum; j++){
//				printf("GCD %d & %d:", number[i], number[j]);
				gcdTotal[counter] = gcd(number[i], number[j]);
//				printf("%d", gcdTotal[counter]);
//				puts("\n");
				counter++;
			}
		}
		max = gcdTotal[0];
		for(int check = 1; check < counter; check++){
			if(max < gcdTotal[check]){
				max = gcdTotal[check];
			}
		}
		
		printf("Case #%d: %d\n", loop, max);
		
	}
	
	return 0;
}
