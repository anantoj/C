#include<stdio.h>

int main(){
	int loop; //looping
	int year[150]; 
	
	scanf("%d", &loop);
	
	
	for(int y = 0; y < loop; y++){
		scanf("%d", &year[y]);
		int leapY = 0;
		leapY = leapY + (year[y] / 4) - (year[y] / 100 - year[y] / 400);
		
//		if(year[y] > 4){
//				leapY = leapY + (year[y] / 4);
//			if(year[y] / 100 >= 1){ //menghitung berapa kali 100 tahun
//				leapY = leapY - (year[y] / 100);
//			}
//			if(year[y] / 400 >= 1){
//				leapY = leapY + (year[y] / 400);
//			}
//		}
		printf("Case #%d: %d\n", y + 1, leapY);
	}

	return 0;
}
