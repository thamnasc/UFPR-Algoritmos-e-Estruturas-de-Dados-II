#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"
#include "testes.h"
#define MAX 1048576

int main() {

    char nome[MAX_CHAR_NOME];

    /* tamanho máximo: 1.048.576 = 2^20   */
    int *vetor = malloc(MAX * sizeof(int));
    if(vetor == NULL){
        printf("Falha fatal. Impossível alocar memoria.\n");
        return 1;
    }

    getNome(nome);
    printf("Trabalho de %s\n", nome);
    printf("GRR %u\n", getGRR());

    printf("\n------Teste para verificar se os algoritmos estão ordenando------");

    printf("\nVetor desordenado: ");
    atribuiVetor(vetor);
    imprimeVetor(vetor, 6);
    
    printf("\nInsertion Sort:    ");
    insertionSort(vetor, 6);
    imprimeVetor(vetor, 6);

    printf("\nSelection Sort:    ");
    atribuiVetor(vetor);
    selectionSort(vetor, 6);
    imprimeVetor(vetor, 6);

    printf("\nMerge Sort:        ");
    atribuiVetor(vetor);
    mergeSort(vetor, 6);
    imprimeVetor(vetor, 6);

    printf("\nQuick Sort:        ");
    atribuiVetor(vetor);
    quickSort(vetor, 6);
    imprimeVetor(vetor, 6);

    /* Testes de custo de comparação e de tempo com algoritmos */
    testeOrdenacao(vetor, 1000);
    testeBusca(vetor, 1000, 42);
    testeOrdenacao(vetor, 2000);
    testeBusca(vetor, 2000, 42);
    testeOrdenacao(vetor, 5000);
    testeBusca(vetor, 5000, 42);
    testeOrdenacao(vetor, 10000);
    testeBusca(vetor, 10000, 42);
    testeOrdenacao(vetor, 20000);
    testeBusca(vetor, 20000, 42);
    testeOrdenacao(vetor, 50000); 
    testeBusca(vetor, 50000, 42);

    free(vetor);
    vetor = NULL;

    return 0;
}
