#include<stdio.h>
#include<stdlib.h>

// start = 0, end = 4 -> size = 5
int *subArray(int *arr, int start, int end)
{
	int *result = (int *)malloc(sizeof(int) * (end-start+1));
	int count = 0;
	
	for (int i = start; i <= end; i++) {
		result[count] = arr[i];
		count++;
	}
	
	return result;
}

int *merge(int *left, int lSize, int *right, int rSize)
{
	int *result = (int *)malloc(sizeof(int) * (lSize + rSize));
	int count = 0;
	int lCount = 0, rCount = 0;
	
	while(lCount < lSize && rCount < rSize) {
		if (left[lCount] < right[rCount]) {
			result[count] = left[lCount];
			count++; lCount++;
		} else {
			result[count] = right[rCount];
			count++; rCount++;
		}
	}
	while (lCount < lSize) {
		result[count] = left[lCount];
		count++; lCount++;
	}
	while (rCount < rSize) {
		result[count] = right[rCount];
		count++; rCount++;
	}
	
	return result;
}

int *mergeSort(int *arr, int size)
{
	if (size == 1) return arr;
	// 0..9 -> size = 10, 
	int start = 0;
	int mid = (size / 2) - 1; // 4
	int end = size - 1; // 9
	
	int leftSize = mid - start + 1;
	int rightSize = end - mid;
	
	int *left = subArray(arr, start, mid);
	int *right = subArray(arr, mid+1, end);
	
	left = mergeSort(left, leftSize);
	right = mergeSort(right, rightSize);
	
	return merge(left, leftSize, right, rightSize);
}


int main() {
	int arr[20] = {6, 12, 9, 17, 11, 10, 5, 1, 15, 3};
	
	int *temp = mergeSort(arr, 10);
	
	for (int i = 0; i < 10; i++) {
		printf("%d ", temp[i]);
	}
	
	return 0;
}
