#include <iostream>
#include <memory>

// Includes das classes base
#include "Elemento.h"
#include "Pessoa.h"
#include "Produto.h"

// Includes das estruturas com alocação sequencial
#include "ListaNaoOrdenada.h"
#include "ListaOrdenada.h"
#include "Pilha.h"
#include "Fila.h"
#include "FilaOtimizada.h"

// Includes das estruturas com alocação encadeada
#include "ListaSimplesmenteEncadeada.h"
#include "ListaDuplamenteEncadeada.h"
#include "ListaDuplamenteEncadeadaCircular.h"
#include "PilhaEncadeada.h"
#include "FilaEncadeada.h"
#include "Deque.h"
#include "ArvoreBinariaBusca.h"

/**
 * Função auxiliar para pausar a execução e aguardar entrada do usuário
 */
void pausar()
{
    std::cout << "\nPressione Enter para continuar..." << std::endl;
    std::cin.get();
}

/**
 * Função auxiliar para imprimir separador
 */
void imprimirSeparador(const std::string &titulo)
{
    std::cout << "\n"
              << std::string(60, '=') << std::endl;
    std::cout << "  " << titulo << std::endl;
    std::cout << std::string(60, '=') << std::endl;
}

/**
 * Demonstra o polimorfismo com estruturas de alocação sequencial
 */
void demonstrarPolimorfismoSequencial()
{
    imprimirSeparador("DEMONSTRAÇÃO DE POLIMORFISMO - ESTRUTURAS SEQUENCIAIS");

    // Cria uma lista não ordenada
    ListaNaoOrdenada lista;

    // Cria objetos de diferentes classes que herdam de Elemento
    Pessoa *pessoa1 = new Pessoa(1, "João Silva", 30);
    Produto *produto1 = new Produto(2, "Notebook", 2500.00, 10);
    Pessoa *pessoa2 = new Pessoa(3, "Maria Santos", 25);
    Produto *produto2 = new Produto(4, "Mouse", 50.00, 100);

    // Adiciona elementos de diferentes tipos na mesma lista
    lista.inserirNoFinal(pessoa1);
    lista.inserirNoFinal(produto1);
    lista.inserirNoFinal(pessoa2);
    lista.inserirNoFinal(produto2);

    std::cout << "\n=== POLIMORFISMO EM AÇÃO ===" << std::endl;
    std::cout << "A mesma lista contém objetos de diferentes classes:" << std::endl;

    // Demonstra polimorfismo: o método correto é chamado para cada tipo
    lista.imprimirTodos();

    std::cout << "\n=== TESTANDO OPERAÇÕES DA LISTA ===" << std::endl;

    // Testa busca
    Elemento *encontrado = lista.buscarPeloId(2);
    if (encontrado)
    {
        std::cout << "Elemento encontrado com ID 2: ";
        encontrado->imprimirInfo();
    }

    // Testa remoção
    Elemento *removido = lista.removerPeloId(3);
    if (removido)
    {
        std::cout << "Elemento removido com ID 3: ";
        removido->imprimirInfo();
        delete removido; // Libera memória do elemento removido
    }

    std::cout << "\nLista após remoção:" << std::endl;
    lista.imprimirTodos();

    pausar();
}

/**
 * Demonstra as estruturas de dados com alocação sequencial
 */
