// Leia 15 idades e mostre a moda (idade que mais aparece).

#include <stdio.h>
#include "minhaBiblioteca.h"

#define TAMANHO 15

int main(){
    int vIdades[TAMANHO], moda;

    printf("\n\nForneça %d valores para verificar qual a moda:\n", TAMANHO);
    lerVetor(vIdades, TAMANHO);

    moda = modaVetor(vIdades, TAMANHO);

    printf("\nA moda é o número %d.\n\n", moda);

    return 0;
}