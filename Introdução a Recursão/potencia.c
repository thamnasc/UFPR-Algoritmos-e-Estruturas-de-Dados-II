// Potencia em Recursão
// Thalita Maria do Nascimento
// 09/02/2022

#include <stdio.h>

float potencia(float x, int n) {

	//x^0
	if(n == 0) return 1.0;
	//x^n
	return x * potencia(x, n - 1);
}

int main() {

	float x, resultado;
	int n;

	do {
		printf("Insira um valor x > 0 e n >= 0 para x^n\n");
		//base maior que zero e positiva
		scanf("%f", &x);
		//expoente maior ou igual a zero
		scanf("%d", &n);
	} while((x <= 0) || (n < 0));
	
	resultado = potencia(x, n);
	printf("%.1f^%d = %.2f\n", x, n, resultado);

	return 0;
}
