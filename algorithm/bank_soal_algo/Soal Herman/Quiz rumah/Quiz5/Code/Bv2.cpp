#include <stdio.h>
#include <string.h>

long long int power(int index){
	long long int res = 1;
	for(int x = 1; x <= index; x++){
		res = res * 2;
	}
	return res;
}


int main(){
	int testcase, counter, urutan, binner[35];
	long long int res;
	char number[200];
	
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){
		urutan = 0;
		res = 0;
		scanf("%s", number);
		
		int len = strlen(number);
		counter = 0;
		for(int x = 0; x < len; x++){
			if(number[x] == '1'){
				binner[counter] = 1;
				counter++;
			} else if(number[x] == '-'){
				binner[counter] = -1;
				counter++;
				x++;
			} else if(number[x] == '0'){
				binner[counter] = 0;
				counter++;
			}
		}
		
		counter -= 1;
		for(int out = counter; out >= 0; out--){
			if(out == counter && binner[out] == 1){
				res = 1;
				urutan++;
			} else if(out == counter && binner[out] == -1){
				res = -1;
				urutan++;
			} else if(binner[out] == 1){
				res = res + power(urutan);
				urutan++;
			} else if(binner[out] == -1){
				res = res - power(urutan);
				urutan++;
			} else {
				urutan++;
			}
		}
		
		printf("Case #%d: %lld\n", loop, res);
		
	}
	
	return 0;
}
