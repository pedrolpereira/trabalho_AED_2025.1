# Makefile para o projeto AED
# Demonstração dos 4 pilares da POO em C++

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = programa
SOURCES = main.cpp Pessoa.cpp Produto.cpp ListaNaoOrdenada.cpp ListaOrdenada.cpp Pilha.cpp Fila.cpp FilaOtimizada.cpp ListaSimplesmenteEncadeada.cpp ListaDuplamenteEncadeada.cpp ListaDuplamenteEncadeadaCircular.cpp PilhaEncadeada.cpp FilaEncadeada.cpp Deque.cpp ArvoreBinariaBusca.cpp

# Regra principal
all: $(TARGET)

# Compilação do programa
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

# Limpeza dos arquivos gerados
clean:
	rm -f $(TARGET) $(TARGET).exe

# Execução do programa
run: $(TARGET)
	./$(TARGET)

# Regra para forçar recompilação
rebuild: clean all

.PHONY: all clean run rebuild
