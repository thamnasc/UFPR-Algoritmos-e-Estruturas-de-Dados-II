//Primeiro Programa usando Recursão
//09/02/22
//Thalita Nascimento
//Aprendendo fatorial com recursão

#include <stdio.h>

int f(int n) {

	if(n == 0) return 1;

	return n * f(n - 1);
}

int main() {
	
	int n = 0, fatorial;

	do {
		printf("Insira um valor de fatorial n >= 0:\n");
		scanf("%d", &n);
	} while(n < 0);

	fatorial = f(n);

	printf("%d! = %d\n", n, fatorial);
}
