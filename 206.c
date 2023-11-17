#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

struct reg{
	int conteudo;
	struct reg *prox;
};

typedef struct reg celula;

void insere(int x, celula *p){
	celula *nova;
	nova = malloc(sizeof(celula));
	nova->conteudo = x;
	nova->prox = p->prox;
	p->prox = nova;
}

bool comparar(celula *A, celula *B){
	celula *p = A;
	celula *q = B;

	for(q = B->prox; q != NULL; q = q->prox){
		for(p = A->prox; p != NULL; p = p->prox){
			if(q->conteudo == p->conteudo){
				break;
			}
		}
		if(p == NULL){
			return 0;
		}
	}
	return 1;
}

int main() {

	celula *A;
	A = malloc(sizeof(celula));
	A->conteudo = 0;
	A->prox = NULL;

	celula *B;
	B = malloc(sizeof(celula));
	B->conteudo = 0;
	B->prox = NULL;

	int n,m,x;
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&x);
		insere(x, A);
	}
	scanf("%d",&m);
	for(int i=0; i<m; i++){
		scanf("%d", &x);
		insere(x,B);
	}

	if (comparar(A, B)){
		printf("1\n");
	}else{
		printf("0\n");
	}
	return 0;
}
