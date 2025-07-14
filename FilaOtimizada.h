#ifndef FILA_OTIMIZADA_H
#define FILA_OTIMIZADA_H

#include "Elemento.h"
#include <memory>

/**
 * Classe Fila Otimizada implementada com fila circular.
 * Esta implementação corrige o problema de eficiência da Fila básica.
 * Demonstra o pilar do Encapsulamento ao esconder os detalhes de implementação.
 * Segue o padrão FIFO (First In, First Out) com operações O(1).
 */
class FilaOtimizada
{
private:
    static const int TAMANHO_MAX = 100;      // Capacidade máxima da fila
    std::unique_ptr<Elemento *[]> elementos; // Array circular de ponteiros para elementos
    int frente;                              // Índice do primeiro elemento
    int tras;                                // Índice da próxima posição livre
    int tamanho;                             // Número atual de elementos na fila
    int capacidade;                          // Capacidade máxima da fila

    /**
     * Calcula o próximo índice na fila circular
     * @param indice Índice atual
     * @return Próximo índice na fila circular
     * Complexidade: O(1)
     */
    int proximoIndice(int indice) const;

public:
    /**
     * Construtor da Fila Otimizada
     */
    FilaOtimizada();

    /**
     * Destrutor da Fila Otimizada
     */
    ~FilaOtimizada();

    /**
     * Enfileira um elemento (adiciona no final)
     * @param elemento Ponteiro para o elemento a ser enfileirado
     * @return true se enfileirado com sucesso, false caso contrário
     * Complexidade: O(1) - Inserção direta
     */
    bool enfileirar(Elemento *elemento);

    /**
     * Desenfileira um elemento (remove do início)
     * @return Ponteiro para o elemento desenfileirado ou nullptr se vazia
     * Complexidade: O(1) - Remoção direta (OTIMIZADO)
     */
    Elemento *desenfileirar();

    /**
     * Consulta o elemento da frente sem removê-lo
     * @return Ponteiro para o elemento da frente ou nullptr se vazia
     * Complexidade: O(1) - Acesso direto
     */
    Elemento *consultarFrente() const;

    /**
     * Consulta o elemento de trás sem removê-lo
     * @return Ponteiro para o elemento de trás ou nullptr se vazia
     * Complexidade: O(1) - Acesso direto
     */
    Elemento *consultarTras() const;

    /**
     * Verifica se a fila está cheia
     * @return true se cheia, false caso contrário
     * Complexidade: O(1)
     */
    bool filaCheia() const;

    /**
     * Verifica se a fila está vazia
     * @return true se vazia, false caso contrário
     * Complexidade: O(1)
     */
    bool filaVazia() const;

    /**
     * Obtém o tamanho atual da fila
     * @return Número de elementos na fila
     * Complexidade: O(1)
     */
    int getTamanho() const { return tamanho; }

    /**
     * Imprime todos os elementos da fila (da frente para trás)
     * Complexidade: O(n)
     */
    void imprimirFila() const;
};

#endif // FILA_OTIMIZADA_H
