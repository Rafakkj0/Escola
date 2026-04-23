#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");

    int qtdClientes, i, nota, codigo, somaNotas1 = 0, somaNotas2 = 0, somaNotas3 = 0, qtdVotos1 = 0, qtdVotos2 = 0, qtdVotos3 = 0, menorNota, clienteMenorNota;
    float media1, media2, media3;

    printf("\nQuantos clientes participaram da pesquisa? ");
    scanf("%d",&qtdClientes);
    if(qtdClientes <= 0) printf("Forneça uma quantidade valida!\n\n");
    else{
        for(i=1 ; i <= qtdClientes ; i++){
            printf("--------------------------------------------------\n");
            printf("    Escolha um lanche do cardapio para avliar!    \n");
            printf("                                                  \n");
            printf("     1 - Hamburguer Byte     2 - Batata Turbo     \n");
            printf("     3 - Milk Shake Mega                          \n");
            printf("                                                  \n");
            printf("Qual lanche deseja avaliar?                       \n");
            printf(" -> ");
            scanf("%d",&codigo);
            while(codigo < 1 || codigo > 3){
                printf("Código invalido, tente novamente!\n");
                printf(" -> ");
                scanf("%d",&codigo);
            }
            printf("Dê uma nota ao lanche de 0 a 5.\n");
            printf(" -> ");
            scanf("%d", &nota);
            while(nota < 0 || nota > 5){
                printf("Forneça uma avaliação valida!\n");
                printf(" -> ");
                scanf("%d", &nota);
            }

            //verificando a menor nota de todas
            if(i == 1){// se for a primeira nota
                menorNota = nota;
                clienteMenorNota = i;
            } 
            else if(nota < menorNota){
                menorNota = nota;
                clienteMenorNota = i;
            }

            // media de cada produto
            switch(codigo){
                case 1:
                    qtdVotos1++;
                    somaNotas1+=nota;
                    break;
                case 2:
                    qtdVotos2++;
                    somaNotas2+=nota;
                    break;
                case 3:
                    qtdVotos3++;
                    somaNotas3+=nota;
                    break;
            }



        }

        media1 = (float)somaNotas1/qtdVotos1;
        media2 = (float)somaNotas2/qtdVotos2;
        media3 = (float)somaNotas3/qtdVotos3;
        
        printf("\n\nQuantidade de avaliações em cada produto:\n");
        printf("Hamburguer Byte: %d\n",qtdVotos1);
        printf("Batata Turbo: %d\n",qtdVotos2);
        printf("Milk Shake Mega: %d\n\n",qtdVotos3);


        printf("Média de cada produto:\n");
        printf("Hamburguer Byte: %.2f\n",media1);
        printf("Batata Turbo: %.2f\n",media2);
        printf("Milk Shake Mega: %.2f\n\n",media3);

        printf("Lanche melhor avaliado: ");
        if(media1 >= media2 && media1 >= media3) printf("Hamburguer Byte\n\n");
        else if(media2 >= media1 && media2 >= media3) printf("Batata Turbo\n\n");
        else printf("Milk Shake Mega\n\n");
        
        printf("Lanche com mais avaliações: ");
        if(qtdVotos1 >= qtdVotos2 && qtdVotos1 >= qtdVotos3) printf("Hamburguer Byte\n\n");
        else if(qtdVotos2 >= qtdVotos1 && qtdVotos2 >= qtdVotos3) printf("Batata Turbo\n\n");
        else printf("Milk Shake Mega\n\n");

        printf("Média das notas do restaurante: %.2f\n\n",(somaNotas1 + somaNotas2 + somaNotas3)/(float)qtdClientes);

        printf("A menor nota foi do cliente de número %d que deu %d como nota.\n\n",clienteMenorNota,menorNota);
    }
    return 0;
}