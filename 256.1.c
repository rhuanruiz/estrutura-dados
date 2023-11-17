#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
	//printf("Tamanho de ambos vetores:\n");
	scanf("%d",&n);
	int a[n],b[n],c[2*n];

	//printf("Primeiro vetor:\n");
	for(int j=0;j<n;j++){
		scanf("%d",&a[j]);
	}

	//printf("Segundo vetor:\n");
	for(int k=0;k<n;k++){
		scanf("%d",&b[k]);
	}

	int j=0, k=0;
	for(int i=0;i<(2*n);i++){
		if(i%2 == 0){
			c[i]=a[j];
			j++;
		}else{
			c[i]=b[k];
			k++;
		}
	}
	for(int i=0;i<(2*n);i++){
		printf("%d\n",c[i]);
	}
	return 0;
}