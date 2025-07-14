#include "Produto.h"
#include <iostream>
#include <iomanip>

/**
 * Implementação do método imprimirInfo() da classe Produto
 * Complexidade: O(1) - Tempo constante
 */
void Produto::imprimirInfo() const
{
    std::cout << "Produto - ID: " << id << ", Nome: " << nome
              << ", Preço: R$ " << std::fixed << std::setprecision(2) << preco
              << ", Quantidade: " << quantidade << std::endl;
}

/**
 * Implementação do método equals() da classe Produto
 * Complexidade: O(1) - Tempo constante
 */
bool Produto::equals(const Elemento &outro) const
{
    try
    {
        const Produto &outroProduto = dynamic_cast<const Produto &>(outro);
        return (id == outroProduto.id && nome == outroProduto.nome &&
                preco == outroProduto.preco && quantidade == outroProduto.quantidade);
    }
    catch (const std::bad_cast &e)
    {
        return false;
    }
}
