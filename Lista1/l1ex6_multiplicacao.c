#include <stdio.h>
#include <stdlib.h>

int mult_aux(int n, int m) {

	if(m == 0) return 0;
	return n + mult_aux(n, m - 1);
}

int mult(int n, int m) {

	int aux = 0;

	if(abs(n) < abs(m)) { //para ter o mínimo de recorrencias possiveis
		aux = n;
		n = m;
		m = aux;
	}

	if(n > 0 && m < 0)
		return -mult_aux(n, -m);

	else if(n < 0 && m < 0)
		return mult_aux(-n, -m);

	// para n, m e -n, m 
	return mult_aux(n, m);
}

int main () {
	
	int n, m;

	scanf("%d %d", &n, &m);

	printf("%d\n", mult(n, m));

	return 0;
}
