#include <stdio.h>
#include <math.h>

void toString(int res){
	char stringHours[5], stringMin[5];
	int hours = res / 60;
	int min = res % 60;
	
	if(hours < 10){
		sprintf(stringHours, "0%d", hours);
	} else {
		sprintf(stringHours, "%d", hours);
	}
	
	if(min < 10){
		sprintf(stringMin, "0%d", min);
	} else {
		sprintf(stringMin, "%d", min);
	}
	printf("%s:%s\n", stringHours, stringMin);
	
}

int convHours(char hours[]){
	int scheduleHours = 0;
	for(int x = 0; x < 2; x++){
		scheduleHours = scheduleHours * 10 + (hours[x] - 48);
	}
	return scheduleHours;
}

int convMins(char minutes[]){
	int scheduleMin = 0;
	for(int x = 3; x < 5; x++){
		scheduleMin = scheduleMin * 10 + (minutes[x] - 48);
	}
	return scheduleMin;
}

int main(){
	int testcase;
	char classStart[10];
	int velocity, distance;
	int startHours, startMin; //class start schedule
	int hours, min, latestHours, latestMin;
	float minF;
	
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){
		scanf("%d %d %s", &velocity, &distance, classStart);
		
		if(velocity > distance){
			hours = 0;
			min = (distance % velocity) * 60;
			minF = (float) min / velocity;
			min = (int)ceil(minF);
			
		} else {
			hours = distance / velocity;
			min = (distance % velocity) * 60;
			minF = (float) min / velocity;
			min = (int)ceil(minF);
		}
		int totalMin = (hours * 60) + min;
		
		startHours = convHours(classStart);
		startMin = convMins(classStart);
		int tStartMin = startMin + (startHours * 60);
		int res = tStartMin - totalMin;
		if(res < 0){
			res += 1440;
		}		
		
		printf("Case #%d: ", loop);
		toString(res);
		
	}
	
	return 0;
} 
