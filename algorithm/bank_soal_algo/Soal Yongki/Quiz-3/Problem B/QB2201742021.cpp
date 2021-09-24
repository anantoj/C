#include <stdio.h>

int main(){
	
	int C, i;
	int juming, j;
	int qty_ingneed[100000];
	int qty_ingal[100000];
	long long int total;

	scanf("%d", &C);
	for (i = 0 ; i < C ; i++){
		scanf("%d", &juming);
		for(j = 0 ; j < juming ; j++){
			scanf("%d", &qty_ingneed[j]);
			}
		for(j = 0 ; j < juming ; j++){
			scanf("%d", &qty_ingal[j]);
		}
		total = 0;
		for(j = 0 ; j < juming ; j++){
			if(qty_ingal[j] < qty_ingneed[j]){
				total++;
			}
		}
			if(total >= 1){
				printf("Case #%d: No\n", i+1);
			} else{
				printf("Case #%d: Yes\n", i+1);
			}
	}
	return 0;
}



