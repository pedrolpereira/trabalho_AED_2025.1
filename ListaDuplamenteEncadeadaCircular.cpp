#include "ListaDuplamenteEncadeadaCircular.h"
#include <iostream>

/**
 * Construtor da Lista Duplamente Encadeada Circular
 * Complexidade: O(1)
 */
ListaDuplamenteEncadeadaCircular::ListaDuplamenteEncadeadaCircular() : tamanho(0)
{
    // Cria o nó sentinela que aponta para si mesmo
    sentinela = new No(nullptr);
    sentinela->proximo = sentinela;
    sentinela->anterior = sentinela;
}

/**
 * Destrutor da Lista Duplamente Encadeada Circular
 * Complexidade: O(n) - Precisa deletar todos os nós
 */
ListaDuplamenteEncadeadaCircular::~ListaDuplamenteEncadeadaCircular()
{
    while (!estaVazia())
    {
        removerPrimeiro();
    }
    delete sentinela;
}

/**
 * Método auxiliar para encontrar um nó pelo ID
 * Complexidade: O(n) - Busca linear
 */
ListaDuplamenteEncadeadaCircular::No *ListaDuplamenteEncadeadaCircular::encontrarNo(int id) const
{
    No *atual = sentinela->proximo;

    while (atual != sentinela)
    {
        if (atual->elemento->getID() == id)
        {
            return atual;
        }
        atual = atual->proximo;
    }

    return nullptr;
}

/**
 * Insere um elemento no início da lista
 * Complexidade: O(1) - Inserção direta no início
 */
bool ListaDuplamenteEncadeadaCircular::inserirNoInicio(Elemento *elemento)
{
    if (elemento == nullptr)
    {
        return false;
    }

    No *novoNo = new No(elemento, sentinela->proximo, sentinela);
    sentinela->proximo->anterior = novoNo;
    sentinela->proximo = novoNo;

    tamanho++;
    return true;
}

/**
 * Insere um elemento no fim da lista
 * Complexidade: O(1) - Inserção direta no fim
 */
bool ListaDuplamenteEncadeadaCircular::inserirNoFim(Elemento *elemento)
{
    if (elemento == nullptr)
    {
        return false;
    }

    No *novoNo = new No(elemento, sentinela, sentinela->anterior);
    sentinela->anterior->proximo = novoNo;
    sentinela->anterior = novoNo;

    tamanho++;
    return true;
}

/**
 * Remove um elemento pelo ID
 * Complexidade: O(n) - Busca linear + remoção O(1)
 */
Elemento *ListaDuplamenteEncadeadaCircular::removerPeloId(int id)
{
    No *noARemover = encontrarNo(id);

    if (noARemover == nullptr)
    {
        return nullptr;
    }

    Elemento *elementoRemovido = noARemover->elemento;

    // Ajusta os ponteiros dos nós vizinhos
    noARemover->anterior->proximo = noARemover->proximo;
    noARemover->proximo->anterior = noARemover->anterior;

    delete noARemover;
    tamanho--;
    return elementoRemovido;
}

/**
 * Busca um elemento pelo ID
 * Complexidade: O(n) - Busca linear
 */
Elemento *ListaDuplamenteEncadeadaCircular::buscarPeloId(int id) const
{
    No *no = encontrarNo(id);
    return (no != nullptr) ? no->elemento : nullptr;
}

/**
 * Altera um elemento pelo ID
 * Complexidade: O(n) - Busca linear
 */
bool ListaDuplamenteEncadeadaCircular::alterarPeloId(int id, Elemento *novoElemento)
{
    if (novoElemento == nullptr)
    {
        return false;
    }

    No *no = encontrarNo(id);
    if (no != nullptr)
    {
        delete no->elemento; // Libera memória do elemento antigo
        no->elemento = novoElemento;
        return true;
    }

    return false;
}

/**
 * Remove o primeiro elemento da lista
 * Complexidade: O(1) - Remoção direta do início
 */
Elemento *ListaDuplamenteEncadeadaCircular::removerPrimeiro()
{
    if (estaVazia())
    {
        return nullptr;
    }

    No *noARemover = sentinela->proximo;
    Elemento *elementoRemovido = noARemover->elemento;

    sentinela->proximo = noARemover->proximo;
    noARemover->proximo->anterior = sentinela;

    delete noARemover;
    tamanho--;
    return elementoRemovido;
}

/**
 * Remove o último elemento da lista
 * Complexidade: O(1) - Remoção direta do fim
 */
Elemento *ListaDuplamenteEncadeadaCircular::removerUltimo()
{
    if (estaVazia())
    {
        return nullptr;
    }

    No *noARemover = sentinela->anterior;
    Elemento *elementoRemovido = noARemover->elemento;

    sentinela->anterior = noARemover->anterior;
    noARemover->anterior->proximo = sentinela;

    delete noARemover;
    tamanho--;
    return elementoRemovido;
}

/**
 * Imprime todos os elementos da lista (do início ao fim)
 * Complexidade: O(n * numVoltas)
 */
void ListaDuplamenteEncadeadaCircular::imprimirTodos(int numVoltas) const
{
    std::cout << "=== Lista Duplamente Encadeada Circular (Início → Fim) ===" << std::endl;
    if (estaVazia())
    {
        std::cout << "Lista vazia!" << std::endl;
        return;
    }

    No *atual = sentinela->proximo;
    int elementosImpressos = 0;
    int voltasCompletas = 0;

    while (voltasCompletas < numVoltas)
    {
        std::cout << "Volta " << (voltasCompletas + 1) << ", Posição " << (elementosImpressos % tamanho) << ": ";
        atual->elemento->imprimirInfo();
        atual = atual->proximo;
        elementosImpressos++;

        if (atual == sentinela->proximo)
        {
            voltasCompletas++;
            if (voltasCompletas < numVoltas)
            {
                std::cout << "--- Fim da volta " << voltasCompletas << " ---" << std::endl;
            }
        }
    }

    std::cout << "Total de elementos: " << tamanho << std::endl;
    std::cout << "Elementos impressos: " << elementosImpressos << std::endl;
}

/**
 * Imprime todos os elementos da lista (do fim ao início)
 * Complexidade: O(n * numVoltas)
 */
void ListaDuplamenteEncadeadaCircular::imprimirTodosReverso(int numVoltas) const
{
    std::cout << "=== Lista Duplamente Encadeada Circular (Fim → Início) ===" << std::endl;
    if (estaVazia())
    {
        std::cout << "Lista vazia!" << std::endl;
        return;
    }

    No *atual = sentinela->anterior;
    int elementosImpressos = 0;
    int voltasCompletas = 0;

    while (voltasCompletas < numVoltas)
    {
        std::cout << "Volta " << (voltasCompletas + 1) << ", Posição " << (tamanho - 1 - (elementosImpressos % tamanho)) << ": ";
        atual->elemento->imprimirInfo();
        atual = atual->anterior;
        elementosImpressos++;

        if (atual == sentinela->anterior)
        {
            voltasCompletas++;
            if (voltasCompletas < numVoltas)
            {
                std::cout << "--- Fim da volta " << voltasCompletas << " ---" << std::endl;
            }
        }
    }

    std::cout << "Total de elementos: " << tamanho << std::endl;
    std::cout << "Elementos impressos: " << elementosImpressos << std::endl;
}
