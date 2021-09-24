#include <stdio.h>
#include <math.h>

int main(){
	int testcase, loop, x;
	long long int buyamount, counter;
	double total, temp, price, minprice;
	
	scanf("%d", &testcase);
	
	for(loop = 1; loop <= testcase; loop++){ //testcase loop
		scanf("%lf %lf %lld", &price, &minprice, &buyamount);
		
		total = price;
		temp = total;
		counter = 1;
		
		for(x = 1; x < buyamount; x++){
			//checking if the discount is greater than the minimum price
			if(temp / 2 >= minprice){
				temp /= 2;
				total += temp;
				counter++;
			} else if(temp / 2 < minprice){
				counter = buyamount - counter;
				total = total + (counter * minprice);
				break;
			}
		}
		printf("Case #%d: %.3lf\n", loop, total);
		
	}
	
	return 0;
}
