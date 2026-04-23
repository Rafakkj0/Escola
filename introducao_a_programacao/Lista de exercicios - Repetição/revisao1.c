#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");

    double entrada, maiorPositivo, menorPositivo, maiorNegativo, menorNegativo, primeiroPositivo = 0, primeiroNegativo = 0;

    printf("Fornaça os valores para medir quais foram os maiores e menores, para encerrar o programa digite 0.\n");
    
    while(1){
        printf("-> ");
        scanf("%lf",&entrada);
        
        if(entrada == 0) break;

        if(entrada > 0){ // Se for positivo
            if(primeiroPositivo == 0){
                maiorPositivo = entrada;
                menorPositivo = entrada;
                primeiroPositivo = entrada;
            }
            else{
                //verificando se é maior ou menor
                if(entrada > maiorPositivo) maiorPositivo = entrada;
                else if(entrada < menorPositivo) menorPositivo = entrada;
            }
        }
        else{ // Se for negativo
            if(primeiroNegativo == 0){
                maiorNegativo = entrada;
                menorNegativo = entrada;
                primeiroNegativo = entrada;
            }
            else{
                //verificando se é maior ou menor
                if(entrada > maiorNegativo) maiorNegativo = entrada;
                else if(entrada < menorNegativo) menorNegativo = entrada;
            }
        }
    }

    // Mostrando o resultado
    printf("\n\nRESULTADOS:\n\n");
    if(primeiroPositivo != 0) printf("O primeiro número positivo digitado foi: %lf\n",primeiroPositivo);
    if(primeiroNegativo != 0) printf("O primeiro número negativo digitado foi: %lf\n",primeiroNegativo);
    if(primeiroPositivo != 0) {
        printf("O maior valor positivo digitado foi:     %lf\n",maiorPositivo);
        printf("O maior valor positivo digitado foi:     %lf\n",menorPositivo);
    }
    if(primeiroNegativo != 0){
        printf("O maior valor negativo digitado foi:     %lf\n",maiorNegativo);
        printf("O maior valor negativo digitado foi:     %lf\n\n",menorNegativo);
    }
    if(primeiroNegativo == 0 && primeiroPositivo == 0) printf("Nenhum número foi informado,\nportanto não há resultados.\n\n");

    return 0;
}