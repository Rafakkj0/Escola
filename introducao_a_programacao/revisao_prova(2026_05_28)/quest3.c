// Durante um campeonato muito esperado, foi criado um jogo de loteria esportiva em que os
// participantes precisam prever os resultados de 13 partidas. Para cada jogo, o resultado possível é
// representado pelos números 1, 2 ou 3, correspondendo às três colunas de aposta.
// Faça um programa que leia um vetor com 13 números inteiros representando o gabarito oficial das
// partidas. Em seguida, leia, para cada apostador, o nome do apostador (que deve ser único e
// funcionar como seu identificador) e um vetor com 13 números inteiros representando suas
// respostas. O programa deve garantir que não haja dois apostadores com o mesmo nome. Para cada
// participante válido, o programa deve comparar suas respostas com o gabarito e calcular a
// quantidade de acertos obtidos. Essas informações devem ser armazenadas durante a leitura dos
// dados.
// Após a leitura de todos os apostadores (no máximo 100), o programa deve apresentar um relatório
// final mostrando, para cada nome de apostador, a quantidade total de acertos obtidos.

#include <stdio.h>
#include <string.h>

#define QTD_APOSTADORES 100 // Quantidade máxima de apostadores
#define TAM_NOME 16 // Quantidade máxima de caracteres +1
#define QTD_PARTIDAS 3

void limpaBuffer(){
    int ch;
    do{
        ch=getchar();
    }while(ch!='\n' && ch!=EOF);
}

int main(){
    char nome[QTD_APOSTADORES][TAM_NOME], imputNome[TAM_NOME];
    int gabarito[QTD_PARTIDAS], qtdAcertos[QTD_APOSTADORES] = {0}, qtdApostas = 0, imputResultado;
    
    // leitura do gabarito //

    printf("\nOs resultados são representados com os números 1, 2 e 3:\n1 - Vitória da Casa  |  2 - Empate  |  3 - Vitória do Time Mandante\n\nForneça os resultados das partidas:\n");
    for(int i=0; i<QTD_PARTIDAS; i++){
        while(1){
            printf("%dª partida: ", i + 1);
            scanf("%d", &gabarito[i]);
            limpaBuffer();
            if(gabarito[i] >= 1 && gabarito[i] <= 3) break;
            printf("\n%d não é uma resposta valida! Os resultados são representados com os números 1, 2 e 3:\n1 - Vitória da Casa  |  2 - Empate  |  3 - Vitória do Time Mandante\n\n", gabarito[i]);
        }
    }

    // lendo os dados dos apostadores //

    printf("\n\nForneça as apostas dos apostadores:\n");

    for(int i=0; i < QTD_APOSTADORES; i++){
        while(1){
            printf("\nNome do %dº apostador: ", i+1);
            fgets(imputNome, TAM_NOME, stdin);
            int tam = strlen(imputNome);
            if(imputNome[tam - 1] == '\n'){
                imputNome[tam - 1] = '\0';
            }
            else limpaBuffer();
            int achou = 0;
            for(int k=0; k < qtdApostas && achou == 0; k++){
                if(strcmp(imputNome, nome[k]) == 0){
                    achou = 1;
                }
            }
            if(achou == 0){
                strcpy(nome[qtdApostas], imputNome);
                break;
            }
            else{
                printf("\nNome já registrado.\n");
            }
        }

        // lendo as respostas do apostador //

        for(int k=0; k < QTD_PARTIDAS; k++){
            while(1){
                printf("%dª partida: ", k + 1);
                scanf("%d", &imputResultado);
                limpaBuffer();
                if(imputResultado >= 1 && imputResultado <= 3) break;
                printf("\n%d não é uma resposta valida! Os resultados são representados com os números 1, 2 e 3:\n1 - Vitória da Casa  |  2 - Empate  |  3 - Vitória do Time Mandante\n\n", gabarito[i]);
            }
            if(imputResultado == gabarito[k]){
                qtdAcertos[i]++;
            }   
        }

        qtdApostas++;

        printf("\nDeseja sair? 1 - Sim | 0 - Não\n");
        scanf("%d", &imputResultado);
        limpaBuffer();
        if(imputResultado == 1) break;
    }

    // Apresentando os resultados //

    printf("\nNome:\t\tAcertos:\n");
    for(int i=0; i < qtdApostas; i++){
        printf("%s\t\t%d\n", nome[i], qtdAcertos[i]);
    }

    return 0;
}