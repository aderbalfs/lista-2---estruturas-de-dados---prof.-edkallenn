/*
 Função:
 Autor : Aderbal Ferreira da Silva Filho
 Data : 05/06/2024
 Observações: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    char dataNasc[11];
    char documento[15];
    char dataInicio[11];
    float vencimento;
} Trabalhador;

void lerTrabalhador(Trabalhador *trab) {
    printf("Nome: ");
    fgets(trab->nome, 50, stdin);
    trab->nome[strcspn(trab->nome, "\n")] = '\0';

    printf("Data de nascimento (dd/mm/yyyy): ");
    fgets(trab->dataNasc, 11, stdin);
    trab->dataNasc[strcspn(trab->dataNasc, "\n")] = '\0';

    printf("Documento (RG/CPF): ");
    fgets(trab->documento, 15, stdin);
    trab->documento[strcspn(trab->documento, "\n")] = '\0';

    printf("Data de início (dd/mm/yyyy): ");
    fgets(trab->dataInicio, 11, stdin);
    trab->dataInicio[strcspn(trab->dataInicio, "\n")] = '\0';

    printf("Vencimento: ");
    scanf("%f", &trab->vencimento);
    getchar();
}

void imprimirTrabalhador(const Trabalhador *trab) {
    printf("Nome: %s\n", trab->nome);
    printf("Data de nascimento: %s\n", trab->dataNasc);
    printf("Documento: %s\n", trab->documento);
    printf("Data de início: %s\n", trab->dataInicio);
    printf("Vencimento: %.2f\n", trab->vencimento);
}

void removerTrabalhador(Trabalhador **trabalhadores, int *n, int indice) {
    if (indice < 0 || indice >= *n) {
        printf("Índice inválido!\n");
        return;
    }

    for (int i = indice; i < *n - 1; i++) {
        (*trabalhadores)[i] = (*trabalhadores)[i + 1];
    }

    (*n)--;
    *trabalhadores = realloc(*trabalhadores, (*n) * sizeof(Trabalhador));
    if (*trabalhadores == NULL && *n > 0) {
        printf("Erro ao realocar memória!\n");
        exit(1);
    }
}

int main() {
    int n = 0;
    Trabalhador *trabalhadores = NULL;
    int opcao, indice;

    do {
        printf("1. Adicionar trabalhador\n");
        printf("2. Listar trabalhadores\n");
        printf("3. Remover trabalhador\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                n++;
                trabalhadores = realloc(trabalhadores, n * sizeof(Trabalhador));
                if (trabalhadores == NULL) {
                    printf("Erro ao alocar memória!\n");
                    exit(1);
                }
                lerTrabalhador(&trabalhadores[n - 1]);
                break;
            case 2:
                for (int i = 0; i < n; i++) {
                    printf("Trabalhador %d:\n", i + 1);
                    imprimirTrabalhador(&trabalhadores[i]);
                }
                break;
            case 3:
                printf("Índice do trabalhador a ser removido (1 a %d): ", n);
                scanf("%d", &indice);
                getchar();
                removerTrabalhador(&trabalhadores, &n, indice - 1);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 4);

    free(trabalhadores);

    return 0;
}
