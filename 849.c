#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

double volumeEsfera(double *raio){
	double volume;
	volume = (4*3.1416)*(pow(*raio,3));
	return volume/3;
}

int main() {
    double *p, *q, *r, r1, r2, r3;
	scanf("%lf", &r1);
	scanf("%lf", &r2);
	scanf("%lf", &r3);
	p = &r1;
	q = &r2;
	r = &r3;
	printf("%.2lf\n", volumeEsfera(p));
	printf("%.2lf\n", volumeEsfera(q));
	printf("%.2lf\n", volumeEsfera(r));
	return 0;
}