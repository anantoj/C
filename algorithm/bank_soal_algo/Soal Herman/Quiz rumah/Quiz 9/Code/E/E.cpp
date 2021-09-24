#include <stdio.h>
#include <stdlib.h>

int sqrRoot(int num){
	if(num == 1){
		return 1;
	}
	
	int floorRoot = 2, res = 4;
	while(res <= num){
		floorRoot++;
		res = floorRoot * floorRoot;
		
	}
	return floorRoot - 1;
}

int main(){
	FILE *file = fopen("testdata.in", "r");
	char check;
	int num, counter = 0;
	int arr[1005];
	long long int sum = 0, idx = 0;
	
	while(!feof(file)){
		fscanf(file, "%d ", &arr[idx]); 
//		printf("%d\n", arr[idx]);
		if(check == '\n'){
			break;
		}
		
		int root = sqrRoot(arr[idx]);
		
		if(root * root == arr[idx]){
//			printf("NUM %d root is %d\n", num, root);
			sum -= arr[idx];
		} else {
			sum += arr[idx];
		}
		counter++;
		idx++;
	}
	
//	for(int y = 0; y < idx; y++){
//		printf("%d\n", arr[y]);
//	}
//	
	printf("Special sum of %d datas is %lld.\n", counter, sum);
	
	fclose(file);
	
	return 0;
}
