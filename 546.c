#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

struct noh{
    int conteudo;
    struct noh* esq;
    struct noh* dir;
};

int arvoreBusca(struct noh* arvore, int min, int max){
	if (arvore==NULL){
		return 1;
	}
	if (arvore->conteudo < min || arvore->conteudo > max){
		return 0;
	}else{
		return arvoreBusca(arvore->esq, min, arvore->conteudo-1) && arvoreBusca(arvore->dir, arvore->conteudo+1, max);
	}
}

int arvoreBusc(struct noh* arvore){
	return(arvoreBusca(arvore, INT_MIN, INT_MAX));
}

struct noh* inserir(int conteudo){
	struct noh* noh = (struct noh*)malloc(sizeof(struct noh));
	noh->conteudo = conteudo;
	noh->esq = NULL;
	noh->dir = NULL;
	return(noh);
}

int main(){
    
    char str[25],str2[25];
	scanf("%s %s",str,str2);
	
	struct noh *raiz= inserir(5);
	raiz->esq = inserir(4);
	raiz->esq->esq = inserir(11);
	raiz->esq->esq->esq = inserir(7);
	raiz->esq->esq->dir = inserir(2);
	raiz->dir = inserir(8);
	raiz->dir->dir = inserir(4);
	raiz->dir->esq = inserir(13);
	raiz->dir->dir->dir = inserir(1);

	if(arvoreBusc(raiz)){
		printf("VERDADEIRO");
	}else{
		printf("FALSO");
	}

	return 0;
}