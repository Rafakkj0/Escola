/*Chico tem 1,50 metros e cresce 2 centímetros por ano, enquanto Zé tem 1,10 metros e cresce 3
centímetros por ano. Construa um programa que calcule e imprima quantos anos serão necessários
para que Zé seja maior que Chico.*/
#include <stdio.h>
#include <locale.h>

//Quantidade que cada um cresce por ano:
#define CRESC_CHICO 0.2;
#define CRESC_ZE 0.3;


int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    int ano = 0;
    float tamanhoChico = 1.5, tamanhoZe = 1.1;
    while (tamanhoZe <= tamanhoChico)
    {
        tamanhoChico += CRESC_CHICO;
        tamanhoZe += CRESC_ZE;
        ano++;
    }
    printf("----------------------------------------\n");
    printf("Daqui a %d anos Zé será maior que Chico!\n", ano);
    printf("----------------------------------------\n");
    return 0;
}