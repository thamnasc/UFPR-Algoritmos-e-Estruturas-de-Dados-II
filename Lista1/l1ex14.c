#include <stdio.h>
#define MAX 5

void imprime_vetor(int v[]) {

	for(int i = 0; i < MAX; i++)
		printf("%d ", v[i]);
	printf("\n");
}

void inverte_vetor(int v[], int a, int b) {
	
	int aux;

	if(a >= b) 
		return imprime_vetor(v);

	aux = v[a];
	v[a] = v[b];
	v[b] = aux;
	return inverte_vetor(v, a + 1, b - 1);
}


int main() {
	
	int v[MAX] = {1, 2, 3, 4, 5};

	inverte_vetor(v, 0, MAX - 1);

	return 0;
}
