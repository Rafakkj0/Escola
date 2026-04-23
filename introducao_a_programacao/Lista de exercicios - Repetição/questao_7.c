/*Faça um programa que tenha como entrada um conjunto de numeros inteiros. Calcular e imprimir:
a) A media dos numeros lidos;
b) O maior número;
c) O menor número.
Obs. Flag de saida= número zero (não deve ser considerado)*/

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    int numero, maiorNumero, menorNumero, qtdeNumeros = 0;
    float soma;
    
    printf("\n--------------- Calculadora diversa ---------------\n\n");
    printf("Insira os números inteiros que deseja e a calculadora vai informar:\n");
    printf("- A média\n- O maior númeoro\n- O menor número\n");
    printf("\nPara parar concluir e realizar as contas, digite 0 (zero).\n");

    printf("-> ");
    scanf("%d", &numero);

    if(numero != 0){
        maiorNumero = numero;
        menorNumero = numero;
    }


    while (numero != 0)
    {
        soma+=numero;
        qtdeNumeros++;

        if(qtdeNumeros >= 2){
            if(numero > maiorNumero){
                maiorNumero = numero;
            }
            else{
                if(numero < menorNumero){
                    menorNumero = numero;
                }
            }
        }

        printf("-> ");
        scanf("%d", &numero);
    }

    if(qtdeNumeros > 1){
        printf("\nA média dos números é %.2f\n", (float)soma / qtdeNumeros);
        printf("O maior número é %d\n", maiorNumero);
        printf("O menor número é %d\n\n", menorNumero);
    }
    else{
        if(qtdeNumeros == 0) printf("Nenhum número insserido, portanto, nenhum calculo foi realizado.\n\n");
        else printf("Apenas um número insserido, portanto, nenhum calculo foi realizado.\n\n");   
    }
    return 0;
}