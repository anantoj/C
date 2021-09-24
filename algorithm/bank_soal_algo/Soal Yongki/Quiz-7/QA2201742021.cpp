#include <stdio.h>

int main(){
	
	int t, i, j, k;
	
	scanf("%d", &t);
	for(i = 1 ; i <= t ; i++){
		int amount;
		scanf("%d", &amount);
		int start[amount+5];
		int end[amount+5];
		for(j = 0 ; j < amount ; j++){
			scanf("%d %d", &start[j], &end[j]);
		}
		
		int flag = 1;
		
		for(k = 1 ; k < amount ; k++){
			if(start[k] < end[k-1]){
				flag++;
				break;
			}
		}
		printf("Case #%d: ", i);
		if(flag >= 2){
			printf("NO\n");
		} else{
			printf("YES\n");
		}
	}
	return 0;	
}
