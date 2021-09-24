#include <stdio.h>

int main(){
	int testcase, numroom, leftenergy, rightenergy, topenergy, left, right;
	int roomenergy[1005];
	
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){ //testcase loop
		scanf("%d", &numroom);
		rightenergy = 0;
		leftenergy = 0;
		left = 0;
		right = numroom - 1;
		topenergy = -1000001;
		
		for(int x = 0; x < numroom; x++){ //taking input
			scanf("%d", &roomenergy[x]);
			if(roomenergy[x] > topenergy){ //to know the boss room
				topenergy = roomenergy[x];
			}
		}
		int flag1 = 0, flag2 = 0;
		do{
			if(flag1 == 0){
				if(roomenergy[left] == topenergy){
					flag1 = 1;
				} else if(roomenergy[left] > roomenergy[left - 1] && roomenergy[left] > roomenergy[left + 1]){
					leftenergy += roomenergy[left];
				}
			}
			if(flag2 == 0){
				if(roomenergy[right] == topenergy){
					flag2 = 1;
				} else if(roomenergy[right] > roomenergy[right - 1] && roomenergy[right] > roomenergy[right + 1]){
					rightenergy += roomenergy[right];
				}
			}
			left++;
			right--;
		}while(flag1 == 0 || flag2 == 0);
		
		if(rightenergy > leftenergy){
			printf("Case #%d: left\n", loop);
		} else if(rightenergy < leftenergy){
			printf("Case #%d: right\n", loop);
		} else {
			printf("Case #%d: same\n", loop);
		}
	}
	return 0;
}
