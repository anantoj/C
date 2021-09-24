#include <stdio.h>

int main(){
	
	int jumtestcase, i;
	int jumroom, k;
	long long int room[1001];
	long long int boss = -1000001;
	int boss_coor = 0;
	long long int left = 0;
	long long int right = 0;
	
	scanf("%d", &jumtestcase);
	for(i = 0; i < jumtestcase; i++){
		scanf("%d", &jumroom);
		for (int j = 0 ; j < jumroom ; j++){
			scanf("%lld", &room[j]);
			if(room[j] > boss){
				boss = room[j];
				boss_coor = j;
			}
		}
		printf("Case #%d: ", i+1);
		if(boss_coor == 0) printf("left");
		else if (boss_coor == jumroom - 1) printf("right");
		else{
			for(int j = 1 ; j < jumroom - 1 ; j++){
				if (j == boss_coor) break;
				if (room[j-1] < room[j] && room[j+1] < room[j]) left += room[j];
			}
			for(int j = jumroom - 2 ; j > 1 ; j--){
				if(j == boss_coor) break;
				if (room[j-1] < room[j] && room[j+1] < room[j]) right += room[j];
			}	
			if(left < right) printf("left");
			else if(left == right) printf("same");
			else printf("right");
		}
		puts("");
	}
	return 0;
}