void demonstrarEstruturasSequenciais()
{
    imprimirSeparador("DEMONSTRAÇÃO DAS ESTRUTURAS SEQUENCIAIS");

    // Lista Ordenada
    std::cout << "\n=== TESTANDO LISTA ORDENADA ===" << std::endl;
    ListaOrdenada listaOrdenada;

    // Insere elementos fora de ordem para mostrar que mantém ordem
    listaOrdenada.inserirNoFinal(new Pessoa(50, "Pedro", 40));
    listaOrdenada.inserirNoInicio(new Pessoa(20, "Ana", 35));
    listaOrdenada.inserirNoFinal(new Pessoa(30, "Carlos", 28));
    listaOrdenada.inserirNoInicio(new Pessoa(10, "Beatriz", 32));

    std::cout << "Lista ordenada (mantém ordem pelo ID):" << std::endl;
    listaOrdenada.imprimirTodos();

    // Testa busca binária
    std::cout << "\nTeste de busca binária (ID 30):" << std::endl;
    Elemento *encontrado = listaOrdenada.buscarPeloId(30);
    if (encontrado)
    {
        encontrado->imprimirInfo();
    }

    pausar();

    // Pilha
    std::cout << "\n=== TESTANDO PILHA (LIFO) ===" << std::endl;
    Pilha pilha;

    pilha.empilhar(new Produto(101, "Teclado", 150.00, 20));
    pilha.empilhar(new Produto(102, "Monitor", 800.00, 5));
    pilha.empilhar(new Produto(103, "Impressora", 300.00, 15));

    std::cout << "Pilha após empilhar 3 elementos:" << std::endl;
    pilha.imprimirPilha();

    std::cout << "\nDesempilhando elementos:" << std::endl;
    while (!pilha.pilhaVazia())
    {
        Elemento *elemento = pilha.desempilhar();
        if (elemento)
        {
            std::cout << "Desempilhado: ";
            elemento->imprimirInfo();
            delete elemento;
        }
    }

    pausar();

    // Fila e Fila Otimizada
    std::cout << "\n=== TESTANDO FILA BÁSICA (FIFO) ===" << std::endl;
    Fila fila;

    fila.enfileirar(new Pessoa(201, "Cliente 1", 25));
    fila.enfileirar(new Pessoa(202, "Cliente 2", 30));
    fila.enfileirar(new Pessoa(203, "Cliente 3", 35));

    std::cout << "Fila após enfileirar 3 elementos:" << std::endl;
    fila.imprimirFila();

    std::cout << "\n=== TESTANDO FILA OTIMIZADA (FIFO) ===" << std::endl;
    FilaOtimizada filaOtimizada;

    filaOtimizada.enfileirar(new Pessoa(301, "Cliente A", 28));
    filaOtimizada.enfileirar(new Pessoa(302, "Cliente B", 33));
    filaOtimizada.enfileirar(new Pessoa(303, "Cliente C", 29));

    std::cout << "Fila otimizada após enfileirar 3 elementos:" << std::endl;
    filaOtimizada.imprimirFila();

    std::cout << "\nDesenfilerando da fila otimizada:" << std::endl;
    while (!filaOtimizada.filaVazia())
    {
        Elemento *elemento = filaOtimizada.desenfileirar();
        if (elemento)
        {
            std::cout << "Desenfileirado: ";
            elemento->imprimirInfo();
            delete elemento;
        }
    }

    pausar();
}

/**
 * Demonstra as estruturas de dados com alocação encadeada
 */
