#include <stdio.h>
#include <stdlib.h>

void print(char word[], int idx){
	if(word[idx] != NULL){
		print(word, idx + 1);
		printf("%c", word[idx]);
	}
	return;
}

int main(){
	char word[10000];
	FILE *file = fopen("testdata2.txt", "r");
	while(!feof(file)){
		fscanf(file, "%[^\n]\n", word);
		print(word, 0);
		printf("\n");
	}
	
	fclose(file);
	
	return 0;
}

