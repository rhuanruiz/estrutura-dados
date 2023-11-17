#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

double distancia(int *xa, int *ya, int *xb, int *yb){
	double d;
	d = pow((pow((*xb-*xa),2.0) + pow((*yb-*ya),2)),0.5);
	return d;
}

const char* posicao(int *x, int *y){
	if(*x == 0){
		if(*y == 0){
			return "origem";
		}
		else if(*y > 0){
			return "eixo y positivo";
		}else{
			return "eixo y negativo";
		}
	}
	else if(*y == 0){
		if(*x > 0){
			return "eixo x positivo";
		}else{
			return "eixo x negativo";
		}
	}else if(*x > 0){
		if(*y > 0){
			return "quadrante 1";
		}else{
			return "quadrante 4";
		}
	}else if(*x < 0){
		if(*y > 0){
			return "quadrante 2";
		}else{
			return "quadrante 3";
		}
	}
}

int main() {
    int qtd,xa,ya,xb,yb,*p,*q,*r,*s,*t;
	double maiorD=0,D=0;
	scanf("%d",&qtd);
	p = &qtd;
	const char* pos1[*p];
	const char* pos2[*p];

	for(int i=0; i<*p; i++){
		scanf("%d %d",&xa,&ya);
		q = &xa;
		r = &ya;
		pos1[i] = posicao(q,r);

		scanf("%d %d",&xb,&yb);
		s = &xb;
		t = &yb;
		pos2[i] = posicao(s,t);

		D = distancia(q,r,s,t);
		if (D > maiorD){
			maiorD = D;
		}
	}

	printf("%.2lf\n",maiorD);
	for(int i=0; i<*p; i++){
		printf("%s\n",pos1[i]);
		printf("%s\n",pos2[i]);
	}
	return 0;
}