#include <stdio.h>
#include <math.h>

int potencia(int a, int b) {

	if(b == 0) 
		return 1;
	if(b % 2 == 0)
		return potencia(a * a, floor(b / 2));
	return potencia(a * a, floor(b / 2)) * a;
}

int main() {
	
	int a, b;

	scanf("%d %d", &a, &b);
	printf("%d\n", potencia(a, b));

	return 0;
}
