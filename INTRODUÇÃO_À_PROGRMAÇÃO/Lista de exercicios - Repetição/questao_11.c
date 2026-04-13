/*Construir um programa que calcule a média aritmética de vários valores inteiros positivos. O final da leitura acontecerá quando for lido um valor negativo.*/
#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    printf("----------------- Calculadora de média aritmética -----------------\n");
    printf("Forneça números inteiros, para enserrar insira um número negativo.\n");

    int qtdNumeros=0, entrada, soma=0;

    printf("%dº número: ", qtdNumeros + 1);
    scanf("%d",&entrada);
    while (entrada >= 0){
        soma += entrada;
        qtdNumeros++;
        printf("%dº número: ", qtdNumeros + 1);
        scanf("%d",&entrada);
    }
    printf("---------------------------\n");
    if(qtdNumeros >= 2) printf("Média aritmética: %.2f\n", (float)soma / qtdNumeros);
    else printf("Informações insuficiente.\n");
    printf("---------------------------\n");

    return 0;
}