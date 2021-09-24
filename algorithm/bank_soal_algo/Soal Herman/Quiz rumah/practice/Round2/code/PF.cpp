#include <stdio.h>

int main(){
	int testcase, match;
	char result[120];
	scanf("%d\n", &testcase);
	
	for(int x = 0; x < testcase; x++){
		int lili = 0, bibi = 0;
		scanf("%d %s", &match, result);
		
		for(int y = 0; y < match; y++){ //win lose 
			if(result[y] == 'L'){
				lili += 1;
			} else if(result[y] == 'B'){
				bibi += 1;
			} else if(result[y] == 'T'){
				lili += 1;
				bibi += 1;
			}
		}
		if(lili > bibi){
			printf("Lili\n");
		} else if(lili < bibi){
			printf("Bibi\n");
		} else {
			printf("None\n");
		}
	}
	
	return 0;
}
