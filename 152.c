#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void baguncarArray(int *pn, int *pv){
	int i=0,*pi=&i,j=0,*pj=&j,aux=0,*paux = &aux;
	//Ordem inversa:
	for(*pi=(*pn-1); *pi >= 0; (*pi)--){
		if(*pi == 0){
			printf("%d",*(pv+*pi));
		}else{
			printf("%d ",*(pv+*pi));
		}
	}
	printf("\n");
	//Deslocamento para esquerda:
	*paux=*pv;
	for(*pi=0;*pi<(*pn-1);(*pi)++){
		*(pv+*pi)=*(pv+(*pi+1));
	}
	*(pv+(*pn-1))=*paux;
	for(*pi=0; *pi < *pn; (*pi)++){
		if(*pi == (*pn-1)){
			printf("%d",*(pv+*pi));
		}else{
			printf("%d ",*(pv+*pi));
		}
	}
	printf("\n");
	//Ordem decrescente:
	for(*pi=0; *pi<*pn; (*pi)++){
		for(*pj=*pi; *pj<*pn; (*pj)++){
			if(*(pv+*pi) < *(pv+*pj)){
				*paux = *(pv+*pi);
				*(pv+*pi) = *(pv+*pj);
				*(pv+*pj) = *paux;
			}
		}
	}
	for(*pi=0; *pi<*pn; (*pi)++){
		if(*pi == (*pn-1)){
			printf("%d",*(pv+*pi));
		}else{
			printf("%d ",*(pv+*pi));
		}
	}
	printf("\n");
}

int main() {
    int n,i=0,*pn = &n;
	scanf("%d",pn);
	int v[*pn],*pv = &v[0];
	for(int *pi=&i; *pi < *pn; (*pi)++){
		scanf("%d",(pv+*pi));
	}
	baguncarArray(pn,pv);
	return 0;
}