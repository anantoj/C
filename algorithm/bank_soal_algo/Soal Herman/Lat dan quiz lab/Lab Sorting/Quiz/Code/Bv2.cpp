#include <stdio.h>

struct data{
	char name[35];
	int flag;
	int age;
};

int main(){
	struct data mhs[105];
	int classmates;
	int queries, check = 0;
	int flag;
	char name[104][35];
	
	scanf("%d", &classmates); getchar();
	
	for(int loop = 0; loop < classmates; loop++){
		scanf("%d %[^\n]", &mhs[loop].age, &mhs[loop].name); getchar();
	}
	
	scanf("%d", &queries); getchar();
	
	for(int x = 0; x < queries; x++){
		scanf("%[^\n]", &name[x]); getchar();
		check++;
	}
	
	for(int y = 0; y < check; y++){ //queries name
		flag = -1;
		for(int z = 0; z < classmates; z++){ //struct name list
			int len = 0;
			while(name[y][len] == mhs[z].name[len]){ //check per char
				if(name[y][len] == NULL){
					flag = z;
				}
				len++;
			}
			
		}
		if(flag != -1){
			printf("%d\n", mhs[flag].age);
		} else {
			printf("-1\n");
		}
	}
	
	return 0;
}
