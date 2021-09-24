#include <stdio.h>

int main(){
	int testcase, x, y, z, m, n, p;
	int var1, var2; //x years ago
	int var3, var4; //y years from now
	int res1, res2, jojo, bibi, jojoP, bibiP;
	
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){
		var2 = 0;
		scanf("%d %d %d %d %d %d", &x, &y, &z, &m, &n, &p);
		
		var1 = m;
		var2 = ((x * -1) * m) + x;
		
		var3 = n;
		var4 = ((y * 1) * n) - y;
		
		bibi = ((var2 * -1) + var4) / (var1 + (var3 * -1));
		jojo = (bibi * n);
		
		jojoP = jojo - y;
		bibiP = bibi - y;
		
		res1 = jojoP + z;
		res2 = (bibiP + z) * p;
		if(res1 == res2){
			printf("Case #%d: YES\n", loop);
		} else {
			printf("Case #%d: NO\n", loop);
		}
	}
	
	return 0;
}
