/*Faça um programa que calcule/imprima a fatorial de um n natural.*/
#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");

    int n, fat=1, i;

    printf("\n---- Calculadora de fatorial ----\n");
    printf("Fatorial de: ");
    scanf("%d",&n);

    if(n>=0){
        for( i = 1 ; i <= n ; i++ ){
            fat = fat * i;
        }
        printf("Resultado: %d", fat);
    }
    else printf("O número deve ser maior ou igual a 0.");
    return 0;
}