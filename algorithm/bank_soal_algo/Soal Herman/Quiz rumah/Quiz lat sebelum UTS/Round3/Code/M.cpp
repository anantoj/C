#include <stdio.h>

int main(){
	int testcase, numword, loop, flag, totalword;
	int wordlen[105];
	char word[105][105];
	
	scanf("%d", &testcase);
	
	for(loop = 1; loop <= testcase; loop++){ //testcase loop
		scanf("%d", &numword);
		
		for(int x = 0; x <= numword; x++){ // the last loop is for the typo check
			scanf("%d %s", &wordlen[x], word[x]);
			printf("%s\n", word[x]);
			if(x == numword){
				int check;
				
				// wordlen[x] because the if statement block executed when the x loop reached it last loop
				for(check = 0; check < numword; check++){
					printf("check ke %d\n", check);
					flag = 0; //to mark how many different char
					
					if(wordlen[x] == wordlen[check]){
						int i = 0;
						while(word[x][i] != '\0'){ //check each char in a string till NULL value
							if(word[x][i] == word[check][i]){
								printf("word x: %c not equal word check: %c\n", word[x][i], word[check][i]);
								flag++;
							}
							if(flag > 1){
								printf("flag > 1\n");
								totalword++;
								break;
							}
							i++;
						}	
					} else {
						printf("word len is not equal\n");
						totalword++;
					}
				}
			}
		}
		printf("%d %d\n", totalword, numword);
		if(totalword == numword){
			printf("Case #%d: yes\n", loop);
		} else {
			printf("Case #%d: no\n", loop);
		}
		
	}
	
	return 0;
}