void demonstrarEstruturasEncadeadas()
{
    imprimirSeparador("DEMONSTRAÇÃO DAS ESTRUTURAS ENCADEADAS");

    // Lista Simplesmente Encadeada
    std::cout << "\n=== TESTANDO LISTA SIMPLESMENTE ENCADEADA ===" << std::endl;
    ListaSimplesmenteEncadeada listaSimples;

    listaSimples.inserirNoInicio(new Pessoa(1001, "Alice", 22));
    listaSimples.inserirNoFim(new Pessoa(1002, "Bob", 25));
    listaSimples.inserirNoInicio(new Pessoa(1003, "Carol", 28));

    std::cout << "Lista simplesmente encadeada:" << std::endl;
    listaSimples.imprimirTodos();

    pausar();

    // Lista Duplamente Encadeada
    std::cout << "\n=== TESTANDO LISTA DUPLAMENTE ENCADEADA ===" << std::endl;
    ListaDuplamenteEncadeada listaDupla;

    listaDupla.inserirNoInicio(new Produto(2001, "Produto A", 100.00, 50));
    listaDupla.inserirNoFim(new Produto(2002, "Produto B", 200.00, 30));
    listaDupla.inserirNoInicio(new Produto(2003, "Produto C", 150.00, 40));

    std::cout << "Lista duplamente encadeada (início → fim):" << std::endl;
    listaDupla.imprimirTodos();

    std::cout << "\nLista duplamente encadeada (fim → início):" << std::endl;
    listaDupla.imprimirTodosReverso();

    pausar();

    // Lista Duplamente Encadeada Circular
    std::cout << "\n=== TESTANDO LISTA DUPLAMENTE ENCADEADA CIRCULAR ===" << std::endl;
    ListaDuplamenteEncadeadaCircular listaCircular;

    listaCircular.inserirNoInicio(new Pessoa(3001, "Pessoa X", 30));
    listaCircular.inserirNoFim(new Pessoa(3002, "Pessoa Y", 35));
    listaCircular.inserirNoInicio(new Pessoa(3003, "Pessoa Z", 40));

    std::cout << "Lista circular - 1 volta completa:" << std::endl;
    listaCircular.imprimirTodos(1);

    std::cout << "\nLista circular - 2 voltas completas:" << std::endl;
    listaCircular.imprimirTodos(2);

    pausar();
}

/**
 * Demonstra os adaptadores de estruturas encadeadas
 */
void demonstrarAdaptadoresEncadeados()
{
    imprimirSeparador("DEMONSTRAÇÃO DOS ADAPTADORES ENCADEADOS");

    // Pilha Encadeada
    std::cout << "\n=== TESTANDO PILHA ENCADEADA ===" << std::endl;
    PilhaEncadeada pilhaEncadeada;

    pilhaEncadeada.empilhar(new Produto(4001, "Item 1", 50.00, 100));
    pilhaEncadeada.empilhar(new Produto(4002, "Item 2", 75.00, 80));
    pilhaEncadeada.empilhar(new Produto(4003, "Item 3", 100.00, 60));

    std::cout << "Pilha encadeada:" << std::endl;
    pilhaEncadeada.imprimirPilha();

    pausar();

    // Fila Encadeada
    std::cout << "\n=== TESTANDO FILA ENCADEADA ===" << std::endl;
    FilaEncadeada filaEncadeada;

    filaEncadeada.enfileirar(new Pessoa(5001, "Usuário 1", 26));
    filaEncadeada.enfileirar(new Pessoa(5002, "Usuário 2", 31));
    filaEncadeada.enfileirar(new Pessoa(5003, "Usuário 3", 27));

    std::cout << "Fila encadeada:" << std::endl;
    filaEncadeada.imprimirFila();

    pausar();

    // Deque
    std::cout << "\n=== TESTANDO DEQUE (DOUBLE-ENDED QUEUE) ===" << std::endl;
    Deque deque;

    deque.inserirFrente(new Produto(6001, "Produto Frente", 120.00, 25));
    deque.inserirTras(new Produto(6002, "Produto Trás", 80.00, 45));
    deque.inserirFrente(new Produto(6003, "Produto Frente 2", 90.00, 35));
    deque.inserirTras(new Produto(6004, "Produto Trás 2", 110.00, 20));

    std::cout << "Deque (frente → trás):" << std::endl;
    deque.imprimirDeque();

    std::cout << "\nDeque (trás → frente):" << std::endl;
    deque.imprimirDequeReverso();

    std::cout << "\nRemovendo da frente e de trás:" << std::endl;
    Elemento *removidoFrente = deque.removerFrente();
    Elemento *removidoTras = deque.removerTras();

    if (removidoFrente)
    {
        std::cout << "Removido da frente: ";
        removidoFrente->imprimirInfo();
        delete removidoFrente;
    }

    if (removidoTras)
    {
        std::cout << "Removido de trás: ";
        removidoTras->imprimirInfo();
        delete removidoTras;
    }

    std::cout << "\nDeque após remoções:" << std::endl;
    deque.imprimirDeque();

    pausar();
}

