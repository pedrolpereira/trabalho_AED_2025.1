@echo off
REM Script de compilação do projeto AED
REM Compila todos os arquivos necessários

echo Compilando projeto AED...

g++ -std=c++11 -o programa.exe main.cpp Pessoa.cpp Produto.cpp ListaNaoOrdenada.cpp ListaOrdenada.cpp Pilha.cpp Fila.cpp FilaOtimizada.cpp ListaSimplesmenteEncadeada.cpp ListaDuplamenteEncadeada.cpp ListaDuplamenteEncadeadaCircular.cpp PilhaEncadeada.cpp FilaEncadeada.cpp Deque.cpp ArvoreBinariaBusca.cpp

if %errorlevel% == 0 (
    echo ✅ Compilação concluída com sucesso!
    echo Execute: programa.exe
) else (
    echo ❌ Erro na compilação!
    pause
    exit /b 1
)

pause