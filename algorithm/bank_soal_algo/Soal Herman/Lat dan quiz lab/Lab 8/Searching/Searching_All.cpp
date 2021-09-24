#include<stdio.h>
#include<string.h>

struct data{
	int id, stok;
	char name[20];
}dt[100];

int linear(struct data *dt, int key, int N){
	for(int i=0;i<N;i++){
		if(dt[i].id == key) return i;
	}
	
	return -1;
}

int linear(struct data *dt, char *key, int N){
	for(int i=0;i<N;i++){
		if(strcmp(dt[i].name, key) == 0) return i;
	}
	
	return -1;
}

void swap(struct data *a, struct data *b){
	struct data temp = *a;
	*a = *b;
	*b = temp;
}

void bubble(struct data *dt, int n){
	for(int i=0;i<n;i++){
		for(int j=n-1;j>i;j--){
			//if(dt[j].id < dt[j-1].id) swap(&dt[j], &dt[j-1]);
			if(strcmp(dt[j].name, dt[j-1].name)>0) swap(&dt[j], &dt[j-1]);
		}
	}
}

int binary(struct data *dt, int key, int L, int R){
	int mid;
	
	do{
		mid = (L+R)/2;
		if(dt[mid].id == key) return mid;
		else if(dt[mid].id < key) L = mid+1;
		else if(dt[mid].id > key) R = mid-1;
	}while(L<=R && dt[mid].id != key);
	
	if(dt[mid].id != key) return -1;
}

int interpolation(struct data *dt, int key, int L, int R){
	int mid;
	
	do{
		mid = ((key - dt[L].id) * (R-L) / (dt[R].id - dt[L].id))+L;
		if(dt[mid].id == key) return mid;
		else if(dt[mid].id < key) L = mid+1;
		else if(dt[mid].id > key) R = mid-1;
	}while(L<=R && dt[mid].id != key);
	
	if(dt[mid].id != key) return -1;
}

int main(){
	FILE *f = fopen("testingdata.in", "r");
	
	int N;
	fscanf(f, "%d\n", &N);
	
	for(int i=0;i<N;i++){
		fscanf(f, "%d. %[^#]#%d\n", &dt[i].id, &dt[i].name, &dt[i].stok);
	}
	
	int key;
	//scanf("%d", &key);
	
	char key2[100];
	scanf("%[^\n]", &key2);
	
	int idx = linear(dt, key2, N);
	
	
	//bubble(dt, N);

	//int idx = binary(dt, key, 0, N-1);
	//int idx = interpolation(dt, key, 0, N-1);
	if(idx == -1) printf("Data tidak ada");
	else{
		printf("Data di id %d adalah %s dengan stok %d", dt[idx].id, dt[idx].name, dt[idx].stok);
		/*
		//update data
		scanf("%d", &dt[idx].stok);
		printf("Data baru di id %d adalah %s dengan stok %d", dt[idx].id, dt[idx].name, dt[idx].stok);
		*/
		
		/*
		//delete data
		for(int i=idx;i<N;i++){
			dt[i] = dt[i+1];
		}
		N--;
		*/
	} 
	
	f = fopen("testingdata.out", "w");
	fprintf(f, "%d\n", N);
	for(int i=0;i<N;i++){
		fprintf(f, "%d. %s#%d\n", dt[i].id, dt[i].name, dt[i].stok);
	}
	
	
	return 0;
}
