#include "ListaOrdenada.h"
#include <iostream>

/**
 * Construtor da Lista Ordenada
 * Complexidade: O(1)
 */
ListaOrdenada::ListaOrdenada() : tamanho(0), capacidade(TAMANHO_MAX)
{
    elementos = new Elemento *[capacidade];
}

/**
 * Destrutor da Lista Ordenada
 * Complexidade: O(n) - Precisa deletar todos os elementos
 */
ListaOrdenada::~ListaOrdenada()
{
    for (int i = 0; i < tamanho; i++)
    {
        delete elementos[i];
    }
    delete[] elementos;
}

/**
 * Encontra a posição correta para inserir um elemento (busca binária)
 * Complexidade: O(log n) - Busca binária
 */
int ListaOrdenada::encontrarPosicaoInsercao(int id) const
{
    int esquerda = 0;
    int direita = tamanho;

    while (esquerda < direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        if (elementos[meio]->getID() < id)
        {
            esquerda = meio + 1;
        }
        else
        {
            direita = meio;
        }
    }

    return esquerda;
}

/**
 * Encontra a posição de um elemento pelo ID (busca binária)
 * Complexidade: O(log n) - Busca binária
 */
int ListaOrdenada::encontrarPosicaoElemento(int id) const
{
    int esquerda = 0;
    int direita = tamanho - 1;

    while (esquerda <= direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        if (elementos[meio]->getID() == id)
        {
            return meio;
        }
        else if (elementos[meio]->getID() < id)
        {
            esquerda = meio + 1;
        }
        else
        {
            direita = meio - 1;
        }
    }

    return -1; // Não encontrado
}

/**
 * Insere um elemento mantendo a ordem (implementação para inserirNoInicio)
 * Complexidade: O(n) - Busca O(log n) + inserção O(n)
 */
bool ListaOrdenada::inserirNoInicio(Elemento *elemento)
{
    if (estaCheia() || elemento == nullptr)
    {
        return false;
    }

    // Encontra posição correta para manter ordem
    int posicao = encontrarPosicaoInsercao(elemento->getID());

    // Desloca elementos para a direita
    for (int i = tamanho; i > posicao; i--)
    {
        elementos[i] = elementos[i - 1];
    }

    elementos[posicao] = elemento;
    tamanho++;
    return true;
}

/**
 * Insere um elemento mantendo a ordem (implementação para inserirNoFinal)
 * Complexidade: O(n) - Busca O(log n) + inserção O(n)
 */
bool ListaOrdenada::inserirNoFinal(Elemento *elemento)
{
    // Na lista ordenada, inserir no final é igual a inserir no início
    // pois a posição correta é determinada pelo ID
    return inserirNoInicio(elemento);
}

/**
 * Remove o primeiro elemento da lista
 * Complexidade: O(n) - Precisa deslocar todos os elementos para a esquerda
 */
Elemento *ListaOrdenada::removerPrimeiro()
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
Elemento *ListaOrdenada::removerUltimo()
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
 * Complexidade: O(n) - Busca O(log n) + remoção O(n)
 */
Elemento *ListaOrdenada::removerPeloId(int id)
{
    int posicao = encontrarPosicaoElemento(id);

    if (posicao == -1)
    {
        return nullptr; // Elemento não encontrado
    }

    Elemento *elementoRemovido = elementos[posicao];

    // Desloca elementos para a esquerda
    for (int i = posicao; i < tamanho - 1; i++)
    {
        elementos[i] = elementos[i + 1];
    }

    tamanho--;
    return elementoRemovido;
}

/**
 * Busca um elemento pelo ID usando busca binária
 * Complexidade: O(log n) - Busca binária
 */
Elemento *ListaOrdenada::buscarPeloId(int id) const
{
    int posicao = encontrarPosicaoElemento(id);

    if (posicao != -1)
    {
        return elementos[posicao];
    }

    return nullptr;
}

/**
 * Altera um elemento pelo ID
 * Complexidade: O(n) - Busca O(log n) + possível reorganização O(n)
 */
bool ListaOrdenada::alterarPeloId(int id, Elemento *novoElemento)
{
    if (novoElemento == nullptr)
    {
        return false;
    }

    // Se o novo elemento tem o mesmo ID, substitui diretamente
    if (novoElemento->getID() == id)
    {
        int posicao = encontrarPosicaoElemento(id);
        if (posicao != -1)
        {
            delete elementos[posicao];
            elementos[posicao] = novoElemento;
            return true;
        }
        return false;
    }

    // Se o ID é diferente, remove o antigo e insere o novo
    Elemento *elementoRemovido = removerPeloId(id);
    if (elementoRemovido != nullptr)
    {
        delete elementoRemovido;
        return inserirNoInicio(novoElemento);
    }

    return false;
}

/**
 * Imprime todos os elementos da lista
 * Complexidade: O(n) - Percorre todos os elementos
 */
void ListaOrdenada::imprimirTodos() const
{
    std::cout << "=== Lista Ordenada ===" << std::endl;
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
