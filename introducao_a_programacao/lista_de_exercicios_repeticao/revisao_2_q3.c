// Questão 03
// Um campeonato possui vários jogadores. O programa deve:
// 1. Ler quantos jogadores irão participar.
// 2. Para cada jogador:
//    - Ler quantas partidas ele jogou
//    - Ler a pontuação de cada partida
// Ao final mostrar:
// - A maior pontuação total obtida por um jogador
// - A menor pontuação total
// - A média geral das pontuações
// - Quantas pontuações foram maiores que 70
#include <stdio.h>
#include <windows.h>

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int qtdJogadores, qtdPartidas, pontuacao, maiorPontuacao, menorPontuacao, somaPontuacao = 0, somaPartidas = 0, qtdPontuacaoAlta = 0, i, p;

    while(1){
        printf("\nQuantidade de jogadores irão participar: ");
        scanf("%d", &qtdJogadores);
        if(qtdJogadores > 0) break;
        else printf("\nValor invalido, tente novamente.\n");
    }
    for(i = 1 ; i <= qtdJogadores ; i++){
        while (1){
            printf("\nQuantidade de partidas que o jogador %d participou: ", i);
            scanf("%d", &qtdPartidas);
            if(qtdPartidas > 0) break;
            else printf("\nValor invalido, tente novamente.\n");
        }
        for(p = 1 ; p <= qtdPartidas ; p++){
            while(1){
                printf("\nPontuação do jogador %d na %dº partida: ", i, p);
                scanf("%d", &pontuacao);
                if(pontuacao>=0) break;
                else printf("\nValor invalido, tente novamente.\n");
            }

            if(p == 1 || pontuacao > maiorPontuacao) maiorPontuacao = pontuacao;

            if(i == 1 && p == 1 || pontuacao < menorPontuacao) menorPontuacao = pontuacao;

            somaPontuacao+=pontuacao;
            somaPartidas++;

            if(pontuacao > 70) qtdPontuacaoAlta++;
        }
        printf("\n> Maior pontuação do jogador %d: %d\n", i, maiorPontuacao);
    }
    printf("\n> Menor pontuação registrada: %d\n", menorPontuacao);
    printf("> Média geral das pontuações: %.2f\n", (float)somaPontuacao / somaPartidas);
    printf("> Quantidade de pontuações maiores que 70: %d\n\n", qtdPontuacaoAlta);

    return 0;
}