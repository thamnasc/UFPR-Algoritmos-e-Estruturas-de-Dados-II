#include <stdio.h>

int mdc(int a, int b) {
	
	if(b==0) return a;
	return mdc(b, a % b);
}

int mdc_iterativo(int a, int b) {

	int aux;

	while(b != 0) {

		aux = a;
		a = b;
		b = aux % b;
	}

	return a;
}

int main () {
	
	int a, b;
	scanf("%d%d", &a,&b);
	printf("%d\n", mdc(a, b));
	printf("%d\n", mdc_iterativo(a, b));
	
	return 0;
}


