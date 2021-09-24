#include <stdio.h>

int main(){
	int testcase;
	scanf("%d", &testcase);
	
	for(int y = 1; y <= testcase; y++){
		int width, height;
		scanf("%d %d", &height, &width);
		
		printf("Case #%d:\n", y);
		for(int tinggi = 1; tinggi <= height; tinggi++){ //height
			for(int panjang = 1; panjang <= width; panjang++){ //panjang
				if(tinggi == 1 || tinggi == height || panjang == 1 || panjang == width){
					printf("#");
				} else {
					printf(" ");
				}
			}
			printf("\n");
		}
		
	}
	
	
	return 0;
}
