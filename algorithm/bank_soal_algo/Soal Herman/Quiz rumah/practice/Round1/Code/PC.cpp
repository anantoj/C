#include <stdio.h>

int main(){
	int testcase;
	scanf("%d", &testcase);
	
	for(int x = 0; x < testcase; x++){ //testcase loop
		long int jojo = 0, lili = 0;
		int size = 0;
		scanf("%d", &size);
		long int array[size];
		
		for(int y = 0; y < size; y++){
			scanf("%ld" , &array[y]);
			
			if(y % 2 == 0 && array[y] % 2 == 0){
				jojo += array[y];
			} else if( y % 2 != 0 && array[y] % 2 != 0){
				lili += array[y];
			}
		}
		
		if(jojo % 2 == 0 &&  lili % 2 == 0){
			printf("Case #%d: :)\n", x + 1);
		} else if(jojo % 2 != 0 && lili % 2 != 0){
			printf("Case #%d: :(\n", x + 1);
		} else {
			printf("Case #%d: :|\n", x + 1);
		}
		
	}
	
	return 0;
}
