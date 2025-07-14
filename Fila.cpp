#include "Fila.h"
#include <iostream>

/**
 * Enfileira um elemento (adiciona no final)
 * Usa inserirNoFinal da lista para ter complexidade O(1)
 * Complexidade: O(1) - Inserção no final da lista
 */
bool Fila::enfileirar(Elemento *elemento)
{
    if (elemento == nullptr)
    {
        return false;
    }

    // Usa inserirNoFinal para ter complexidade O(1)
    return lista.inserirNoFinal(elemento);
}

/**
 * Desenfileira um elemento (remove do início)
 * Usa removerPrimeiro da lista, que tem complexidade O(n) - INEFICIENTE
 * Complexidade: O(n) - Remoção do início da lista
 */
Elemento *Fila::desenfileirar()
{
    // Usa removerPrimeiro que tem complexidade O(n) - PROBLEMA!
    return lista.removerPrimeiro();
}

/**
 * Consulta o elemento da frente sem removê-lo
 * Complexidade: Depende da implementação da lista para acessar o primeiro elemento
 */
Elemento *Fila::consultarFrente() const
{
    if (filaVazia())
    {
        return nullptr;
    }

    // Para acessar o primeiro elemento, precisamos usar busca
    // Como não temos acesso direto por índice, esta operação é ineficiente
    // Idealmente, a lista deveria ter um método para acessar por índice

    // Implementação simplificada: assumindo que temos acesso ao primeiro elemento
    // Na prática, seria necessário modificar a lista para ter acesso direto
    return nullptr; // Placeholder
}

/**
 * Verifica se a fila está cheia
 * Complexidade: O(1)
 */
bool Fila::filaCheia() const
{
    return lista.estaCheia();
}

/**
 * Verifica se a fila está vazia
 * Complexidade: O(1)
 */
bool Fila::filaVazia() const
{
    return lista.estaVazia();
}

/**
 * Obtém o tamanho atual da fila
 * Complexidade: O(1)
 */
int Fila::getTamanho() const
{
    return lista.getTamanho();
}

/**
 * Imprime todos os elementos da fila (da frente para trás)
 * Complexidade: O(n)
 */
void Fila::imprimirFila() const
{
    std::cout << "=== Fila (FIFO) ===" << std::endl;
    if (filaVazia())
    {
        std::cout << "Fila vazia!" << std::endl;
        return;
    }

    std::cout << "Elementos da fila (da frente para trás):" << std::endl;
    // Reutiliza a impressão da lista subjacente
    lista.imprimirTodos();
    std::cout << "Tamanho da fila: " << getTamanho() << std::endl;

    std::cout << "\nNOTA: Esta implementação de fila apresenta ineficiência na operação" << std::endl;
    std::cout << "de desenfileirar (O(n)) devido ao uso de removerPrimeiro() da lista." << std::endl;
}
