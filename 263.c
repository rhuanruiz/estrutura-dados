#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct reg{
	int conteudo;
	struct reg *prox;
} celula;

void inserir(int x, celula *li){
	celula *nova;
	nova = malloc(sizeof(celula));
	nova->conteudo = x;
	nova->prox = li->prox;
	li->prox = nova;
}

void imprimir(celula *li){
	celula *p;
	for(p = li->prox; p != NULL; p = p->prox){
		printf("%d\n",p->conteudo);
	}
	printf("\n");
}

celula * buscar(int x, celula *li){
	celula *p;
	p = li->prox;
	while(p != NULL && p->conteudo != x){
		p = p->prox;
	}
	return p;
}

void intersecao(celula *li1, celula *li2, celula *li3){
	celula *p, *q, *r;
	p = li1;
	q = li2;
	r = li3;
	for(p = li1->prox; p != NULL; p = p->prox){
		if(buscar(p->conteudo,q) != NULL){
			if(buscar(p->conteudo,r) == NULL){
				inserir(p->conteudo,r);
			}
		}
	}
}

void ordemCrescente(celula *li){

	celula *p,*q;
	int aux=0,*paux=&aux;

	p = li->prox;

	while(p != NULL){
		q = p->prox;
		while(q != NULL){
			if((q->conteudo) < (p->conteudo)){
				*paux = p->conteudo;
				p->conteudo = q->conteudo;
				q->conteudo = *paux;
			}
			q = q->prox;
		}
		p = p->prox;
	}
}

int main(){

	celula *li1;
	li1 = malloc(sizeof(celula));
	li1->conteudo = 0;
	li1->prox = NULL;

	celula *li2;
	li2 = malloc(sizeof(celula));
	li2->conteudo = 0;
	li2->prox = NULL;

	celula *li3;
	li3 = malloc(sizeof(celula));
	li3->conteudo = 0;
	li3->prox = NULL;

	int x = 0, i, *px = &x,*pi = &i;

	for(*pi = 0; *pi<20; (*pi)++){
		scanf("%d",px);
		inserir(*px,li1);
	}
	for(*pi = 0; *pi<20; (*pi)++){
		scanf("%d",px);
		inserir(*px,li2);
	}
	intersecao(li1,li2,li3);
	if(li3->prox != NULL){
		ordemCrescente(li3);
		imprimir(li3);
	}else{
		printf("VAZIO");
	}

	return 0;
}
