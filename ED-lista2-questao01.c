/*
 Função 
 Autor :Aderbal Ferreira da Silva Filho
 Data : 05/06/2024
 Observações: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordenarPorSelecao(int vetor[], int tamanho) {
    int i, j, indiceMin;

    for (i = 0; i < tamanho - 1; i++) {
        indiceMin = i;
        for (j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[indiceMin]) {
                indiceMin = j;
            }
        }
        int temp = vetor[indiceMin];
        vetor[indiceMin] = vetor[i];
        vetor[i] = temp;
    }
}

void gerarVetorAleatorio(int vetor[], int tamanho) {
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100;
    }
}

void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int tamanho = 10;
    int meuVetor[tamanho];

    gerarVetorAleatorio(meuVetor, tamanho);

    printf("Vetor original:\n");
    imprimirVetor(meuVetor, tamanho);

    ordenarPorSelecao(meuVetor, tamanho);

    printf("Vetor ordenado:\n");
    imprimirVetor(meuVetor, tamanho);

    return 0;
}
