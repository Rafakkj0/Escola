// Imagine uma matriz 5x5 que representa o mapa de um jogo simples. O número 0 representa o
// caminho livre, o número 1 representa uma parede intransponível, e o número 2 representa a posição
// inicial do nosso personagem. Faça um programa que:
// • Inicialize a matriz estaticamente no código com um caminho válido e algumas paredes.
// • 2. Peça para o usuário digitar um caractere para mover o personagem: 'W' (para cima), 'S'
// (para baixo), 'A' (para esquerda) ou 'D' (para direita).
// • 3. O programa deve calcular a nova posição. Se o movimento for em direção a uma parede
// (1) ou para fora dos limites da matriz (5x5), exiba a mensagem "Colisão! Movimento
// inválido." e mantenha o personagem no mesmo lugar. Caso contrário, atualize a matriz (a
// posição antiga vira 0 e a nova vira 2) e mostre o mapa atualizado.

#include <stdio.h>

void apresentarMapa(int mapa[][5]){
    printf("\n");
    for(int l = 0; l < 5; l++){
        for(int c = 0; c < 5; c++){
            if( mapa[l][c] == 0) printf("🟩​");
            if( mapa[l][c] == 1) printf("🧱​​");
            if( mapa[l][c] == 2) printf("🐈​");
        }
        printf("\n");
    }
}

int main(){
    char entrada;
    int mapa[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {2, 0, 0, 0, 0},
    };
    int possicao[2] = {0, 4};
    
    while(1){
        apresentarMapa(mapa);

        printf("Mover: ");
        scanf(" %c", &entrada);
        if(entrada == 'w' || entrada == 'W'){
            if(possicao[1] > 0 && mapa[possicao[1] - 1][possicao[0]] == 0){
                mapa[possicao[1] - 1][possicao[0]] = 2;
                mapa[possicao[1]][possicao[0]] = 0;
                possicao[1]--;
            }
            else printf("\n[!] Você colidiu em algo, tente alguma outra direção.\n");
        }
        else if(entrada == 'a' || entrada == 'A'){
            if(possicao[0] > 0 && mapa[possicao[1]][possicao[0] - 1] == 0){
                mapa[possicao[1]][possicao[0] - 1] = 2;
                mapa[possicao[1]][possicao[0]] = 0;
                possicao[0]--;
            }
            else printf("\n[!] Você colidiu em algo, tente alguma outra direção.\n");
        }
        else if(entrada == 's' || entrada == 'S'){
            if(possicao[1] < 4 && mapa[possicao[1] + 1][possicao[0]] == 0){
                mapa[possicao[1] + 1][possicao[0]] = 2;
                mapa[possicao[1]][possicao[0]] = 0;
                possicao[1]++;
            }
            else printf("\n[!] Você colidiu em algo, tente alguma outra direção.\n");
        }
        else if(entrada == 'd' || entrada == 'D'){
            if(possicao[0] < 4 && mapa[possicao[1]][possicao[0] + 1] == 0){
                mapa[possicao[1]][possicao[0] + 1] = 2;
                mapa[possicao[1]][possicao[0]] = 0;
                possicao[0]++;
            }
            else printf("\n[!] Você colidiu em algo, tente alguma outra direção.\n");
        }
    }
    
    return 0;
}