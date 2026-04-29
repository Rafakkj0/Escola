// Implemente a função int fatorial(int n, int *resultado)que calcule o fatorial de
// um número inteiro positivo. A função deve verificar se o valor de n é válido (n ≥ 0). Caso o valor
// seja inválido, a função deve retornar 0 indicando erro; caso contrário, deve retornar 1 indicando que
// o cálculo foi realizado com sucesso.
#include <stdio.h>
#include <windows.h>

int fatorial(int n, int *resultado){
    if(n >= 0){
        int fat=1, i;
        for(i=1 ; i <= n ; i++){
            fat*=i;
        }
        *resultado = fat;
        return 1;
    }
    else return 0;
}

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int n, res;

    printf("\nInforme um número: ");
    scanf("%d", &n);

    if(fatorial(n, &res) == 1){
        printf("O fatorial de %d é %d", n, res);
    }
    else printf("\nValor invalido\n");
}