/*
Exemplo02E2 - v0.0. - 01 / 04 / 2022
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
    char x = '0'; // definir variavel com valor inicial
    char y = '0';
    char z = '0';

    // identificar
    IO_id ( "Exemplo02E2 - Programa - v0.0" );

    // ler do teclado
    z = IO_readchar ( "Entrar com um caractere x: ");
    x = IO_readchar ( "Entrar com um caractere y: ");
    y = IO_readchar ( "Entrar com um caractere z: ");
    IO_printf ("\n");

    // testar valor
    if ((x == y) || (y == z) || (z == x))
    {
        if (x == y)
        {
            IO_printf ("(y) e' igual a (z)");
        }
        else if (y == z)
        {
            IO_printf ("(z) e' igual a (x)");
        }
        else if (z == x)
        {
            IO_printf ("(x) e' igual a (y)");
        }
    }
    else 
    {
        if (y > x)
        {
            if ((x < z) && (z < y))
            {
                IO_printf ("%c esta' entre %c e %c", z, x, y);
            }
            else
            {
                IO_printf ("%c nao esta' entre %c e %c", z, x, y);
            }
        }
        else if (y < x)
        {
            if ((y < z) && (z < x ))
            {
                IO_printf ("%c esta' entre %c e %c", z, y, x);
            }
            else
            {
                IO_printf ("%c nao esta' entre %c e %c", z, y, x);
            }
        }
    }

    // encerrar
    printf ("\n");
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