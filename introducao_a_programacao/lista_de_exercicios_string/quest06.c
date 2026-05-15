// Crie uma função que recebe uma string e um caractere, e apague todas as ocorrências desses
// caractere na string.

#include <stdio.h>
#include "mylib.h"
#define TAMANHO 101



int main(){
    int txt[TAMANHO], c;
    printf("\n- Forneça o texto com no máximo %d caracteres:\n", TAMANHO -1);
    lerString(txt, TAMANHO);

    printf("- Forneça o caractere que deseja remover: ");
    scanf("%c", c);



    return 0;
}