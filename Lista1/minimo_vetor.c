
// Encontrar o valor mínimo do vetor com recursividade
// 16/02/2022
// Autora: tmn21

#include <stdio.h>

int minimo(int *v, int a, int b) {

    int m;

    if(a == b)
        return a;

    m = minimo(v, a, (b - 1));

    if(v[m] > v[b])
        m = b;

    return m;
}

int main() {

    int v[6] = {4,6,1,0,9,5};

    printf("%d\n", minimo(v, 3, 5));
    
    return 0;
}
