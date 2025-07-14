#include "Pessoa.h"
#include <iostream>

/**
 * Implementação do método imprimirInfo() da classe Pessoa
 * Complexidade: O(1) - Tempo constante
 */
void Pessoa::imprimirInfo() const
{
    std::cout << "Pessoa - ID: " << id << ", Nome: " << nome
              << ", Idade: " << idade << " anos" << std::endl;
}

/**
 * Implementação do método equals() da classe Pessoa
 * Complexidade: O(1) - Tempo constante
 */
bool Pessoa::equals(const Elemento &outro) const
{
    try
    {
        const Pessoa &outraPessoa = dynamic_cast<const Pessoa &>(outro);
        return (id == outraPessoa.id && nome == outraPessoa.nome && idade == outraPessoa.idade);
    }
    catch (const std::bad_cast &e)
    {
        return false;
    }
}
