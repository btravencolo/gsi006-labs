rem Desativa o print de todos os comandos utilizados.
@echo off

rem Limpa a tela.
cls

rem Verifica os parâmetros passados pelo usuário.
if defined %1 ( 
    GOTO seta_variavel
)

if exist %1\ ( 
    GOTO seta_variavel
)

echo "É necessário passar o nome de um exercício válido como parâmetro."
exit /B 1 

:seta_variavel
    set EXERCICIO=%1



rem Realiza a compilação do exercício, caso esteja dentro do padrão.
:compila_programa
    cd %EXERCICIO%
    gcc -c -std=c11 %EXERCICIO%.c -o %EXERCICIO%.o
    gcc %EXERCICIO%.o -o %EXERCICIO%.exe
    GOTO testa_entrada1



rem Executa o exercício para a primeira entrada.
:testa_entrada1
setlocal EnableDelayedExpansion

set /A i=1
for %%f in (*.in?) do (
    %EXERCICIO% < %%~nf.in > %%~nf.out!i!
    FC %%~nf.out %%~nf.out!i! > NUL
    
    if ERRORLEVEL 1 (
        call code -d %%~nf.out!i! %%~nf.out
        echo "Seu exercicio falhou no teste !i!."
    ) else ( echo "Seu exercicio passou no teste !i!." )

    set /A i+=1
)



rem Remove o arquivo executável, o arquivo objeto e suas saídas.
:remove_arquivo
DEL %EXERCICIO%.o
DEL %EXERCICIO%.exe
cd ..
