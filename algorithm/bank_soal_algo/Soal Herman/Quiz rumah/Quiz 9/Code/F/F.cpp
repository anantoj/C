#include <stdio.h>

void reset(int letter[]){
	for(int x = 0; x < 130; x++){
		letter[x] = 0;
	}
	return;
}

int main(){
	int testcase;
	int letter[130];
	char word[1005];
	char temp;
	int ascii, counter;
	FILE *file = fopen("testdata.in", "r");
	
	fscanf(file, "%d", &testcase); 
	
	for(int loop = 1; loop <= testcase; loop++){
		counter = 0;
		reset(letter);
		
		fscanf(file, " %[^\n]", word);
		
		while(word[counter] != NULL){
			temp = word[counter];
			letter[temp] += 1;
			counter++;
		}
		
		for(int check = 65; check <= 90; check++ ){
			letter[check] += letter[check + 32];
		}
		
		counter = 1;
		int letterPrint = 65;
		printf("Case #%d:\n", loop);
		while(counter <= 26){
			printf("%c : %d", letterPrint, letter[64 + counter]);
			if(counter % 5 != 0 && counter != 26){
				printf(", ");
			}
			
			if (counter % 5 == 0){
				printf("\n");
			}
			
			counter++;
			letterPrint++;
		}
		printf("\n\n");
		
	}
	
	fclose(file);
	
	return 0;
}
