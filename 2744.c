#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void ordenarTempo(int *pn){
	int i,j,*pi=&i,*pj=&j,aux2=0,*paux2=&aux2;
	char *pnomes[5]={
						"Ambrosio",
						"Peu",
						"Minerin",
						"Entidade",
						"Jeff"
					};
	char *paux[8];

	for(*pi=0; *pi<5; (*pi)++){
		for(*pj=*pi; *pj<5; (*pj)++){
			if(*(pn+*pi) > *(pn+*pj)){
				*paux2 = *(pn+*pi);
				*(pn+*pi) = *(pn+*pj);
				*(pn+*pj) = *paux2;

				*paux = *(pnomes+*pi);
				*(pnomes+*pi) = *(pnomes+*pj);
				*(pnomes+*pj) = *paux;
			}
		}
	}
	printf("Terca-feira: %s\nQuarta-feira: %s\nQuinta-feira: %s\nSexta-feira: %s",*(pnomes+1),*(pnomes+2),*(pnomes+3),*(pnomes+4));
}

int main() {
    int i=0,n[5],*pn = &n[0];
	for(int *pi=&i; *pi<5; (*pi)++){
		scanf("%d",(pn+*pi));
	}
	ordenarTempo(pn);
	return 0;
}