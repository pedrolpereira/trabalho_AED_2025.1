# Trabalho de Algoritmos e Estruturas de Dados (AED)

## Integrantes do Grupo

- Pedro Lannes Pereira

## Descrição do Projeto

Este trabalho implementa os quatro pilares da Programação Orientada a Objetos (Abstração, Encapsulamento, Herança e Polimorfismo) através de um conjunto de estruturas de dados clássicas em C++.

## Principais Decisões de Design

### 1. Hierarquia de Classes

- **Classe Elemento**: Implementada como classe abstrata base com método virtual puro `imprimirInfo()` para garantir que todas as classes derivadas implementem sua própria forma de apresentação.
- **Classes Pessoa e Produto**: Implementadas como classes concretas que herdam de Elemento, demonstrando herança e polimorfismo.

### 2. Estruturas Sequenciais

- **Composição para Pilha e Fila**: Optei por composição utilizando `ListaNaoOrdenada` para implementar a Pilha e a Fila para maximizar o reuso de código e manter a responsabilidade única de cada classe.
- **Fila Otimizada**: Implementei uma segunda versão da Fila (`FilaOtimizada`) que resolve o problema de ineficiência da primeira implementação através do uso de índices circulares.

### 3. Estruturas Encadeadas

- **Encapsulamento de Nós**: Todas as classes de nó são implementadas como classes privadas internas às estruturas de dados, escondendo completamente os detalhes de implementação.
- **Pilha Encadeada**: Utiliza `ListaSimplesmenteEncadeada` por composição para operações O(1) no topo.
- **Fila Encadeada**: Utiliza `ListaDuplamenteEncadeada` por composição para operações O(1) em ambas as extremidades.
- **Deque**: Implementado usando `ListaDuplamenteEncadeada` para permitir inserção/remoção eficiente em ambas as extremidades.

### 4. Árvore Binária de Busca

- **Implementação Recursiva**: Métodos de inserção, busca e remoção implementados recursivamente para clareza e elegância.
- **Três Tipos de Percurso**: Implementados os percursos em ordem, pré-ordem e pós-ordem.

## Complexidade das Operações

### Estruturas Sequenciais

#### Lista Não Ordenada

| Operação        | Complexidade | Justificativa                          |
| --------------- | ------------ | -------------------------------------- |
| InserirNoInicio | O(n)         | Necessário deslocar todos os elementos |
| InserirNoFinal  | O(1)         | Inserção direta no final               |
| RemoverPrimeiro | O(n)         | Necessário deslocar todos os elementos |
| RemoverUltimo   | O(1)         | Remoção direta do final                |
| RemoverPeloId   | O(n)         | Busca linear + deslocamento            |
| BuscarPeloId    | O(n)         | Busca linear                           |
| AlterarPeloId   | O(n)         | Busca linear                           |

#### Lista Ordenada

| Operação        | Complexidade | Justificativa                                |
| --------------- | ------------ | -------------------------------------------- |
| InserirNoInicio | O(n)         | Busca binária O(log n) + inserção O(n)       |
| InserirNoFinal  | O(n)         | Busca binária O(log n) + inserção O(n)       |
| RemoverPrimeiro | O(n)         | Deslocamento de elementos                    |
| RemoverUltimo   | O(1)         | Remoção direta do final                      |
| RemoverPeloId   | O(n)         | Busca binária O(log n) + remoção O(n)        |
| BuscarPeloId    | O(log n)     | Busca binária                                |
| AlterarPeloId   | O(n)         | Busca O(log n) + possível reorganização O(n) |

#### Pilha

| Operação      | Complexidade | Justificativa                    |
| ------------- | ------------ | -------------------------------- |
| Empilhar      | O(1)         | Inserção no final da lista       |
| Desempilhar   | O(1)         | Remoção do final da lista        |
| ConsultarTopo | O(1)         | Acesso direto ao último elemento |

#### Fila

| Operação      | Complexidade | Justificativa                   |
| ------------- | ------------ | ------------------------------- |
| Enfileirar    | O(1)         | Inserção no final               |
| Desenfileirar | O(n)         | Remoção do início (ineficiente) |

#### Fila Otimizada

| Operação      | Complexidade | Justificativa                |
| ------------- | ------------ | ---------------------------- |
| Enfileirar    | O(1)         | Inserção com índice circular |
| Desenfileirar | O(1)         | Remoção com índice circular  |

### Estruturas Encadeadas

#### Lista Simplesmente Encadeada

| Operação        | Complexidade | Justificativa                    |
| --------------- | ------------ | -------------------------------- |
| InserirNoInicio | O(1)         | Inserção direta no início        |
| InserirNoFinal  | O(n)         | Necessário percorrer até o final |
| RemoverPeloId   | O(n)         | Busca linear + remoção           |
| BuscarPeloId    | O(n)         | Busca linear                     |

#### Lista Duplamente Encadeada

