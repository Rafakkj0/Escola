#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TAM_TABULEIRO 6

void imprimirTabuleiro(int mar[][TAM_TABULEIRO]){
    int lin, col;
    printf("Tabuleiro:\n");
    for(lin=0; lin<TAM_TABULEIRO; lin++){
        if(lin == 0){
            printf("X| ");
            for(int l=0; l<TAM_TABULEIRO; l++){
                printf("%d ", l);
            }
            printf("\n");
        }
        for(col=0; col<TAM_TABULEIRO; col++){
            if(col == 0){
                printf("%d|", lin);
            }
            if(mar[lin][col] == 0 || mar[lin][col] == 5){
                printf("🟦");
            }
            if(mar[lin][col] == 1){
                printf("⬛");
            }
            if(mar[lin][col] == 2){
                printf("💥");
            }
        }
        printf("\n");
    }
}

void aleatorizarPosicao(int mar[][TAM_TABULEIRO], int qtd){
    int lin, col;
    srand(time(NULL));
    for(int i=0; i<qtd; i++){
        lin = rand()%6;
        col = rand()%6;
        if(mar[lin][col] == 0){
            mar[lin][col] = 5;
        }
        else{
            i--;
        }
    }
}

int main(){
    int mar[TAM_TABULEIRO][TAM_TABULEIRO] = {0};
    int lin, col;

    aleatorizarPosicao(mar, 6);

    while(1){
        imprimirTabuleiro(mar);
        printf("Qual linha deseja jogar a bomba?\n");
        while(1){
            printf("> ");
            scanf("%d", &lin);
            if(lin >= 0 && lin < TAM_TABULEIRO) break;
        }
        printf("Qual coluna deseja jogar a bomba?\n");
        while(1){
            printf("> ");
            scanf("%d", &col);
            if(col >= 0 && col < TAM_TABULEIRO) break;
        }
        if(mar[lin][col] == 5){
            mar[lin][col] = 2;
            printf("💥 - Navio atingido!!!!\n\n");
        }
        else{
            if(mar[lin][col] == 0){
                mar[lin][col] = 1;
                printf("Nenhum navio atingido.\n\n");
            }
            else printf("Local já explodido, tente outro.\n\n");
        }
    }
    return 0;
}