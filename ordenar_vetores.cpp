#include <stdio.h>
#include <stdlib.h>
#include "time.h"

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
	
	long n = 50000; // n controla o total de posições no vetor
	long vetor[n];
	
	printf("Iniciando...\n\n");
		
	//gera_vetor_ordenado_ASC(&vetor[0], n);
	//gera_vetor_ordenado_DESC(&vetor[0], n);
	gera_vetor_aleatorio(&vetor[0], n);
	
	// imprime o vetor
	imprime_vetor(vetor, n);
		
	printf("\nFinalizado!!!");
	
	
	
}
