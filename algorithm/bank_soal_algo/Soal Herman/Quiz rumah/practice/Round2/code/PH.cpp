#include <stdio.h>

int main(){
	int testcase, allnum, number[allnum];;
	int odd, even;
	scanf("%d", &testcase);
	
	for(int x = 0; x < testcase; x++){
		scanf("%d", &allnum);
		odd = 0, even = 0;
		for(int y = 0; y < allnum; y++){ //number group
			scanf("%d", &number[y]);
			if(number[y] % 2 == 0){
				even += 1;
			} else if(number[y] % 2 != 0){
				odd += 1;
			}
		}
		printf("Odd group : %d integer(s).\n", odd);
		printf("Even group : %d integer(s).\n\n", even);
		
	}
	x
	return 0;
}
