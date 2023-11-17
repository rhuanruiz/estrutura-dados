#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

const char* calcularDigito(char *chave){
	int num[14],maior1=0,maior2=0,maior3=0,*r,*m1,*m2,*m3;
	r = &num;
	m1 = &maior1;
	m2 = &maior2;
	m3 = &maior3;
	for(int i=0; i<3; i++){
		r[i] = chave[i] - '0';
		if(r[i] > *m1){
			*m1 = r[i];
		}
	}
	for(int i=4; i<7; i++){
		r[i] = chave[i] - '0';
		if(r[i] > *m2){
			*m2 = r[i];
		}
	}
	for(int i=8; i<11; i++){
		r[i] = chave[i] - '0';
		if(r[i] > *m3){
			*m3 = r[i];
		}
	}
	r[12] = chave[12] - '0';
	if((*m1+*m2+*m3)%10 == r[12]){
		return "VALIDO";
	}else{
		return "INVALIDO";
	}
}

int main() {
   int a = 0;
	char chave1[14], chave2[14], c[4],*p,*q,*r;
	while(a == 0){
		scanf("%s",chave1);
		p = &chave1;
		if(strcmp(chave1,"FIM") == 0){
			return 0;
		}
		printf("%s\n",calcularDigito(p));
		a = 0;
	}
	return 0;
}