#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct reg{
	int conteudo;
	struct reg *prox;
};

typedef struct reg celula;

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
	p = pi->prox;
	for(p = pi->prox; p != NULL; p = p->prox){
		if(p->prox == NULL){
			printf("%d", p->conteudo);
		}else{
			printf("%d ", p->conteudo);
		}
	}
	printf("\n");
}

int main(){

	celula *pi;
	pi = malloc(sizeof(celula));
	pi->conteudo = 0;
	pi->prox = NULL;

	int x = 1, y = 0;
	char * s = malloc(100 * sizeof(char));

	while(x != 0){
		scanf("%s",s);
		if(strcmp(s,"Empilhar") == 0){
			scanf("%d",&y);
			empilhar(y,pi);
		}
		else if(strcmp(s,"Desempilhar") == 0){
			desempilhar(pi);
		}
		else if(strcmp(s,"Imprimir") == 0){
			imprimir(pi);
		}
		else if(strcmp(s,"Finalizar") == 0){
			break;
		}
	}
}
