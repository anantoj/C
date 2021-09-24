#include<stdio.h>

int linear(int *arr, int key, int N){
	for(int i=0;i<N;i++){
		if(arr[i] == key) return i;
	}
	
	return -1;
}

int main(){
	int arr[] = {10,50,70,60,20,30,80,40};
	int N = 8;
	
	int key;
	scanf("%d", &key);
	
	int idx = linear(arr, key, N);
	if(idx == -1) printf("Data tidak ada");
	else printf("Data ada di index ke-%d", idx);
	
	return 0;
}
