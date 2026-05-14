// Desenvolva uma função void incrementar(int *n) que aumente em uma unidade o valor
// da variável apontada.
#include <stdio.h>

void incrementar(int *n){
    *n += 1;
}

int main(){
    int n;
    printf("\nInforme um numero: ");
    scanf("%d", &n);
    incrementar(&n);
    printf("Seu numero +1 e igual a %d\n", n);
}