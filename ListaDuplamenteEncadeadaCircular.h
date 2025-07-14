#ifndef LISTA_DUPLAMENTE_ENCADEADA_CIRCULAR_H
#define LISTA_DUPLAMENTE_ENCADEADA_CIRCULAR_H

#include "Elemento.h"

/**
 * Classe que implementa uma Lista Duplamente Encadeada Circular com alocação dinâmica.
 * Demonstra o pilar do Encapsulamento ao esconder completamente a implementação dos nós.
 * Na lista circular, o último nó aponta para o primeiro e vice-versa.
 */
class ListaDuplamenteEncadeadaCircular
{
private:
    /**
     * Classe privada para representar os nós da lista.
     * Demonstra o Encapsulamento ao esconder este detalhe de implementação.
     */
    class No
    {
    public:
        Elemento *elemento;
        No *proximo;
        No *anterior;

        /**
         * Construtor do nó
         * @param elem Ponteiro para o elemento
         * @param prox Ponteiro para o próximo nó
         * @param ant Ponteiro para o nó anterior
         */
        No(Elemento *elem, No *prox = nullptr, No *ant = nullptr)
            : elemento(elem), proximo(prox), anterior(ant) {}
    };

    No *sentinela; // Nó sentinela para facilitar operações (não contém elemento)
    int tamanho;   // Número de elementos na lista

    /**
     * Método auxiliar para encontrar um nó pelo ID
     * @param id ID do elemento procurado
     * @return Ponteiro para o nó encontrado ou nullptr se não encontrado
     * Complexidade: O(n) - Busca linear
     */
    No *encontrarNo(int id) const;

public:
    /**
     * Construtor da Lista Duplamente Encadeada Circular
     */
    ListaDuplamenteEncadeadaCircular();

    /**
     * Destrutor da Lista Duplamente Encadeada Circular
     */
    ~ListaDuplamenteEncadeadaCircular();

    /**
     * Insere um elemento no início da lista
     * @param elemento Ponteiro para o elemento a ser inserido
     * @return true se inserido com sucesso, false caso contrário
     * Complexidade: O(1) - Inserção direta no início
     */
    bool inserirNoInicio(Elemento *elemento);

    /**
     * Insere um elemento no fim da lista
     * @param elemento Ponteiro para o elemento a ser inserido
     * @return true se inserido com sucesso, false caso contrário
     * Complexidade: O(1) - Inserção direta no fim
     */
    bool inserirNoFim(Elemento *elemento);

    /**
     * Remove um elemento pelo ID
     * @param id ID do elemento a ser removido
     * @return Ponteiro para o elemento removido ou nullptr se não encontrado
     * Complexidade: O(n) - Busca linear + remoção O(1)
     */
    Elemento *removerPeloId(int id);

    /**
     * Busca um elemento pelo ID
     * @param id ID do elemento a ser buscado
     * @return Ponteiro para o elemento encontrado ou nullptr se não encontrado
     * Complexidade: O(n) - Busca linear
     */
    Elemento *buscarPeloId(int id) const;

    /**
     * Altera um elemento pelo ID
     * @param id ID do elemento a ser alterado
     * @param novoElemento Ponteiro para o novo elemento
     * @return true se alterado com sucesso, false caso contrário
     * Complexidade: O(n) - Busca linear
     */
    bool alterarPeloId(int id, Elemento *novoElemento);

    /**
     * Verifica se a lista está vazia
     * @return true se vazia, false caso contrário
     * Complexidade: O(1)
     */
    bool estaVazia() const { return tamanho == 0; }

    /**
     * Obtém o tamanho atual da lista
     * @return Número de elementos na lista
     * Complexidade: O(1)
     */
    int getTamanho() const { return tamanho; }

    /**
     * Remove o primeiro elemento da lista
     * @return Ponteiro para o elemento removido ou nullptr se vazia
     * Complexidade: O(1) - Remoção direta do início
     */
    Elemento *removerPrimeiro();

    /**
     * Remove o último elemento da lista
     * @return Ponteiro para o elemento removido ou nullptr se vazia
     * Complexidade: O(1) - Remoção direta do fim
     */
    Elemento *removerUltimo();

    /**
     * Imprime todos os elementos da lista (do início ao fim)
     * @param numVoltas Número de voltas completas na lista circular (padrão: 1)
     * Complexidade: O(n * numVoltas)
     */
    void imprimirTodos(int numVoltas = 1) const;

    /**
     * Imprime todos os elementos da lista (do fim ao início)
     * @param numVoltas Número de voltas completas na lista circular (padrão: 1)
     * Complexidade: O(n * numVoltas)
     */
    void imprimirTodosReverso(int numVoltas = 1) const;
};

#endif // LISTA_DUPLAMENTE_ENCADEADA_CIRCULAR_H
