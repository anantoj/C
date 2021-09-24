#include <stdio.h>
#include <string.h>

long long int power(int number){
	long long int res;
	for(int a = number - 1; a >= 0;){
		res = 1;
		if(number % 10 == 0){
			res *= 1024;
			a -= 10;
		} else  {
			res *= 2;
			a--;
		}
	}
	return res;
}

int main(){
	int testcase, len, binner[100], counter;
	long long int res, temp;
	char input[200];
	
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){
		counter = 0;
		res = 0;
		scanf("%s", input);
		len = strlen(input);
		
		for(int x = len - 1; x >= 0; x--){
			if(input[x] == '1'){
				binner[counter] = 1;
				counter++;
			} else if(input[x] == '0'){
				binner[counter] = 0;
				counter++;
			} else if(input[x] == '-'){
				binner[counter] = -1;
				x += 1;
				counter++;
			}
		}
		for(int y = 0; y < counter; y++){
			if(y == 0 && binner[y] == 1){
				res += 1;
			}else if(y == 0 && binner[y] == -1){
				res -= 1;
			} else if(binner[y] == 1){
				res = res + power(y);
			} else if(binner[y] == -1){
				res = res + power(y);
			}
		}
		printf("Case #%d: %d\n", loop, res);
	}
	
	return 0;
}
