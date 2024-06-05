/*
 Função:
 Autor: Aderbal Ferreira da Silva Filho
 Data: 05/06/2024
 Observações: 
*/

#include <stdio.h>
#include <math.h>

double funcao(double x) {
    return x * x - 2;
}

double derivadaFuncao(double x) {
    return 2 * x;
}

void metodoNewtonRaphson(double chuteInicial, double tolerancia, int maximoIteracoes) {
    double x = chuteInicial;
    int iteracao = 0;

    while (iteracao < maximoIteracoes) {
        double fx = funcao(x);
        double dfx = derivadaFuncao(x);

        if (fabs(dfx) < 1e-6) {
            printf("Derivada próxima de zero, método não converge.\n");
            return;
        }

        double x_proximo = x - fx / dfx;

        printf("Iteração %d: x = %lf\n", iteracao + 1, x_proximo);

        if (fabs(x_proximo - x) < tolerancia) {
            printf("Convergência alcançada em %d iterações: raiz aproximada = %lf\n", iteracao + 1, x_proximo);
            return;
        }

        x = x_proximo;
        iteracao++;
    }

    printf("Máximo de iterações atingido. Raiz aproximada = %lf\n", x);
}

int main() {
    double chuteInicial;
    double tolerancia;
    int maximoIteracoes;

    printf("Digite o valor inicial: ");
    scanf("%lf", &chuteInicial);
    printf("Digite a tolerância: ");
    scanf("%lf", &tolerancia);
    printf("Digite o número máximo de iterações: ");
    scanf("%d", &maximoIteracoes);

    metodoNewtonRaphson(chuteInicial, tolerancia, maximoIteracoes);

    return 0;
}
