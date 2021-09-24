#include <stdio.h>
int array[100001];
int binarySearch(int left, int right, int match){
	if(left <= right){
		int mid = (left + right)/2;
		if(array[mid] == match){
			return 1;
		} else if(array[left] == match){
			return 1;
		} else if(array[right] == match){
			return 1;
		} else{
			if(array[mid] < match){
				left = mid+1;
			} else if(array[mid] > match){
				right = mid-1;
			} 
			return binarySearch(left, right, match);
		}
	} else{
		return 0;
	}
}

int main(){
	int input, query, match, found = 0;
	scanf("%d %d", &input, &query); getchar();

	for(int i = 0; i < input; i++){
		scanf("%d", &array[i]);
	}
	
	for(int i = 0; i < query; i++){
		scanf("%d", &match);
		found += binarySearch(0, input-1, match);
	} 
	printf("%d\n", found);
	
	return 0;
}  
