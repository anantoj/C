#include <stdio.h>

int main(){
	int loop; //test case
	char op[10];//operator
	char temp;
	scanf("%d", &loop);
	
	for(int repeat = 1; repeat <= loop; repeat++){ //testcase repeat
		scanf("%s %s %s", &op[0], &op[1], &op[2]);
		for(int x = 0; x < 3; x++){ 
			for(int checker = 0; checker < 3; checker++){ //sorting 1 elements
		 		if(op[0] > op[1] ){
		 			temp = op[0];
		 			op[0] = op[1];
		 			op[1] = temp;
				} 
				if(op[1] > op[2]){
					temp = op[1];
		 			op[1] = op[2];
		 			op[2] = temp;
				}
			 
			}
		}
		printf("Case #%d: %c %c %c\n", repeat, op[0], op[1], op[2]);
//		printf("%s", op);
	}
		
	return 0;
}
