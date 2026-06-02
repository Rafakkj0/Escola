#include <stdio.h>
/**
 * @brief Apresenta o conteúdo atual da memória
 * Exemplo:
 * [1] [1] [0] [0] [2] [2] [2] [0] [3] [3] | Depois apresenta a quantidade de blocos livres e a quantidade de blocos ocupados.
 * @param memoria Vetor de memória.
 * @param tamanho Tamanho do vetor da memória.
 */
void exibirMemoria(int memoria[], int tamanho);

/**
 * @brief Aloca processo ( First Fit )
 * A estratégia First Fit percorre a memória do início para o fim e utiliza o primeiro bloco livre consecutivo capaz de armazenar o processo.
 * @param memoria Vetor de memória.
 * @param tamanho Tamanho do vetor da memória.
 * @param pid Valor que será armazenado na memória.
 * @param quantidade O tamanho que irá ocupar este PID.
 * @return int Retorna o disperdicio desta estratégia no processo (valor >= 0); Retorna -1 se não tiver espaço sulficiente; Retorna -2 em caso de fragmentação externa; Retorna -3 se a PID já existe na memória.
 */
int alocarFirstFit(int memoria[], int tamanho, int pid, int quantidade);


/**
 * @brief Aloca processo ( Best Fit )
 * A estratégia Best Fit deve escolher o menor bloco livre possível que ainda consiga armazenar o processo..
 * @param memoria Vetor de memória.
 * @param tamanho Tamanho do vetor da memória.
 * @param pid Valor que será armazenado na memória.
 * @param quantidade O tamanho que irá ocupar este PID.
 * @return int Retorna o disperdicio desta estratégia no processo (valor >= 0); Retorna -1 se não tiver espaço sulficiente; Retorna -2 em caso de fragmentação externa; Retorna -3 se a PID já existe na memória.
 */
int alocarBestFit(int memoria[], int tamanho, int pid, int quantidade);


/**
 * @brief Aloca processo ( Worst Fit )
 * A estratégia Worst Fit deve escolher o maior bloco livre disponível.
 * @param memoria Vetor de memória.
 * @param tamanho Tamanho do vetor da memória.
 * @param pid Valor que será armazenado na memória.
 * @param quantidade O tamanho que irá ocupar este PID.
 * @return int Retorna o disperdicio desta estratégia no processo (valor >= 0); Retorna -1 se não tiver espaço sulficiente; Retorna -2 em caso de fragmentação externa; Retorna -3 se a PID já existe na memória.
 */
int alocarWorstFit(int memoria[], int tamanho, int pid, int quantidade);


/**
 * @brief Apaga um processo da memória.
 * @param memoria Vetor de memória.
 * @param tamanho Tamanho do vetor da memória.
 * @param pid Valor que será removido
 * @return int Retorna 0 se for realizado com sucesso; Retorna -1 se o PID não exista na memória.
 */
int liberarProcesso(int memoria[], int tamanho, int pid);


/**
 * @brief Compacta a memória.
 * A compactação move todos os processos para posições de valor baixo removendo os 0s entre eles.
 * @param memoria Vetor de memória.
 * @param tamanho Tamanho do vetor da memória.
 */
void compactarMemoria(int memoria[], int tamanho);


/**
 * @brief Faz um relatório geral da memória.
 * Apresenta o total de blocos, quantidade de blocos livres, quantidade de blocos ocupados, percentual de ocupação, maior bloco livre consecutivo e a quantidade de fragmentos livres. ( fragmentos são a quantidade de conjustos de 0s consecutivos )
 * @param memoria Vetor de memória.
 * @param tamanho Tamanho do vetor da memória.
 */
void relatorioMemoria(int memoria[], int tamanho);


/**
 * @brief Apresenta a eficiencia das estratégias.
 * Calcula a média de disperdicio das 3 estratégias, First Fit, Best Fit, Worst Fit.
 * @param alocacoes Vetor que armazena quantas vezes as estratégias foram ultilizadas.
 * @param desperdicios Vetor que armazena quantos espaços foram disperdiçados.
 */
void relatorioEficiencia(int alocacoes[], int desperdicios[]);


/**
 * @brief Verifica o tamanho do maior fragmento livre
 * @param memoria Vetor de memória.
 * @param tamanho Tamanho do vetor da memória.
 * @return int Retorna o tamanho do maior fragmento livre.
 */
int maiorBlocoLivre(int memoria[], int tamanho);


/**
 * @brief Retorna a quantidade de fragmentos.
 * Fragmentos são conjuntos de 0s consecutivos.
 * @param memoria Vetor de memória.
 * @param tamanho Tamanho do vetor da memória.
 */
int contarFragmentos(int memoria[], int tamanho);


/**
 * @brief Busca uma PID na memória.
 * @param memoria Vetor de memória.
 * @param tamanho Tamanho do vetor da memória.
 * @param pid Valor a ser procurado
 * @return int Retorna a posição da PID; -1 caso ela não exista na memória.
 */
int buscarPID(int memoria[], int tamanho, int pid);

/**
 * @brief Retorna a quantidade de blocos vazios existem na memória.
 * @param memoria Vetor de memória.
 * @param tamanho Tamanho do vetor da memória.
 * @return int Retorna a quantidade de blocos vazios na memória
 */
int contarBlocosVazios(int memoria[], int tamanho);

/**
 * @brief Lê um inteiro positivo.
 * @return int retorna o valor lido (maior que 0); Retorna -1 caso o valor lido é menor ou igual a 0; Retorna -2 caso não for lido nenhum número.
 */
int lerInteiroPositivo();

/**
 * @brief Verifica se a memória está compactada
 * @param memoria Vetor de memória.
 * @param tamanho Tamanho do vetor da memória.
 * @return int Retorna 1 se a memória estiver compactada; Retorna 0 se ela não estiver compactada.
 */
int verificarCompactacao(int memoria[], int tamanho);
