#include <stdio.h>

int findGood(char word[], char pat[], int pos, int n){
	if(pat[n] == NULL){
		return 1;
	}
	
	if(word[pos] == pat[n] || word[pos] + 32 == pat[n]){
		findGood(word, pat, pos + 1, n + 1);
	} else {
		return 0;
	}
	
}

int main(){
	int testcase, boolean;
	int pos;
	char word[100], pat[10] = "good";
	
	
	scanf("%d", &testcase); getchar();
	for(int x = 1; x <= testcase; x++){
		boolean = 0;
		
		scanf("%[^\n]", word); getchar();
		pos = 0;
		while(word[pos] != NULL){
			if(word[pos] == 'G' || word[pos] == 'g'){
				boolean = findGood(word, pat, pos, 0);
				if(boolean == 1){
					break;
				}
			}
			pos++;
		}
		
		if(boolean == 0){
			printf("Case #%d: no\n", x);
		} else {
			printf("Case #%d: yes\n", x);
		}
		
	}
	
	return 0;
}
