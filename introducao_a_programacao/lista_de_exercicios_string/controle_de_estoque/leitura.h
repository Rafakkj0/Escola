/**
 * @file leitura.h
 * @brief Biblioteca para leitura segura e robusta de dados via teclado (stdin).
 * 
 * Esta biblioteca estende as funcionalidades padrões de leitura do C,
 * prevenindo estouro de buffer (Buffer Overflow), tratando caracteres residuais
 * no buffer de entrada (sujeira) e evitando travamentos por fim de arquivo (EOF).
 * 
 * Todas as funções numéricas e de string retornam um padrão booleano:
 * - 1 para SUCESSO (leitura limpa e válida)
 * - 0 para INSUCESSO (entrada inválida ou lixo no buffer)
 */

#ifndef LEITURA_H
#define LEITURA_H

/**
 * @brief Limpa o buffer de entrada padrão (stdin).
 * 
 * Remove todos os caracteres restantes no buffer até encontrar uma quebra de 
 * linha ('\n') ou o fim do arquivo (EOF). É utilizada internamente para purificar
 * a entrada após leituras numéricas ou quando uma string excede o tamanho limite.
 * 
 * @return int Retorna 1 se havia caracteres residuais (lixo) no buffer;
 *             Retorna 0 se o buffer já estava limpo.
 */
int limparBuffer();

/**
 * @brief Lê uma string de forma segura a partir do stdin.
 * 
 * Utiliza o fgets para impedir o estouro de memória. Remove automaticamente o 
 * caractere de quebra de linha ('\n') se ele for capturado. Caso a entrada do 
 * usuário seja maior que o tamanho estipulado, o excesso é descartado de forma segura.
 * 
 * @param texto Vetor de caracteres (char[]) onde a string lida será armazenada.
 * @param tamanho Capacidade máxima de armazenamento do vetor (incluindo o '\0').
 * @return int Retorna 1 para SUCESSO na leitura;
 *             Retorna 0 para INSUCESSO (fim de arquivo / EOF ou falha crítica).
 */
int lerString(char texto[], int tamanho);

/**
 * @brief Lê um número inteiro estritamente válido do teclado.
 * 
 * Valida se a entrada é um número inteiro puro. Se o usuário digitar letras 
 * misturadas com números (ex: "12abc"), a função limpa o buffer e invalida a leitura.
 * 
 * @param valor Ponteiro para a variável inteira onde o dado lido será salvo.
 * @return int Retorna 1 para SUCESSO (inteiro puro);
 *             Retorna 0 para INSUCESSO (entrada inválida ou com lixo).
 */
int lerInt(int *valor);

/**
 * @brief Lê um número real de precisão simples (float) do teclado.
 * 
 * Valida se a entrada corresponde a um float puro. O buffer residual é limpo 
 * e avaliado para garantir que nenhum caractere inválido foi digitado após o número.
 * 
 * @param valor Ponteiro para a variável do tipo float onde o dado lido será salvo.
 * @return int Retorna 1 para SUCESSO (float puro);
 *             Retorna 0 para INSUCESSO (entrada inválida ou com lixo).
 */
int lerFloat(float *valor);

/**
 * @brief Lê um número real de dupla precisão (double) do teclado.
 * 
 * Realiza a leitura segura de um double utilizando a máscara apropriada (%lf).
 * Garante o descarte de qualquer lixo deixado no buffer de entrada e valida a pureza do número.
 * 
 * @param valor Ponteiro para a variável do tipo double onde o dado lido será salvo.
 * @return int Retorna 1 para SUCESSO (double puro);
 *             Retorna 0 para INSUCESSO (entrada inválida ou com lixo).
 */
int lerDouble(double *valor);

int lerChar(char *valor);

#endif // LEITURA_H