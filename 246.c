#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void ultt(char *str, int ult[256], int tam){
    for (int i = 0; i < 256; i++){
    	ult[i] = -1;
    }
    for (int i = 0; i < tam; i++){
    	ult[(int) str[i]] = i;
    }
}

void boyermoore(char *strg, char *c1, char *c2){

    int m = strlen(c1), n = strlen(strg), s = 0;
    int ult[256];

    ultt(c1, ult, m);

    while(s <= (n - m)){
    	int i = m-1;
        while(i >= 0 && strg[s+i] == c1[i]){
            i--;
        }
        if (i < 0){
        	strg[s] = *c2;
            if((s+m) < n){
            	s = s + (m-ult[strg[s+m]]);
            }else{
            	s = (s+1);
            }
        }else{
        	s = s + ma(1, i - ult[strg[s+i]]);
    	}
    }
    printf("%s",strg);
}

int ma(int a, int b){
	if(a > b){
		return a;
	}else{
		return b;
	}
}

int main(){

	char strg[101],c1[2],c2[2];

	scanf("%s ",strg);
	scanf("%s ",c1);
	scanf("%s",c2);

	boyermoore(strg,c1,c2);

	return 0;
}
