#ifndef ARVORE_BINARIA_BUSCA_H
#define ARVORE_BINARIA_BUSCA_H

#include "Elemento.h"

/**
 * Classe que implementa uma Árvore Binária de Busca com alocação dinâmica.
 * Demonstra o pilar do Encapsulamento ao esconder completamente a implementação dos nós.
 * Mantém a propriedade fundamental: nó esquerdo < nó pai < nó direito.
 */
class ArvoreBinariaBusca
{
private:
    /**
     * Classe privada para representar os nós da árvore.
     * Demonstra o Encapsulamento ao esconder este detalhe de implementação.
     */
    class No
    {
    public:
        Elemento *elemento;
        No *esquerdo;
        No *direito;

        /**
         * Construtor do nó
         * @param elem Ponteiro para o elemento
         * @param esq Ponteiro para o nó esquerdo
         * @param dir Ponteiro para o nó direito
         */
        No(Elemento *elem, No *esq = nullptr, No *dir = nullptr)
            : elemento(elem), esquerdo(esq), direito(dir) {}
    };

    No *raiz;    // Ponteiro para o nó raiz
    int tamanho; // Número de elementos na árvore

    /**
     * Método auxiliar recursivo para inserir um elemento
     * @param no Ponteiro para o nó atual
     * @param elemento Elemento a ser inserido
     * @return Ponteiro para o nó (modificado ou não)
     * Complexidade: O(log n) no caso médio, O(n) no pior caso
     */
    No *inserirRecursivo(No *no, Elemento *elemento);

    /**
     * Método auxiliar recursivo para buscar um elemento
     * @param no Ponteiro para o nó atual
     * @param id ID do elemento procurado
     * @return Ponteiro para o elemento encontrado ou nullptr
     * Complexidade: O(log n) no caso médio, O(n) no pior caso
     */
    Elemento *buscarRecursivo(No *no, int id) const;

    /**
     * Método auxiliar recursivo para remover um elemento
     * @param no Ponteiro para o nó atual
     * @param id ID do elemento a ser removido
     * @return Ponteiro para o nó (modificado ou removido)
     * Complexidade: O(log n) no caso médio, O(n) no pior caso
     */
    No *removerRecursivo(No *no, int id);

    /**
     * Método auxiliar para encontrar o menor elemento de uma subárvore
     * @param no Ponteiro para o nó raiz da subárvore
     * @return Ponteiro para o nó com menor valor
     * Complexidade: O(log n) no caso médio, O(n) no pior caso
     */
    No *encontrarMinimo(No *no) const;

    /**
     * Método auxiliar recursivo para percurso em ordem
     * @param no Ponteiro para o nó atual
     * Complexidade: O(n) - Visita todos os nós
     */
    void emOrdemRecursivo(No *no) const;

    /**
     * Método auxiliar recursivo para percurso pré-ordem
     * @param no Ponteiro para o nó atual
     * Complexidade: O(n) - Visita todos os nós
     */
    void preOrdemRecursivo(No *no) const;

    /**
     * Método auxiliar recursivo para percurso pós-ordem
     * @param no Ponteiro para o nó atual
     * Complexidade: O(n) - Visita todos os nós
     */
    void posOrdemRecursivo(No *no) const;

    /**
     * Método auxiliar recursivo para destruir a árvore
     * @param no Ponteiro para o nó atual
     * Complexidade: O(n) - Visita todos os nós
     */
    void destruirArvore(No *no);

public:
    /**
     * Construtor da Árvore Binária de Busca
     */
    ArvoreBinariaBusca();

    /**
     * Destrutor da Árvore Binária de Busca
     */
    ~ArvoreBinariaBusca();

    /**
     * Insere um elemento na árvore mantendo a propriedade de busca
     * @param elemento Ponteiro para o elemento a ser inserido
     * @return true se inserido com sucesso, false caso contrário
     * Complexidade: O(log n) no caso médio, O(n) no pior caso
     */
    bool inserir(Elemento *elemento);

    /**
     * Busca um elemento pelo ID
     * @param id ID do elemento a ser buscado
     * @return Ponteiro para o elemento encontrado ou nullptr se não encontrado
     * Complexidade: O(log n) no caso médio, O(n) no pior caso
     */
    Elemento *buscarPeloId(int id) const;

    /**
     * Remove um elemento pelo ID
     * @param id ID do elemento a ser removido
     * @return Ponteiro para o elemento removido ou nullptr se não encontrado
     * Complexidade: O(log n) no caso médio, O(n) no pior caso
     */
    Elemento *removerPeloId(int id);

    /**
     * Percurso em ordem (esquerda, raiz, direita)
     * Imprime os elementos em ordem crescente de ID
     * Complexidade: O(n) - Visita todos os nós
     */
    void emOrdem() const;

    /**
     * Percurso pré-ordem (raiz, esquerda, direita)
     * Complexidade: O(n) - Visita todos os nós
     */
    void preOrdem() const;

    /**
     * Percurso pós-ordem (esquerda, direita, raiz)
     * Complexidade: O(n) - Visita todos os nós
     */
    void posOrdem() const;

    /**
     * Verifica se a árvore está vazia
     * @return true se vazia, false caso contrário
     * Complexidade: O(1)
     */
    bool estaVazia() const { return raiz == nullptr; }

    /**
     * Obtém o tamanho atual da árvore
     * @return Número de elementos na árvore
     * Complexidade: O(1)
     */
    int getTamanho() const { return tamanho; }
};

#endif // ARVORE_BINARIA_BUSCA_H
