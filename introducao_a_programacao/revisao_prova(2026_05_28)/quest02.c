// Um mapa é representado por um vetor de números inteiros, onde:
// 0: representa água
// 1: representa terra
// Uma ilha é formada por três ou mais valores 1 consecutivos no vetor.
// Você deve implementar um programa que:
// 1. Leia 15 valores (apenas 0 ou 1)
// 2. Armazene esses valores em um vetor
// 3. Conte quantas ilhas existem no vetor
// 4. Identifique o índice de início e o índice de fim da maior ilha
// 5. Em caso de empate(duas ou mais ilhas com o mesmo tamanho máximo), retorne o índice da
// primeira maior ilha encontrada
// Entrada:
// 15 números inteiros, cada um podendo ser 0 ou 1, separados por espaço ou quebra de linha
// Saída:
// O número total de ilhas encontradas
// O índice inicial e o índice final da maior ilha (considerando o vetor com índices de 0 a 14)


#include <stdio.h>

#define TAM_MAPA 15

void verificarIlhas(int mapa[], int tamanho, int *qtdIlhas, int *inicioMaiorIlha, int *fimMaiorIlha){
    int tamIlha, tamMaiorIlha = 0, i, k;
    for(i=0; i < tamanho; i++){
        if(mapa[i] == 1){
            tamIlha = 0;
            for(k = i; k < tamanho && mapa[k] == 1; k++){
                tamIlha++;
            }
            if(tamIlha >= 3){
                (*qtdIlhas)++;

                if(tamIlha > tamMaiorIlha){
                    tamMaiorIlha = tamIlha;
                    *inicioMaiorIlha = i;
                    *fimMaiorIlha = k-1;
                }
                
            }
        }
        i+=tamIlha;
    }
}

int main(){
    int mapa[TAM_MAPA], qtdIlhas = 0, inicioMaiorIlha, fimMaiorIlha;

    printf("\nForneça o mapa (0 para água, 1 para terra):\n");
    for(int i=0; i < TAM_MAPA; i++){
        printf("%dº codernada: ", i);
        if(scanf("%d", &mapa[i]) == 0){
            printf("Erro, tente novamente.\n");
            i--;
        }
    }

    verificarIlhas(mapa, TAM_MAPA, &qtdIlhas, &inicioMaiorIlha, &fimMaiorIlha);

    printf("\nQuantidade de ilhas: %d", qtdIlhas);
    printf("\nCodernada de inicio maior ilha: %d", inicioMaiorIlha);
    printf("\nCordenada do fim da maior ilha: %d\n\n", fimMaiorIlha);

    return 0;
}