/* Uma melhoria que foi implementada no codigo foi a utilização de ponteiros para acessar o endereço da memória ao qual estão armazenados as variaveis, com eles se evita recalcular o deslocamento da array a cada acesso, melhorando assim o desempenho. Outras vantagens são um melhor gerenciamento da memória.*/

// Função de Insertion Sort usando ponteiros
void insertionSortPonteiro(long* vetor, long total) {
    for (long* i = vetor + 1; i < vetor + total; i++) {
        long elementoAtual = *i;  // Valor do elemento atual
        long* j = i - 1;  // Ponteiro para o elemento à esquerda

        // Mover elementos maiores que o elemento atual para a direita
        while (j >= vetor && *j > elementoAtual) {
            *(j + 1) = *j;  // Mover o elemento para a direita
            j--;
        }

        // Inserir o elemento atual na posição correta
        *(j + 1) = elementoAtual;
    }
}