#include <stdio.h>

int razao(int r, int n) {
	
	if(n==0) return 1;
	return r * razao(r, n-1);
}

int soma_pg(int a, int r, int n) {
	if(n==0) return a;
	return a * razao(r, n) + soma_pg(a, r, n-1);
}

int main() {

	int a, r, n;

	scanf("%d%d%d", &a, &r, &n);
	printf("%d\n", soma_pg(a, r, n));

	return 0;
}
