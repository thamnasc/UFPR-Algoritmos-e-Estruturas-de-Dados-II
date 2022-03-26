#include "ordenacao.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>

/****************************Dados da aluna****************************/
void getNome(char nome[]) {

	strncpy(nome, "Thalita Maria do Nascimento", MAX_CHAR_NOME);
	//adicionada terminação manual para caso de overflow
	nome[MAX_CHAR_NOME-1] = '\0';
}

//a função a seguir deve retornar o número de GRR
unsigned int getGRR() {

	return 20211079;
}
/*********************************************************************/


/**************************Busca Sequencial**************************/
/* x é o elemento procurado
* a é o índice inicial do vetor
* b é o índice final do vetor
*/
int buscaSequencialAux(int x, int v[], int a, int b, int *numComparacoes) {

	//o elemento é menor dos que estão nos vetores
	if(a > b)
		return a - 1;

	*numComparacoes += 1;
	if(x >= v[b]) 
		return b;

	return buscaSequencialAux(x, v, a, b - 1, numComparacoes);
}

int buscaSequencial(int vetor[], int tam, int valor, int *numComparacoes) {

	//zera a variável do ponteiro a cada nova chamada na main
	*numComparacoes = 0;

	return buscaSequencialAux(valor, vetor, 0, tam - 1, numComparacoes);
}
/*********************************************************************/


/*****************************Busca Binária**************************/
/* x é o elemento procurado
* a é o índice inicial do vetor
* b é o índice final do vetor
* m é o índice no meio do vetor
*/
int buscaBinariaAux(int x, int v[], int a, int b, int *numComparacoes) {

	int m;

	//não está no vetor
	if(a > b)
		return -1;

	m = floor((a + b) / 2);

	*numComparacoes += 1;
	if(x == v[m])
		return m;

	//o elemento deve estar na primeira metade
	*numComparacoes += 1;
	if(x < v[m]) 
		return buscaBinariaAux(x, v, a, m - 1, numComparacoes);

	//o elemento deve estar na segunda metade
	return buscaBinariaAux(x, v, m + 1, b, numComparacoes);
}

int buscaBinaria(int vetor[], int tam, int valor, int *numComparacoes) {

	//zera a variável do ponteiro a cada nova chamada na main
	*numComparacoes = 0;

	return buscaBinariaAux(valor, vetor, 0, tam - 1, numComparacoes);
}
/*********************************************************************/


/*********************************Troca******************************/
void troca(int v[], int x, int y) {

	int aux;

	aux = v[x];
	v[x] = v[y];
	v[y] = aux;
}
/********************************************************************/


/****************************Insertion Sort*************************/
/* a é o índice inicial do vetor
* b é o índice final do vetor
*/
void insere(int v[], int a, int b, int *numComparacoes) {

	int p, i;

	p = buscaSequencialAux(v[b], v, a, b - 1, numComparacoes);

	//vai trocando o elemento da vez até chegar na devida posição
	for(i = b; i > p + 1; i--) 
		troca(v, i, i - 1);
}

void insertionSortAux(int v[], int a, int b, int *numComparacoes) {

	if(a >= b)
		return;

	insertionSortAux(v, a, b - 1, numComparacoes);

	insere(v, a, b, numComparacoes);
}

int insertionSort(int vetor[], int tam) {

	//o ponteiro foi criado nesta função
	//para que a variável não seja reinicializada
	//a cada chamada recursiva	

	int comparacao = 0;
	int *numComparacoes = &comparacao;

	insertionSortAux(vetor, 0, tam - 1, numComparacoes);

	return *numComparacoes;
}
/********************************************************************/


/****************************Selection Sort*************************/
/* a é o índice inicial do vetor
* b é o índice final do vetor
*/
int minimo(int v[], int a, int b, int *numComparacoes) {

	int m;

	if(a == b)
		return a;

	m = minimo(v, a, b - 1, numComparacoes);

	*numComparacoes += 1;
	if(v[b] < v[m])
		m = b;

	return m;
}

