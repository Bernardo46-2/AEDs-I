/*
Exemplo0219 - v0.0. - 01 / 04 / 2022
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
    double x = 0; // definir variavel com valor inicial
    double y = 0;
    double z = 0;

    // identificar
    IO_id ( "Exemplo0219 - Programa - v0.0" );

    // ler do teclado
    x = IO_readdouble ( "Entrar com x: ");
    y = IO_readdouble ( "Entrar com y: ");
    z = IO_readdouble ( "Entrar com z: ");
    IO_printf ("\n");

    // testar valor
    if (x == y)
    {
        IO_printf ("%lf e' igual a %lf", x, y);
    }
    else if (x != y)
    {
        if (y > x)
        {
            if ((x < z) && (z < y))
            {
                IO_printf ("%lf esta' entre %lf e %lf", z, x, y);
            }
            else
            {
                IO_printf ("%lf nao esta' entre %lf e %lf", z, x, y);
            }
        }
        else if (y < x)
        {
            if ((y < z) && (z < x ))
            {
                IO_printf ("%lf esta' entre %lf e %lf", z, y, x);
            }
            else
            {
                IO_printf ("%lf nao esta' entre %lf e %lf", z, y, x);
            }
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