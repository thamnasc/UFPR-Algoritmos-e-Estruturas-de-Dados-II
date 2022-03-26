#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "testes.h"
#include "ordenacao.h"

void testeOrdenacao(int vetor[], int tam) {

    int numComp;

    //variáveis do tipo clock_t
    clock_t start, end;
    
    printf("\n\n------Teste na ordem de %d elementos------", tam);
    
    printf("\nInsertion Sort: ");
    atribuiVetorRandom(vetor, tam);
    //start recebe o "ciclo" corrente
	start = clock();
	numComp = insertionSort(vetor, tam);
    //end recebe o "ciclo" corrente
	end = clock();
	//o tempo total é a diferença dividida pelos ciclos por segundo
    imprimeDados(start, end, numComp);
    
    printf("\nSelection Sort: ");
    atribuiVetorRandom(vetor, tam);
	start = clock();
	numComp = selectionSort(vetor, tam);
	end = clock();
    imprimeDados(start, end, numComp);

    printf("\nMerge Sort: ");
    atribuiVetorRandom(vetor, tam);
	start = clock();
	numComp = mergeSort(vetor, tam);
	end = clock();
    imprimeDados(start, end, numComp);

    printf("\nQuick Sort: ");
    atribuiVetorRandom(vetor, tam);
	start = clock();
	numComp = quickSort(vetor, tam);
	end = clock();
    imprimeDados(start, end, numComp);
}

void atribuiVetorRandom(int vetor[], int tam) {

    //cria uma semente para os números aleatórios
    //por meio do horário do computador
    srand(time(0));

    for(int i = 0; i < tam; i++) 
        vetor[i] = rand();
}

/* função para atribuir valores para verificar os 
 * algoritmos ordenando corretamente
 */
void atribuiVetor(int vetor[]) {

    vetor[0] = 12;
    vetor[1] = 1;
    vetor[2] = -7;
    vetor[3] = 2;
    vetor[4] = 25;
    vetor[5] = 6;
}

void imprimeVetor(int vetor[], int tam) {

    for(int i = 0; i < tam; i++) 
        printf("%d ", vetor[i]);
}

void imprimeDados(clock_t start, clock_t end, int numComp) {

    double total;

    total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nTempo total: %f", total);
    printf("\nNumero de comparacoes feitas: %d \n", numComp);
}

void testeBusca(int vetor[], int tam, int elemento) {

    int idxBusca, numComp;

    //variáveis do tipo clock_t
    clock_t start, end;

    printf("\nBusca Senquencial");
    start = clock();
    idxBusca = buscaSequencial(vetor, tam, elemento, &numComp);
    end = clock();
    printf("\nProcurando %d, Indice do elemento: %d", elemento, idxBusca);
    imprimeDados(start, end, numComp);
    
    printf("\nBusca Binaria");
    start = clock();
    idxBusca = buscaBinaria(vetor, tam, elemento, &numComp);
    end = clock();
    printf("\nProcurando %d, Indice do elemento: %d", elemento, idxBusca);
    imprimeDados(start, end, numComp);
}