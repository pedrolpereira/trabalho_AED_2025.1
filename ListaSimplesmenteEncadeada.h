#ifndef LISTA_SIMPLESMENTE_ENCADEADA_H
#define LISTA_SIMPLESMENTE_ENCADEADA_H

#include "Elemento.h"

/**
 * Classe que implementa uma Lista Simplesmente Encadeada com alocação dinâmica.
 * Demonstra o pilar do Encapsulamento ao esconder completamente a implementação dos nós.
 */
class ListaSimplesmenteEncadeada
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

        /**
         * Construtor do nó
         * @param elem Ponteiro para o elemento
         * @param prox Ponteiro para o próximo nó
         */
        No(Elemento *elem, No *prox = nullptr) : elemento(elem), proximo(prox) {}
    };

    No *cabeca;  // Ponteiro para o primeiro nó
    int tamanho; // Número de elementos na lista

    /**
     * Método auxiliar para encontrar um nó pelo ID
     * @param id ID do elemento procurado
     * @return Ponteiro para o nó encontrado ou nullptr se não encontrado
     * Complexidade: O(n) - Busca linear
     */
    No *encontrarNo(int id) const;

    /**
     * Método auxiliar para encontrar o nó anterior a um nó com determinado ID
     * @param id ID do elemento procurado
     * @return Ponteiro para o nó anterior ou nullptr se não encontrado
     * Complexidade: O(n) - Busca linear
     */
    No *encontrarNoAnterior(int id) const;

public:
    /**
     * Construtor da Lista Simplesmente Encadeada
     */
    ListaSimplesmenteEncadeada();

    /**
     * Destrutor da Lista Simplesmente Encadeada
     */
    ~ListaSimplesmenteEncadeada();

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
     * Complexidade: O(n) - Precisa percorrer até o final
     */
    bool inserirNoFim(Elemento *elemento);

    /**
     * Remove um elemento pelo ID
     * @param id ID do elemento a ser removido
     * @return Ponteiro para o elemento removido ou nullptr se não encontrado
     * Complexidade: O(n) - Busca linear + remoção
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
    bool estaVazia() const { return cabeca == nullptr; }

    /**
     * Obtém o tamanho atual da lista
     * @return Número de elementos na lista
     * Complexidade: O(1)
     */
    int getTamanho() const { return tamanho; }

    /**
     * Imprime todos os elementos da lista
     * Complexidade: O(n)
     */
    void imprimirTodos() const;

    /**
     * Remove o primeiro elemento da lista
     * @return Ponteiro para o elemento removido ou nullptr se vazia
     * Complexidade: O(1) - Remoção direta do início
     */
    Elemento *removerPrimeiro();

    /**
     * Remove o último elemento da lista
     * @return Ponteiro para o elemento removido ou nullptr se vazia
     * Complexidade: O(n) - Precisa percorrer até o penúltimo
     */
    Elemento *removerUltimo();
};

#endif // LISTA_SIMPLESMENTE_ENCADEADA_H
