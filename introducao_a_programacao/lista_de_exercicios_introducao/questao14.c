#include <stdio.h>

int main(){
    int a1, an, n, soma;
    printf("--- Calculadora de soma da progrecao aritimetica ---\n");
    printf("Qual o primeiro temrmo da P.A.?  ");
    scanf("%d",&a1);
    printf("Quantos termos quer somar?  ");
    scanf("%d", &n);
    an = a1 + ( n - 1);
    soma = ((a1 + an)*n)/2;
    printf("A soma dos números de %d a %d é %d", a1, an, soma);
    return 0;
}