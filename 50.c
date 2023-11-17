#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void organizarAltura(double *paltura){
	int i=0,j=0,*pi = &i,*pj = &j;
	double auxiliar=0,*pauxiliar = &auxiliar;
	for(*pi=0; *pi<4; (*pi)++){
		for(*pj=*pi; *pj < 4; (*pj)++){
			if(*(paltura+*pi) > *(paltura+*pj)){
				*pauxiliar = *(paltura+*pi);
				*(paltura+*pi) = *(paltura+*pj);
				*(paltura+*pj) = *pauxiliar;
			}
		}
	}
	printf("%.2lf\n%.2lf\n%.2lf\n%.2lf\n",*paltura,*(paltura+2),*(paltura+3),*(paltura+1));
}

int main() {
   int i=0;
	double altura[4], *paltura = &altura[0];
	for(int *pi=&i; *pi<4; (*pi)++){
		scanf("%lf",(paltura+*pi));
	}
	organizarAltura(paltura);
	return 0;
}