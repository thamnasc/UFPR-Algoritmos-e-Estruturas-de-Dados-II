#include <stdio.h>
#define MAX 5

int minimo(int v[], int a, int b) {

	int m;

	if(a == b) 
		return a;
	
	m = minimo(v, a + 1, b);
	if(v[a] < v[b]) 
		m = a;
	return m;
}

int main() {

	int v[MAX] = {1, 16, 5, 7, 6};
	printf("%d\n", minimo(v, 0, 4));
}
