// Implemente   a   função  int   separar_digitos(int   num,   int   *dezena,   int
// *unidade)  que receba um número inteiro de dois dígitos e separe seus valores em dezena e
// unidade, armazenando os resultados nos ponteiros fornecidos. A função deve verificar se o número
// informado realmente possui dois dígitos (entre 10 e 99 ou entre -99 e -10. Caso o valor não seja
// válido, a função deve retornar 0 indicando erro; caso contrário, deve retornar 1 indicando que a
// separação foi realizada com sucesso
#include <stdio.h>

int separar_digitos(int num, int *dezena, int *unidade){
    if((num >= 10 && num <= 99)||(num <= -10 && num >= -99)){
        *dezena = num / 10;
        *unidade = num % 10;
        return 1;
    }
    else return 0;
}

int main(){

    int entrada, dezena, unidade;

    printf("\nForneça um número de dois digitos: ");
    scanf("%d", &entrada);

    if( separar_digitos(entrada, &dezena, &unidade) == 1){
        printf("\nDezana: %d\nUnidade: %d\n", dezena, unidade);
    }
    else{
        printf("\nO número informado não possui somente dois digitos.\n");
    }

    return 0;
}