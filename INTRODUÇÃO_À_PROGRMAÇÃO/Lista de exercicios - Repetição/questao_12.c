/*Em uma eleição presidencial existem quatro candidatos, sendo:1-Maria Luíza, 2-Pedro Henrique, 3-Lara Cota e 4-Letícia Cota. Os votos são informados através de códigos. Os dados utilizados para a contagem dos votos obedecem à seguinte codificação:
- 1,2,3,4 = voto para os respectivos candidatos;
- 5 = voto nulo;
- 6 = voto em branco;
Elabore um programa que leia o código do candidato em um voto e calcule/escreva.:
? total de votos para cada candidato;
? total de votos nulos;
? total de votos em branco;
? nome do candidato vencedor. Suponha que não ocorrerá empate.
Como finalizador do conjunto de votos, tem-se o valor 0.*/
#include <stdio.h>
#include <locale.h>

int main(){
    int maria = 0, pedro = 0, lara = 0, leticia = 0, nulo = 0, branco = 0, voto;

    printf("1- Maria Lúiza    2- Pedro Henrique   3- Lara Cota\n");
    printf("4- Letícia Cota   5- Nulo             6- Branco\n");
    printf("                  0- Encerrar\n");
    printf("\n-> ");
    scanf("%d",&voto);

    while(voto != 0){
        switch (voto)
        {
        case 1:
            maria++;
            break;
        case 2:
            pedro++;
            break;
        case 3:
            lara++;
            break;
        case 4:
            leticia++;
            break;
        case 5:
            nulo++;
            break;
        case 6:
            branco++;
            break;
        default:
            printf("Voto invalido! Tente novamente\n");
            break;
        }
        printf("1- Maria Lúiza    2- Pedro Henrique   3- Lara Cota\n");
        printf("4- Letícia Cota   5- Nulo             6- Branco\n");
        printf("                  0- Encerrar\n");
        printf("\n-> ");
        scanf("%d",&voto);
    }
    printf("%d votos para Maria Lúiza\n", maria);
    printf("%d votos para Pedro Henrique\n", pedro);
    printf("%d votos para Lara Cota\n", lara);
    printf("%d votos para Letícia Cota\n", leticia);
    printf("%d votos Nulos\n", nulo);
    printf("%d votos em Branco\n", branco);

    //Verificando o vencedor:

    printf("\n\nO vencedor é: ");
    if(maria > pedro && maria > lara && maria > leticia){
        printf("Maria Lúiza\n");
    }
    else{
        if(pedro > lara && pedro > leticia){
            printf("Pedro Henrique\n");
        }
        else{
            if(lara > leticia){
                printf("Lara Cota\n");
            }
            else{
                printf("Letícia Cota\n");
            }
        }
    }
    return 0;
}