#include <stdio.h>
#define MAX 3

int busca_vetor(int x, int v[], int a, int b) {

	int r;

	if(a > b)
		return -1;

	r = busca_vetor(x, v, a, b - 1);
	if(r != -1)
		return r;

	if(x == v[b])
		return b;

	return -1;
}

int main() {
	
	int v[MAX] = {2, 7, 3};

	printf("%d\n", busca_vetor(7, v, 0, MAX - 1));

	return 0;
}
