//contagem regressiva em recursão
//tmn21
//09/02/2022

/* Receba n >= 1 e imprima n, n - 1, n - 2, ..., 3, 2, 1
 * */

#include <stdio.h>

void count_down(int n) {
	
	if(n == 1)
		printf("1...\n");
	else {
		printf("%d, ", n);
		count_down(n - 1);
	}
}

int main() {

	int n;

	do {
		printf("Informe um valor n >= 1 para a contagem regressiva:\n");
		scanf("%d", &n);
	} while (n < 1);

	count_down(n);

	return 0;
}
