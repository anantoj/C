#include <stdio.h>

struct Mid{
	char name[110];
	int score;
};

int main(){
	
	int t, i, j, k;
	int amount, flag;
	int lili_score;
	
	scanf("%d", &t);
	for(i = 1 ; i <= t ; i++){
		scanf("%d", &amount);
		struct Mid fr_score[amount+5];
		for(j = 0 ; j < amount ; j++){
			scanf("%s %d", &fr_score[j].name, &fr_score[j].score);
		}
		flag = 0;
		scanf("%d", &lili_score);
		printf("Case #%d:\n", i);
		for(k = 0 ; k < amount ; k++){
			if(lili_score < fr_score[k].score){
				printf("%s\n", fr_score[k].name);
				flag++;
			}
		}
		if(flag == 0){
			printf("No one\n");
		}
	}	
	return 0;
}
