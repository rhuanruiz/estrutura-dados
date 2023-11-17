#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct reg{
	int conteudo,conteudo2;
	struct reg *prox;
};

typedef struct reg celula;

celula *colocanafila(int x, int y, celula *fi){
	celula *nova;
	nova = malloc(sizeof(celula));
	nova->prox = fi->prox;
	fi->prox = nova;
	fi->conteudo = x;
	fi->conteudo2 = y;
	return nova;
}

int tiradafila(celula *fi){
	celula *p;
	p = fi->prox;
	int x = p->conteudo;
	fi->prox = p->prox;
	free(p);
	return x;
}


void imprimir(celula *fi, celula *fi2){
	celula *p,*q;

	printf("fila de idosos:\n");
	for(p = fi->prox; p != fi; p = p->prox){
		printf("ID: %d IDADE: %d\n", p->conteudo,p->conteudo2);
	}
	printf("fila de nao-idosos:\n");
	for(q = fi2->prox; q != fi2; q = q->prox){
		printf("ID: %d IDADE: %d\n", q->conteudo,q->conteudo2);
	}
	printf("----------\n\n");
}

int main(){

	celula *fi1;
	fi1 = malloc(sizeof(celula));
	fi1->prox = fi1;

	celula *fi2;
	fi2 = malloc(sizeof(celula));
	fi2->prox = fi2;

	char * c = malloc(100 * sizeof(char));

	int n=0,id=0,idade=0,cont=1;
	scanf("%d",&n);

	while(1){
		scanf("%s",c);
		if(strcmp(c,"a") == 0){
			scanf("%d %d",&id,&idade);
			if(idade > 60){
				fi1 = colocanafila(id,idade,fi1);
			}else{
				fi2 = colocanafila(id,idade,fi2);
			}
		}
		else if(strcmp(c,"r") == 0){
			if(cont < n){
				tiradafila(fi1);
				cont++;
			}else if(cont == n){
				tiradafila(fi1);
				cont = 1;
			}else{
				tiradafila(fi2);
			}
		}
		else if(strcmp(c,"i") == 0){
			imprimir(fi1,fi2);
		}
		else if(strcmp(c,"f") == 0){
			break;
		}
	}
}