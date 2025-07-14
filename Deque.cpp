#include "Deque.h"
#include <iostream>

/**
 * Insere um elemento no início (frente) do deque
 * Usa inserirNoInicio da lista dupla para ter complexidade O(1)
 * Complexidade: O(1) - Inserção no início da lista dupla
 */
bool Deque::inserirFrente(Elemento *elemento)
{
    if (elemento == nullptr)
    {
        return false;
    }

    // Usa inserirNoInicio para ter complexidade O(1)
    return lista.inserirNoInicio(elemento);
}

/**
 * Insere um elemento no final (trás) do deque
 * Usa inserirNoFim da lista dupla para ter complexidade O(1)
 * Complexidade: O(1) - Inserção no fim da lista dupla
 */
bool Deque::inserirTras(Elemento *elemento)
{
    if (elemento == nullptr)
    {
        return false;
    }

    // Usa inserirNoFim para ter complexidade O(1)
    return lista.inserirNoFim(elemento);
}

/**
 * Remove um elemento do início (frente) do deque
 * Usa removerPrimeiro da lista dupla para ter complexidade O(1)
 * Complexidade: O(1) - Remoção do início da lista dupla
 */
Elemento *Deque::removerFrente()
{
    // Usa removerPrimeiro para ter complexidade O(1)
    return lista.removerPrimeiro();
}

/**
 * Remove um elemento do final (trás) do deque
 * Usa removerUltimo da lista dupla para ter complexidade O(1)
 * Complexidade: O(1) - Remoção do fim da lista dupla
 */
Elemento *Deque::removerTras()
{
    // Usa removerUltimo para ter complexidade O(1)
    return lista.removerUltimo();
}

/**
 * Consulta o elemento da frente sem removê-lo
 * Complexidade: O(1) - Acesso ao primeiro elemento
 */
Elemento *Deque::consultarFrente() const
{
    if (dequeVazio())
    {
        return nullptr;
    }

    // Para acessar o primeiro elemento, usamos o mesmo truque das outras estruturas
    // Removemos temporariamente e inserimos de volta
    ListaDuplamenteEncadeada *listaTemp = const_cast<ListaDuplamenteEncadeada *>(&lista);

    Elemento *frente = listaTemp->removerPrimeiro();

    if (frente != nullptr)
    {
        listaTemp->inserirNoInicio(frente);
    }

    return frente;
}

/**
 * Consulta o elemento de trás sem removê-lo
 * Complexidade: O(1) - Acesso ao último elemento
 */
Elemento *Deque::consultarTras() const
{
    if (dequeVazio())
    {
        return nullptr;
    }

    // Para acessar o último elemento, usamos o mesmo truque
    // Removemos temporariamente e inserimos de volta
    ListaDuplamenteEncadeada *listaTemp = const_cast<ListaDuplamenteEncadeada *>(&lista);

    Elemento *tras = listaTemp->removerUltimo();

    if (tras != nullptr)
    {
        listaTemp->inserirNoFim(tras);
    }

    return tras;
}

/**
 * Verifica se o deque está vazio
 * Complexidade: O(1)
 */
bool Deque::dequeVazio() const
{
    return lista.estaVazia();
}

/**
 * Obtém o tamanho atual do deque
 * Complexidade: O(1)
 */
int Deque::getTamanho() const
{
    return lista.getTamanho();
}

/**
 * Imprime todos os elementos do deque (da frente para trás)
 * Complexidade: O(n)
 */
void Deque::imprimirDeque() const
{
    std::cout << "=== Deque (Double-ended queue) ===" << std::endl;
    if (dequeVazio())
    {
        std::cout << "Deque vazio!" << std::endl;
        return;
    }

    std::cout << "Elementos do deque (da frente para trás):" << std::endl;
    // Reutiliza a impressão da lista subjacente
    lista.imprimirTodos();
    std::cout << "Tamanho do deque: " << getTamanho() << std::endl;

    std::cout << "\nNOTA: Esta implementação usa Lista Duplamente Encadeada," << std::endl;
    std::cout << "proporcionando operações O(1) para inserção e remoção em ambas as extremidades." << std::endl;
}

/**
 * Imprime todos os elementos do deque (de trás para frente)
 * Complexidade: O(n)
 */
void Deque::imprimirDequeReverso() const
{
    std::cout << "=== Deque (Double-ended queue) - Ordem Reversa ===" << std::endl;
    if (dequeVazio())
    {
        std::cout << "Deque vazio!" << std::endl;
        return;
    }

    std::cout << "Elementos do deque (de trás para frente):" << std::endl;
    // Reutiliza a impressão reversa da lista subjacente
    lista.imprimirTodosReverso();
    std::cout << "Tamanho do deque: " << getTamanho() << std::endl;
}
