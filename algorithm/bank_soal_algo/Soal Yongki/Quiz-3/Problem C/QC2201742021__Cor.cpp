#include <stdio.h>

int main(){
	
	int c, i;
	int N[100000];
	int M[100];
	int samcho, j;
	int ancho, k, l;
	int a, b, d;
	
	
	scanf("%d", &c);
	
	for( i = 1 ; i <= c; i++){
		a=0;
		scanf("%d %d", &samcho, &ancho);
		for( j = 0 ; j < samcho ; j++){
		scanf("%d", &N[j]);
		M[N[j] - 1] += 1;
		}
		d = M[0];
			for( k = 0 ; k < ancho ; k++){	
				if(d>M[k])
				{
				d=M[k];
				a=k;
				}
			}
	printf("Case #%d: %d\n", i, a+1);
					for(l = 0 ; l < ancho ; l++){
					M[l] = 0;
					}
	}
	return 0;
}
