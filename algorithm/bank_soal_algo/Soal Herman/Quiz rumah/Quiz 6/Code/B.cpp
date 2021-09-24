#include <stdio.h>

void encription(int number, char *code){
	int x = 0;
	int letterNum;
	
	while(code[x] != '\0'){
		if(code[x] >= 65 && code[x] <= 90){
			letterNum = code[x];
			letterNum += number;
			
			while(letterNum > 90){
				letterNum -= 26;
			}
			
			code[x] = letterNum;
			
		} else if(code[x] >= 97 && code[x] <= 122){
			letterNum = code[x];
			letterNum += number;
			while(letterNum > 122){
				letterNum -= 26;
			}
			code[x] = letterNum;
		} else {
			code[x] = code[x];
		}
		x++;
	}
}

int main(){
	int testcase, skipNum;
	char code[1005];
	
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){
		scanf("%d", &skipNum); getchar();
		scanf("%[^\n]", code); 
		
		encription(skipNum, code);
		
		printf("Case #%d: %s\n", loop, code);
		
		
		
	}
	
	return 0;
}
