/*
Exemplo0212 - v0.0. - 01 / 04 / 2022
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
    IO_id ( "Exemplo0212 - Programa - v0.0" );

    // ler do teclado
    x = IO_readint ( "Entrar com um inteiro: ");

    // testar valor
    if ((x % 2 == 0) && (x > -30))
    {
        IO_println ("Numero par e maior que -30");
    } 
    else if ((x % 2 != 0) && (x < 30))
    {
        IO_println ("Numero impar e menor que trinta");
    } 
    else if ((x % 2 == 0) && (x < -30))
    {
        IO_println ("Numero par e menor que -30");
    }
    else if ((x % 2 != 0) && (x > 30))
    {
        IO_println ("Numero impar e maior que trinta");
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