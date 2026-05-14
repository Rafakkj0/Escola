/*Escreva um programa que calcule a média dos números digitados pelo usuário, se eles forem
pares. Termine a leitura se o usuário digitar zero (0).*/
#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");

    int contador = 0, soma = 0, numero;

    printf("Calculadora de média de números pares inteiros\n");
    printf("Responda com o número 0 para encerrar.\n");
// Coletando os dados:
    while(1){
        printf("Forneça o %dº número: ", contador + 1);
        scanf("%d",&numero);
        if(numero == 0) break;
        if(numero % 2 != 0) {
            printf("\nForneça apenas números pares.\n\n");
            continue;
        }
        contador++;
        soma += numero;
    }
// Apresentando o resultado:
    if(contador > 0) printf("\nA média dos números é: %.2f\n", (float)soma / contador);
    else printf("\nNenhum número valido foi informado\n");

    return 0;
}