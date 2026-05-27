// Implemente uma função em linguagem C que seja responsável por ler os nomes de uma sequência
// de apostadores e armazená-los em uma matriz de caracteres (strings). A função deve obedecer aos
// seguintes requisitos:
// 1. Assinatura e Parâmetros: A função deve receber como parâmetros a matriz de strings onde
// os nomes serão armazenados, o número máximo N de cadastros permitidos e uma variável
// (passada por referência/ponteiro) que armazenará a quantidade real de nomes lidos com
// sucesso.
// 2. Restrição de Unicidade: Para cada nome digitado pelo usuário, a função deve verificar se ele
// já foi cadastrado anteriormente na matriz.
// • Se o nome for repetido, o programa deve exibir uma mensagem de erro e solicitar
// que o usuário digite um novo nome para aquela posição.
// • Se o nome for único, ele deve ser aceito e armazenado.
// 3. Condição de Parada: A leitura deve ser interrompida quando o limite máximo N for atingido
// ou quando o usuário digitar uma condição de parada específica (por exemplo, a palavra
// "FIM" ou responder "Não" a uma pergunta de continuidade).

#include <stdio.h>
#include <string.h>
#include "leitura.h"
#define MAX_APOSTADORES 5
#define MAX_CARACTERES 15

void anotarNomes(char nomes[][MAX_CARACTERES], int max, int *qtd){
    char imputNome[MAX_CARACTERES];
    printf("\n\nEscreva o nome dos apostadores ( Máximo de %d ), para encerrar digite 'fim'\n", max);
    for(int i=0; i<max; i++){
        printf("\n%dº apostador: ", i + 1);
        int k;
        lerString(imputNome, MAX_CARACTERES);
        if(strcmp(imputNome, "fim") == 0){
            break;
        }
        for(k = 0; k < *qtd; k++){
            if(strcmp(imputNome, nomes[k]) == 0){
                break;
            }
        }
        if(k == *qtd){
            strcpy(nomes[*qtd], imputNome);
            (*qtd)++;
        }
        else{
            printf("\nNome Repetido! Tente Novamente.\n");
            i--;
        }
    }
}

int main(){
    char nomes[MAX_APOSTADORES][MAX_CARACTERES];
    int qtdApostadores = 0;

    anotarNomes(nomes, MAX_APOSTADORES, &qtdApostadores);

    return 0;
}