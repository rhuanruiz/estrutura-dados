#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct reg{
	int conteudo;
	struct reg *prox;
};

typedef struct reg celula;

celula *colocanafila(int x, celula *fi){
	celula *nova;
	nova = malloc(sizeof(celula));
	nova->prox = fi->prox;
	fi->prox = nova;
	fi->conteudo = x;
	return nova;
}

void imprimir(celula *fi){
	celula *p;
	for(p = fi->prox; p != fi; p = p->prox){
		printf("%d\n", p->conteudo);
	}
}

void intercalarFila(celula *fi1, celula *fi2){
	celula *fi3,*p,*q;
	fi3 = malloc(sizeof(celula));
	fi3->prox = fi3;

	p = fi1->prox;
	q = fi2->prox;

	while(p != fi1 || q != fi2){
		if(p != fi1){
			fi3 = colocanafila(p->conteudo,fi3);
			p = p->prox;
		}
		if(q != fi2){
			fi3 = colocanafila(q->conteudo,fi3);
			q = q->prox;
		}
	}
	imprimir(fi3);
}

int main() {
    
	celula *fi1;
	fi1 = malloc(sizeof(celula));
	fi1->prox = fi1;

	celula *fi2;
	fi2 = malloc(sizeof(celula));
	fi2->prox = fi2;

	int n,m,k,x=0;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0; i<n; i++){
		scanf("%d",&x);
		fi1 = colocanafila(x,fi1);
	}
	for(int i=0; i<m; i++){
		scanf("%d",&x);
		fi2 = colocanafila(x,fi2);
	}

	if(k==1){
		intercalarFila(fi2,fi1);
	}else{
		intercalarFila(fi1,fi2);
	}
	
}