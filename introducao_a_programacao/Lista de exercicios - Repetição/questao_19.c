/*Questão 19
Escrever um programa que tenha como entrada um número não determinado de pares de valores
m,n, todos inteiros e positivos, um par de cada vez, e calcula e escreve a soma dos n inteiros
consecutivos a partir de m inclusive.*/
#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    printf("\nSoma de N termos a partir de um número M,\npara encerrar o código digite um número negativo.\n\n");

    int n, m, i, soma = 0;

    while(1){

        printf("Fornaça o números de termos para a soma: ");
        scanf("%d", &n);
        if(n < 0) break;
        if(n == 0){
            printf("\nForneça um número positivo.\n\n");
            continue;
        }

        printf("Forneça em qual número a soma irá iniciar: ");
        scanf("%d", &m);
        if(m < 0) break;

        for( i = 1 ; i <= n ; i++ ){
            soma+=m;
            m++;
        }
        printf("\nResultado da soma é: %d\n\n", soma);
    }
    return 0;
}