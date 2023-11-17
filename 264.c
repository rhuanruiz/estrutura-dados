#include <stdio.h>
#include <string.h>
#include <math.h>
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

void imprimirInverso(celula *li){
    if (li == NULL){
    	return;
    }
    imprimirInverso(li->prox);
    if(li->prox == NULL){
    	printf("%d", li->conteudo);
    }else{
    	printf(" %d", li->conteudo);
    }
}

void inverter(celula *li){
	celula *aux,*p,*q;

	aux = li->prox;
	q = NULL;

	while(aux != NULL){
		p = aux->prox;
		aux->prox = q;
		q = aux;
		aux = p;
	}
	li->prox = q;
}

int main(){

	celula *li;
	li = malloc(sizeof(celula));
	li->conteudo = 0;
	li->prox = NULL;

    int x,*px = &x;
	char teste;

    while(teste != '\n' && teste != EOF){
    	scanf("%d",px);
    	insere(*px,li);
    	teste = getchar();
    }
    inverter(li);
    imprimirInverso((li)->prox);
	return 0;
}