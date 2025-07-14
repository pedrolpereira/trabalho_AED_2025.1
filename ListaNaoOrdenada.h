#ifndef LISTA_NAO_ORDENADA_H
#define LISTA_NAO_ORDENADA_H

#include "Elemento.h"

/**
 * Classe que implementa uma Lista Não Ordenada com alocação sequencial.
 * Demonstra o pilar do Encapsulamento ao esconder os detalhes de implementação.
 */
class ListaNaoOrdenada
{
private:
    static const int TAMANHO_MAX = 100; // Capacidade máxima da lista
    Elemento **elementos;               // Array de ponteiros para elementos
    int tamanho;                        // Número atual de elementos na lista
    int capacidade;                     // Capacidade máxima da lista

public:
    /**
     * Construtor da Lista Não Ordenada
     */
    ListaNaoOrdenada();

    /**
     * Destrutor da Lista Não Ordenada
     */
    ~ListaNaoOrdenada();

    /**
     * Insere um elemento no início da lista
     * @param elemento Ponteiro para o elemento a ser inserido
     * @return true se inserido com sucesso, false caso contrário
     * Complexidade: O(n) - Precisa deslocar todos os elementos
     */
    bool inserirNoInicio(Elemento *elemento);

    /**
     * Insere um elemento no final da lista
     * @param elemento Ponteiro para o elemento a ser inserido
     * @return true se inserido com sucesso, false caso contrário
     * Complexidade: O(1) - Inserção direta no final
     */
    bool inserirNoFinal(Elemento *elemento);

    /**
     * Remove o primeiro elemento da lista
     * @return Ponteiro para o elemento removido ou nullptr se vazia
     * Complexidade: O(n) - Precisa deslocar todos os elementos
     */
    Elemento *removerPrimeiro();

    /**
     * Remove o último elemento da lista
     * @return Ponteiro para o elemento removido ou nullptr se vazia
     * Complexidade: O(1) - Remoção direta do final
     */
    Elemento *removerUltimo();

    /**
     * Remove um elemento pelo ID
     * @param id ID do elemento a ser removido
     * @return Ponteiro para o elemento removido ou nullptr se não encontrado
     * Complexidade: O(n) - Busca linear + deslocamento
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
     * Verifica se a lista está cheia
     * @return true se cheia, false caso contrário
     * Complexidade: O(1)
     */
    bool estaCheia() const { return tamanho >= capacidade; }

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
};

#endif // LISTA_NAO_ORDENADA_H
