#include <stdio.h>

struct student{
	int id;
	int day, month, year;
	char name[15], address[15];
};

int main(){
	struct student detail[1000];
	int totalStu; //total student
	int counter = 0;
	int totalQuery, numQuery[105]; //numQuery -> query ke berapa
	
	scanf("%d", &totalStu);
	for(int loop = 0; loop < totalStu; loop++){
		scanf("%d %d %d %d %s %s", &detail[loop].id, &detail[loop].day, &detail[loop].month, &detail[loop].year, detail[loop].name, detail[loop].address ); 
//		printf("%d %d %d %d %s %s\n", detail[loop].id, detail[loop].day, detail[loop].month, detail[loop].year, detail[loop].name, detail[loop].address );
	}
	scanf("%d", &totalQuery); //input the data id to be searched
	for(int x = 0; x < totalQuery; x++){
		scanf("%d", &numQuery[x]);
		counter++;
	}
	
	//find id that match the query input
	for(int output = 0; output < counter; output++){
		for(int check = 0; check < totalStu; check++){
			if(numQuery[output] == detail[check].id){
				printf("%d. %s was born on %d/%d/%d and live at %s\n", detail[check].id, detail[check].name, detail[check].day, detail[check].month, detail[check].year, detail[check].address);
				break;
			} else if(check == totalStu - 1){
				printf("No data found!\n");
			}
		}
	}
	
	return 0;
}
