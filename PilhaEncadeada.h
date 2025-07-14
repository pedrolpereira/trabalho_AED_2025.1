#ifndef PILHA_ENCADEADA_H
#define PILHA_ENCADEADA_H

#include "ListaSimplesmenteEncadeada.h"

/**
 * Classe Pilha Encadeada implementada usando composição com ListaSimplesmenteEncadeada.
 * Demonstra o pilar da Composição e Encapsulamento.
 * Segue o padrão LIFO (Last In, First Out).
 * Utiliza a Lista Simplesmente Encadeada para máxima eficiência.
 */
class PilhaEncadeada
{
private:
    ListaSimplesmenteEncadeada lista; // Composição: usa uma lista para implementar a pilha

public:
    /**
     * Construtor da Pilha Encadeada
     */
    PilhaEncadeada() = default;

    /**
     * Destrutor da Pilha Encadeada
     */
    ~PilhaEncadeada() = default;

    /**
     * Empilha um elemento (adiciona no topo)
     * @param elemento Ponteiro para o elemento a ser empilhado
     * @return true se empilhado com sucesso, false caso contrário
     * Complexidade: O(1) - Inserção no início da lista
     */
    bool empilhar(Elemento *elemento);

    /**
     * Desempilha um elemento (remove do topo)
     * @return Ponteiro para o elemento desempilhado ou nullptr se vazia
     * Complexidade: O(1) - Remoção do início da lista
     */
    Elemento *desempilhar();

    /**
     * Consulta o elemento do topo sem removê-lo
     * @return Ponteiro para o elemento do topo ou nullptr se vazia
     * Complexidade: O(1) - Busca pelo primeiro elemento
     */
    Elemento *consultarTopo() const;

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

#endif // PILHA_ENCADEADA_H
