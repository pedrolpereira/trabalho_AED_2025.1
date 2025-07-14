#include "ListaSimplesmenteEncadeada.h"
#include <iostream>

/**
 * Construtor da Lista Simplesmente Encadeada
 * Complexidade: O(1)
 */
ListaSimplesmenteEncadeada::ListaSimplesmenteEncadeada() : cabeca(nullptr), tamanho(0) {}

/**
 * Destrutor da Lista Simplesmente Encadeada
 * Complexidade: O(n) - Precisa deletar todos os nós
 */
ListaSimplesmenteEncadeada::~ListaSimplesmenteEncadeada()
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
ListaSimplesmenteEncadeada::No *ListaSimplesmenteEncadeada::encontrarNo(int id) const
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
 * Método auxiliar para encontrar o nó anterior a um nó com determinado ID
 * Complexidade: O(n) - Busca linear
 */
ListaSimplesmenteEncadeada::No *ListaSimplesmenteEncadeada::encontrarNoAnterior(int id) const
{
    if (cabeca == nullptr || cabeca->elemento->getID() == id)
    {
        return nullptr; // Não há anterior para o primeiro nó
    }

    No *atual = cabeca;
    while (atual->proximo != nullptr)
    {
        if (atual->proximo->elemento->getID() == id)
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
bool ListaSimplesmenteEncadeada::inserirNoInicio(Elemento *elemento)
{
    if (elemento == nullptr)
    {
        return false;
    }

    No *novoNo = new No(elemento, cabeca);
    cabeca = novoNo;
    tamanho++;
    return true;
}

/**
 * Insere um elemento no fim da lista
 * Complexidade: O(n) - Precisa percorrer até o final
 */
bool ListaSimplesmenteEncadeada::inserirNoFim(Elemento *elemento)
{
    if (elemento == nullptr)
    {
        return false;
    }

    No *novoNo = new No(elemento);

    if (estaVazia())
    {
        cabeca = novoNo;
    }
    else
    {
        No *atual = cabeca;
        while (atual->proximo != nullptr)
        {
            atual = atual->proximo;
        }
        atual->proximo = novoNo;
    }

    tamanho++;
    return true;
}

/**
 * Remove um elemento pelo ID
 * Complexidade: O(n) - Busca linear + remoção
 */
Elemento *ListaSimplesmenteEncadeada::removerPeloId(int id)
{
    if (estaVazia())
    {
        return nullptr;
    }

    // Caso especial: remover o primeiro elemento
    if (cabeca->elemento->getID() == id)
    {
        return removerPrimeiro();
    }

    No *anterior = encontrarNoAnterior(id);
    if (anterior != nullptr && anterior->proximo != nullptr)
    {
        No *noARemover = anterior->proximo;
        Elemento *elementoRemovido = noARemover->elemento;
        anterior->proximo = noARemover->proximo;
        delete noARemover;
        tamanho--;
        return elementoRemovido;
    }

    return nullptr;
}

/**
 * Busca um elemento pelo ID
 * Complexidade: O(n) - Busca linear
 */
Elemento *ListaSimplesmenteEncadeada::buscarPeloId(int id) const
{
    No *no = encontrarNo(id);
    return (no != nullptr) ? no->elemento : nullptr;
}

/**
 * Altera um elemento pelo ID
 * Complexidade: O(n) - Busca linear
 */
bool ListaSimplesmenteEncadeada::alterarPeloId(int id, Elemento *novoElemento)
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
Elemento *ListaSimplesmenteEncadeada::removerPrimeiro()
{
    if (estaVazia())
    {
        return nullptr;
    }

    No *noARemover = cabeca;
    Elemento *elementoRemovido = noARemover->elemento;
    cabeca = cabeca->proximo;
    delete noARemover;
    tamanho--;
    return elementoRemovido;
}

/**
 * Remove o último elemento da lista
 * Complexidade: O(n) - Precisa percorrer até o penúltimo
 */
Elemento *ListaSimplesmenteEncadeada::removerUltimo()
{
    if (estaVazia())
    {
        return nullptr;
    }

    // Caso especial: apenas um elemento
    if (cabeca->proximo == nullptr)
    {
        return removerPrimeiro();
    }

    // Encontra o penúltimo nó
    No *atual = cabeca;
    while (atual->proximo->proximo != nullptr)
    {
        atual = atual->proximo;
    }

    No *noARemover = atual->proximo;
    Elemento *elementoRemovido = noARemover->elemento;
    atual->proximo = nullptr;
    delete noARemover;
    tamanho--;
    return elementoRemovido;
}

/**
 * Imprime todos os elementos da lista
 * Complexidade: O(n) - Percorre todos os elementos
 */
void ListaSimplesmenteEncadeada::imprimirTodos() const
{
    std::cout << "=== Lista Simplesmente Encadeada ===" << std::endl;
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
