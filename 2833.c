#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int rf(int *px, int*py){
	int r,*pr = &r;
	*pr = pow(3*(*px),2) + pow(*py,2);
	return *pr;
}

int bt(int *px, int*py){
	int b,*pb = &b;
	*pb = (2*(pow(*px,2))) + pow(5*(*py),2);
	return *pb;
}

int cl(int *px, int*py){
	int c,*pc = &c;
	*pc = (-100*(*px)) + (pow(*py,3));
	return *pc;
}

void maiorResultado(int *px, int*py){
	int r,b,c;
	int *pr = &r, *pb = &b, *pc = &c;
	*pr = rf(px,py);
	*pb = bt(px,py);
	*pc = cl(px,py);
	if(*pr > *pb && *pr > *pc){
		printf("Rafael ganhou\n");
	}else if(*pb > *pr && *pb > *pc){
		printf("Beto ganhou\n");
	}else if(*pc > *pr && *pc > *pb){
		printf("Carlos ganhou\n");
	}
}

int main() {
    int n,x,y,i=0;
	scanf("%d",&n);
	int *pn = &n,*px = &x, *py = &y;
	for(int *pi = &i; *pi<*pn; (*pi)++){
		scanf("%d %d",&x,&y);
		maiorResultado(px,py);
	}
	return 0;
}