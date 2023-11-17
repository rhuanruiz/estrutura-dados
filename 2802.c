#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct reg{
	int chave;
	int conteudo;
	struct reg *esq, *dir;
} noh;

typedef noh *arvore;
int n=0;

noh* novonoh(int k){
	noh *novo;
	novo = malloc(sizeof(noh));
	novo->chave = k;
	novo->esq = novo->dir = NULL;
	return novo;
}

arvore insere(arvore r, int k){
	if (r==NULL){
        r = novonoh(k);
	}else{
		if (r->chave > k){
			r->esq = insere(r->esq, k);
		}else{
			r->dir = insere(r->dir, k);
		}
	}
	return r;
}

int busca(arvore r, int k, int ocorr){
	if (r == NULL || r->chave == k){
		return ocorr;
	}
	if (r->chave > k){
		return busca (r->esq, k,ocorr+1);
	}else{
		return busca (r->dir, k,ocorr+1);
	}
}

int main(){

	arvore r = NULL;
	n = 0;

	int m,k,x,ocorr=1,ocorr2=0;

	scanf("%d",&m);
	int v[m];

	for(int i = 0; i < m; i++){
		scanf("%d",&k);
		v[i] = k;
		r = insere(r,k);
	}

	while(scanf("%d",&x) != EOF){
		ocorr2=0;
		for(int i = 0; i < m; i++){
			if(v[i] == x){
				ocorr2++;
				break;
			}else{
				ocorr2++;
			}
		}
		printf("%d %d",ocorr2,busca(r,x,ocorr));
		printf("\n");
	}
}

