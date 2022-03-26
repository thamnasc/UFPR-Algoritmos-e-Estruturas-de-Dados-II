#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"

int main(){
	char nome[MAX_CHAR_NOME];
	int idxBusca;
	int numComp;

	//Dica: a declaração de vetores pode ser estática ou dinâmica. A alocação dinâmica permite criar vetores maior que estática (se você julgar necessário para seus testes). 
	
	//Descomente para fazer a alocação estática
	/* -------------------------------------------------------------------------- */
	//const unsigned int N = 1048576;    /* tamanho máximo: 1.048.576 = 2^20   */
	//int vetor[N];
	/*-------------------------------------------------------------------------- */
		
	//Descomente para fazer alocação dinâmica
	//const unsigned int N = 1048576;    /* tamanho máximo: 1.048.576 = 2^20   */
	//int* vetor = malloc(N * sizeof(int));
	//if(vetor == NULL){
	//	printf("Falha fatal. Impossível alocar memoria.");
	//	return 1;
	//}
	
	//Depois de alocado, o vetor pode ser utilizado normalmente
	//OBS: Se alocado dinamicamente, não esqueça de desalocar no final do programa via free
		
	vetor[0] = 1;
	vetor[1] = 10;
	vetor[2] = 12;

	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());

	//Para medir o tempo, inclua time.h, e siga o exemplo:
	clock_t start, end;//variáveis do tipo clock_t
    double total;

	start = clock();//start recebe o "ciclo" corrente
	numComp = insertionSort(vetor, 3);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f", total);

	numComp = selectionSort(vetor, 3);
	numComp = mergeSort(vetor, 3);
	numComp = quickSort(vetor, 3);

	for(int i=0; i < 3; i++){
		printf("%d ", vetor[i]);
	}
	idxBusca = buscaSequencial(vetor, 3, 10, &numComp);
	idxBusca = buscaBinaria(vetor, 3, 10, &numComp);

	printf("\n%d %d", idxBusca, numComp);
	printf("\n");

	//Descomente se você alocou o vetor dinamicamente. 
	//free(vetor);

	return 0;
}
