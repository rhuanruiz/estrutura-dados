#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void ordemCrescente(int n, int *pv, int *pvi){
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

int buscaBinaria(int x, int n, int v[]){
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

	int n=15,cod=0,d=0,cont=1;
	int *va,*vt,*v;

	va = malloc(n * sizeof(int));
	vt = malloc(n * sizeof(int));

	for(int i = 0; i < n; i++){
		printf("Digite o codigo de area e o telefone:\n");
		scanf("%d %d",&va[i],&vt[i]);
	}

	ordemCrescente(n,va,vt);

	printf("Digite o codigo de area desejado:\n");
	scanf("%d",&cod);

	d = buscaBinaria(cod,n,va);

	if((d == 0 && cod != va[0]) || d == 15){
		printf("Nao ha nenhum telefone com o codigo %d\n",cod);
		free(va);
		free(vt);
		return 0;
	}

	d++;
	while(va[d] == cod){
		cont++;
		d++;
	}

	v = malloc(cont * sizeof(int));
	d = d - cont;
	cont = 1;
	v[0]=vt[d];
	d++;

	while(va[d] == cod){
		v[cont] = vt[d];
		cont++;
		d++;
	}

	//ordemCrescente2(cont,v);

	printf("Telefones com o codigo de area %d:\n",cod);
	for(int i = 0; i < cont; i++){
		printf("%d %d\n",cod,v[i]);
	}

	free(va);
	free(vt);
	free(v);
	return 0;
}