#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct reg{
	int conteudo;
	struct reg *prox;
} celula;

typedef struct{
	celula *primeiro;
	celula *ultimo;
} lista;

void tabelaHash(int M, lista *tb){
	for(int i = 0; i < M; i++){
		tb[i].primeiro = NULL;
		tb[i].ultimo = NULL;
	}
}

void inserirHash(int ch, int M, int resto, lista *tb){

	celula *p;
	p = malloc(sizeof(celula)); 
	                            
	if(tb[resto].primeiro){
		(tb[resto].ultimo)->prox = p;
	}else{
		tb[resto].primeiro = p;
	}
	tb[resto].ultimo = p;
	p->prox = NULL;
	p->conteudo = ch;
}

int main() {
    
	celula *li;
	int N=0,M=0,C=0,chave=0;

	scanf("%d",&N);

	for(int i = 0; i < N; i++){
		scanf("%d %d",&M,&C);

		lista *tb;
		tb = malloc(M * sizeof(lista));
		tabelaHash(M,tb);

		for(int i = 0; i < C; i++){
			scanf("%d",&chave);
			inserirHash(chave,M,chave%M,tb);
		}

		for(int i = 0; i < M; i++){
			printf("%d -> ",i);
			for (li = tb[i].primeiro; li; li = li->prox){
				printf("%d -> ", li->conteudo);
			}
			printf("\\\n");
		}
		printf("\n");
	}
	return 0;
}