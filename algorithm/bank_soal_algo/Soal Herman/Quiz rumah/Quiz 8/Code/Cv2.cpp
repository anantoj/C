#include <stdio.h>

int main(){
	int totalNumber, query;
	int number[1005];
	int queryNum[1005];
	int sum;
	int flag;
	
	
	scanf("%d %d", &totalNumber, &query);
	
	for(int inputNum = 0; inputNum < totalNumber; inputNum++ ){
		scanf("%d", &number[inputNum]);
	}
		
	for(int inputQuery = 0; inputQuery < query; inputQuery++){
		scanf("%d", &queryNum[inputQuery]);
		printf("Case #%d: ", inputQuery + 1);
		
		for(int i = 0; i < totalNumber; i++){
			sum = 0;
			flag = 0;
			for(int j = i; j < totalNumber; j++){
				sum += number[j];
				if(sum == queryNum[inputQuery]){
					printf("%d %d\n", i, j);
					flag = 1;
					break;
				} else if(i == totalNumber - 1 && j == totalNumber - 1){
					flag = -1;
				}
			}
			if(flag == 1){
				break;
			} else if(flag == -1){
				printf("-1\n");
			}
		}
	}
	
	
	
	return 0;
}
