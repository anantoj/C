#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
//  int nilai[5],i;
//  for (i=0;i<5;i++)
//  {  printf("Masukan nilai mahasiswa %d : ", i+1);
//	 scanf("%d",&nilai[i]);
//  }
//
//  for (i=0;i<5;i++)
//  {  printf("Nilai mahasiswa %d : %d \n", i+1,nilai[i]);
//	 printf("alamat : %x\n",&nilai[i]);
//  }
//
//  printf("alamat i : %x\n",&i);
//
// //input nilai jumlah berdasarkan yang diminta user
//  int nilai[100],i, j, total = 0, max=0, min=101;
//  scanf("%d",&j);
//  for (i=0;i<j;i++)
//  {     do{
//			printf("Masukan nilai mahasiswa %d : ", i+1);
//	 		scanf("%d",&nilai[i]);
//		}while(nilai[i]<0 || nilai[i]>100);
//	 	if(nilai[i]>max){
//			max=nilai[i];}
//	 	if(min>nilai[i]){
//			min=nilai[i];}
//  }
//
//  for (i=0;i<j;i++)
//  {  printf("Nilai mahasiswa %d : %d \n", i+1,nilai[i]);
//    total += nilai[i];
//  }
//
//  	printf("Total : %d\n",total);
//  	printf("Rata rata : %d\n",total/j);
//  	printf("Maximum: %d\n", max);
//	printf("Minimum : %d \n", min);

// LATIHAN : string manipulation
// a. hitung jumlah huruf
// b. masukkan kata dan tampilkan secara terbalik
// c. mencari huruf tertentu dalam kata yan dimasukkan
//

int i,j,matrix1[3][3];

for(i=0;i<3;i++)
{   for(j=0;j<3;j++)
	{
	printf("data [%d][%d] : ",i+1,j+1);
	scanf("%d",&matrix1[i][j]);
	}
}

for(i=0;i<3;i++)
{   for(j=0;j<3;j++)
	{
	printf("%d ",matrix1[i][j]);
	}
	printf("\n");
}

// LATIHAN1 :
// Hitung jumlah dan average seluruh nilai yang dimasukkan
// Cari nilai max dan min

// LATIHAN2 :
// Buat array bilangan prima dari data matrix
// Syarat data yang sama tidak boleh berulang
// Contoh : 3 17 5 (bila ada 3 lagi tidak usah ditambah)

  system("PAUSE");	
  return 0;
}
