// INSERTION SORT

// Nome dos integrantes:
// Eduardo Felipe Hoeft
// Gustavo Nascimento Caballero
// Rafael Augusto dos Anjos


#include <stdio.h>
#include <stdlib.h>
#include "time.h"

void insertionSort(long *vetor, long total) {
    // Laço externo percorre todos os elementos do array começando do segundo elemento 
    for (int i = 1; i < total; i++) {
        int elementoAtual = vetor[i];  // Guarda o elemento atual que será inserido na posição correta
        int j = i - 1;  // Variável para rastrear os elementos anteriores, começando pelo elemento à esquerda do atual

        // Laço para mover os elementos maiores que o elementoAtual uma posição à frente
        // COMPARAÇÃO: Verifica se o elemento anterior é maior que o elemento atual
        while (j >= 0 && vetor[j] > elementoAtual) {
            // TROCA: Mover o elemento arr[j] para a posição j+1 (deslocamento)
            vetor[j + 1] = vetor[j];  // Move o elemento para a direita
            j--;  // Decrementa j para continuar verificando os elementos à esquerda
        }

        // Insere o elemento atual na posição correta (logo após o último elemento menor)
        vetor[j + 1] = elementoAtual;
    }
}

void imprime_vetor(long *vetor, long total){
	for(int i = 0; i < total; i++){
		printf("\nVetor[%d] = %d", i, vetor[i]);
	}
	printf("\n");
}

//gera um vetor ordenado de forma crescente e sem repetição [MELHOR CASO]
void gera_vetor_ordenado_ASC(long *vetor, long n) {
	for(int i = 0; i < n; i++){
		vetor[i] = i;
	}
}

//gera um vetor ordenado de forma DEcrescente e sem repetição [PIOR CASO]
void gera_vetor_ordenado_DESC(long *vetor, long n) {
	int j = n - 1;
	for(int i = 0; i < n; i++){
		vetor[i] = j--;
	}
}

//gera um vetor ordenado de forma aleatória e sem repetição [CASO MÉDIO]
void gera_vetor_aleatorio(long *vetor, long n) {
	int j, aux;
	
	for(long i = 0; i < n; i++){
		vetor[i] = i;
	}
	
	srand(time(0));
	
	//aplica o algoritmo de Fisher-Yates
	for(int i = 0; i < n; i++){
		// gera um número randomico de 0 a n -1
		j = rand() % n;
		// troca de posição
		aux = vetor[i];
		vetor[i] = vetor[j];
		vetor[j] = aux;
	}
}

int main(){
	
	long n = 7; // n controla o total de posições no vetor
	long vetor[n];
	
	printf("Iniciando...\n\n");
		
	//gera_vetor_ordenado_ASC(&vetor[0], n);
	//gera_vetor_ordenado_DESC(&vetor[0], n);
	gera_vetor_aleatorio(&vetor[0], n);
	
	// imprime o vetor antes de ser ordenado
	imprime_vetor(vetor, n);

    // chama a funcao para ordenar o vetor
    insertionSort(&vetor[0], n);
    // imprime o vetor depois de ordenado
    imprime_vetor(vetor, n);
		
	printf("\nFinalizado!!!");
	
}
