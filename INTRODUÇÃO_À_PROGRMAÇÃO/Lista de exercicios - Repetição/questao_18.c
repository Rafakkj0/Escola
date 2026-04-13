/*Questão 18
Escrever um programa que leia uma quantidade desconhecida de números e conte quantos deles
estão nos seguintes intervalos: [0.25], [26,50], [51,75] e [76,100]. A entrada de dados deve
terminar quando for lido um número negativo.*/

#include <stdio.h>

#define MIN1 0
#define MAX1 25
#define MIN2 26
#define MAX2 50
#define MIN3 51
#define MAX3 75
#define MIN4 76
#define MAX4 100

int main(){
    printf("Forneça números para verificar quantos deles estão nos seguintes intervalos:\n");
    printf(" 1 - [0, 25]     2 - [26, 50]     3 - [51, 75]     4 - [76, 100]\n\nPara encerrar digite um número negativo\n\n");
    
    float entrada;
    int qtd1 = 0, qtd2 = 0, qtd3 = 0, qtd4 = 0;
    
    while(1){
        printf("-> ");
        scanf("%f", &entrada);
        if (entrada < 0) break;
        
        if(entrada >= MIN1 && entrada <= MAX1) qtd1++;
        else if(entrada >= MIN2 && entrada <= MAX2) qtd2++;
        else if(entrada >= MIN3 && entrada <= MAX3) qtd3++;
        else if(entrada >= MIN4 && entrada <= MAX4) qtd4++;
        else{
            printf("\nO número inserido não corresponde a nenhum intervalo.\nTente novamente!\n\n");
            continue;
        }
    }
    if(qtd1 == 0 && qtd2 == 0 && qtd3 == 0 && qtd4 == 0) printf("\nNenhum número valido foi inserido, portanto não há resultados.\n\n");
    else{
        printf("\nQuantidades de números em cada intervalo:\n");
        printf("1º Intervalo: %d\n", qtd1);
        printf("2º Intervalo: %d\n", qtd2);
        printf("3º Intervalo: %d\n", qtd3);
        printf("4º Intervalo: %d\n\n", qtd4);
    }
    return 0;
}