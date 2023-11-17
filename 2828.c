#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void ordemCrescente(int n, int *pv){
	int aux=0;
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
   int e = -1,d = n,cont = 0;
   while (e < d-1) {
      int m = (e + d)/2;
      if (v[m] < x){
    	  e = m;
      }else{
    	  d = m;
      }
   }
   while(v[d] == x){
	   cont++;
	   d++;
   }
   return cont;
}

int main(){

	int n,*v,maior,menor;

	scanf("%d",&n);
	v = malloc(n * sizeof(int));

	scanf("%d",&v[0]);
	maior = v[0];
	menor = v[0];

	for(int i = 1; i<n; i++){
		scanf("%d",&v[i]);

		if(v[i] > maior){
			maior = v[i];
		}
		if(v[i] < menor){
			menor = v[i];
		}
	}

	ordemCrescente(n,v);
	int contMa = buscaBinaria(maior,n,v);
	int contMe = buscaBinaria(menor,n,v);
	printf("Maior: %d apareceu %d vezes\n",maior,contMa);
	printf("Menor: %d apareceu %d vezes",menor,contMe);
	
	free(v);
	return 0;
}
