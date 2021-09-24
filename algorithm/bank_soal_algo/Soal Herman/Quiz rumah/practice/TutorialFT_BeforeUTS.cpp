#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main(){
	
	
	//soal 1 virus
	// 1 virus membelah diri menjadi 2
	int n,x;
	long long int t;
	scanf("%d",&n); //testcase
	
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		t=1;
		for(int j=0;j<x;j++){
			t=t*2;
		}
		printf("Case #%d: %lld\n",i+1,t);
	}
	


	/*
	//soal 2 fibo
	int n,value[100001];
	scanf("%d",&n);
	value[0]=0;
	value[1]=1;
	for(int i=2;i<=n;i++){
		value[i]=value[i-1]+value[i-2];
	}
	printf("%d",value[n]);
	//value[sekarang] = value[sekarang-1] + value[sekarang-2]
	*/
	
	/*
	//soal 3 max number
	int n,x,max=-60,min=60;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(max<x)
			max=x;
			
		if(min>x)
			min=x;
		
	}
	
	printf("Max:%d\nMin:%d\n",max,min);
	*/
	
	/*
	//soal 4 kelipatan angka
	for(int i=0;i<10;i+=2){
		printf("%d ",i+2);
	}
	*/
	
	/*
	//soal 5 rotate karakter
	//0123456789 10 11 12 13 14 15
	//Binus Univ e  r  s  i  t  y
	//iBun snUvireisyt
	char kata[100],temp,flag[100];
	scanf("%[^\n]",&kata);
	//printf("%d",strlen(kata));
	
	for(int i=0;i<strlen(kata);i+=2){
		temp=kata[i];
		kata[i]=kata[i+1];
		kata[i+1]=temp;
	}
	printf("%s\n",kata);
	
	int x=0;
	for(int i=strlen(kata)-1;i>=0;i--){
		flag[x]=kata[i];
		x++;
	}
	flag[strlen(kata)]='\0';
	strcpy(kata,flag);
	printf("%s\n",kata);
	*/
	
	/*
	//soal 6 initial name
	char nama[100],initial[3];
	scanf("%[^\n]",&nama);
	initial[0]=nama[0];
	initial[2]='\0';
	
	for(int i=1;i<strlen(nama);i++){
		if(nama[i]==' '){
			initial[1]=nama[i+1];
		}
	}
	printf("%s",initial);
	*/
	
	/*
	//soal 7 generate email
	int temp,spasi_kedua;
	char nama[100],email[100];
	scanf("%[^\n]",&nama);
	//Fidelson Tanzil
	//fiTanzil@binus.edu
	email[0]=nama[0];
	email[1]=nama[1];
	//spasi pertama
	for(int i=2;i<strlen(nama);i++){
		if(nama[i]==' '){
			temp=i+1;
			break;
		}
	}
	
	//spasi kedua
	for(int i=temp;i<strlen(nama);i++){
		if(nama[i]==' '){
			spasi_kedua=i;
			break;
		}
	}
	
	int x=2;
	for(int i=temp;i<spasi_kedua;i++){
		email[x]=nama[i];
		x++;
	}
	email[x]='\0';
	
	for(int i=0;i<strlen(email);i++){
			email[i]=tolower(email[i]); //tolower buat huruf kecil
	}
	strcat(email,"@binus.edu"); //buat append binus.edu ke email
	printf("%s",email);
	*/
	
	/*
	//soal 8 array
	int n,value[100],index_arr[100];
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		scanf("%d",&index_arr[i]);
	}
	
	for(int i=0;i<n;i++){
		scanf("%d",&value[index_arr[i]]);
	}
	
	for(int i=0;i<n;i++){
		printf("%d ",value[i]);	
	}
	*/
	
	//soal 9 door
//	bool pintu[4]={false};
//	int x;
//	while(1){
//		for(int i=0;i<4;i++){
//			if(pintu[i]==false)
//				printf(" x ");
//			else
//				printf(" v ");
//		}
//		printf("\n>>");
//		scanf("%d",&x);getchar();
//		
//		if(x==0){
//			break;
//		}	
//		
//		//;=={}
//		if(pintu[x-1]==false)
//			pintu[x-1]=true;
//		
//		else{
//			pintu[x-1]=false;
//		}
//		
//		
//	}
	
	return 0;
}
