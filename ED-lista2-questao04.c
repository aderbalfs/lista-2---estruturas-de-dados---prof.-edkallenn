/*
 Função:
 Autor: Aderbal Ferreira da Silva Filho
 Data: 05/06/2024
 Observações: 
*/

#include <stdio.h>

int ehPrimo(int n) {
    if (n <= 1) return 0;  
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int inicio = 700;
    int fim = 1100;

    for (int num = inicio; num <= fim; num += 2) { 
        printf("Numero par: %d\n", num);

        for (int i = 2; i <= num / 2; i++) {
            if (ehPrimo(i) && ehPrimo(num - i)) {
                printf("%d + %d\n", i, num - i);
                break;
            }
        }
        printf("\n");
    }

    return 0;
}