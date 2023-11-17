#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct reg{
	long int conteudo;
	struct reg *prox;
} celula;

void inserir(int x, celula *est){
	celula *nova;
	nova = malloc(sizeof(celula));
	nova->conteudo = x;
	nova->prox = est->prox;
	est->prox = nova;
}

int desempilhar(celula *est){
	celula *p;
	p = est->prox;
	long int x = p->conteudo;
	est->prox = p->prox;
	free(p);
	return x;
}

void buscarRemover(int y, celula *est){
   celula *p, *q;
   p = est;
   q = est->prox;
   while (q != NULL && q->conteudo != y) {
      p = q;
      q = q->prox;
   }
   if (q != NULL) {
      p->prox = q->prox;
      free (q);
   }
}

void imprimir(celula *est){
	celula *p;
	for(p = est->prox; p != NULL; p = p->prox){
		printf("%ld ",p->conteudo);
	}
	printf("\n");
}

void deletarEst(celula *est){
	celula *p,*aux;
	p = est->prox;
	while(p != NULL){
		aux = p->prox;
		free(p);
		p = aux;
	}
	est = NULL;
}

celula * buscar(int x, celula *est){
	celula *p;
	p = est;
	while(p != NULL && p->conteudo != x){
		p = p->prox;
	}
	return p;
}

int main(){

	long int x=0,y=2,z=1,t=0,n=0,o=0,primeiro=0,i=0;
	long int *px=&x,*py=&y,*pz=&z,*pt=&t,*pn=&n,*po=&o,*pprimeiro=&primeiro,*pi=&i;

	scanf("%ld",pt);

	while(*pz <= *pt){

		celula *est;
		est = malloc(sizeof(celula));
		est->conteudo = 0;
		est->prox = NULL;

		scanf("%ld",pn);

		for(*pi = 1; *pi<=*pn; (*pi)++){
			scanf("%ld",po);

			if(*po == 1){
				scanf("%ld",px);
				if(est->prox == NULL){
					*pprimeiro = *px;
				}
				inserir(*px,est);
				*py = 2;
			}

			else if(*po == 2){
				scanf("%ld",px);

				if(buscar(*px,est) == NULL){
					*py = 0;
					break;
				}

				else if(*px == *pprimeiro){
					if((est->prox)->prox == NULL){
						*py = 2;
						buscarRemover(*px,est);
					}
					else if(*px == (est->prox)->conteudo){
						*py = 1;
						desempilhar(est);
					}else if(*px == *pprimeiro){
						*py = 3;
						buscarRemover(*px,est);
						*pprimeiro = (est->prox)->conteudo;
					}else{
						*py = 0;
					}
				}else if(*px != *pprimeiro){
					if(*px == (est->prox)->conteudo){
						*py = 1;
						desempilhar(est);
					}else{
						*py = 0;
					}
				}else if(*px != *pprimeiro && *px != (est)->conteudo){
					*py = 0;
				}
			}
		}

		if(*py == 0){
			printf("caso %ld: nenhuma\n",*pz);
		}else if(*py == 1){
			printf("caso %ld: pilha\n",*pz);
		}else if(*py == 2){
			printf("caso %ld: ambas\n",*pz);
		}else if(*py == 3){
			printf("caso %ld: fila\n",*pz);
		}
		deletarEst(est);
		(*pz)++;
	}

	return 0;
}
