#include <stdio.h>


int fat_descend(int n, int k) {
	
	if(k==0) return 1;
	return n * fat_descend(n-1, k-1);
}

int main() {

	
	printf("%d\n",fat_descend(8, 3));
	return 0;
}
