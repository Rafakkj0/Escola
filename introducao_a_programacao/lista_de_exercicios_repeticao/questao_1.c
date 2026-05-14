/* Faça um programa que imprima os 100 primeiros inteiros positivos. */
#include <stdio.h>
#include <locale.h>

#define NUMEROS 100

int main(){
    setlocale(LC_ALL, "");

    int contador=0;

    while (contador<NUMEROS){
        contador++;
        printf("%d\n", contador);
    }
    return 0;
}