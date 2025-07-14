#ifndef LISTA_ORDENADA_H
#define LISTA_ORDENADA_H

#include "Elemento.h"

/**
 * Classe que implementa uma Lista Ordenada com alocação sequencial.
 * Os elementos são mantidos em ordem crescente pelo ID.
 * Demonstra o pilar do Encapsulamento ao esconder os detalhes de implementação.
 */
class ListaOrdenada
{
private:
    static const int TAMANHO_MAX = 100; // Capacidade máxima da lista
    Elemento **elementos;               // Array de ponteiros para elementos
    int tamanho;                        // Número atual de elementos na lista
    int capacidade;                     // Capacidade máxima da lista

    /**
     * Encontra a posição correta para inserir um elemento (busca binária)
     * @param id ID do elemento a ser inserido
     * @return Posição onde o elemento deve ser inserido
     * Complexidade: O(log n) - Busca binária
     */
    int encontrarPosicaoInsercao(int id) const;

    /**
     * Encontra a posição de um elemento pelo ID (busca binária)
     * @param id ID do elemento a ser buscado
     * @return Posição do elemento ou -1 se não encontrado
     * Complexidade: O(log n) - Busca binária
     */
    int encontrarPosicaoElemento(int id) const;

public:
    /**
     * Construtor da Lista Ordenada
     */
    ListaOrdenada();

    /**
     * Destrutor da Lista Ordenada
     */
    ~ListaOrdenada();

    /**
     * Insere um elemento no início da lista (mantém ordem)
     * @param elemento Ponteiro para o elemento a ser inserido
     * @return true se inserido com sucesso, false caso contrário
     * Complexidade: O(n) - Busca O(log n) + inserção O(n)
     */
    bool inserirNoInicio(Elemento *elemento);

    /**
     * Insere um elemento no final da lista (mantém ordem)
     * @param elemento Ponteiro para o elemento a ser inserido
     * @return true se inserido com sucesso, false caso contrário
     * Complexidade: O(n) - Busca O(log n) + inserção O(n)
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
     * Complexidade: O(n) - Busca O(log n) + remoção O(n)
     */
    Elemento *removerPeloId(int id);

    /**
     * Busca um elemento pelo ID usando busca binária
     * @param id ID do elemento a ser buscado
     * @return Ponteiro para o elemento encontrado ou nullptr se não encontrado
     * Complexidade: O(log n) - Busca binária
     */
    Elemento *buscarPeloId(int id) const;

    /**
     * Altera um elemento pelo ID
     * @param id ID do elemento a ser alterado
     * @param novoElemento Ponteiro para o novo elemento
     * @return true se alterado com sucesso, false caso contrário
     * Complexidade: O(n) - Busca O(log n) + possível reorganização O(n)
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

#endif // LISTA_ORDENADA_H
