#include <stdio.h>

int main(){
	int testcase, size;
	scanf("%d", &testcase);
	
	for(int x = 1; x <= testcase; x++){ //testcase loop
		scanf("%d", &size);
		
		for(int height = 0; height < size; height++){ //tinggi
			for(int width = 0; width < size; width++){ //panjang
				if(height == 0 || height == size - 1 || width == 0 || width == size - 1){
					printf("*");
				} else if(height == width || height + 1 == size - width){
					printf("*");
				} else {
					printf(" ");
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	
	return 0;
}
