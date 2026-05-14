/*Escreva um programa que leia 50 valores e encontre o maior e o menor deles. Mostre o resultado*/
#include <stdio.h>
#include <locale.h>

#define QTD_NUMEROS 50

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    float maior, menor, numero, contador;

    printf("\n    Verificador de qual númeoro é menor e qual é o maior    \n");
    printf("Escreva 50 números:\n");
    printf("-> ");
    scanf("%f",&numero);
    menor = numero;
    maior = numero;

    for (contador = 0; contador < QTD_NUMEROS ; contador++)
    {
        printf("-> ");
        scanf("%f",&numero);

        if(numero>maior) maior = numero;
        else if(numero<menor) menor = numero;
    }
    printf("\nO maior número é o %.1f\n", maior);
    printf("O menor número é o %.1f\n", menor);

    return 0;
}