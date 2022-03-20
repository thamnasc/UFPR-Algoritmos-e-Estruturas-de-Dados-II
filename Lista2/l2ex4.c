#include <stdio.h>

float potencia(int x, int n) {

	if(n == 0)
		return 1;
	return x * potencia(x, n - 1);
}

float polinomio(int p[], int a, int b, int x) {

	if(b == a)
		return p[a];
	return p[b] * potencia(x, b) + polinomio(p, a, b - 1, x);
}

int main() {

	int p[6] = {4, 8, 15, 16, 23, 42};
	printf("%f \n", polinomio(p, 0, 5, 2));
	return 0;
}
