#include <stdio.h>

int main(){
	int geniusP;
	int answer[150];
	int decider = 0;
	scanf("%d", &geniusP);
	
	for(int x = 0; x < geniusP; x++){
		scanf("%d", &answer[x]);
		if(decider == 0){ //easy or not easy
			if(answer[x] == 1){
				decider = 1;
			}
		}
		
	}
	
	if(decider == 0){
		printf("easy\n");
	} else if(decider == 1){
		printf("not easy\n");
	}
	
	return 0;
}
