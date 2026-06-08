// Faça um programa que leia as dimensões de uma matriz quadrada de ordem N, onde N é menor ou
// igual a 10. Preencha cada posição da matriz com a soma dos seus próprios índices (ou seja, M[i][j] =
// i + j). Ao final, imprima a matriz na tela em formato de tabela.

#include <stdio.h>

int main(){
    int matriz[10][10];
    int n;

    while(1){
        printf("\nFornaça o tamanho da matriz: ");
        scanf("%d", &n);
        if(n<=10 && n>0) break;
        printf("\n[!] Erro: Informe um número maior que zero e menor ou igual a dez.\n");
    }
    for(int l=0; l<n; l++){
        for(int c=0; c<n; c++){
            matriz[l][c] = l + c;
            printf("%d\t", matriz[l][c]);
        }
        printf("\n");
    }   
}