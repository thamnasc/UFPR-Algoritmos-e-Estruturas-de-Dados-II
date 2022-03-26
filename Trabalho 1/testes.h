#ifndef TESTES_H_
#define TESTES_H_

/* testes com os quatro algoritmos de ordenação */
void testeOrdenacao(int vetor[], int tam);

void atribuiVetorRandom(int vetor[], int tam);

void atribuiVetor(int vetor[]);

void imprimeVetor(int vetor[], int tam);

/* imprime tempo em segundos e comparações realizadas */
void imprimeDados(clock_t start, clock_t end, int numComp);

/* teste de busca com Busca Sequencial e Binária */
void testeBusca(int vetor[], int tam, int elemento);

#endif 