void selectionSortAux(int v[], int a, int b, int *numComparacoes) {

	if(a >= b)
		return;

	//troca o menor elemento da vez para a devida posição
	troca(v, a, minimo(v, a, b, numComparacoes));

	selectionSortAux(v, a + 1, b, numComparacoes);
}

int selectionSort(int vetor[], int tam) {

	//o ponteiro foi criado nesta função
	//para que a variável não seja reinicializada
	//a cada chamada recursiva

	int comparacao = 0;
	int *numComparacoes = &comparacao;

	selectionSortAux(vetor, 0, tam - 1, numComparacoes);

	return *numComparacoes;
}
/********************************************************************/


/******************************Merge Sort***************************/
/* a é o primeiro índice do vetor
* b é o último índice do vetor
* m é o índice do meio do vetor
*/
void intercala(int v[], int a, int m, int b, int *numComparacoes) {

	int i = a, j = m + 1, k;
	int *u;
	int tam_u = b - a + 1;

	//aloca memória dinamicamente para o vetor auxiliar 
	u = malloc(sizeof(int) * tam_u);

	if(a >= b)
		return;

	for(k = 0; k <= b - a; k++) {

		//verifica se os índices i são maiores ou iguais a m
		//se o índice j não ultrapassou o limite do vetor
		//atribui os elementos ao vetor auxiliar em ordem crescente
		*numComparacoes += 1;
		if((j > b) || ((i <= m) && (v[i] <= v[j]))) {

			u[k] = v[i];
			i++;
		}

		else {

			u[k] = v[j];
			j++;
		}
	}

	//passa os elementos do vetor auxiliar para o vetor original
	for(k = 0; k <= b - a; k++) 
		v[k + a] = u[k];

	//libera a memória alocada
	free(u);
	u = NULL;
}

void mergeSortAux(int v[], int a, int b, int *numComparacoes) {

	int m;

	if(a >= b)
		return;

	m = floor((a + b) / 2);

	mergeSortAux(v, a, m, numComparacoes);

	mergeSortAux(v, m + 1, b, numComparacoes);

	intercala(v, a, m, b, numComparacoes);
}

int mergeSort(int vetor[], int tam) {

	//o ponteiro foi criado aqui para que a variável a qual ele aponta
	//não seja zerada a cada chamada recursiva
	//a escolha também foi feita para manter o padrão com o quicksort
	//já que o particiona não poderia retornar dois valores

	int comparacao = 0;
	int *numComparacoes = &comparacao;

	mergeSortAux(vetor, 0, tam - 1, numComparacoes);

	return *numComparacoes;	
}
/********************************************************************/


/******************************Quick Sort***************************/
/* pivo é o último elemento do vetor
* a é o índice inicial do vetor
* b é o índice final do vetor
*/
int particiona(int pivo, int v[], int a, int b, int *numComparacoes) {

	//o particiona procura a posição em que o elemento
	//pivo deve estar em um vetor ordenado
	int m = a - 1, i;

	for(i = a; i <= b; i++) {

		*numComparacoes += 1;
		if(v[i] <= pivo) {

			m++;
			troca(v, m, i);
		}
	}	

	return m;
}

void quickSortAux(int v[], int a, int b, int *numComparacoes) {

	int m;

	if(a >= b) 
		return;

	m = particiona(v[b], v, a, b, numComparacoes);

	quickSortAux(v, a, m - 1, numComparacoes);

	quickSortAux(v, m + 1, b, numComparacoes);
}

int quickSort(int vetor[], int tam) {

	//o ponteiro foi criado aqui para que a variável a qual ele aponta
	//não seja zerada a cada chamada recursiva

	int comparacao = 0;
	int *numComparacoes = &comparacao;

	quickSortAux(vetor, 0, tam - 1, numComparacoes);

	return *numComparacoes;
}