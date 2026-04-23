#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");

    int codigo, peso, qtdJohnes=0, qtdPedrao=0, qtdMaluzinha=0, qtdBaixo=0, qtdMedio=0, qtdAlto=0, qtdDP=0, qtdBarulho=0, qtdBebedeira=0, qtdHero=0;

    while (1){
        printf("---------- Tipo de Ocorrência: ----------\n");
        printf("1- Direção Perigosa     2- Barulho\n");
        printf("3- Bebedeira            4- Hero\n");
        printf("-> Qual a ocorrencia? ");
        scanf("%d",&codigo);
        if(codigo < 1 && codigo > 4) break;

        switch (codigo)
        {
        case 1:
            qtdDP++;
            break;
        case 2:
            qtdBarulho++;
            break;
        case 3:
            qtdBebedeira++;
            break;
        case 4:
            qtdJohnes++;
            qtdAlto++;
            qtdHero++;
        default:
            break;
        }
        if(codigo != 4){
            printf("------ Gravidade da ocorrência ------\n");
            printf("1- Baixa  2- Media  3- Alta\n");
            printf("-> Qual o peso da ocorrencia? ");
            scanf("%d",&peso);
            if (peso > 0 && peso <= 3){
                switch (peso){
                case 1:
                    qtdBaixo++;
                    break;
                case 2:
                    qtdMedio++;
                    break;
                case 3:
                    qtdAlto++;
                    break;
                default:
                    break;
                }
                if(qtdJohnes <= qtdMaluzinha && qtdJohnes <= qtdJohnes){
                    qtdJohnes++;
                    printf("O caso vai para Maluzinha!\n\n");
                }
                else{
                    if(qtdPedrao <= qtdJohnes && qtdPedrao <= qtdMaluzinha){
                        qtdPedrao++;
                        printf("O caso vai para Pedrão!\n\n");
                    }
                    else{
                        qtdMaluzinha++;
                        printf("O caso vai para Johnes!\n\n");
                    }
                }
            }
            else{
                printf("Forneça um peso existente.");
                peso = 200
            }
        }
        //resultados
        if(peso!=200){
        printf("------------------------------------------------\n");
        printf("Quantidade de casos para o Jones: %d\n",qtdJohnes);
        printf("Quantidade de casos para o Pedão: %d\n",qtdPedrao);
        printf("Quantidade de casos para a Maluzinha: %d\n\n",qtdMaluzinha);

        printf("Quantidade de casos com gravidade Baixa: %d\n",qtdBaixo);
        printf("Quantidade de casos com gravidade Media: %d\n",qtdMedio);
        printf("Quantidade de casos com gravidade Alta: %d\n\n",qtdAlto);

        printf("Quantidade de casos de Direção Perigosa: %d\n",qtdDP);
        printf("Quantidade de casos de Barulho: %d\n",qtdBarulho);
        printf("Quantidade de casos de Bebedeira: %d\n",qtdBebedeira);
        printf("Quantidade de casos de Hero: %d\n",qtdHero);
        printf("------------------------------------------------\n");
        }
    }
    return 0;
}