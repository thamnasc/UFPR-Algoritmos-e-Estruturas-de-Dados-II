#include <stdio.h>

int soma_pg(int a, int r, int n) {
	
	if(n == 0) 
		return a;

	return a + r * soma_pg(a, r, n - 1);
}

int main() {

	/* 2x1 + 2x3 + 2x9 = 26 */
	/* 1x1 + 1x2 + 1x4 + 1x8 */
	printf("a = 2, r = 3, n = 2, resultado deve ser 26\n");
	printf("%d\n", soma_pg(2, 3, 2));
	printf("a = 1, r = 2, n = 3, resultado deve ser 15\n");
	printf("%d\n", soma_pg(1, 2, 3));

	return 0;
}
