#include "ArvoreBinariaBusca.h"
#include <iostream>

/**
 * Construtor da Árvore Binária de Busca
 * Complexidade: O(1)
 */
ArvoreBinariaBusca::ArvoreBinariaBusca() : raiz(nullptr), tamanho(0) {}

/**
 * Destrutor da Árvore Binária de Busca
 * Complexidade: O(n) - Precisa deletar todos os nós
 */
ArvoreBinariaBusca::~ArvoreBinariaBusca()
{
    destruirArvore(raiz);
}

/**
 * Método auxiliar recursivo para inserir um elemento
 * Complexidade: O(log n) no caso médio, O(n) no pior caso
 */
ArvoreBinariaBusca::No *ArvoreBinariaBusca::inserirRecursivo(No *no, Elemento *elemento)
{
    // Caso base: encontrou a posição para inserir
    if (no == nullptr)
    {
        return new No(elemento);
    }

    // Decisão baseada no ID do elemento
    if (elemento->getID() < no->elemento->getID())
    {
        no->esquerdo = inserirRecursivo(no->esquerdo, elemento);
    }
    else if (elemento->getID() > no->elemento->getID())
    {
        no->direito = inserirRecursivo(no->direito, elemento);
    }
    else
    {
        // ID já existe, não insere (ou poderia substituir)
        return no;
    }

    return no;
}

/**
 * Método auxiliar recursivo para buscar um elemento
 * Complexidade: O(log n) no caso médio, O(n) no pior caso
 */
Elemento *ArvoreBinariaBusca::buscarRecursivo(No *no, int id) const
{
    // Caso base: nó nulo ou encontrado
    if (no == nullptr)
    {
        return nullptr;
    }

    if (id == no->elemento->getID())
    {
        return no->elemento;
    }

    // Busca recursiva na subárvore apropriada
    if (id < no->elemento->getID())
    {
        return buscarRecursivo(no->esquerdo, id);
    }
    else
    {
        return buscarRecursivo(no->direito, id);
    }
}

/**
 * Método auxiliar recursivo para remover um elemento
 * Complexidade: O(log n) no caso médio, O(n) no pior caso
 */
ArvoreBinariaBusca::No *ArvoreBinariaBusca::removerRecursivo(No *no, int id)
{
    // Caso base: nó não encontrado
    if (no == nullptr)
    {
        return nullptr;
    }

    // Busca o nó a ser removido
    if (id < no->elemento->getID())
    {
        no->esquerdo = removerRecursivo(no->esquerdo, id);
    }
    else if (id > no->elemento->getID())
    {
        no->direito = removerRecursivo(no->direito, id);
    }
    else
    {
        // Nó encontrado - casos de remoção

        // Caso 1: Nó folha ou com apenas um filho
        if (no->esquerdo == nullptr)
        {
            No *temp = no->direito;
            delete no->elemento;
            delete no;
            return temp;
        }
        else if (no->direito == nullptr)
        {
            No *temp = no->esquerdo;
            delete no->elemento;
            delete no;
            return temp;
        }

        // Caso 2: Nó com dois filhos
        // Encontra o sucessor em ordem (menor valor da subárvore direita)
        No *sucessor = encontrarMinimo(no->direito);

        // Substitui o elemento do nó atual pelo do sucessor
        delete no->elemento;
        no->elemento = sucessor->elemento;

        // Remove o sucessor (que agora é duplicado)
        no->direito = removerRecursivo(no->direito, sucessor->elemento->getID());
    }

    return no;
}

/**
 * Método auxiliar para encontrar o menor elemento de uma subárvore
 * Complexidade: O(log n) no caso médio, O(n) no pior caso
 */
ArvoreBinariaBusca::No *ArvoreBinariaBusca::encontrarMinimo(No *no) const
{
    while (no->esquerdo != nullptr)
    {
        no = no->esquerdo;
    }
    return no;
}

/**
 * Método auxiliar recursivo para percurso em ordem
 * Complexidade: O(n) - Visita todos os nós
 */
void ArvoreBinariaBusca::emOrdemRecursivo(No *no) const
{
    if (no != nullptr)
    {
        emOrdemRecursivo(no->esquerdo);
        std::cout << "ID: " << no->elemento->getID() << " - ";
        no->elemento->imprimirInfo();
        emOrdemRecursivo(no->direito);
    }
}

