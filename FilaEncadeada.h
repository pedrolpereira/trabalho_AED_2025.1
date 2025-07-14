#ifndef FILA_ENCADEADA_H
#define FILA_ENCADEADA_H

#include "ListaDuplamenteEncadeada.h"

/**
 * Classe Fila Encadeada implementada usando composição com ListaDuplamenteEncadeada.
 * Demonstra o pilar da Composição e Encapsulamento.
 * Segue o padrão FIFO (First In, First Out).
 * Utiliza a Lista Duplamente Encadeada para máxima eficiência (O(1) para inserção e remoção).
 */
class FilaEncadeada
{
private:
    ListaDuplamenteEncadeada lista; // Composição: usa uma lista para implementar a fila

public:
    /**
     * Construtor da Fila Encadeada
     */
    FilaEncadeada() = default;

    /**
     * Destrutor da Fila Encadeada
     */
    ~FilaEncadeada() = default;

    /**
     * Enfileira um elemento (adiciona no final)
     * @param elemento Ponteiro para o elemento a ser enfileirado
     * @return true se enfileirado com sucesso, false caso contrário
     * Complexidade: O(1) - Inserção no fim da lista dupla
     */
    bool enfileirar(Elemento *elemento);

    /**
     * Desenfileira um elemento (remove do início)
     * @return Ponteiro para o elemento desenfileirado ou nullptr se vazia
     * Complexidade: O(1) - Remoção do início da lista dupla
     */
    Elemento *desenfileirar();

    /**
     * Consulta o elemento da frente sem removê-lo
     * @return Ponteiro para o elemento da frente ou nullptr se vazia
     * Complexidade: O(1) - Acesso ao primeiro elemento
     */
    Elemento *consultarFrente() const;

    /**
     * Consulta o elemento de trás sem removê-lo
     * @return Ponteiro para o elemento de trás ou nullptr se vazia
     * Complexidade: O(1) - Acesso ao último elemento
     */
    Elemento *consultarTras() const;

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

#endif // FILA_ENCADEADA_H
