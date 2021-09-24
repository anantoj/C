#include <stdio.h>

int main(){
	int repeat;
	int line[15]; //line number
	scanf("%d", &repeat);//testcase
	for(int ask = 0; ask < repeat; ask++){
		scanf("%d", &line[ask] );
	}
	
	for(int testcase = 1; testcase <= repeat; testcase++){ //testcase loop
		printf("Case #%d:\n", testcase);
		
			for(int linenum = 1; linenum <= line[testcase - 1]; linenum++){ //line text loop
			int notPrime = 0; //prime number determinator
			if(linenum > 1){
				for(int checker = 2; checker <= linenum / 2; ++checker){
					if(linenum % checker == 0){
						notPrime = 1;
						break;
					}
				}
				if(notPrime == 0){
					printf("I will become a good boy.\n");
				}
			}
			
		}
	}
	
	return 0;
}
