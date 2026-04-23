#include <stdio.h>

#define porCentagemGorjeta 0.1

int main(){
    float valor, gorjeta, valorTotal;
    printf("\n---- Calculadora de gorgeta ----\n\n");
    printf("Valor a pagar: R$");
    scanf("%f",&valor);
    gorjeta = valor * porCentagemGorjeta;
    valorTotal = valor + gorjeta;
    printf("Valor da gorjeta: R$%.2f\n", gorjeta);
    printf("Valor total a pagar: R$%.2f <--\n\n", valorTotal);
    return 0;
}