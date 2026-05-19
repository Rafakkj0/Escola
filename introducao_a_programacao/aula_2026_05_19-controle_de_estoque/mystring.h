/**
 * @file mystring.h
 * @brief Biblioteca para manipulação  de strings.
 * 
 * Esta biblioteca fornece funções utilitárias para manipulaçãode string
 */

#ifndef MYSTRING_H
#define MYSTRING_H

/**
 * @brief Converte todos os caracteres alfabéticos de uma string para maiúsculas.
 * 
 * Percorre a string caractere por caractere e, caso encontre letras minúsculas 
 * (intervalo de 'a' a 'z'), realiza a conversão para maiúsculas (intervalo de 'A' a 'Z').
 * Caracteres numéricos, símbolos e o terminador '\0' são preservados.
 * 
 * @note A alteração é feita diretamente no vetor original (in-place).
 * 
 * @param str Vetor de caracteres (string) que será convertido.
 */
void converteMaiuscula(char str[]);

/**
 * @brief Converte todos os caracteres alfabéticos de uma string para minúsculas.
 * 
 * Percorre a string caractere por caractere e, caso encontre letras maiúsculas 
 * (intervalo de 'A' a 'Z'), realiza a conversão para minúsculas (intervalo de 'a' a 'z').
 * Caracteres numéricos, símbolos e o terminador '\0' são preservados.
 * 
 * @note A alteração é feita diretamente no vetor original (in-place).
 * 
 * @param str Vetor de caracteres (string) que será convertido.
 */
void converteMinuscula(char str[]);

#endif 