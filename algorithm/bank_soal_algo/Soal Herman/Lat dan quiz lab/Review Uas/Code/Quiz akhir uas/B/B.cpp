#include <stdio.h>
#include <stdlib.h>

struct data{
	char name[15];
	int money;
};

void swap(data *swp1, data *swp2){
	data temp = *swp1;
	*swp1 = *swp2;
	*swp2 = temp;
}

void bubble(data ppl[], int totalPpl){
	for(int x = 0; x < totalPpl - 1; x++){
		for(int y = x + 1; y < totalPpl; y++){
			if(ppl[y].money > ppl[x].money){
				swap(&ppl[y], &ppl[x]);
			}
		}
	}
}

int main(){
	FILE *file = fopen("testdata.txt", "r");
	int testcase, totalPpl;
	data ppl[105];
	
	fscanf(file, "%d\n", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){
		fscanf(file, "%d\n", &totalPpl);
		for(int x = 0; x < totalPpl; x++){
			fscanf(file, "%s %d\n", &ppl[x].name, &ppl[x].money);
		}
		
		bubble(ppl, totalPpl);
		printf("Case %d:\n", loop);
		for(int i = 0; i < totalPpl; i++){
			printf("%s\n", ppl[i].name);
		}
		
	}
	
	return 0;
}
