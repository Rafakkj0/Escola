// Implemente uma função para calcular a soma de dois inteiros.

#include <stdio.h>
#include <windows.h>

int soma(int, int);

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int entrada1, entrada2;

    printf("\nEscreva dois números inteiros para saber sua soma.\n");
    printf("-> ");
    scanf("%d", &entrada1);
    printf("-> ");
    scanf("%d", &entrada2);
    
    printf("Resultado da soma: %d", soma(entrada1, entrada2));

    return 0;
}

int soma(int numero1, int numero2){
    return numero1 + numero2;
}