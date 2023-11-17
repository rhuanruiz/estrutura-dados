#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void exibeMultiplos(int *pi, int *pf, int *px){
	int j=*pi;
	for(int *pj = &j; *pj<=*pf; (*pj)++){
		if(*pj % *px == 0){
			printf("%d\n",*pj);
		}
	}
}

int main() {
    int i,f,x;
	scanf("%d %d %d",&i,&f,&x);
	exibeMultiplos(&i,&f,&x);
	return 0;
}