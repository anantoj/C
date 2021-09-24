#include <stdio.h>
int main(){
	int player[5][4] = {0}, player_totalscore[5] = {0}, winner = -1, final_point = 0;
	for(int i = 0; i < 5; i++){
		scanf("%d %d %d %d", &player[i][0], &player[i][1], &player[i][2], &player[i][3]);
		player_totalscore[i] = player[i][0] + player[i][1] + player[i][2] + player[i][3];
	}
	
	for(int i = 0; i < 5; i++){
		if(final_point < player_totalscore[i]){
			winner = i+1;
			final_point = player_totalscore[i];
		}
	}
	printf("%d %d\n", winner, final_point);
	
	return 0;
}
