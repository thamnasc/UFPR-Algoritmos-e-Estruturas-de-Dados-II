/* Contagem para baixo e para cima com recursão
 * tmn21
 * 09/02/2022
 */

/* Faça um programa recursivo que recebe um inteiro n >= 1 e imprime
 * n, n - 1, ..., 1, ..., n - 1, n
 */

#include <stdio.h>

void count_down_up(int n) {
	
	if(n == 1)
		printf("%d ", n);
	else {
		printf("%d ", n);
		count_down_up(n - 1);
		printf("%d ", n);
	}
}

int main() {

	int n;

	do {
		printf("Informe n >= 1 para a contagem:\n");
		scanf("%d", &n);
	} while(n < 1);

	count_down_up(n);

	printf("\n");

	return 0;
}
