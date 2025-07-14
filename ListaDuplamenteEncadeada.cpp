#include "ListaDuplamenteEncadeada.h"
#include <iostream>

/**
 * Construtor da Lista Duplamente Encadeada
 * Complexidade: O(1)
 */
ListaDuplamenteEncadeada::ListaDuplamenteEncadeada() : cabeca(nullptr), cauda(nullptr), tamanho(0) {}

/**
 * Destrutor da Lista Duplamente Encadeada
 * Complexidade: O(n) - Precisa deletar todos os nós
 */
ListaDuplamenteEncadeada::~ListaDuplamenteEncadeada()
{
    while (!estaVazia())
    {
        removerPrimeiro();
    }
}

/**
 * Método auxiliar para encontrar um nó pelo ID
 * Complexidade: O(n) - Busca linear
 */
ListaDuplamenteEncadeada::No *ListaDuplamenteEncadeada::encontrarNo(int id) const
{
    No *atual = cabeca;
    while (atual != nullptr)
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
bool ListaDuplamenteEncadeada::inserirNoInicio(Elemento *elemento)
{
    if (elemento == nullptr)
    {
        return false;
    }

    No *novoNo = new No(elemento, cabeca, nullptr);

    if (estaVazia())
    {
        cabeca = cauda = novoNo;
    }
    else
    {
        cabeca->anterior = novoNo;
        cabeca = novoNo;
    }

    tamanho++;
    return true;
}

/**
 * Insere um elemento no fim da lista
 * Complexidade: O(1) - Inserção direta no fim (vantagem da dupla ligação)
 */
bool ListaDuplamenteEncadeada::inserirNoFim(Elemento *elemento)
{
    if (elemento == nullptr)
    {
        return false;
    }

    No *novoNo = new No(elemento, nullptr, cauda);

    if (estaVazia())
    {
        cabeca = cauda = novoNo;
    }
    else
    {
        cauda->proximo = novoNo;
        cauda = novoNo;
    }

    tamanho++;
    return true;
}

/**
 * Remove um elemento pelo ID
 * Complexidade: O(n) - Busca linear + remoção O(1)
 */
Elemento *ListaDuplamenteEncadeada::removerPeloId(int id)
{
    No *noARemover = encontrarNo(id);

    if (noARemover == nullptr)
    {
        return nullptr;
    }

    Elemento *elementoRemovido = noARemover->elemento;

    // Ajusta os ponteiros dos nós vizinhos
    if (noARemover->anterior != nullptr)
    {
        noARemover->anterior->proximo = noARemover->proximo;
    }
    else
    {
        cabeca = noARemover->proximo; // Removendo o primeiro nó
    }

    if (noARemover->proximo != nullptr)
    {
        noARemover->proximo->anterior = noARemover->anterior;
    }
    else
    {
        cauda = noARemover->anterior; // Removendo o último nó
    }

    delete noARemover;
    tamanho--;
    return elementoRemovido;
}

/**
 * Busca um elemento pelo ID
 * Complexidade: O(n) - Busca linear
 */
Elemento *ListaDuplamenteEncadeada::buscarPeloId(int id) const
{
    No *no = encontrarNo(id);
    return (no != nullptr) ? no->elemento : nullptr;
}

/**
 * Altera um elemento pelo ID
 * Complexidade: O(n) - Busca linear
 */
bool ListaDuplamenteEncadeada::alterarPeloId(int id, Elemento *novoElemento)
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
Elemento *ListaDuplamenteEncadeada::removerPrimeiro()
{
    if (estaVazia())
    {
        return nullptr;
    }

    No *noARemover = cabeca;
    Elemento *elementoRemovido = noARemover->elemento;

    cabeca = cabeca->proximo;

    if (cabeca != nullptr)
    {
        cabeca->anterior = nullptr;
    }
    else
    {
        cauda = nullptr; // Lista ficou vazia
    }

    delete noARemover;
    tamanho--;
    return elementoRemovido;
}

/**
 * Remove o último elemento da lista
 * Complexidade: O(1) - Remoção direta do fim (vantagem da dupla ligação)
 */
Elemento *ListaDuplamenteEncadeada::removerUltimo()
{
    if (estaVazia())
    {
        return nullptr;
    }

    No *noARemover = cauda;
    Elemento *elementoRemovido = noARemover->elemento;

    cauda = cauda->anterior;

    if (cauda != nullptr)
    {
        cauda->proximo = nullptr;
    }
    else
    {
        cabeca = nullptr; // Lista ficou vazia
    }

    delete noARemover;
    tamanho--;
    return elementoRemovido;
}

/**
 * Imprime todos os elementos da lista (do início ao fim)
 * Complexidade: O(n) - Percorre todos os elementos
 */
void ListaDuplamenteEncadeada::imprimirTodos() const
{
    std::cout << "=== Lista Duplamente Encadeada (Início → Fim) ===" << std::endl;
    if (estaVazia())
    {
        std::cout << "Lista vazia!" << std::endl;
        return;
    }

    No *atual = cabeca;
    int posicao = 0;
    while (atual != nullptr)
    {
        std::cout << "Posição " << posicao << ": ";
        atual->elemento->imprimirInfo();
        atual = atual->proximo;
        posicao++;
    }
    std::cout << "Total de elementos: " << tamanho << std::endl;
}

/**
 * Imprime todos os elementos da lista (do fim ao início)
 * Complexidade: O(n) - Percorre todos os elementos em ordem reversa
 */
void ListaDuplamenteEncadeada::imprimirTodosReverso() const
{
    std::cout << "=== Lista Duplamente Encadeada (Fim → Início) ===" << std::endl;
    if (estaVazia())
    {
        std::cout << "Lista vazia!" << std::endl;
        return;
    }

    No *atual = cauda;
    int posicao = tamanho - 1;
    while (atual != nullptr)
    {
        std::cout << "Posição " << posicao << ": ";
        atual->elemento->imprimirInfo();
        atual = atual->anterior;
        posicao--;
    }
    std::cout << "Total de elementos: " << tamanho << std::endl;
}
