#include <stdio.h>

int main(){
	int c, i;
	int a, ans = 1;
	int j;
	int b[100], k;
	bool arr[100001];
	int x;
	
	scanf("%d", &c);
	
	for (i = 1 ; i <= c ; i++){
		scanf("%lld %d", &a, &b);
		for (j = 0 ; j < a ; j++){
			scanf("%d", &x);
			arr[x] = true;
		}
		ans = 1;
		for (k = 1 ; k <= b ; k++){
			if (arr[k] == false){
				ans = k;
				break;
			}else{
			arr[k] = false;
			}
		}
		printf("Case #%d: %lld\n", i, ans);
	}
	
	return 0;
}
