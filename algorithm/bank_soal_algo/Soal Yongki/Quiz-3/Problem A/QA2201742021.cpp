#include <stdio.h>

int main(){
	
	int C, i;
	int jumflav, j;
	int priceflav[100];
	int qtyflav[100];
	long long int total;
	
	scanf("%d", &C);
	
	for (i = 0 ; i < C ; i++){
		scanf("%d", &jumflav);
		
		for(j = 0 ; j < jumflav ; j++){
			scanf("%d", &priceflav[j]);
			}
		for(j = 0 ; j < jumflav ; j++){
			scanf("%d", &qtyflav[j]);
		}
		total = 0;
		for(j = 0 ; j < jumflav ; j++){
			total += priceflav[j] * qtyflav[j];
		}
		printf("Case #%d: %lld\n", i+1, total);
	}
	return 0;
}
