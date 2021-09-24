#include <stdio.h>

int main(){
	int testcase, number;
	
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){
		scanf("%d", &number);
		printf("Case #%d:\n", loop);
		for(int x = number; x > 0; x--){
			if(x == number || x == 60 || x == 30 || x == 10 || x == 5){
				printf("%d SECONDS TILL NEW YEAR!!\n", x);
			} else {
				printf("%d\n", x);
			}
		}
		
	}
	
	
	return 0;
}
