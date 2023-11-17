#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void ordemCrescente(int *pn, int *pv){
	int i=0,j=0,aux=0;
	int *pj = &j, *paux = &aux;
	for(int *pi = &i; *pi<*pn; (*pi)++){
		for(*pj = *pi; *pj<*pn; (*pj)++){
			if(*(pv+*pi) > *(pv+*pj)){
				*paux = *(pv+*pi);
				*(pv+*pi) = *(pv+*pj);
				*(pv+*pj) = *paux;
			}
		}
		printf("[%d]",*(pv+*pi));
	}
	printf("\n");
}

int main() {
    int n,i=0,*pn = &n;
	scanf("%d",pn);
	int v[*pn],*pv = &v[0];
	for(int *pi=&i; *pi<*pn; (*pi)++){
		scanf("%d",(pv+*pi));
	}
	ordemCrescente(pn,pv);
	return 0;
}