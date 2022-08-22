/*
Exemplo0217 - v0.0. - 01 / 04 / 2022
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
    int y = 0;

    // identificar
    IO_id ( "Exemplo0217 - Programa - v0.0" );

    // ler do teclado
    x = IO_readint ( "Entrar com x: ");
    y = IO_readint ( "Entrar com y: ");
    IO_printf ("\n");

    // testar valor
    if (x == 0)
    {
        IO_println ("(x) e' um valor nulo");
    }
    else
    {
       if (x % 2 == 0) 
        {
            IO_printf ("(x) e' par");
        }
        else if (x % 2 != 0) 
        {
            IO_printf ("(x) e' impar");
        }
        if (x > 0)
        {
            IO_println (" e positivo");
        }
        else if (x < 0)
        {
            IO_println (" e negativo");
        }
    }

    if (y == 0)
    {
        IO_println ("(y) e' um valor nulo");
    }
    else
    {
       if (y % 2 == 0) 
        {
            IO_printf ("(y) e' par");
        }
        else if (y % 2 != 0) 
        {
            IO_printf ("(y) e' impar");
        }
        if (y > 0)
        {
            IO_println (" e positivo");
        }
        else if (y < 0)
        {
            IO_println (" e negativo");
        }
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