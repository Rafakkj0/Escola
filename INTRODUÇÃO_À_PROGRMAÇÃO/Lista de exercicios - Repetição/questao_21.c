/*Questão 21
Faça um programa que tenha como entrada um conjunto não determinado de pares de valores a, b,
e para cada par lido, obtém o M.D.C. e o M.M.C. de a,b, escrevendo-os juntamente com os valores
lidos.*/
#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");

    printf("\n--- Calculadora de M.D.C. e M.M.C de dois termos --- \n");
    printf("Forneça o valor de A e B para receber o resultado,\ndigite 0 ou um número negativo para encerrar.\n");

    int a, b, i, mdc = 0, mmc = 0;

    while(1){
        printf("\nA = ");
        scanf("%d", &a);
        if(a <= 0) break;
        printf("B = ");
        scanf("%d", &b);
        if(b <= 0) break;
        if(a == b){
            printf("\nForneça números distintos. Tente novamente.\n");
            continue;
        }

        if( a < b ) i = a;
        else i = b;
        for( mdc = 0 ; mdc == 0 ; i--){
            if( (a % i) == 0 && (b % i) == 0){
                mdc = i;
            }
        }

        for( i = 1 ; mmc == 0 ; i++){
            if( (i % a) == 0 && (i % b) == 0){
                mmc = i;
            }
        }

        printf("\nO M.D.C. é %d\n", mdc);
        printf("O M.M.C. é %d\n", mmc);
    }
    return 0;
}