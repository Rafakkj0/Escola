/*A delegacia de polícia de Alvinópolis conta com somente 3 policiais: o chefe de polícia Johnes, e os policiais Pedrão e Maluzinha. Como é de se esperar, esse pequeno contingente de policiais não consegue atender imediatamente a todos os chamados policiais. Portanto, você foi contratado para criar um sistema de atendimento, implementado usando a Linguagem de Programação C, de maneira que cada um dos policiais fique com um conjunto equilibrado de chamados.
Considere os requisitos:
Cada ocorrência deve ser de um tipo, e as mesmas tem um código:
1 ? Direção Perigosa, 2 - Barulho, 3 ? Bebedeira e 4 - Hero
? Cada ocorrência deve ser de um nível de gravidade: Baixo, Médio e Alto;
? Toda ocorrência do tipo Hero tem nível de gravidade alto;

? Novas ocorrências devem ser atribuídas ao policial com menos ocorrências;
? Ocorrências do tipo Hero sempre são atribuídas ao chefe de polícia.
A cada registro de ocorrência o sistema deve imprimir a quantidade de ocorrências de cada policial. Mostrar no final o total de cada tipo de ocorrência e o número de cada nível de gravidade das ocorrências. O término da entrada de dados é identificado por um tipo de ocorrência diferente das descritas anteriormente.*/

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    
    int codigo, peso, qtdJohnes=0, qtdPedrao=0, qtdMaluzinha=0, qtdBaixo=0, qtdMedio=0, qtdAlto=0, qtdDP=0, qtdBarulho=0, qtdBebedeira=0, qtdHero=0;

    printf("----------------------------------------------\n");
        printf("Qual a ocorrencia: ");
        scanf("%d",&codigo);

    while (codigo > 0 && codigo <=4){
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
        default:
            break;
        }
        if(codigo == 4){
            qtdJohnes++;
            qtdAlto++;
            qtdHero++;
        }
        else{
            printf("Qual o peso da ocorrencia: ");
            scanf("%d",&peso);
            if (peso > 0 && peso <= 3)
            {
                switch (peso)
                {
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
                if(qtdMaluzinha <= qtdPedrao && qtdMaluzinha <= qtdJohnes){
                    qtdMaluzinha++;
                    printf("O caso vai para Maluzinha!\n\n");
                }
                else{
                    if(qtdPedrao <= qtdJohnes && qtdPedrao <= qtdMaluzinha){
                        qtdPedrao++;
                        printf("O caso vai para Pedrão!\n\n");
                    }
                    else{
                        qtdJohnes++;
                        printf("O caso vai para Johnes!\n\n");
                    }
                }
            }
            else{
                printf("Forneça um peso existente.");
            }
        }
        //resultados
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
        printf("Qual a ocorrencia: ");
        scanf("%d",&codigo);
    }
    return 0;
}