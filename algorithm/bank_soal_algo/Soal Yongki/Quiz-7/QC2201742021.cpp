#include <stdio.h>
#include <string.h>

int main(){
	
	int T, i, j;
	int corr_lili;
	char ans_jojo[11000];
	char ans_lili[11000];
	int length, different, same;
	int max_score;
	
	FILE *fptr;
	fptr = fopen("testdata.in", "r");
	
	fscanf(fptr, "%d", &T);
	for(i = 1 ; i <= T ; i++){
		fscanf(fptr, "%d", &corr_lili);
		fscanf(fptr, "%s", &ans_jojo);
		fscanf(fptr, "%s", &ans_lili);
		
		length = strlen(ans_jojo);
		different = 0;
		same = 0;
		
		for(j = 0 ; j < length ; j++){
			if(ans_jojo[j] != ans_lili[j]){
				different++;
			} else{
				same++;
			}
		}
		if(same <= corr_lili){
			max_score = different + same - corr_lili + same;
		} else{
			max_score = different + corr_lili;
		}
		printf("Case #%d: %d\n", i, max_score);
	}
	fclose(fptr);	
	return 0;
}
