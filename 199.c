#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int tacografo(int *pt, int *pv){
	return (*pv)*(*pt);
}

int main() {
    int n,t,v,s = 0,i = 0;
	int *pn = &n,*pt = &t,*pv = &v, *ps = &s;
	scanf("%d",pn);
	for(int *pi = &i; *pi<*pn; (*pi)++){
		scanf("%d %d",pt,pv);
		*ps = *ps + tacografo(pt,pv);
	}
	printf("%d",*ps);
	return 0;
}