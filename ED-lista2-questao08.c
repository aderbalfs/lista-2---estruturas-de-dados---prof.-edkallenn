/*
 Função:
 Autor: Aderbal Ferreira da Silva Filho
 Data: 05/06/2024
 Observações: 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double parteReal;
    double parteImaginaria;
} NumeroComplexo;

NumeroComplexo* criarNumeroComplexo(double real, double imaginario) {
    NumeroComplexo* num = (NumeroComplexo*)malloc(sizeof(NumeroComplexo));
    if (num != NULL) {
        num->parteReal = real;
        num->parteImaginaria = imaginario;
    }
    return num;
}

void liberarNumeroComplexo(NumeroComplexo* num) {
    if (num != NULL) {
        free(num);
    }
}

NumeroComplexo* lerNumeroComplexo() {
    double real, imaginario;
    printf("Informe a parte real: ");
    scanf("%lf", &real);
    printf("Informe a parte imaginária: ");
    scanf("%lf", &imaginario);
    return criarNumeroComplexo(real, imaginario);
}

NumeroComplexo* adicionarComplexos(NumeroComplexo* num1, NumeroComplexo* num2) {
    return criarNumeroComplexo(num1->parteReal + num2->parteReal, num1->parteImaginaria + num2->parteImaginaria);
}

NumeroComplexo* subtrairComplexos(NumeroComplexo* num1, NumeroComplexo* num2) {
    return criarNumeroComplexo(num1->parteReal - num2->parteReal, num1->parteImaginaria - num2->parteImaginaria);
}

NumeroComplexo* multiplicarComplexos(NumeroComplexo* num1, NumeroComplexo* num2) {
    double real = num1->parteReal * num2->parteReal - num1->parteImaginaria * num2->parteImaginaria;
    double imaginario = num1->parteReal * num2->parteImaginaria + num1->parteImaginaria * num2->parteReal;
    return criarNumeroComplexo(real, imaginario);
}

NumeroComplexo* dividirComplexos(NumeroComplexo* num1, NumeroComplexo* num2) {
    double denominador = num2->parteReal * num2->parteReal + num2->parteImaginaria * num2->parteImaginaria;
    if (denominador == 0) {
        printf("Erro: Divisão por zero!\n");
        return NULL;
    }
    double real = (num1->parteReal * num2->parteReal + num1->parteImaginaria * num2->parteImaginaria) / denominador;
    double imaginario = (num1->parteImaginaria * num2->parteReal - num1->parteReal * num2->parteImaginaria) / denominador;
    return criarNumeroComplexo(real, imaginario);
}

void mostrarNumeroComplexo(NumeroComplexo* num) {
    if (num != NULL) {
        printf("(%lf, %lf)\n", num->parteReal, num->parteImaginaria);
    }
}

int main() {
    NumeroComplexo* num1 = lerNumeroComplexo();
    NumeroComplexo* num2 = lerNumeroComplexo();

    NumeroComplexo* resultadoSoma = adicionarComplexos(num1, num2);
    NumeroComplexo* resultadoSubtracao = subtrairComplexos(num1, num2);
    NumeroComplexo* resultadoMultiplicacao = multiplicarComplexos(num1, num2);
    NumeroComplexo* resultadoDivisao = dividirComplexos(num1, num2);

    printf("Resultado da soma: ");
    mostrarNumeroComplexo(resultadoSoma);

    printf("Resultado da subtração: ");
    mostrarNumeroComplexo(resultadoSubtracao);

    printf("Resultado da multiplicação: ");
    mostrarNumeroComplexo(resultadoMultiplicacao);

    printf("Resultado da divisão: ");
    mostrarNumeroComplexo(resultadoDivisao);

    liberarNumeroComplexo(num1);
    liberarNumeroComplexo(num2);
    liberarNumeroComplexo(resultadoSoma);
    liberarNumeroComplexo(resultadoSubtracao);
    liberarNumeroComplexo(resultadoMultiplicacao);
    liberarNumeroComplexo(resultadoDivisao);

    return 0;
}
