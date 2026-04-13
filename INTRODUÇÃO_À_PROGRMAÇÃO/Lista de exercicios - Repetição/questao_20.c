/*Questão 20
Escrever um programa que tenha como entrada um número não determinado de valores para m,
todos inteiros e positivos, um de cada vez. Se m for par, verificar quantos divisores possui e
escrever esta informação. Se m for impar e menor do que 10 calcular e escrever o fatorial de m. Se
m for ímpar e maior ou igual a 10 calcular e escrever a soma dos inteiros de 1 até m.*/

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");

    int entrada, i, qtdDivisores = 0, fatorial, soma = 0;

    while(1){
        printf("-> ");
        scanf("%d",&entrada);
        if(entrada <= 0) break;
        
        if( (entrada % 2) == 0){
            for( i = 1 ; i <= entrada ; i++ ){
                if( ( entrada % i ) == 0 ){
                    qtdDivisores++;
                }
            }
            printf("\nO número %d possuí %d divisores\n\n", entrada, qtdDivisores);
        }
        else{
            if( entrada < 10 ){
                for( i = 1 ; i <= entrada ; i++){
                    if ( i == 1 ){
                        fatorial = 1;
                    }
                    else{
                        fatorial = fatorial * i;
                    }
                }
                printf("\nO fatorial de %d é %d.\n\n", entrada, fatorial);
            }
            else{
                for( i = 1 ; i <= entrada ; i++ ){
                    soma+=i;
                }
                printf("\nA soma dos números de 1 a %d é igual a %d\n\n", entrada, soma);
            }
        }
    }
    return 0;
}