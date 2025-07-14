#ifndef FILA_H
#define FILA_H

#include "ListaNaoOrdenada.h"

/**
 * Classe Fila implementada usando composição com ListaNaoOrdenada.
 * Demonstra o pilar da Composição e Encapsulamento.
 * Segue o padrão FIFO (First In, First Out).
 *
 * NOTA: Esta implementação apresenta ineficiência na operação de desenfileirar,
 * pois usa removerPrimeiro() que tem complexidade O(n).
 */
class Fila
{
private:
    ListaNaoOrdenada lista; // Composição: usa uma lista para implementar a fila

public:
    /**
     * Construtor da Fila
     */
    Fila() = default;

    /**
     * Destrutor da Fila
     */
    ~Fila() = default;

    /**
     * Enfileira um elemento (adiciona no final)
     * @param elemento Ponteiro para o elemento a ser enfileirado
     * @return true se enfileirado com sucesso, false caso contrário
     * Complexidade: O(1) - Inserção no final da lista
     */
    bool enfileirar(Elemento *elemento);

    /**
     * Desenfileira um elemento (remove do início)
     * @return Ponteiro para o elemento desenfileirado ou nullptr se vazia
     * Complexidade: O(n) - Remoção do início da lista (INEFICIENTE)
     */
    Elemento *desenfileirar();

    /**
     * Consulta o elemento da frente sem removê-lo
     * @return Ponteiro para o elemento da frente ou nullptr se vazia
     * Complexidade: O(1) - Acesso ao primeiro elemento
     */
    Elemento *consultarFrente() const;

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
    int getTamanho() const;

    /**
     * Imprime todos os elementos da fila (da frente para trás)
     * Complexidade: O(n)
     */
    void imprimirFila() const;
};

#endif // FILA_H
