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

void red(arvore r, int k, int a){
	if(r != NULL){
		a++;
		if(r->chave == k){
			printf("ESTA NA ARVORE\n%d",a-1);
			exit(0);
		}
		red(r->esq,k,a);
		red(r->dir,k,a);
	}
}

arvore insere_red(arvore r){
	int out, *pout = &out;
	int num, *pnum = &num;
	char str[2], *pstr = &str[0];

	scanf("%c",pstr);

	while(*pstr == ' '){
		scanf("%c",pstr);
	}

	if(*pstr == '('){
		if(scanf("%d",pnum)){
			r = novonoh(*pnum);
			n++;
		}else{
			scanf("%c", pstr);
			return r;
		}
		r->esq = insere_red(r->esq);
		r->dir = insere_red(r->dir);
		scanf("%c", pstr);
	}
	return r;
}

int main(){

	arvore r = NULL;
	r = insere_red(r);
	n = 0;

	int a=0,chave=0;
	scanf("%d",&chave);

	red(r,chave,a);
	printf("NAO ESTA NA ARVORE\n-1");

	return 0;
}