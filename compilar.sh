#!/bin/bash

# Script de compilação do projeto AED
# Compila todos os arquivos necessários

echo "Compilando projeto AED..."

g++ -std=c++11 -o programa \
    main.cpp \
    Pessoa.cpp \
    Produto.cpp \
    ListaNaoOrdenada.cpp \
    ListaOrdenada.cpp \
    Pilha.cpp \
    Fila.cpp \
    FilaOtimizada.cpp \
    ListaSimplesmenteEncadeada.cpp \
    ListaDuplamenteEncadeada.cpp \
    ListaDuplamenteEncadeadaCircular.cpp \
    PilhaEncadeada.cpp \
    FilaEncadeada.cpp \
    Deque.cpp \
    ArvoreBinariaBusca.cpp

if [ $? -eq 0 ]; then
    echo "✅ Compilação concluída com sucesso!"
    echo "Execute: ./programa"
else
    echo "❌ Erro na compilação!"
    exit 1
fi
