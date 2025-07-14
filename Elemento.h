#ifndef ELEMENTO_H
#define ELEMENTO_H

/**
 * Classe abstrata base para todos os elementos que serão armazenados nas estruturas de dados.
 * Esta classe implementa o pilar da Abstração, definindo uma interface comum para todos os elementos.
 */
class Elemento
{
protected:
    int id; // Atributo protegido que serve como chave primária

public:
    /**
     * Construtor da classe Elemento
     * @param id Identificador único do elemento
     */
    Elemento(int id) : id(id) {}

    /**
     * Destrutor virtual para garantir polimorfismo correto
     */
    virtual ~Elemento() = default;

    /**
     * Método público para acessar o ID do elemento (Encapsulamento)
     * @return ID do elemento
     */
    int getID() const { return id; }

    /**
     * Método virtual puro que força todas as classes filhas a implementar
     * uma forma de apresentar suas informações (Polimorfismo)
     */
    virtual void imprimirInfo() const = 0;

    /**
     * Método virtual puro para comparação de elementos
     * @param outro Elemento a ser comparado
     * @return true se os elementos são iguais, false caso contrário
     */
    virtual bool equals(const Elemento &outro) const = 0;
};

#endif // ELEMENTO_H
