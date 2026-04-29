// Desenvolva  uma  função  converter_minutos(int total_min, int *horas, int
// *minutos)  que  converta  um valor  total  de  minutos  em horas   e minutos,  retornando  os  dois
// resultados por referência.
#include <stdio.h>
#include <windows.h>

void converter_minutos(int total_min, int *horas, int *minutos){
    *horas = total_min / 60;
    *minutos = total_min % 60;
}

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int entrada, min, horas;

    printf("Escreva os minutos para converter para horas: ");
    scanf("%d", &entrada);

    converter_minutos(entrada, &horas, &min);

    printf("\n%d minutos são %d horas", entrada, horas);
    if(min>0) printf(" e %d minutos.", min);
    else printf(".");

    return 0;
}