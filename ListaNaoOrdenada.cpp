#include "ListaNaoOrdenada.h"
#include <iostream>

/**
 * Construtor da Lista Não Ordenada
 * Complexidade: O(1)
 */
ListaNaoOrdenada::ListaNaoOrdenada() : tamanho(0), capacidade(TAMANHO_MAX)
{
    elementos = new Elemento *[capacidade];
}

/**
 * Destrutor da Lista Não Ordenada
 * Complexidade: O(n) - Precisa deletar todos os elementos
 */
ListaNaoOrdenada::~ListaNaoOrdenada()
{
    for (int i = 0; i < tamanho; i++)
    {
        delete elementos[i];
    }
    delete[] elementos;
}

/**
 * Insere um elemento no início da lista
 * Complexidade: O(n) - Precisa deslocar todos os elementos para a direita
 */
bool ListaNaoOrdenada::inserirNoInicio(Elemento *elemento)
{
    if (estaCheia() || elemento == nullptr)
    {
        return false;
    }

    // Desloca todos os elementos para a direita
    for (int i = tamanho; i > 0; i--)
    {
        elementos[i] = elementos[i - 1];
    }

    elementos[0] = elemento;
    tamanho++;
    return true;
}

/**
 * Insere um elemento no final da lista
 * Complexidade: O(1) - Inserção direta no final
 */
bool ListaNaoOrdenada::inserirNoFinal(Elemento *elemento)
{
    if (estaCheia() || elemento == nullptr)
    {
        return false;
    }

    elementos[tamanho] = elemento;
    tamanho++;
    return true;
}

/**
 * Remove o primeiro elemento da lista
 * Complexidade: O(n) - Precisa deslocar todos os elementos para a esquerda
 */
Elemento *ListaNaoOrdenada::removerPrimeiro()
{
    if (estaVazia())
    {
        return nullptr;
    }

    Elemento *elementoRemovido = elementos[0];

    // Desloca todos os elementos para a esquerda
    for (int i = 0; i < tamanho - 1; i++)
    {
        elementos[i] = elementos[i + 1];
    }

    tamanho--;
    return elementoRemovido;
}

/**
 * Remove o último elemento da lista
 * Complexidade: O(1) - Remoção direta do final
 */
Elemento *ListaNaoOrdenada::removerUltimo()
{
    if (estaVazia())
    {
        return nullptr;
    }

    Elemento *elementoRemovido = elementos[tamanho - 1];
    tamanho--;
    return elementoRemovido;
}

/**
 * Remove um elemento pelo ID
 * Complexidade: O(n) - Busca linear + deslocamento de elementos
 */
Elemento *ListaNaoOrdenada::removerPeloId(int id)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (elementos[i]->getID() == id)
        {
            Elemento *elementoRemovido = elementos[i];

            // Desloca elementos para a esquerda
            for (int j = i; j < tamanho - 1; j++)
            {
                elementos[j] = elementos[j + 1];
            }

            tamanho--;
            return elementoRemovido;
        }
    }
    return nullptr;
}

/**
 * Busca um elemento pelo ID
 * Complexidade: O(n) - Busca linear
 */
Elemento *ListaNaoOrdenada::buscarPeloId(int id) const
{
    for (int i = 0; i < tamanho; i++)
    {
        if (elementos[i]->getID() == id)
        {
            return elementos[i];
        }
    }
    return nullptr;
}

/**
 * Altera um elemento pelo ID
 * Complexidade: O(n) - Busca linear
 */
bool ListaNaoOrdenada::alterarPeloId(int id, Elemento *novoElemento)
{
    if (novoElemento == nullptr)
    {
        return false;
    }

    for (int i = 0; i < tamanho; i++)
    {
        if (elementos[i]->getID() == id)
        {
            delete elementos[i]; // Libera memória do elemento antigo
            elementos[i] = novoElemento;
            return true;
        }
    }
    return false;
}

/**
 * Imprime todos os elementos da lista
 * Complexidade: O(n) - Percorre todos os elementos
 */
void ListaNaoOrdenada::imprimirTodos() const
{
    std::cout << "=== Lista Não Ordenada ===" << std::endl;
    if (estaVazia())
    {
        std::cout << "Lista vazia!" << std::endl;
        return;
    }

    for (int i = 0; i < tamanho; i++)
    {
        std::cout << "Posição " << i << ": ";
        elementos[i]->imprimirInfo();
    }
    std::cout << "Total de elementos: " << tamanho << std::endl;
}
