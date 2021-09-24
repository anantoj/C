#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int testcase;
	int len;
	char word[1005];
	scanf("%d", &testcase); getchar();
	char alphabet[200];
	
	FILE *file = fopen("testdata.in", "w");
	for(int loop = 1; loop <= testcase; loop++){ //testcase
		scanf("%[^\n]", word); getchar();
		fprintf(file, "%s\n", word);
	}
	fclose(file);
	
	file = fopen("testdata.in", "r");
	for(int x = 0; x < testcase; x++){
		fscanf(file, "%[\n]", word);
		len = strlen(word);
		for(int y = 0; y < len; y++){
			int pos = word[y]
			if(pos >= 65 && pos <= 90 || pos >= 97 && pos <= 122){
				alphabet[]
			}
		}
		
		
	}
	
	return 0;
}