| Operação        | Complexidade | Justificativa               |
| --------------- | ------------ | --------------------------- |
| InserirNoInicio | O(1)         | Inserção direta no início   |
| InserirNoFinal  | O(1)         | Acesso direto ao final      |
| RemoverPeloId   | O(n)         | Busca linear + remoção O(1) |
| BuscarPeloId    | O(n)         | Busca linear                |

#### Lista Duplamente Encadeada Circular

| Operação        | Complexidade | Justificativa               |
| --------------- | ------------ | --------------------------- |
| InserirNoInicio | O(1)         | Inserção direta no início   |
| InserirNoFinal  | O(1)         | Acesso direto ao final      |
| RemoverPeloId   | O(n)         | Busca linear + remoção O(1) |
| BuscarPeloId    | O(n)         | Busca linear                |

#### Pilha Encadeada

| Operação      | Complexidade | Justificativa                      |
| ------------- | ------------ | ---------------------------------- |
| Empilhar      | O(1)         | Inserção no início da lista        |
| Desempilhar   | O(1)         | Remoção do início da lista         |
| ConsultarTopo | O(1)         | Acesso direto ao primeiro elemento |

#### Fila Encadeada

| Operação      | Complexidade | Justificativa                    |
| ------------- | ------------ | -------------------------------- |
| Enfileirar    | O(1)         | Inserção no final da lista dupla |
| Desenfileirar | O(1)         | Remoção do início da lista dupla |

#### Deque

| Operação        | Complexidade | Justificativa                     |
| --------------- | ------------ | --------------------------------- |
| InserirNoInicio | O(1)         | Inserção no início da lista dupla |
| InserirNoFinal  | O(1)         | Inserção no final da lista dupla  |
| RemoverDoInicio | O(1)         | Remoção do início da lista dupla  |
| RemoverDoFinal  | O(1)         | Remoção do final da lista dupla   |

#### Árvore Binária de Busca

| Operação      | Complexidade                   | Justificativa       |
| ------------- | ------------------------------ | ------------------- |
| Inserir       | O(log n) médio, O(n) pior caso | Altura da árvore    |
| BuscarPeloId  | O(log n) médio, O(n) pior caso | Altura da árvore    |
| RemoverPeloId | O(log n) médio, O(n) pior caso | Altura da árvore    |
| EmOrdem       | O(n)                           | Visita todos os nós |
| PreOrdem      | O(n)                           | Visita todos os nós |
| PosOrdem      | O(n)                           | Visita todos os nós |

## Como Compilar

```bash
g++ -std=c++11 -o programa main.cpp Pessoa.cpp Produto.cpp ListaNaoOrdenada.cpp ListaOrdenada.cpp Pilha.cpp Fila.cpp FilaOtimizada.cpp ListaSimplesmenteEncadeada.cpp ListaDuplamenteEncadeada.cpp ListaDuplamenteEncadeadaCircular.cpp PilhaEncadeada.cpp FilaEncadeada.cpp Deque.cpp ArvoreBinariaBusca.cpp
```

## Como Executar

```bash
./programa
```

## Estrutura de Arquivos

```
├── Elemento.h                              # Classe abstrata base
├── Pessoa.h / Pessoa.cpp                   # Classe concreta derivada
├── Produto.h / Produto.cpp                 # Classe concreta derivada
├── ListaNaoOrdenada.h / ListaNaoOrdenada.cpp   # Lista com alocação sequencial
├── ListaOrdenada.h / ListaOrdenada.cpp     # Lista ordenada com busca binária
├── Pilha.h / Pilha.cpp                     # Pilha por composição
├── Fila.h / Fila.cpp                       # Fila por composição
├── FilaOtimizada.h / FilaOtimizada.cpp     # Fila otimizada
├── ListaSimplesmenteEncadeada.h / ListaSimplesmenteEncadeada.cpp  # Lista encadeada simples
├── ListaDuplamenteEncadeada.h / ListaDuplamenteEncadeada.cpp      # Lista encadeada dupla
├── ListaDuplamenteEncadeadaCircular.h / ListaDuplamenteEncadeadaCircular.cpp  # Lista circular
├── PilhaEncadeada.h / PilhaEncadeada.cpp   # Pilha encadeada
├── FilaEncadeada.h / FilaEncadeada.cpp     # Fila encadeada
├── Deque.h / Deque.cpp                     # Deque (Double-ended queue)
├── ArvoreBinariaBusca.h / ArvoreBinariaBusca.cpp  # Árvore binária de busca
├── main.cpp                                # Programa de demonstração
└── README.md                               # Este arquivo
```

## Demonstração dos Pilares da POO

O programa `main.cpp` demonstra todos os quatro pilares da POO:

1. **Abstração**: Classe `Elemento` define interface comum através de métodos virtuais puros
2. **Encapsulamento**: Todos os atributos são privados/protegidos com acesso controlado por métodos públicos
3. **Herança**: Classes `Pessoa` e `Produto` herdam de `Elemento`
4. **Polimorfismo**: Diferentes tipos de objetos são tratados de forma uniforme através da interface comum
