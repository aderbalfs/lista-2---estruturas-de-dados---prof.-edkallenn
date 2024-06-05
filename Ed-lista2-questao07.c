/*
 Função:
 Autor: Aderbal Ferreira da Silva Filho
 Data: 05/06/2024
 Observações: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordenacaoRapida(int *array, int inicio, int fim) {
    if (inicio < fim) {
        int esquerda = inicio, direita = fim;
        int pivo = array[(inicio + fim) / 2];
        while (esquerda <= direita) {
            while (array[esquerda] < pivo) esquerda++;
            while (array[direita] > pivo) direita--;
            if (esquerda <= direita) {
                int temp = array[esquerda];
                array[esquerda] = array[direita];
                array[direita] = temp;
                esquerda++;
                direita--;
            }
        }
        ordenacaoRapida(array, inicio, direita);
        ordenacaoRapida(array, esquerda, fim);
    }
}

void mostrarArray(int *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int tamanho = 10;
    int array[tamanho];

    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        array[i] = rand() % 100; // Gera valores aleatórios entre 0 e 99
    }

    printf("Array original:\n");
    mostrarArray(array, tamanho);

    ordenacaoRapida(array, 0, tamanho - 1);

    printf("Array ordenado:\n");
    mostrarArray(array, tamanho);

    return 0;
}
