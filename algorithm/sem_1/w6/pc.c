#include <stdio.h>

typedef struct{
    char code[31];
    char name[31];
    char gender[31];
    char father[31];
    char mother[31];
    int sib;
}student;

typedef struct{
    char code[31];
    char name[31];
    char gender[31];
    int numStudent;
    student mhs[100];
}lec;



int main(void){
    int n;
    scanf("%d", &n); getchar();

    lec lecturer[n];
    for (int i = 0; i < n; i++){
        scanf("%[^\n]s", lecturer[i].code); 
        getchar();
        scanf("%[^\n]s", lecturer[i].name); 
        getchar();
        scanf("%[^\n]s", lecturer[i].gender); 
        getchar();
        scanf("%d", &lecturer[i].numStudent); 
        getchar();

        // mhs mhs[lecturer[i].numStudent];

        for (int j = 0; j < lecturer[i].numStudent; j++){
            scanf("%[^\n]s", lecturer[i].mhs[j].code); 
            getchar();
            scanf("%[^\n]s", lecturer[i].mhs[j].name); 
            getchar();
            scanf("%[^\n]s", lecturer[i].mhs[j].gender); 
            getchar();
            scanf("%[^\n]s", lecturer[i].mhs[j].father); 
            getchar();
            scanf("%[^\n]s", lecturer[i].mhs[j].mother);
            getchar();
            scanf("%d", &lecturer[i].mhs[j].sib); 
            getchar();
        }
    }

    int i;
    scanf("%d",&i);

    printf("Kode Dosen: %s\n", lecturer[i-1].code);
    printf("Nama Dosen: %s\n", lecturer[i-1].name);
    printf("Gender Dosen: %s\n", lecturer[i-1].gender);
    printf("Jumlah Mahasiswa: %d\n", lecturer[i-1].numStudent);

    for (int j = 0; j <lecturer[i-1].numStudent; j++){
        printf("Kode Mahasiswa: %s\n", lecturer[i-1].mhs[j].code);
        printf("Nama Mahasiswa: %s\n", lecturer[i-1].mhs[j].name);
        printf("Gender Mahasiswa: %s\n", lecturer[i-1].mhs[j].gender);
        printf("Nama Ayah: %s\n", lecturer[i-1].mhs[j].father);
        printf("Nama Ibu: %s\n", lecturer[i-1].mhs[j].mother);
        printf("Jumlah Saudara Kandung: %d\n", lecturer[i-1].mhs[j].sib);
    }

}