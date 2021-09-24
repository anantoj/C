#include <stdio.h>

int main(){
int teman = 0;
int tiket = 0;
scanf("%d", &teman);
int totalOrg = 3 + teman;
int poin = 0;

while (tiket < totalOrg){
    poin = poin + 1;

    tiket++;
    if(poin %2 == 0){
        tiket = tiket + 1;
    }

}
printf("%d\n", poin);

return 0;
}


