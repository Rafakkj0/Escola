// Implemente uma função que receba dois inteiros e retorne o menor

#include <stdio.h>
#include <windows.h>

int menor(int a, int b);

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int entrada1, entrada2;

    printf("\nForneça dois números para verifcar qual é menor:\n");
    scanf("%d %d", &entrada1, &entrada2);

    printf("O maior número é: %d\n", menor(entrada1, entrada2));

    return 0;
}

int menor(int a, int b){
    if(a<b) return a;
    else return b;
}
