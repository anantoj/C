#include <stdio.h>

void toString(int minutes, int classMinutes){
	char stringHours[5], stringMin[5];
	
	int latestMin = classMinutes - minutes;
	int latestHours = latestMin / 60;
	latestMin %= 60;
	
	if(latestHours < 10){
		sprintf(stringHours, "0%d", latestHours);
	} else {
		sprintf(stringHours, "%d", latestHours);
	}
	
	if(latestMin < 10){
		sprintf(stringMin, "0%d", latestMin);
	} else {
		sprintf(stringMin, "%d", latestMin);
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
	int velocity, distance; //speed / hours
	int hours, minutes;
	int classHours, classMin; //class schedule time
	char classTime[10];
	
	scanf("%d", &testcase); getchar();
	
	for(int loop = 1; loop <= testcase; loop++){
		scanf("%d %d %s", &velocity, &distance, classTime); getchar();
		puts("section 1");
		if(velocity > distance){
			hours = 0;
			minutes = (distance % velocity) * 60 / velocity;
		} else {
			hours = distance / velocity;
			printf("%d\n", hours);
			minutes = ((distance % velocity) * 60 / velocity) + (hours * 60);
			printf("%d\n", minutes);
		}
		
		puts("section 2");
		classHours = convHours(classTime);
		puts("---------------");
		classMin = convMins(classTime) + (classHours * 60);
		puts("section 3");
		
		printf("Case #%d: ", loop);
		toString(minutes, classMin);
		
	}
	
	return 0;
}
