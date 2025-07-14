#include "FilaOtimizada.h"
#include <iostream>

/**
 * Construtor da Fila Otimizada
 * Complexidade: O(1)
 */
FilaOtimizada::FilaOtimizada() : frente(0), tras(0), tamanho(0), capacidade(TAMANHO_MAX)
{
    elementos = std::make_unique<Elemento *[]>(capacidade);
}

/**
 * Destrutor da Fila Otimizada
 * Complexidade: O(n) - Precisa deletar todos os elementos
 */
FilaOtimizada::~FilaOtimizada()
{
    // Percorre a fila circular para deletar todos os elementos
    int indiceAtual = frente;
    for (int i = 0; i < tamanho; i++)
    {
        delete elementos[indiceAtual];
        indiceAtual = proximoIndice(indiceAtual);
    }
}

/**
 * Calcula o próximo índice na fila circular
 * Complexidade: O(1)
 */
int FilaOtimizada::proximoIndice(int indice) const
{
    return (indice + 1) % capacidade;
}

/**
 * Enfileira um elemento (adiciona no final)
 * Complexidade: O(1) - Inserção direta no final da fila circular
 */
bool FilaOtimizada::enfileirar(Elemento *elemento)
{
    if (filaCheia() || elemento == nullptr)
    {
        return false;
    }

    elementos[tras] = elemento;
    tras = proximoIndice(tras);
    tamanho++;
    return true;
}

/**
 * Desenfileira um elemento (remove do início)
 * Complexidade: O(1) - Remoção direta do início da fila circular (OTIMIZADO)
 */
Elemento *FilaOtimizada::desenfileirar()
{
    if (filaVazia())
    {
        return nullptr;
    }

    Elemento *elementoRemovido = elementos[frente];
    frente = proximoIndice(frente);
    tamanho--;
    return elementoRemovido;
}

/**
 * Consulta o elemento da frente sem removê-lo
 * Complexidade: O(1) - Acesso direto ao primeiro elemento
 */
Elemento *FilaOtimizada::consultarFrente() const
{
    if (filaVazia())
    {
        return nullptr;
    }

    return elementos[frente];
}

/**
 * Consulta o elemento de trás sem removê-lo
 * Complexidade: O(1) - Acesso direto ao último elemento
 */
Elemento *FilaOtimizada::consultarTras() const
{
    if (filaVazia())
    {
        return nullptr;
    }

    // O índice de trás aponta para a próxima posição livre,
    // então o último elemento está na posição anterior
    int indiceTras = (tras - 1 + capacidade) % capacidade;
    return elementos[indiceTras];
}

/**
 * Verifica se a fila está cheia
 * Complexidade: O(1)
 */
bool FilaOtimizada::filaCheia() const
{
    return tamanho >= capacidade;
}

/**
 * Verifica se a fila está vazia
 * Complexidade: O(1)
 */
bool FilaOtimizada::filaVazia() const
{
    return tamanho == 0;
}

/**
 * Imprime todos os elementos da fila (da frente para trás)
 * Complexidade: O(n) - Percorre todos os elementos
 */
void FilaOtimizada::imprimirFila() const
{
    std::cout << "=== Fila Otimizada (FIFO) ===" << std::endl;
    if (filaVazia())
    {
        std::cout << "Fila vazia!" << std::endl;
        return;
    }

    std::cout << "Elementos da fila (da frente para trás):" << std::endl;

    int indiceAtual = frente;
    for (int i = 0; i < tamanho; i++)
    {
        std::cout << "Posição " << i << ": ";
        elementos[indiceAtual]->imprimirInfo();
        indiceAtual = proximoIndice(indiceAtual);
    }

    std::cout << "Tamanho da fila: " << tamanho << std::endl;
    std::cout << "Índice da frente: " << frente << std::endl;
    std::cout << "Índice de trás: " << tras << std::endl;

    std::cout << "\nNOTA: Esta implementação otimizada usa fila circular," << std::endl;
    std::cout << "proporcionando operações O(1) tanto para enfileirar quanto para desenfileirar." << std::endl;
}
