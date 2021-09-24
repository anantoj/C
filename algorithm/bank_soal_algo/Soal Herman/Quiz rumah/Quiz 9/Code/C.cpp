#include <stdio.h>

int gcd(int a, int b){
	
	if(a < b){
		return gcd(b, a);
	} else if(a > b && b != 0){
		return gcd(b, a % b);
	} else if(b == 0) {
		return a;
	}
}

int combination(int num[], int temp[], int totalNum, int start, int step, int resTotal){ //r = 2 | resTotal = 0
	int res;
	int gcdRes[5000];
	
	if(step == 2){
		int a = temp[0];
		int b = temp[1];
		return gcd(a,b);
	}
	
	for(int x = 0; x < totalNum && x + (2 - step) < totalNum; x++){
		temp[step] = num[x];
		res = combination(num, temp, totalNum, x + 1, step + 1);
		if(res != 0){
			gcdRes[resTotal] = res;
			resTotal++;
		}
	}
	
}

int main(){
	int testcase;
	int num[105], totalNum;
	int temp[5];
	
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){
		scanf("%d", &totalNum);
		for(int x = 0; x < totalNum; x++){
			scanf("%d", &num[x]);
		}
		
		
		
	}
	
	return 0;
}
