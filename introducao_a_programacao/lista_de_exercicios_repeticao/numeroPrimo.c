#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");

    int entrada, primo, candidato;

    printf("\n\nForneça um número inteiro positivo. Para encerrar o programa digite 0 ou um número negativo\n\n");

    while(1){
        printf("> ");
        scanf("%d",&entrada);
        if(entrada<=0) break;
        
        primo = 1;
        if(entrada == 1){
            primo = 0;
        }
        else{
            for(candidato = 2 ; candidato <= (entrada / 2) && primo == 1 ; candidato++){
                if(entrada % candidato == 0){
                    primo = 0;
                }
            }   
        }

        printf("\nO número %d ", entrada);
        if(primo == 1) printf("é primo!\n\n");
        else printf("não é primo\n\n");
    }
    return 0;
}