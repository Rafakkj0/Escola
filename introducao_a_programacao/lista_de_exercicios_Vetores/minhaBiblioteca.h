#ifndef MINHABIBLIOTECA
#define MINHABIBLIOTECA

void lerVetor(int vetor[], int tamanho);
// Função para o úsuario do programa inserir os valores em um lerVetor
//
// int vetor[]
// Posição na memória do vetor que se deseja armazenar os valores
//
// int tamanho
// O tamanho do vetor

void lerVetorCont(int vetor[], int tamanho);
// Função para o úsuario do programa inserir os valores em um lerVetor com um contador ao lado para ele saber em qual elemento está inserindo a informação
//
// int vetor[]
// Posição na memória do vetor que se deseja armazenar os valores
//
// int tamanho
// O tamanho do vetor

void multiplicaVetores(int vetor1[], int vetor2[],int tamanho,int vetorResposta[]);
// Função para multiplicar os valores de duas funções de acordo com as suas casas e aramzenar o resultado em um terceiro vetor
//
// int vetor1[]
// Posição na memória do primeiro vetor para a multiplicação
//
// int vetor2[]
// Posição na memória do segundo vetor para a multiplicação
//
// int tamanho
// Tamanho dos dois vetores
//
// int vetorResposta[]
// Posição na memória do vetor que será armazenado o resultado da multiplicação

float mediaVetor(int vetor[], int tamanho);
// Função que calcula a media dos valores em um vetor
//
// int vetor[]
// Posição na memória do vetor
//
// tamanho
// Tamanho do vetor

int modaVetor(int vetor[], int tamanho);
// Função que verifica a moda do vetor (qual número mais aparece dentro do vetor)
//
// vetor[]
// Endereço do vetor
//
// tamanho
// Tamanho do vetor

#endif