/**
 * Método auxiliar recursivo para percurso pré-ordem
 * Complexidade: O(n) - Visita todos os nós
 */
void ArvoreBinariaBusca::preOrdemRecursivo(No *no) const
{
    if (no != nullptr)
    {
        std::cout << "ID: " << no->elemento->getID() << " - ";
        no->elemento->imprimirInfo();
        preOrdemRecursivo(no->esquerdo);
        preOrdemRecursivo(no->direito);
    }
}

/**
 * Método auxiliar recursivo para percurso pós-ordem
 * Complexidade: O(n) - Visita todos os nós
 */
void ArvoreBinariaBusca::posOrdemRecursivo(No *no) const
{
    if (no != nullptr)
    {
        posOrdemRecursivo(no->esquerdo);
        posOrdemRecursivo(no->direito);
        std::cout << "ID: " << no->elemento->getID() << " - ";
        no->elemento->imprimirInfo();
    }
}

/**
 * Método auxiliar recursivo para destruir a árvore
 * Complexidade: O(n) - Visita todos os nós
 */
void ArvoreBinariaBusca::destruirArvore(No *no)
{
    if (no != nullptr)
    {
        destruirArvore(no->esquerdo);
        destruirArvore(no->direito);
        delete no->elemento;
        delete no;
    }
}

/**
 * Insere um elemento na árvore mantendo a propriedade de busca
 * Complexidade: O(log n) no caso médio, O(n) no pior caso
 */
bool ArvoreBinariaBusca::inserir(Elemento *elemento)
{
    if (elemento == nullptr)
    {
        return false;
    }

    // Verifica se já existe um elemento com o mesmo ID
    if (buscarPeloId(elemento->getID()) != nullptr)
    {
        return false; // Não permite IDs duplicados
    }

    raiz = inserirRecursivo(raiz, elemento);
    tamanho++;
    return true;
}

/**
 * Busca um elemento pelo ID
 * Complexidade: O(log n) no caso médio, O(n) no pior caso
 */
Elemento *ArvoreBinariaBusca::buscarPeloId(int id) const
{
    return buscarRecursivo(raiz, id);
}

/**
 * Remove um elemento pelo ID
 * Complexidade: O(log n) no caso médio, O(n) no pior caso
 */
Elemento *ArvoreBinariaBusca::removerPeloId(int id)
{
    Elemento *elementoRemovido = buscarPeloId(id);

    if (elementoRemovido != nullptr)
    {
        raiz = removerRecursivo(raiz, id);
        tamanho--;
    }

    return elementoRemovido;
}

/**
 * Percurso em ordem (esquerda, raiz, direita)
 * Complexidade: O(n) - Visita todos os nós
 */
void ArvoreBinariaBusca::emOrdem() const
{
    std::cout << "=== Percurso Em Ordem (Esquerda, Raiz, Direita) ===" << std::endl;
    if (estaVazia())
    {
        std::cout << "Árvore vazia!" << std::endl;
        return;
    }

    std::cout << "Elementos em ordem crescente de ID:" << std::endl;
    emOrdemRecursivo(raiz);
    std::cout << "Total de elementos: " << tamanho << std::endl;
}

/**
 * Percurso pré-ordem (raiz, esquerda, direita)
 * Complexidade: O(n) - Visita todos os nós
 */
void ArvoreBinariaBusca::preOrdem() const
{
    std::cout << "=== Percurso Pré-Ordem (Raiz, Esquerda, Direita) ===" << std::endl;
    if (estaVazia())
    {
        std::cout << "Árvore vazia!" << std::endl;
        return;
    }

    std::cout << "Elementos em pré-ordem:" << std::endl;
    preOrdemRecursivo(raiz);
    std::cout << "Total de elementos: " << tamanho << std::endl;
}

/**
 * Percurso pós-ordem (esquerda, direita, raiz)
 * Complexidade: O(n) - Visita todos os nós
 */
void ArvoreBinariaBusca::posOrdem() const
{
    std::cout << "=== Percurso Pós-Ordem (Esquerda, Direita, Raiz) ===" << std::endl;
    if (estaVazia())
    {
        std::cout << "Árvore vazia!" << std::endl;
        return;
    }

    std::cout << "Elementos em pós-ordem:" << std::endl;
    posOrdemRecursivo(raiz);
    std::cout << "Total de elementos: " << tamanho << std::endl;
}
