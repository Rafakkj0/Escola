#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ORDEM 10

int main(){
    int mat[ORDEM][ORDEM], lin, col, n;
    int somaDiagonalPrincipal = 0;
    int somaDiagonalSecundaria = 0;
    do{
        printf("Forneça a ordem da matriz (1<=ordem<=%d)\n", ORDEM);
        scanf("%d", &n);
        if(n<1 || n>ORDEM){
            printf("A ordem da matiz está errada!\n");
        }
    }while(n<1 || n>ORDEM);
    srand(time(NULL));
    // percorrendo toda a matriz
    for(lin = 0; lin<n; lin++){
        for(col = 0; col<n; col++){
            mat[lin][col] = rand()%100;
        }
    }

    //imprimindo matriz
    printf("\n\n");
    for(lin = 0; lin<n; lin++){
        for(col = 0; col<n; col++){
            if(lin == col){
                if(lin + col == n -1){
                    printf("{[%d]}\t", mat[lin][col]);
                    somaDiagonalPrincipal += mat[lin][col];
                    somaDiagonalSecundaria += mat[lin][col];
                }
                else{
                    printf("[%d]\t", mat[lin][col]);
                    somaDiagonalPrincipal += mat[lin][col];
                }
            }
            else{
                if(lin + col == n -1){
                    printf("{%d}\t", mat[lin][col]);
                    somaDiagonalSecundaria += mat[lin][col];
                }
                else{
                     printf("%d\t", mat[lin][col]);
                }
            }
        }
        printf("\n");
    }

    printf("\nSoma da diagonal principal: %d\n", somaDiagonalPrincipal);
    printf("Soma da diagonal secundaria: %d\n", somaDiagonalSecundaria);
}