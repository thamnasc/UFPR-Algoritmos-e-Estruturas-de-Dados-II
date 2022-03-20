#include <stdio.h>

int fator(int a, int n) {

	if(n == 1) {
		printf("%d \n", n);
		return n;
	}
	if(a % n == 0)
		printf("%d \n", n);
	return fator(a, n - 1);
}

int main() {

	fator(16, 16);
	return 0;
}
