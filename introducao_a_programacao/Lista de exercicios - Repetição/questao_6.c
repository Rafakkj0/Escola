/*Faça um programa que leia 20 números e imprima a soma dos positivos e o total de números negativos.*/
#include <stdio.h>

#define QUANT_NUMEROS 20

int main(){
    printf("Forneça %d números, os positivos serão somados e os negativos serão contados.\n",   QUANT_NUMEROS   );
    
    int contador = 0, contadorNegativos = 0;
    float soma, numero;
    
    while(contador < QUANT_NUMEROS){
        contador++;
        printf("%d° -> ", contador);
        scanf("%f", &numero);
        if(numero != 0){
            if(numero > 0){
                soma += numero;
            }
            else{
                contadorNegativos++;
            }
        }
        else{
            printf("\nZero não é um número positivo e nem negativo!\n\n");
            contador--;
        }
    }
    printf("\nA soma dos números positivos é %.1f\n", soma);
    printf("Você escreveu %d números negativos.\n", contadorNegativos);
    
    return 0;
}