#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void ordemCrescente(int n, double *pv, int *pvi){
	double aux = 0;
	int auxi = 0;
	for(int i = 0; i<n; i++){
		for(int j = i; j<n; j++){
			if(*(pv+i) > *(pv+j)){
				aux = *(pv+i);
				*(pv+i) = *(pv+j);
				*(pv+j) = aux;

				auxi = *(pvi+i);
				*(pvi+i) = *(pvi+j);
				*(pvi+j) = auxi;
			}
		}
	}
}

void ordemCrescente2(int n, int *pv){
	double aux = 0;
	for(int i = 0; i<n; i++){
		for(int j = i; j<n; j++){
			if(*(pv+i) > *(pv+j)){
				aux = *(pv+i);
				*(pv+i) = *(pv+j);
				*(pv+j) = aux;
			}
		}
	}
}

int buscaBinaria(int x, int n, double v[]){
   int e = -1,d = n;
   while (e < d-1) {
      int m = (e + d)/2;

      if (v[m] < x){
    	  e = m;
      }else{
    	  d = m;
      }
   }
   return d;
}

int main(){

	int n = 101,*vi,*vi2,d=0,cont=0;
	double *v,ultimo;

	v = malloc(n * sizeof(double));
	vi = malloc(n * sizeof(int));

	printf("Digite a sequencia de numero:\n");

	for(int i = 0; i < n; i++){
		scanf("%lf",&v[i]);
		vi[i] = i;
	}

	ultimo = v[100];
	ordemCrescente(n,v,vi);

	printf("Indice no qual o numero desejado aparece:\n");

	d = buscaBinaria(ultimo,n,v);
	d++;

	while(v[d] == ultimo){
		cont++;
		d++;
	}

	vi2 = malloc(cont * sizeof(int));
	d = d - cont;
	cont = 1;
	vi2[0]=vi[d-1];

	while(v[d] == ultimo){
		vi2[cont] = vi[d];
		cont++;
		d++;
	}

	ordemCrescente2(cont, vi2);

	for(int i = 0; i < (cont-1); i++){
		printf("%d\n",vi2[i]);
	}

	free(v);
	free(vi);
	free(vi2);
	return 0;
}