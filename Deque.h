#ifndef DEQUE_H
#define DEQUE_H

#include "ListaDuplamenteEncadeada.h"

/**
 * Classe Deque (Double-ended queue) implementada usando composição com ListaDuplamenteEncadeada.
 * Demonstra o pilar da Composição e Encapsulamento.
 * Permite inserção e remoção em ambas as extremidades com eficiência O(1).
 * Utiliza a Lista Duplamente Encadeada para máxima eficiência.
 */
class Deque
{
private:
    ListaDuplamenteEncadeada lista; // Composição: usa uma lista para implementar o deque

public:
    /**
     * Construtor do Deque
     */
    Deque() = default;

    /**
     * Destrutor do Deque
     */
    ~Deque() = default;

    /**
     * Insere um elemento no início (frente) do deque
     * @param elemento Ponteiro para o elemento a ser inserido
     * @return true se inserido com sucesso, false caso contrário
     * Complexidade: O(1) - Inserção no início da lista dupla
     */
    bool inserirFrente(Elemento *elemento);

    /**
     * Insere um elemento no final (trás) do deque
     * @param elemento Ponteiro para o elemento a ser inserido
     * @return true se inserido com sucesso, false caso contrário
     * Complexidade: O(1) - Inserção no fim da lista dupla
     */
    bool inserirTras(Elemento *elemento);

    /**
     * Remove um elemento do início (frente) do deque
     * @return Ponteiro para o elemento removido ou nullptr se vazio
     * Complexidade: O(1) - Remoção do início da lista dupla
     */
    Elemento *removerFrente();

    /**
     * Remove um elemento do final (trás) do deque
     * @return Ponteiro para o elemento removido ou nullptr se vazio
     * Complexidade: O(1) - Remoção do fim da lista dupla
     */
    Elemento *removerTras();

    /**
     * Consulta o elemento da frente sem removê-lo
     * @return Ponteiro para o elemento da frente ou nullptr se vazio
     * Complexidade: O(1) - Acesso ao primeiro elemento
     */
    Elemento *consultarFrente() const;

    /**
     * Consulta o elemento de trás sem removê-lo
     * @return Ponteiro para o elemento de trás ou nullptr se vazio
     * Complexidade: O(1) - Acesso ao último elemento
     */
    Elemento *consultarTras() const;

    /**
     * Verifica se o deque está vazio
     * @return true se vazio, false caso contrário
     * Complexidade: O(1)
     */
    bool dequeVazio() const;

    /**
     * Obtém o tamanho atual do deque
     * @return Número de elementos no deque
     * Complexidade: O(1)
     */
    int getTamanho() const;

    /**
     * Imprime todos os elementos do deque (da frente para trás)
     * Complexidade: O(n)
     */
    void imprimirDeque() const;

    /**
     * Imprime todos os elementos do deque (de trás para frente)
     * Complexidade: O(n)
     */
    void imprimirDequeReverso() const;
};

#endif // DEQUE_H
