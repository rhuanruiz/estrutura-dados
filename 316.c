#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct reg celula;

struct reg {
   int     chave, ocorr;
   celula *prox;
};

int main(){

	int N=0,L=0,valor;
	char * s = malloc(51 * sizeof(char));

	scanf("%d",&N);

	for(int k = 0; k < N; k++){
		scanf("%d",&L);
		valor = 0;
		for(int i = 0; i < L; i++){
			scanf("%s",s);
			for(int j = 0; s[j] != '\0'; j++){
				valor = valor + (s[j] - 65) + i + j;
			}
		}
		printf("%d\n",valor);
	}
	return 0;
}