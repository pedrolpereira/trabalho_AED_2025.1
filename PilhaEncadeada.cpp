#include "PilhaEncadeada.h"
#include <iostream>

/**
 * Empilha um elemento (adiciona no topo)
 * Usa inserirNoInicio da lista para ter complexidade O(1)
 * Complexidade: O(1) - Inserção no início da lista
 */
bool PilhaEncadeada::empilhar(Elemento *elemento)
{
    if (elemento == nullptr)
    {
        return false;
    }

    // Usa inserirNoInicio para ter complexidade O(1)
    return lista.inserirNoInicio(elemento);
}

/**
 * Desempilha um elemento (remove do topo)
 * Usa removerPrimeiro da lista para ter complexidade O(1)
 * Complexidade: O(1) - Remoção do início da lista
 */
Elemento *PilhaEncadeada::desempilhar()
{
    // Usa removerPrimeiro para ter complexidade O(1)
    return lista.removerPrimeiro();
}

/**
 * Consulta o elemento do topo sem removê-lo
 * Complexidade: O(1) - Busca pelo primeiro elemento
 */
Elemento *PilhaEncadeada::consultarTopo() const
{
    if (pilhaVazia())
    {
        return nullptr;
    }

    // Para uma pilha, o topo corresponde ao primeiro elemento da lista
    // Vamos implementar uma busca simples (idealmente a lista teria um método para isso)
    // Como sabemos que há pelo menos um elemento, podemos usar uma abordagem criativa

    // Criamos uma cópia temporária da lista para simular o acesso ao primeiro elemento
    // Isso não é ideal, mas mantém a interface da lista simples
    ListaSimplesmenteEncadeada *listaTemp = const_cast<ListaSimplesmenteEncadeada *>(&lista);

    // Removemos temporariamente o primeiro elemento
    Elemento *topo = listaTemp->removerPrimeiro();

    // Inserimos de volta no início
    if (topo != nullptr)
    {
        listaTemp->inserirNoInicio(topo);
    }

    return topo;
}

/**
 * Verifica se a pilha está vazia
 * Complexidade: O(1)
 */
bool PilhaEncadeada::pilhaVazia() const
{
    return lista.estaVazia();
}

/**
 * Obtém o tamanho atual da pilha
 * Complexidade: O(1)
 */
int PilhaEncadeada::getTamanho() const
{
    return lista.getTamanho();
}

/**
 * Imprime todos os elementos da pilha (do topo para a base)
 * Complexidade: O(n)
 */
void PilhaEncadeada::imprimirPilha() const
{
    std::cout << "=== Pilha Encadeada (LIFO) ===" << std::endl;
    if (pilhaVazia())
    {
        std::cout << "Pilha vazia!" << std::endl;
        return;
    }

    std::cout << "Elementos da pilha (do topo para a base):" << std::endl;
    // Reutiliza a impressão da lista subjacente
    lista.imprimirTodos();
    std::cout << "Tamanho da pilha: " << getTamanho() << std::endl;

    std::cout << "\nNOTA: Esta implementação usa Lista Simplesmente Encadeada," << std::endl;
    std::cout << "proporcionando operações O(1) para empilhar e desempilhar." << std::endl;
}
