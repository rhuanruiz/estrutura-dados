#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void organizarMensagem(int *pn){
	int i=1,j=1,m,*pm = &m;
	char c, *pc = &c,ma[(*pn)][1],*pma = &ma[0][0];
	for(int *pi = &i; *pi<=*pn; (*pi)++){
		scanf("%d %c",pm,pc);
		*(pma+(*pm)) = *pc;
	}
	for(int *pj = &j; *pj<=*pn; (*pj)++){
		printf("%c",*(pma+(*pj)));
	}
}

int main() {
    int n, *pn = &n;
	scanf("%d",pn);
	organizarMensagem(pn);
	return 0;
}