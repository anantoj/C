#include <stdio.h>

int main(){
	
	int jumtestcase, i;
	int know_word, j;
	char word[101][101];
	int length_word[101], k; 
	int amount_alphabet;
	char answer[101];
	int pin = 0;
	int typo = 0;
	
	scanf("%d", &jumtestcase);
	for( i = 1 ; i <= jumtestcase ; i++){
		typo = 0;
		pin = 0;
		scanf("%d", &know_word);
		for( j = 0 ; j < know_word ; j++){
		scanf("%d %s", &length_word[j], word[j]);
		}
		scanf("%d %s", &amount_alphabet, answer);
		for( j = 0 ; j < know_word ; j++){
			if(length_word[j] == amount_alphabet){
		for( k = 0 ; k < length_word[j] ; k++){
			if(word[j][k] != answer[k]){
				typo++;
			}
		}
			if(typo > 1){
				pin++;
				typo = 0;
			}
			}
			else{
				pin++;
			}
	 	}
		printf("Case #%d: ", i);
		if(pin == know_word){
			printf("no\n");
		}else{
			printf("yes\n");
		}
	}
	return 0;
}
