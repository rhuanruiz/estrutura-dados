#include <stdio.h>
#include <stdlib.h>

typedef struct reg{
	int conteudo;
	struct reg *prox;
} celula;

void insere(int x, celula *li){
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

void intercalarLista(celula *li1, celula *li2, celula *li3){
	celula *p,*q;

	p = li1->prox;
	q = li2->prox;

	while(p != NULL || q != NULL){
		if(q != NULL){
			insere(q->conteudo,li3);
			q = q->prox;
		}
		if(p != NULL){
			insere(p->conteudo,li3);
			p = p->prox;
		}
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

	int n=0,x=0,*pn = &n, *px = &x;

	scanf("%d",pn);
	for(int i=0; i < *pn; i++){
		scanf("%d",px);
		insere(*px,li1);
	}
	for(int i=0; i < *pn; i++){
		scanf("%d",px);
		insere(*px,li2);
	}
	intercalarLista(li1,li2,li3);
	imprimir(li3);
}