/*
 Função:
 Autor: Aderbal Ferreira da Silva Filho
 Data: 05/06/2024
 Observações: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char codigo[4];  
    char cidade[51]; 
    char pais[31];  
    float taxaUso;
    int capacidadeMax;
} Aeroporto;

void lerAeroporto(Aeroporto *aeroporto) {
    printf("Código do aeroporto (3 caracteres): ");
    fgets(aeroporto->codigo, 4, stdin);
    aeroporto->codigo[strcspn(aeroporto->codigo, "\n")] = '\0';

    printf("Cidade: ");
    fgets(aeroporto->cidade, 51, stdin);
    aeroporto->cidade[strcspn(aeroporto->cidade, "\n")] = '\0';

    printf("País: ");
    fgets(aeroporto->pais, 31, stdin);
    aeroporto->pais[strcspn(aeroporto->pais, "\n")] = '\0';

    printf("Taxa de uso: ");
    scanf("%f", &aeroporto->taxaUso);
    getchar();

    printf("Capacidade máxima: ");
    scanf("%d", &aeroporto->capacidadeMax);
    getchar();
}

void imprimirAeroporto(const Aeroporto *aeroporto) {
    printf("Código: %s\n", aeroporto->codigo);
    printf("Cidade: %s\n", aeroporto->cidade);
    printf("País: %s\n", aeroporto->pais);
    printf("Taxa de uso: %.2f\n", aeroporto->taxaUso);
    printf("Capacidade máxima: %d\n", aeroporto->capacidadeMax);
}

void removerAeroporto(Aeroporto **aeroportos, int *n, int indice) {
    if (indice < 0 || indice >= *n) {
        printf("Índice inválido!\n");
        return;
    }

    free(aeroportos[indice]);
    for (int i = indice; i < *n - 1; i++) {
        aeroportos[i] = aeroportos[i + 1];
    }

    (*n)--;
    aeroportos = realloc(aeroportos, (*n) * sizeof(Aeroporto *));
    if (aeroportos == NULL && *n > 0) {
        printf("Erro ao realocar memória!\n");
        exit(1);
    }
}

int main() {
    int quantidade = 0;
    Aeroporto **aeroportos = NULL;
    int escolha, indice;

    do {
        printf("1. Adicionar aeroporto\n");
        printf("2. Listar aeroportos\n");
        printf("3. Remover aeroporto\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);
        getchar();

        switch (escolha) {
            case 1:
                quantidade++;
                aeroportos = realloc(aeroportos, quantidade * sizeof(Aeroporto *));
                if (aeroportos == NULL) {
                    printf("Erro ao alocar memória!\n");
                    exit(1);
                }
                aeroportos[quantidade - 1] = malloc(sizeof(Aeroporto));
                if (aeroportos[quantidade - 1] == NULL) {
                    printf("Erro ao alocar memória!\n");
                    exit(1);
                }
                lerAeroporto(aeroportos[quantidade - 1]);
                break;
            case 2:
                for (int i = 0; i < quantidade; i++) {
                    printf("Aeroporto %d:\n", i + 1);
                    imprimirAeroporto(aeroportos[i]);
                }
                break;
            case 3:
                printf("Índice do aeroporto a ser removido (1 a %d): ", quantidade);
                scanf("%d", &indice);
                getchar();
                removerAeroporto(aeroportos, &quantidade, indice - 1);
                break;
            case 4:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (escolha != 4);

    for (int i = 0; i < quantidade; i++) {
        free(aeroportos[i]);
    }
    free(aeroportos);

    return 0;
}
