#ifndef PRODUTO_H
#define PRODUTO_H

#include "Elemento.h"
#include <string>

/**
 * Classe concreta que representa um Produto, herdando de Elemento.
 * Esta classe demonstra os pilares da Herança e Polimorfismo.
 */
class Produto : public Elemento
{
private:
    std::string nome;
    double preco;
    int quantidade;

public:
    /**
     * Construtor da classe Produto
     * @param id Identificador único do produto
     * @param nome Nome do produto
     * @param preco Preço do produto
     * @param quantidade Quantidade em estoque
     */
    Produto(int id, const std::string &nome, double preco, int quantidade)
        : Elemento(id), nome(nome), preco(preco), quantidade(quantidade) {}

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

    // Métodos específicos da classe Produto (Encapsulamento)
    std::string getNome() const { return nome; }
    double getPreco() const { return preco; }
    int getQuantidade() const { return quantidade; }
    void setNome(const std::string &novoNome) { nome = novoNome; }
    void setPreco(double novoPreco) { preco = novoPreco; }
    void setQuantidade(int novaQuantidade) { quantidade = novaQuantidade; }
};

#endif // PRODUTO_H
