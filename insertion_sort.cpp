// Nome dos integrantes
// Eduardo Felipe Hoeft
// Gustavo Nascimento Caballero
// Rafael Augusto dos Anjos


#include <iostream>    // Biblioteca para entrada e saída
using namespace std;    // Usa o namespace std para simplificar o uso de elementos da biblioteca padrão

// Função que implementa o Insertion Sort
void insertionSort(int arr[], int n) {
    // Laço externo percorre todos os elementos do array começando do segundo elemento (índice 1)
    for (int i = 1; i < n; i++) {
        int elementoAtual = arr[i];  // Guarda o elemento atual que será inserido na posição correta
        int j = i - 1;  // Variável para rastrear os elementos anteriores, começando pelo elemento à esquerda do atual

        // Laço para mover os elementos maiores que o elementoAtual uma posição à frente
        // COMPARAÇÃO: Verifica se o elemento anterior é maior que o elemento atual
        while (j >= 0 && arr[j] > elementoAtual) {
            // TROCA: Mover o elemento arr[j] para a posição j+1 (deslocamento)
            arr[j + 1] = arr[j];  // Move o elemento para a direita
            j--;  // Decrementa j para continuar verificando os elementos à esquerda
        }

        // Insere o elemento atual na posição correta (logo após o último elemento menor)
        arr[j + 1] = elementoAtual;
    }
}

// Função auxiliar para imprimir o array
void printArray(int arr[], int n) {
    // Laço que percorre o array e imprime cada elemento
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";  // Imprime o elemento seguido de um espaço
    }
    cout << endl;  // Insere uma nova linha após imprimir todos os elementos
}

int main() {
    // Definição de um array de exemplo
    int arr[] = {7, 4, 5, 2, 9};
    int n = sizeof(arr) / sizeof(arr[0]);  // Calcula o tamanho do array (número de elementos)

    cout << "Array antes da ordenacao: ";
    printArray(arr, n);  // Chama a função para imprimir o array antes da ordenação

    insertionSort(arr, n);  // Chama a função para ordenar o array

    cout << "Array apos a ordenacao: ";
    printArray(arr, n);  // Chama a função para imprimir o array após a ordenação

    return 0;  // Indica que o programa terminou com sucesso
}
