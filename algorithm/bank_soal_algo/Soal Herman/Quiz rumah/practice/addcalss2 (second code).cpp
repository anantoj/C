#include <stdio.h>
#include <string.h>

int  main(){

//	int a;//penamoung
//	int angka[100];
//	
//	scanf("%d", &a);
//	
//	for(int x = 0; x < a; x++){
//		scanf("%d", &angka[x]);
//	}
////	
////	for(int k = 0; k < a; k++){
////		printf("%d\n", angka[k]);
////	}
//	int max = angka[0], min = angka[0];
//	for(int test = 0; test < a; test++){
//		if(angka[test] > max){
//			max = angka[test];
//		} else if(angka[test] < min){
//			min = angka[test];
//		}
//	}
//	
//	printf("max: %d min: %d", max, min);

//	int twodim[3][5] = {1, 2, 3, 4, 5,
//						10, 20, 30, 40, 50,
//						100, 200, 300, 400, 500};
//	
//	int i, j;
//	
//	for(i = 0; i < 3; i++){
//		for(j = 0; j < 5; j++){
//			printf("%d ", twodim[i][j]);
//		}
//		printf("\n");
//		
//	}
	
	int testcase;
	char name[100];
	char terakhir;
	char pertama;
	scanf("%d", &testcase);
	
	for(int x = 0; x < testcase; x++){
		scanf("%s", name);
		
		if(strlen(name) > 10){
			for(int out = 0; out < strlen(name); out++){
				if(name[out + 1] == '\0'){
					terakhir = name[out];
				} else {
					pertama = name[0];
				}
				
			}
			printf("%c%d%C", pertama, strlen(name) - 2, terakhir);
		}
		
	}
	
	
	
	
	return 0;
}
