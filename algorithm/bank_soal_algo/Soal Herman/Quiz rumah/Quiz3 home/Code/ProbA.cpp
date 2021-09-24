#include <stdio.h>

int main(){
	int testcase, press, people, floor[people], pressed[people];
	scanf("%d", &testcase);
	
	for(int x = 0; x < testcase; x++){ //testcase
		scanf("%d", &people);
		press = 0;
		for(int input = 0; input < people; input++){ //floor input
			scanf("%d", &floor[input]);
			
		}
		
		for(int check = 0; check < people; check++){ //floor check
			if(floor[check] - floor[check + 1] == 1 || floor[check] - floor[check + 1] == -1){
				for(int a = 0; a < people; a++){
					if(floor[check] != pressed[a]){
						pressed[check] = floor[check];
						press += 1;
						check += 1;
						break;
					}
				}
			} else {
				for(int a = 0; a < people; a++){
					if(floor[check] != pressed[a]){
						pressed[check] = floor[check];
						press += 1;
						break;
					}
				}
			}
		}
		printf("Case #%d: %d\n",x + 1, press);
	}
	return 0;
}
