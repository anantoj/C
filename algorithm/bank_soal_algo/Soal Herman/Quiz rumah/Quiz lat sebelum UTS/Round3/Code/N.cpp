#include <stdio.h>
#include <math.h>

int main(){
	int testcase, loop, x, flag, y;
	long long int firstprice, minprice, numbuy, counter;
	double discount, totalpay, divisor;
	
	scanf("%d", &testcase);
	
	for(loop = 1; loop <= testcase; loop++){
		scanf("%lld %lld %lld", &firstprice, &minprice, &numbuy);
		totalpay = firstprice;
		counter = 1;
		flag = 0;
		
		for(x = 1; x < numbuy; x++){ //counting total of bill
			if(flag == 0){
				divisor = pow(2, x);
				discount = (double) firstprice / divisor;
				printf("Discount of %lld / %lld = %lf\n", firstprice, divisor, discount);;
				if(discount <= minprice){
					totalpay +=  minprice;
					flag = 1;
					counter++;
				} else {
					totalpay = totalpay + discount;
					counter++;
				}
			} else if(flag == 1){
				discount = (numbuy - counter) * minprice;
				totalpay += discount;
				break;
			}
		}
		printf("Case #%d: %.3lf\n", loop, totalpay);
	}
	
	return 0;
}
