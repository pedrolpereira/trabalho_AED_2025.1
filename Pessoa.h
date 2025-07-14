#ifndef PESSOA_H
#define PESSOA_H

#include "Elemento.h"
#include <string>

/**
 * Classe concreta que representa uma Pessoa, herdando de Elemento.
 * Esta classe demonstra os pilares da Herança e Polimorfismo.
 */
class Pessoa : public Elemento
{
private:
    std::string nome;
    int idade;

public:
    /**
     * Construtor da classe Pessoa
     * @param id Identificador único da pessoa
     * @param nome Nome da pessoa
     * @param idade Idade da pessoa
     */
    Pessoa(int id, const std::string &nome, int idade)
        : Elemento(id), nome(nome), idade(idade) {}

    /**
     * Implementação do método virtual puro da classe base
     * Demonstra o polimorfismo ao fornecer uma implementação específica
     */
    void imprimirInfo() const override;

    /**
     * Implementação do método virtual puro para comparação
     * @param outro Elemento a ser comparado
     * @return true se os elementos são iguais, false caso contrário
     */
    bool equals(const Elemento &outro) const override;

    // Métodos específicos da classe Pessoa (Encapsulamento)
    std::string getNome() const { return nome; }
    int getIdade() const { return idade; }
    void setNome(const std::string &novoNome) { nome = novoNome; }
    void setIdade(int novaIdade) { idade = novaIdade; }
};

#endif // PESSOA_H
