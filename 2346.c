#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void contagemRegressiva(int *p){
	int q;
	q = *p;
	for(int i=0; i<q; i++){
		for(int j=0; j<*p; j++){
			if(j != (*p-1)){
				printf("%d-",*p);
			}else{
				printf("%d",*p);
			}
		}
		printf("\n",*p);
		*p=*p-1;
	}
}

int main() {
    int *p, n;
	scanf("%d",&n);
	p = &n;
	contagemRegressiva(p);
	return 0;
}