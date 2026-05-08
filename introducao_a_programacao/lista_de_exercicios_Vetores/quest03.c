// Leia as notas de 30 alunos e calcule quantos ficaram acima da média

#include <stdio.h>
#include "minhaBiblioteca.h"

#define NUM_ALUNOS 30

int main(){
    int cont=0, vNotas[NUM_ALUNOS];
    float media;

    printf("\nForneça a nota dos %d alunos:\n",NUM_ALUNOS);
    lerVetorCont(vNotas, NUM_ALUNOS);

    media = mediaVetor(vNotas, NUM_ALUNOS);

    for(int i=0; i < NUM_ALUNOS; i++){
        if(vNotas[i] > media) cont++;
    }

    printf("\n%d alunos ficaram acima da média!\n",cont);

    return 0;
}