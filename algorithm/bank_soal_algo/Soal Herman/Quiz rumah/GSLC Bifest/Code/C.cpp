#include <stdio.h>
#include <stdlib.h>



int main(){
	int testcase;
	long long int number;
	long long int  seven[50] = {7, 77, 78, 777, 778, 787, 788, 7777, 7778, 7787, 7788, 7877, 7878, 7887, 7888, 77777, 77778, 77787, 77788, 77877, 77878, 77887, 77888, 78777, 78778, 78787, 78788, 78877, 78878, 78887, 78888};
	long long int  eight[50] = {8, 87, 88, 877, 878, 887, 888, 8777, 8778, 8787, 8788, 8877, 8878, 8887, 8888, 87777, 87778, 87787, 87788, 87877, 87878, 87887, 87888, 88777, 88778, 88787, 88788, 88877, 88878, 88887, 88888};
	
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){
		scanf("%lld", &number);
		
		for(int x = 0; x < 31; x++){
			if(number % seven[x] == 0 || number % eight[x] == 0){
				int total1 = number % seven[x];
				int total2 = number % eight[x];
				printf("Case #%d: YES\n", loop);
				break;
			} else if(x == 30){
				printf("Case #%d: NO\n", loop);
			}
		}
	}
	return 0;
}
