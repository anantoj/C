#include <stdio.h>

int main(){
	int x = 7;
	
	for(int tinggi = 0; tinggi < x; tinggi++){
		for(int lebar = 0; lebar < x; lebar++){
			
			if(tinggi == 0 ||tinggi == x - 1 || lebar == 0 || lebar == x - 1){
				printf("*");
			} else if(lebar == tinggi || tinggi + 1 == x - lebar){
				printf("*");
			} else {
				printf(" ");
			}
			
		}
		printf("\n");
		
	}
	
	return 0;
}
