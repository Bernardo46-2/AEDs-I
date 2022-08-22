/*
Exemplo0214 - v0.0. - 01 / 04 / 2022
Author: Bernardo Marques Fernande - 774119
Para compilar em terminal (janela de comandos):
Linux : gcc -o exemplo0201 exemplo0201.c
Windows: gcc -o exemplo0201 exemplo0201.c
Para executar em terminal (janela de comandos):
Linux : ./exemplo0201
Windows: exemplo0201
*/

// dependencias
#include "io.h" // para definicoes proprias

/*
Funcao principal.
@return codigo de encerramento
@param argc - quantidade de parametros na linha de comandos
@param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main ( )
{
    // definir dado
    int x = 0; // definir variavel com valor inicial

    // identificar
    IO_id ( "Exemplo0214 - Programa - v0.0" );

    // ler do teclado
    x = IO_readint ( "Entrar com um inteiro: ");

    // testar valor
    if ( 15 <= x && x <= 45)
    {
        IO_println ("Valor pertence ao intervalo [15:45]");
    } 
    else
    {
        IO_println ("Valor nao pertence ao intervalo [15:45]");
    }

    // encerrar
    IO_pause ( "Apertar ENTER para terminar" );
    return ( 0 );
} // fim main( )
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 0
b.) 5
c.) -5
---------------------------------------------- historico
Versao Data Modificacao
0.1 __/__ esboco
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) identificacao de programa
*/