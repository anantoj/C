#include <stdio.h>

struct gift{
	char size;
	int color;
};

int main(){
	gift clothes[1005];
	int testcase;
	int totalFriends;
	int totalDis;
	int manySize;
	int sizeS[1005] = {};
	int sizeM[1005] = {};
	int sizeL[1005] = {};
	
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){
		int sizeS[1005] = {};
		int sizeM[1005] = {};
		int sizeL[1005] = {};
		
		scanf("%d", &totalFriends); getchar();
		
		for(int x = 0; x < totalFriends; x++){
			scanf("%c %d", &clothes[x].size, &clothes[x].color); getchar();
			switch(clothes[x].size){
				case 'S':
					sizeS[clothes[x].color - 1] += 1;
				break;
				case 'M':
					sizeM[clothes[x].color - 1] += 1;
				break;
				case 'L':
					sizeL[clothes[x].color - 1] += 1;
				break;
			}
		}
		
//		for(int print = 0; print < 1000; print++){
//			printf("%d\n", sizeS[print]);
//		}
		totalDis = 0;
		for(int count = 0; count < 1000; count++){
			if(sizeS[count] >= 2){
				manySize = sizeS[count] / 2;
				totalDis += (manySize * 10);
			}
			
			if(sizeM[count] >= 2){
				manySize = sizeM[count] / 2;
				totalDis += (manySize * 10);
			}
			
			if(sizeL[count] >= 2){
				manySize = sizeL[count] / 2;
				totalDis += (manySize * 10);
			}
			
		}
		
		printf("Case #%d: %d\n", loop, totalDis);
		
	}
	
	
	return 0;
}
