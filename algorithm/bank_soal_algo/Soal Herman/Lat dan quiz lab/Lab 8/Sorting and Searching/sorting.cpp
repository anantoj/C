#include<stdio.h>

int n = 0;
void print(int *arr){
	for(int i=0;i<n;i++){
		printf("%d\n", arr[i]);
	}
	printf("\n");
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble(int *arr){
	for(int i=0;i<n;i++){
		for(int j=n-1;j>i;j--){
			if(arr[j] < arr[j-1]) swap(&arr[j], &arr[j-1]);
		}
	}
}

void selection(int *arr){
	
	for(int i = 0; i < n; i++) {
		int index = i;
		
		for (int j = i+1; j < n; j++) {
			if (arr[j] < arr[index]) {
				index = j;
			}
		}
		swap(&arr[index], &arr[i]);
	}
	print(arr);
}

void insertion(int *arr){
	for(int i=1;i<n;i++){
		int temp = arr[i];
		for(int j=i-1;j>=0 && temp<arr[j];j--){
			arr[j+1] = arr[j];
			arr[j] = temp;
		}
	}
	print(arr);
}

void quick(int *arr, int L, int R){
	if(L<R){
		int j = L;
		int k = R+1;
		
		do{
			do{
				j++;
			}while(arr[j]<arr[L]);
			
			do{
				k--;
			}while(arr[k]>arr[L]);
			
			if(j<k) swap(&arr[j], &arr[k]);
		}while(j<k);
		
		swap(&arr[L], &arr[k]);
		quick(arr, L, k-1);
		quick(arr, k+1, R);
	}
}

void merging(int *arr, int L, int mid, int R){
	int i = L;
	int j = mid+1;
	int k = 0;
	
	int temp [100000];
	
	while(i<=mid && j<=R){
		if(arr[i]<arr[j]){
			temp[k] = arr[i];
			k++;
			i++;
		}else{
			temp[k] = arr[j];
			k++;
			j++;
		}
	}
	
	while(i<=mid){
		temp[k] = arr[i];
		k++;
		i++;
	}
	
	while(j<=R){
		temp[k] = arr[j];
		k++;
		j++;
	}
	
	for(i = L, j = 0; i<=R; i++, j++){
		arr[i] = temp[j];
	}
}

void merge(int *arr, int L, int R){
	int mid;
	
	if(L < R){
		mid = (L+R)/2;
		merge(arr, L, mid);
		merge(arr, mid+1, R);
		merging(arr, L, mid, R);
	}
}

int main(){
	int arr[100000];
	
	FILE *f = fopen("data.in", "r");
	
	while(!feof(f)){
		fscanf(f, "%d\n", &arr[n]);
		n++;
	}
	
	//print(arr);
	//bubble(arr);
	//selection(arr);
	//insertion(arr);
	//quick(arr,0,n-1);
	//merge(arr, 0, n-1);
	print(arr);
	
	return 0;
}
