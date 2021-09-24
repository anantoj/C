#include <stdio.h>
#include <string.h>

int main()
{
	int c, i;
	int d = 0;
 	int a, b;
 	int j, k, l;
 	char key[7][28] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',};
 	char alfa[100001];
 	int keyus[100001];
 	char alfa2[100001];
	char sp;
	 
 	scanf("%d", &c);
 	for(i=0 ; i < c ; i++){
	scanf("%d %d", &a, &b);
  		for(j = 1 ; j <= a ; j++){
		scanf("%s", key[j]);
  			}
			scanf("%s", alfa);
  			for(k = 0 ; k < b ; k++){
   			scanf("%d", &keyus[k]);
  			}
  			memset(alfa2, 0, sizeof(alfa2));
  				for(;d < b ; d++) {
		  		sp = alfa[d];
  					for(l = 0 ; l < 26 ; l++){
    				if(key[keyus[d]][l] == sp)
					{
     				alfa2[d] = key[0][l];
    				}
    				}
  				}		
  	d=0;
  	printf("Case #%d: %s\n", i+1, alfa2);
 	}
 return 0;
}
