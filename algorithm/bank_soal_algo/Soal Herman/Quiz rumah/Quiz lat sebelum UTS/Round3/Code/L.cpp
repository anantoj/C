#include <stdio.h>

int main(){
	int testcase, len, loop, input, flag, wordlen;
	char letter, word[210];
	
	scanf("%d", &testcase);
	
	for(loop = 1; loop <= testcase; loop++){ //testcase loop
		scanf("%d", &len); getchar();
		wordlen = 0;
		flag = 0;
		
		for(input = 0; input < len; input++){ //space key filter
			scanf("%c", &letter);
			if(letter == ' '){
				flag++;
			}
			if(flag == 0){
				word[wordlen] = letter;
				wordlen++;
			} else if(flag == 2){
				flag = 0;
				word[wordlen] = ' ';
				wordlen++;
			}
		}
		for(int x = 0; x < wordlen; x++){
			if(x == 0){
				printf("Case #%d: ", loop);
			}
			printf("%c", word[x]);
		}
		printf("\n");
	}
	
	return 0;
}
