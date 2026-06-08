// Faça um programa que gere uma matriz 4x4 de char com a configuração
// 1 0 0 0
// 0 1 0 0
// 0 0 1 0
// 0 0 0 1

#include <stdio.h>

int main(){
    char matriz[4][4];

    for(int l = 0; l < 4; l++){
        for(int c = 0; c < 4; c++){
            if( l == c ) matriz[l][c] = '1';
            else matriz[l][c] = '0';
            printf("%c ", matriz[l][c]);
        }
        printf("\n");
    }
    return 0;
}