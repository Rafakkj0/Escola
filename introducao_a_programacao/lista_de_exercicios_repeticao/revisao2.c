#include <stdio.h>
#include <locale.h>

#define NOTA_MAXIMA 10
#define NOTA_MINIMA 0

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    
    int qtdMalabaristas,
        somaNotas = 0,
        i, //contador
        nota,
        maiorNota,
        menorNota;

    printf("\nQuantas malabaristas vão apresentar? ");
    scanf("%d", &qtdMalabaristas);
    if(qtdMalabaristas <= 0) printf("\nValor invalido!!\n");

    else{
        for(i = 1 ; i <= qtdMalabaristas ; i++){
            printf("Forneça a nota da %dº malabarista: ",i);
            scanf("%d", &nota);

            // Verificando se a resposta é vaida
            if(nota < NOTA_MINIMA || nota > NOTA_MAXIMA){
                printf("Forneça um valor valido! ( 0 - 10 )\n");
                i--;
                continue;
            }

            // Registrando notas
            somaNotas += nota;
            if(i==1){
                maiorNota = nota;
                menorNota = nota;
            }
            else{
                if(nota > maiorNota) maiorNota = nota;
                else if(nota < menorNota) menorNota = nota;
            }
        }
        // Resultados:
        printf("\nMédia das notas: %.2f\n", (float)somaNotas / qtdMalabaristas);
        printf("Maior nota: %d\n", maiorNota);
        printf("Menor nota: %d\n\n", menorNota);
    }

    return 0;
}