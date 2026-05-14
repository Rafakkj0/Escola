#include <stdio.h>
#include <stdlib.h>

int main(){
    float horas, minutosP;
    system("cls");
    printf("Quantas horas sao? Exemplos: '3', '5.9', '16.5'.\n");
    scanf("%f",&horas);
    minutosP = horas * 60;
    printf("\nJa se passaram %.0f minutos hoje.\n\n", minutosP);
    return 0;
}