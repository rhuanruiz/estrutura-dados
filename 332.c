#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void paraMaiusculo(char * pnome){
	int i = 0;
	char *pmaiusculo;
	pmaiusculo = pnome;
	*pmaiusculo = toupper(*pnome);
	for(int *pi = &i; *pi<=100; (*pi)++){
		*(pmaiusculo+(*pi)) = toupper(*(pnome+(*pi)));
	}
	printf("%s",pmaiusculo);
}


int main() {
    char nome[100],*pnome = &nome[0];
	scanf("%[^\n]%*c",pnome);
	paraMaiusculo(pnome);
	return 0;
}