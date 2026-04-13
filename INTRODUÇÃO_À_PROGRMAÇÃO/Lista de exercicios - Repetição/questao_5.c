/*Faça um programa que receba quinze números inteiros positivos do usuário e imprima a soma da raiz quadrada de cada número.*/

#include <stdio.h>
#include <locale.h>
#include <math.h>
#define QUANT_NUMEROS 15

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    float resultado = 0, raiz;
    int input;
    printf("Forneça %d números inteiros e positivos para somar suas raizes.\n", QUANT_NUMEROS);

    int contador = 0;
    while (contador<QUANT_NUMEROS)
    {
        printf("-> ");
        scanf("%d", &input);
        if(input<0){
            printf("Forneça um número inteiro positivo!\n");
        }
        else{
            raiz = sqrt(input);
            printf("Raiz de %d = %.2f\n", input, raiz);
            if(contador>0) printf("%.2f + %.2f = ", resultado, raiz);
            resultado += raiz;
            if(contador>0) printf("%.2f\n\n", resultado);
            contador++;
        }
    }
    printf("Soma das raizes: %.3f\n\n", resultado);
    return 0;
}