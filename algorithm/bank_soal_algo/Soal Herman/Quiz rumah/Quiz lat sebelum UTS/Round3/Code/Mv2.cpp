#include <stdio.h>

int main(){
	int testcase, numberword, total, different, flag;
	int wordlen[105];
	char word[105][105];
	
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){
		scanf("%d", &numberword); getchar();
		total = numberword;
		flag = 0;
		
		//inputing n number of string and 1 last string as the comparison for a known word or no
		for(int x = 0; x <= numberword; x++){ 
			scanf("%d %s", &wordlen[x], word[x]);
		}
		
		for(int i = 0; i < numberword; i++){ //check the word in index i			
			if(wordlen[numberword] == wordlen[i]){
				different = 0;
				for(int j = 0; j < wordlen[i]; j++){ //len of word index i to compare each char of the word
					if(word[numberword][j] != word[i][j]){ //check the typo
						different++;
					}
					if(different > 1){ //if the different char is more than 1, end the loop
						break;
					} else if(j == wordlen[i] - 1){ //if the looping still goes on that mean the difference letter is <= 1 (a typo)
						flag = 1;
					}
				}	
			} 
		}
		if(flag < 1){
				total++;
			}
			
		if(total == numberword){
			printf("Case #%d: yes\n", loop);
		} else if(total > numberword){
			printf("Case #%d: no\n", loop);
		}
	}
	
	return 0;
}
