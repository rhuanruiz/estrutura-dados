#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct reg{
	int conteudo;
	struct reg *prox;
} celula;

void empilhar(int x, celula *pi){
	celula *nova;
	nova = malloc(sizeof(celula));
	nova->conteudo = x;
	nova->prox = pi->prox;
	pi->prox = nova;
}

int desempilhar(celula *pi){
	celula *p;
	p = pi->prox;
	int x = p->conteudo;
	pi->prox = p->prox;
	free(p);
	return x;
}

void imprimir(celula *pi){
	celula *p;
	for(p = pi->prox; p != NULL; p = p->prox){
		printf("%d", p->conteudo);
		break;
	}
	printf("\n");
}

int valorAbsoluto(celula *pi){
	celula *p;
	int maior = 0, menor = (pi->prox)->conteudo,*pmaior = &maior, *pmenor = &menor;
	if((pi->prox)->prox == NULL){
		return 0;
	}else{
		for(p = pi->prox; p != NULL; p = p->prox){
			if(p->conteudo > *pmaior){
				*pmaior = p->conteudo;
			}
			if(p->conteudo < *pmenor){
				*pmenor = p->conteudo;
			}
		}
		return (*pmaior-*pmenor);
	}
}

int main(){

	celula *pi;
	pi = malloc(sizeof(celula));
	pi->conteudo = 0;
	pi->prox = NULL;

	int x=0, *px = &x;
	char * s = malloc(100 * sizeof(char));

	while(scanf("%s",s) != EOF){
		getchar();
		if(strcmp(s,"push") == 0){
			scanf("%d",px);
			empilhar(*px,pi);
		}else if(strcmp(s,"pop") == 0){
			imprimir(pi);
			desempilhar(pi);
		}else if(strcmp(s,"abs") == 0){
			printf("%d\n",valorAbsoluto(pi));
		}
	}
	return 0;
}