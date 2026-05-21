// Para a eleição do BSI, candidatam-se 10 alunos.
// Faça um programa que leia o nome de cada canditado(único) e em seguida leia o voto de cada estudante.
// Ao final, mostrar a mais votado e o nome do vencedor.
// Obs.: Considere empates.

#include <stdio.h>
#include <string.h>

#define NUM_CANDITATOS 3
#define MAX_CARACTERE 101

int main(){
    char nome[NUM_CANDITATOS][MAX_CARACTERE]; // nome dos candidatos
    int votos[NUM_CANDITATOS]={0}; // quantidade de votos para cada candidato

    int voto;

    int i, achou, k;
    for(i=0; i<NUM_CANDITATOS; i++){
        do{
            printf("Forneça o nome do %d° candidato: ", i+1);
            scanf("%s", nome[i]);
            k = 0;
            achou = 0;
            while(k < i && achou == 0){
                if(strcmp(nome[i], nome[k]) == 0){
                    achou = 1;
                }
                else{
                    k++;
                }
            }
            if(achou == 1) printf("Nome Repetido\n");
        }while(achou == 1);
    }

    do{
        for(i=0; i < NUM_CANDITATOS; i++) printf("%d - %s\n", i, nome[i]);
        printf("%d - Fim\n", NUM_CANDITATOS);
        printf("Seu voto: ");
        scanf("%d",&voto);
        //verificando se o voto é valido
        if(voto >= 0 && voto < NUM_CANDITATOS) votos[voto]++;
        else if(voto != NUM_CANDITATOS) printf("[!!!!!]Voto invalido\n");
    }while(voto != NUM_CANDITATOS);

    // Vericando o maior numero de votos:

    int maiorVoto = votos[0];
    for(i=1; i < NUM_CANDITATOS; i++){
        if(votos[i] > maiorVoto) maiorVoto = votos[i];
    }

    // Nomeando o(s) vencedor(es)
    if(maiorVoto != 0){
        printf("---------------------------------\n\nVencedor(es):\n");
        for(i=0; i < NUM_CANDITATOS; i++){
            if(votos[i] == maiorVoto){
                printf("%s\n", nome[i]);
            }
        }
    }
    else printf("\nNão ouve nenhum voto.\n");
    return 0;
}