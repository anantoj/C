#include <stdio.h>

int main(){
	int testcase, number, choco, van, straw, choice, max;
	char flavour;
	
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){
		scanf("%d", &number);
		choco = 0, van = 0, straw = 0;
		
		
		for(int x = 1; x <= number; x++){
			scanf(" %c", &flavour);
			if(flavour == 'c'){
				choco += 1;
			} else if(flavour == 'v'){
				van += 1;
			} else if(flavour == 's'){
				straw += 1;
			}
		}
		max = choco;
		if(max < van){
			max = van;
		}
		if(max < straw){
			max = straw;
		}
		
		printf("Case #%d:\n", loop);
		if(choco == max){
			printf("chocolate\n");
		} 
		if(straw == max){
			printf("strawberry\n");
		}
		if(van == max){
			printf("vanilla\n");
		}
		
	}
	
	return 0;
}
