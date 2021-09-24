#include <stdio.h>

int count(int price[], int queue, int mid){
	int sum = 1;
	int counter = 1;
	
	while(price[mid + counter] == queue){
		sum++;
		counter++;
	}
	
	counter = 1;
	while(price[mid - counter] == queue){
		sum++;
		counter++;
	}
	return sum;
}

int binarySearch(int price[], int queue, int start, int end){
	if(start <= end){
		int mid = (start + end) / 2;
		if(queue == price[start]){
			return count(price, queue, start);
		} else if(queue == price[end]){
			return count(price, queue, end);
		} else if(queue == price[mid]){
			return count(price, queue, mid);
		} else {
			if(queue > price[mid]){
				return binarySearch(price, queue, mid + 1, end);
			} else if(queue < price[mid]){
				return binarySearch(price, queue, start, mid - 1);
			}
		}
	}
	return 0;
}

int main(){
	int food, question, queue[100005];
	int price[100005];
	
	for(int set = 0; set < 100005; set++){
		price[set] = 0;
	}
	
	scanf("%d %d", &food, &question);
	
	for(int x = 0; x < food; x++){
		scanf("%d", &price[x]);
	}
	
	for(int y = 0; y < question; y++){
		scanf("%d", &queue[y]);
		printf("%d\n", binarySearch(price, queue[y], 0, food - 1));
	}
	
	return 0;
}
