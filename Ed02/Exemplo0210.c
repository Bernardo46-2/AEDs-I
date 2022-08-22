/*
Exemplo0210 - v0.0. - 01 / 04 / 2022
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

/**
 * Method00 - nao faz nada
*/
void method00 ()
{
}

//method01 - mostrar mensagem com texto constante
void method01 ()
{
    IO_println ("Valor igual a um");
}

//method02 - mostrar mensagem com texto constante e valor variavel
void method02 (int x)
{
    IO_printf (IO_concat ("Valor igual a (", IO_concat (IO_toString_d(x), ")\n")));
}

//method02 - mostrar mensagem com texto e valor variavel
void method03 (char* text1, int x)
{
    IO_println (IO_concat( IO_concat (text1, "("), IO_concat ( IO_toString_d (x), ")\n")));
}

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
    IO_id ( "Exemplo0210 - Programa - v0.0" );

    // ler do teclado
    x = IO_readint ( "Entrar com um inteiro: [0,1,2,3]: ");

    // testar valor
    switch (x)
    {
        case 0:
        method00 ();
        break;
        
        case 1:
        method01 ();
        break;

        case 2:
        method02 (x);
        break;

        case 3:
        method03 ("Valor igual a tres", x);

        default:
        IO_printf (IO_concat ("Valor diferente das opcoes [0,1,2,3] (", IO_concat (IO_toString_d (x), ")")));
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