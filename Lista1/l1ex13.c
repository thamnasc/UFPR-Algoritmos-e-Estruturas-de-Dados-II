#include <stdio.h>
#define MAX 5

int soma_vetor(int v[], int a, int b) {

	if(a == b) 
		return v[a];
	return v[a] + soma_vetor(v, a + 1, b);
}

int main() {

	int v[MAX] = {1, 2, 3, 4, 5};
	
	printf("%d\n", soma_vetor(v, 0, MAX - 1));

	return 0;
}
