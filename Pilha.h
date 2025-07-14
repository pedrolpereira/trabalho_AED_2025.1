#ifndef PILHA_H
#define PILHA_H

#include "ListaNaoOrdenada.h"

/**
 * Classe Pilha implementada usando composição com ListaNaoOrdenada.
 * Demonstra o pilar da Composição e Encapsulamento.
 * Segue o padrão LIFO (Last In, First Out).
 */
class Pilha
{
private:
    ListaNaoOrdenada lista; // Composição: usa uma lista para implementar a pilha

public:
    /**
     * Construtor da Pilha
     */
    Pilha() = default;

    /**
     * Destrutor da Pilha
     */
    ~Pilha() = default;

    /**
     * Empilha um elemento (adiciona no topo)
     * @param elemento Ponteiro para o elemento a ser empilhado
     * @return true se empilhado com sucesso, false caso contrário
     * Complexidade: O(1) - Inserção no final da lista
     */
    bool empilhar(Elemento *elemento);

    /**
     * Desempilha um elemento (remove do topo)
     * @return Ponteiro para o elemento desempilhado ou nullptr se vazia
     * Complexidade: O(1) - Remoção do final da lista
     */
    Elemento *desempilhar();

    /**
     * Consulta o elemento do topo sem removê-lo
     * @return Ponteiro para o elemento do topo ou nullptr se vazia
     * Complexidade: O(1) - Acesso direto ao último elemento
     */
    Elemento *consultarTopo() const;

    /**
     * Verifica se a pilha está cheia
     * @return true se cheia, false caso contrário
     * Complexidade: O(1)
     */
    bool pilhaCheia() const;

    /**
     * Verifica se a pilha está vazia
     * @return true se vazia, false caso contrário
     * Complexidade: O(1)
     */
    bool pilhaVazia() const;

    /**
     * Obtém o tamanho atual da pilha
     * @return Número de elementos na pilha
     * Complexidade: O(1)
     */
    int getTamanho() const;

    /**
     * Imprime todos os elementos da pilha (do topo para a base)
     * Complexidade: O(n)
     */
    void imprimirPilha() const;
};

#endif // PILHA_H
