#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

double calculaMulta(int *velocidade){
	if(*velocidade > ((0.2*50)+50)){
		return (*velocidade-50)*19.28;
	}
	else if(*velocidade > ((0.1*50)+50) && *velocidade <= ((0.2*50)+50)){
		return 340;
	}
	else if(*velocidade > 50 && *velocidade <= ((0.1*50)+50)){
		return 230;
	}
}

int main() {
    int velocidade,*p;
	scanf("%d",&velocidade);
	p = &velocidade;
	printf("%.2lf",calculaMulta(p));
	return 0;
}