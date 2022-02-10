/* Fibonacci com Recursividade
 * tmn21
 * 09/02/2022
 * */

/* 0 1 1 2 3 5 8 13 21... */

#include <stdio.h>

int fib(int n) {

	if(n <= 1) return n;
	else return fib(n - 1) + fib(n - 2);
}

int main() {

	int n, fibonacci;

	do {
		printf("Informe o numero da sequencia de fibonacci que deseja ver:\n");
		scanf("%d", &n);
	} while(n < 0);

	fibonacci = fib(n);

	printf("%d\n", fibonacci);

	return 0;
}
