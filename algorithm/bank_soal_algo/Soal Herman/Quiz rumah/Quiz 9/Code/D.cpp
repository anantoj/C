#include <stdio.h>

int main(){
	int testcase, point;
	int left, right;
	int quadrant[10]; //quadrant;
	int flag;
	
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){
		scanf("%d", &point);
		
		quadrant[0] = quadrant[1] = quadrant[2] = quadrant[3] = 0;
		flag = 0;
		
		for(int x = 0; x < point; x++){
			scanf("%d %d", &left, &right);
			if(left > 0 && right > 0){
				if(quadrant[0] == 0){ //quadrant 1
					flag++;
				}
				quadrant[0]++;
			} else if(left < 0 && right < 0){ //quadrant 3
				if(quadrant[2] == 0){
					flag++;
				}
				quadrant[2]++;
			} else if(left < 0 && right > 0){ //quadrant 2
				if(quadrant[1] == 0){
					flag++;
				}
				quadrant[1]++;
			} else {
				if(quadrant[3] == 0){ //quadrant 4
					flag++;
				}
				quadrant[3]++;
			}
		}
		
		printf("Case #%d:", loop);
		if(flag == 1){
			printf(" YES\n");
		} else if(flag == 2){
			int temp = 0;
			for(int check = 0; check < 4; check++){
				if(temp == 0 && quadrant[check] != 0){
					temp = quadrant[check];
				} else if(temp > 1 && quadrant[check] > 1){ //first found quadrant is > 1, then if the second quadrant found is > 1 too = NO
					printf(" NO\n");
					break;
				} else if(check == 3){
					printf(" YES\n");
				}
			}	
		} else {
			printf(" NO\n");
		}
		
	}
	
	return 0;
}
