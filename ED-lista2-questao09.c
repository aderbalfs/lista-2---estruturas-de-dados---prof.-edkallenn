/*
 Função:
 Autor: Aderbal Ferreira da Silva Filho
 Data: 05/06/2024
 Observações: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordenacaoBolha(int *arranjo, int tamanho, int *contadorComparacoes, int *contadorTrocas) {
    int i, j, temp;
    *contadorComparacoes = 0;
    *contadorTrocas = 0;

    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - 1 - i; j++) {
            (*contadorComparacoes)++;
            if (arranjo[j] > arranjo[j + 1]) {
                temp = arranjo[j];
                arranjo[j] = arranjo[j + 1];
                arranjo[j + 1] = temp;
                (*contadorTrocas)++;
            }
        }
    }
}

void exibirArranjo(int *arranjo, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arranjo[i]);
    }
    printf("\n");
}

int main() {
    int tamanho;
    int contadorComparacoes, contadorTrocas;

    printf("Informe o número de elementos do arranjo: ");
    scanf("%d", &tamanho);

    int *arranjo = (int *)malloc(tamanho * sizeof(int));
    if (arranjo == NULL) {
        printf("Erro ao alocar memória\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        arranjo[i] = rand() % 100; 
    }

    printf("Arranjo original:\n");
    exibirArranjo(arranjo, tamanho);

    ordenacaoBolha(arranjo, tamanho, &contadorComparacoes, &contadorTrocas);

    printf("Arranjo ordenado:\n");
    exibirArranjo(arranjo, tamanho);

    printf("Número de comparações (ifs): %d\n", contadorComparacoes);
    printf("Número de trocas: %d\n", contadorTrocas);

    free(arranjo);

    return 0;
}
