#include <stdio.h>

int main(){
	int testcase, people, count;
	int floor[people];
	
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){
		scanf("%d", &people);
		
		count = 0;
		for(int input = 1; input <= people; input++){
			scanf("%d", &floor[input - 1]);
			if(input > 1){
				for(int output = 0; output < input; output++){ //break this loop to go for the next input loop
					if(floor[input - 1] == floor[output]){
						break;
					} else if(floor[input - 1] - floor[output] != 1 && floor[input - 1] - floor[output] != -1){
						input += 1;
						count += 1;
						break;
					} else {
						count += 1;
					}
				}	
			} else if(input == 1){
				count += 1;
			}
			
		}
		printf("Case #%d: %d\n", loop, count);
	}
	
	return 0;
}
