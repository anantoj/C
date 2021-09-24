#include <stdio.h>

int main(){
	int testcase = 0, people = 0, count, total;
	int number[100], press[100];
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){ //testcase loop
		scanf("%d", &people);
		count = 0;
		total = 0;
		
		for(int x = 0; x < people; x++){ // taking input
			scanf("%d", &number[x]);
			count += 1;
			
			if(x == 0)	{ //check floor
				press[x] = number[x];	//index 0 terisi, count = 1
				total += 1;
			} else if(x > 0){
				for(int y = 0; y < count - 1; y++){ //count mulai dari 2 dan x = 1
					if((number[x] - press[y] != 1 && number[x] - press[y] != -1) && (number[x] != press[y])){//cek semua angka belakang
						if(y == count - 2){
							press[x] = number[x];
							total += 1;
						}
					} else if((number[x] - press[y] == 1 || number[x] - press[y] == -1) || number[x] == press[y]){
						break;
					}
				}
				
			}
		}
		printf("Case #%d: %d\n", loop, total);
	}

	return 0;
}
