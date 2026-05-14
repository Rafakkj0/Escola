// Durante uma aula de Educação Física, o professor deseja analisar a altura dos alunos da turma. Para
// isso, ele pediu que fossem registradas as alturas de 10 alunos.
// Faça um programa que:
// • Leia a altura de 10 alunos
// • Armazene as alturas em um vetor
// • Calcule a altura média
// • Mostre quantos alunos possuem altura maior que a média

#include <stdio.h>
#include "minhaBiblioteca.h"

#define TAMANHO 10

int main(){
    int vAltura[TAMANHO], qtdAlunosAltos = 0;
    float media;

    printf("\n\nForneça a altura dos %d alunos.\n", TAMANHO);
    lerVetorCont(vAltura, TAMANHO);

    media = mediaVetor(vAltura, TAMANHO);

    for(int i=0; i < TAMANHO; i++){
        if(vAltura[i] > media) qtdAlunosAltos++;
    }

    printf("\nMédia da turma: %.2f\n", media);
    printf("Quantidade de alunos acima da média: %d\n\n", qtdAlunosAltos);
}