/**
 * Demonstra a Árvore Binária de Busca
 */
void demonstrarArvoreBinariaBusca()
{
    imprimirSeparador("DEMONSTRAÇÃO DA ÁRVORE BINÁRIA DE BUSCA");

    ArvoreBinariaBusca arvore;

    // Insere elementos na árvore
    std::cout << "\n=== INSERINDO ELEMENTOS NA ÁRVORE ===" << std::endl;
    arvore.inserir(new Pessoa(50, "Raiz", 45));
    arvore.inserir(new Pessoa(30, "Esquerda", 35));
    arvore.inserir(new Pessoa(70, "Direita", 55));
    arvore.inserir(new Pessoa(20, "Esquerda-Esquerda", 25));
    arvore.inserir(new Pessoa(40, "Esquerda-Direita", 30));
    arvore.inserir(new Pessoa(60, "Direita-Esquerda", 40));
    arvore.inserir(new Pessoa(80, "Direita-Direita", 60));

    std::cout << "Árvore criada com " << arvore.getTamanho() << " elementos." << std::endl;

    // Demonstra os três tipos de percurso
    std::cout << "\n=== PERCURSOS DA ÁRVORE ===" << std::endl;

    arvore.emOrdem();
    std::cout << std::endl;

    arvore.preOrdem();
    std::cout << std::endl;

    arvore.posOrdem();
    std::cout << std::endl;

    // Testa busca
    std::cout << "\n=== TESTANDO BUSCA NA ÁRVORE ===" << std::endl;
    Elemento *encontrado = arvore.buscarPeloId(40);
    if (encontrado)
    {
        std::cout << "Elemento encontrado com ID 40: ";
        encontrado->imprimirInfo();
    }

    encontrado = arvore.buscarPeloId(100);
    if (!encontrado)
    {
        std::cout << "Elemento com ID 100 não encontrado (esperado)." << std::endl;
    }

    // Testa remoção
    std::cout << "\n=== TESTANDO REMOÇÃO NA ÁRVORE ===" << std::endl;
    Elemento *removido = arvore.removerPeloId(30);
    if (removido)
    {
        std::cout << "Elemento removido com ID 30: ";
        removido->imprimirInfo();
        delete removido;
    }

    std::cout << "\nÁrvore após remoção (percurso em ordem):" << std::endl;
    arvore.emOrdem();

    pausar();
}

/**
 * Função principal do programa
 */
int main()
{
    std::cout << "=== TRABALHO DE ALGORITMOS E ESTRUTURAS DE DADOS ===" << std::endl;
    std::cout << "Demonstração dos 4 Pilares da Programação Orientada a Objetos" << std::endl;
    std::cout << "em C++ aplicados a Estruturas de Dados" << std::endl;
    std::cout << "\nPilares demonstrados:" << std::endl;
    std::cout << "1. Abstração - Classe base Elemento" << std::endl;
    std::cout << "2. Encapsulamento - Membros privados e métodos públicos" << std::endl;
    std::cout << "3. Herança - Pessoa e Produto herdam de Elemento" << std::endl;
    std::cout << "4. Polimorfismo - Métodos virtuais com comportamentos específicos" << std::endl;

    pausar();

    // Demonstra cada parte do trabalho
    demonstrarPolimorfismoSequencial();
    demonstrarEstruturasSequenciais();
    demonstrarEstruturasEncadeadas();
    demonstrarAdaptadoresEncadeados();
    demonstrarArvoreBinariaBusca();

    imprimirSeparador("FIM DA DEMONSTRAÇÃO");
    std::cout << "\nTodas as estruturas de dados foram testadas com sucesso!" << std::endl;
    std::cout << "O programa demonstrou os 4 pilares da POO em C++." << std::endl;

    return 0;
}
