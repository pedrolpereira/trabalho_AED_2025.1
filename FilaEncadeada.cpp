#include "FilaEncadeada.h"
#include <iostream>

/**
 * Enfileira um elemento (adiciona no final)
 * Usa inserirNoFim da lista dupla para ter complexidade O(1)
 * Complexidade: O(1) - Inserção no fim da lista dupla
 */
bool FilaEncadeada::enfileirar(Elemento *elemento)
{
    if (elemento == nullptr)
    {
        return false;
    }

    // Usa inserirNoFim para ter complexidade O(1)
    return lista.inserirNoFim(elemento);
}

/**
 * Desenfileira um elemento (remove do início)
 * Usa removerPrimeiro da lista dupla para ter complexidade O(1)
 * Complexidade: O(1) - Remoção do início da lista dupla
 */
Elemento *FilaEncadeada::desenfileirar()
{
    // Usa removerPrimeiro para ter complexidade O(1)
    return lista.removerPrimeiro();
}

/**
 * Consulta o elemento da frente sem removê-lo
 * Complexidade: O(1) - Acesso ao primeiro elemento
 */
Elemento *FilaEncadeada::consultarFrente() const
{
    if (filaVazia())
    {
        return nullptr;
    }

    // Para acessar o primeiro elemento, usamos o mesmo truque da pilha
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
Elemento *FilaEncadeada::consultarTras() const
{
    if (filaVazia())
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
 * Verifica se a fila está vazia
 * Complexidade: O(1)
 */
bool FilaEncadeada::filaVazia() const
{
    return lista.estaVazia();
}

/**
 * Obtém o tamanho atual da fila
 * Complexidade: O(1)
 */
int FilaEncadeada::getTamanho() const
{
    return lista.getTamanho();
}

/**
 * Imprime todos os elementos da fila (da frente para trás)
 * Complexidade: O(n)
 */
void FilaEncadeada::imprimirFila() const
{
    std::cout << "=== Fila Encadeada (FIFO) ===" << std::endl;
    if (filaVazia())
    {
        std::cout << "Fila vazia!" << std::endl;
        return;
    }

    std::cout << "Elementos da fila (da frente para trás):" << std::endl;
    // Reutiliza a impressão da lista subjacente
    lista.imprimirTodos();
    std::cout << "Tamanho da fila: " << getTamanho() << std::endl;

    std::cout << "\nNOTA: Esta implementação usa Lista Duplamente Encadeada," << std::endl;
    std::cout << "proporcionando operações O(1) tanto para enfileirar quanto para desenfileirar." << std::endl;
}
