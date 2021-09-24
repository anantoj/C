#include <stdio.h>

int main(){
	
	int testcase, i, j;
	double ori_price, min_price, amount_buy;
	double total;
	
	scanf("%d", &testcase);
	for( i = 1 ; i <= testcase ; i++){
		scanf("%lf %lf %lf", &ori_price, &min_price, &amount_buy);
		total = 0;
		for(j = 0 ; j < amount_buy ; j++){
			if(ori_price <= min_price){
			total += min_price * (amount_buy - j);
			break;
			}
			total += ori_price;
			ori_price /= 2;
		}
		printf("Case #%d: %.3lf\n", i, total);
	}
	return 0;
}
