// Na computação gráfica, as imagens digitais são matrizes de pixels. Quando aplicamos um efeito de
// desfoque (blur), o software calcula a média dos valores dos pixels vizinhos para suavizar a imagem.
// Faça um programa que:
// 1. Crie uma matriz 4x4 de inteiros representando os tons de cinza de uma imagem (valores de
// 0 a 100) preenchida pelo usuário.
// 2. Gere uma segunda matriz (Matriz Modificada). Cada posição interna dessa nova matriz
// (linhas 1 e 2, colunas 1 e 2 — ignorando as bordas para facilitar) deve receber a média
// aritmética entre o seu próprio valor original e os seus 4 vizinhos diretos (cima, baixo,
// esquerda e direita).
// 3. Exiba a matriz original e a matriz com o efeito de desfoque aplicado.

#include <stdio.h>

#define TAMANHO_DA_TELA 4

int main(){
    int tela[TAMANHO_DA_TELA][TAMANHO_DA_TELA];
    float telaBlur[TAMANHO_DA_TELA][TAMANHO_DA_TELA];
    int entrada;

    for(int l = 0; l < TAMANHO_DA_TELA; l++){
        for(int c = 0; c < TAMANHO_DA_TELA; c++){
            while(1){
                printf("Forneça o valor do item de posição (%d, %d): ", c, l);
                scanf("%d", &entrada);
                if(entrada>=0 && entrada <= 100) break;
                printf("Forneça um valor maior ou igual a 0 e menor ou maior que 100.\n");
            }
            tela[l][c] = entrada;
        }
    }

    for(int l = 0; l < TAMANHO_DA_TELA; l++){
        for(int c = 0; c < TAMANHO_DA_TELA; c++){
            if(l > 0 && l < TAMANHO_DA_TELA -1 && c > 0 && c < TAMANHO_DA_TELA -1){
                telaBlur[l][c] = (float)(tela[l][c] + tela[l-1][c] + tela[l+1][c] + tela[l][c-1] + tela[l][c+1])/5;
            }
            else telaBlur[l][c] = tela[l][c];
        }
    }

    printf("\nTela original:\n");

    for(int l = 0; l < TAMANHO_DA_TELA; l++){
        for(int c = 0; c < TAMANHO_DA_TELA; c++){
            printf("%d\t", tela[l][c]);
        }
        printf("\n");
    }

    printf("\nTela com blur:\n");

    for(int l = 0; l < TAMANHO_DA_TELA; l++){
        for(int c = 0; c < TAMANHO_DA_TELA; c++){
            printf("%.1f\t", telaBlur[l][c]);
        }
        printf("\n");
    }

    return 0;
}