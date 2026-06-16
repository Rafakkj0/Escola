#include <stdio.h>

int main(){
    int dis[6][6] = {
        {0, 63, 210, 190, 0, 190},
        {63, 0, 160, 150, 95, 0},
        {210, 160, 0, 10, 0, 0},
        {190, 150, 10, 0, 0, 0},
        {0, 95, 0, 0, 0, 80},
        {190, 0, 0, 0, 80, 0}
    };
    int rota[6] = {3, 4, 2, 5, 6, 1};
    int posAtual, disPercorrida = 0;

    posAtual = rota[0] - 1;
    for(int i = 1; i < 6; i++){
        disPercorrida += dis[posAtual][rota[i] - 1];
        posAtual = rota[i] - 1;
    }

    printf("Distancia percorrida: %d\n", disPercorrida);
}