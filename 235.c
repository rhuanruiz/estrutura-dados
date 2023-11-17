#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void vpar(int *valor){
	int i = 0;
	for(int *pi = &i; *pi < 5; (*pi)++){
		printf("par[%d] = %d\n",*pi,*(valor+(*pi)));
	}
}

void vimpar(int *valor){
	int i = 0;
	for(int *pi = &i; *pi < 5; (*pi)++){
		printf("impar[%d] = %d\n",*pi,*(valor+(*pi)));
	}
}

int main() {
    	int par[5],impar[5],v,i = 0, j = 0, k = 0, contp = 0, conti = 0;
	int *ppar = &par[0], *pimpar = &impar[0],*pv = &v, *pcontp = &contp, *pconti = &conti;
	for(int *pi = &i; *pi<15; (*pi)++){
		scanf("%d",pv);
		if(*pv%2 == 0){
			*(ppar+(*pcontp)) = *pv;
			(*pcontp)++;
			if(*pcontp == 5){
				vpar(ppar);
				*pcontp = 0;
			}
		}else{
			*(pimpar+(*pconti)) = *pv;
			(*pconti)++;
			if(*pconti == 5){
			vimpar(pimpar);
			*pconti = 0;
			}
		}
	}
	for(int *pj = &j; *pj < *pconti; (*pj)++){
		printf("impar[%d] = %d\n",*pj,*(pimpar+(*pj)));
	}
	for(int *pk = &k; *pk < *pcontp; (*pk)++){
		printf("par[%d] = %d\n",*pk,*(ppar+(*pk)));
	}
	return 0;
}