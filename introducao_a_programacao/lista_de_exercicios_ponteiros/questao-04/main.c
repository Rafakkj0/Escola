// Crie uma função  maior(int a, int b, int *resultado)  que compare dois números
// inteiros e armazene, via ponteiro, o maior valor encontrado.

#include <stdio.h>
#include <windows.h>

void maior(int a, int b, int *resultado){
    if(a>b) *resultado = a;
    else *resultado = b;
}

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int a, b, res;

    printf("\nDigite 2 números para descobrir qual é o maior!\n");
    scanf("%d %d", &a, &b);

    maior(a, b, &res);

    printf("\nO maior número é o %d!!\n\n", res);

    return 0;
}