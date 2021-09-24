#include <stdio.h>

typedef struct{
    char name[101];
    char nim[10];
    int age;
    char post[7];
    char pob[101];
    char dob[101];
    char school[101];
    int siblings;
    int height;
    char rekening[10];
}mhs;

int main(void){
    int cases;
    scanf("%d", &cases);
    getchar();
    mhs student[cases];
    for (int i = 0; i < cases; i++){
        scanf("%[^\n]s", student[i].name);
        getchar();
        scanf("%[^\n]s", student[i].nim);
        getchar();
        scanf("%d", &student[i].age);
        getchar();
        scanf("%[^\n]s", student[i].post);
        getchar();
        scanf("%[^\n]s", student[i].pob);
        getchar();
        scanf("%[^\n]s", student[i].dob);
        getchar();
        scanf("%[^\n]s", student[i].school);
        getchar();
        scanf("%d", &student[i].siblings);
        getchar();
        scanf("%d", &student[i].height);
        getchar();
        scanf("%[^\n]s", student[i].rekening);
        getchar();
    }

    for (int i = 0; i < cases; i++){
        printf("Mahasiswa ke-%d:\n", i+1);
        printf("Nama: %s\n", student[i].name);
        printf("NIM: %s\n", student[i].nim);
        printf("Umur: %d\n", student[i].age);
        printf("Kode Pos: %s\n", student[i].post);
        printf("Tempat Lahir: %s\n", student[i].pob); 
        printf("Tanggal Lahir: %s\n", student[i].dob);
        printf("Almamater SMA: %s\n", student[i].school);
        printf("Jumlah Saudara Kandung: %d\n", student[i].siblings);
        printf("Tinggi Badan: %d\n", student[i].height);
        printf("NOMOR REKENING: %s\n", student[i].rekening);
    }
}