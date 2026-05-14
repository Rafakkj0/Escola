// Um sistema registra as últimas 10 senhas digitadas incorretamente para análise de segurança.
// Faça um programa que:
// • Leia 10 números representando tentativas de senha
// • Armazene em um vetor
// • Verifique se alguma senha foi digitada duas vezes seguidas
// • Mostre a posição onde isso ocorreu

#include <stdio.h>
#include "minhaBiblioteca.h"

#define TAMANHO 10

int main(){
    int senhasIncorretas[TAMANHO], erro = 0;

    printf("\n\nSenhas incorretas:\n");
    lerVetor(senhasIncorretas, TAMANHO);

    for(int i=0; i < TAMANHO - 1; i++){
        if(senhasIncorretas[i] == senhasIncorretas[i+1]){
            printf("A senha se repete nas posições %d e %d\n", i, i+1);
            erro = 1;
        }
    }
    if(erro == 0) printf("\nNão ouve nenhuma repetição de senha!");
    printf("\n\n");

    return 0;
}

