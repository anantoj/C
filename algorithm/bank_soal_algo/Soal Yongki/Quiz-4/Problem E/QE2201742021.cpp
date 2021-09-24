#include <stdio.h>

int main(){
		
	int jumtestcase, i;
	int jumroom, j;
	int room[1005];
	int pin, k;
	int left,right;
	int maxx;
	
	scanf("%d",&jumtestcase);
	for(i = 1 ; i <= jumtestcase ; i++){
		scanf("%d",&jumroom);
		for(j = 1 ; j <= jumroom ; j++){
			scanf("%d",&room[j]);
			if(j == 1){
				maxx = room[j];
				pin = 1;
			}	
			if(maxx < room[j]){
				maxx = room[j];
				pin = j;
			}
		}
		left = 0;
		right = 0;
		for(k = 2 ; k <= pin-2 ; k++){
			if(room[k] >= room[k+1] && room[k] >= room[k-1]){ 
				left += room[k];
			}
		}
		for(k = pin+2 ; k <= pin-1 ; k++){
			if(room[k] >= room[k+1] && room[k] >= room[k-1]){ 
				right += room[k];
			}
		}
		if(left > right){
			printf("Case #%d: right\n", i);
		} 
		else if (left<right){
			printf("Case #%d: left\n", i);
		} 
		else {
			printf("Case #%d: same\n", i);
		}
	}
return 0;	
}
