/*
Exemplo0108 - v0.0. - 29 / 03 / 2022
Author: Bernardo Marques Fernandes - 774119
Para compilar em terminal (janela de comandos):
Linux : gcc -o exemplo0101 exemplo0101.c
Windows: gcc -o exemplo0101 exemplo0101.c
Para executar em terminal (janela de comandos):
Linux : ./exemplo0101
Windows: exemplo0101
*/

// dependencias
#include <stdio.h> // para as entradas e saidas
#include <stdbool.h> //para valores logicos
#include <string.h> //para cadeias de caracteres: strcat(), strcpy(), strdup(), strlen()...
#include <math.h> //para funcoes matematicas: pow(), sqrt(), sin(), cos()...

/*
Funcao principal.
@return codigo de encerramento
@param argc - quantidade de parametros na linha de comandos
@param argv - arranjo com o grupo de parametros na linha de comandos
*/

int main ( int argc, char* argv [ ] )
{
    // definir dado
    char x[80] = "abc";
    char y[80] = "def";
    char z[80];
    strcpy (z, "");
    
    // identificar
    printf ( "%s\n", "Exemplo0108 - Programa = v0.0" );
    printf ( "%s\n", "Autor: Bernardo Marques Fernandes" );
    printf ( "\n" ); // mudar de linha
    
    // mostrar valores iniciais e comprimento de cadeias
    printf ( "%s%s (%d)\n", "x = ", x, strlen(x));
    printf ( "%s%s (%d)\n", "y = ", y, strlen(y));
    
    // ler do teclado
    printf ( "Entrar com caracteres: " );
    scanf ( "%s", x ); //OBS.: NAO indicar o endereco -> &
    getchar ( ); // OBS.: Limpar a entrada de dados
    printf ( "Entrar com outros caracteres: " );
    scanf ( "%s", y ); //OBS.: NAO indicar o endereco -> &
    getchar ( ); // OBS.: Limpar a entrada de dados

    //operar valores
    strcpy (z, x); //copiar (x) para (z)
    strcat (z, y); //concatenar (juntar) (z) a (y). OBS.: forma mais eficiente
    
    // mostrar valor resultante
    printf ( "%s[%s]*[%s] = [%s]\n", "z = ", x, y, z );

    //operar valores (forma alternativa)
    strcpy (z, strcat (strdup(x), y)); //copiar para (z) o resultado de concatenar a copia de (x) com (y). OBS.: se nao duplicar, o valor de (x) sera alterado

    //mostrar valor resultande
    printf ("%s[%s]*[%s] = [%s]\n", "z = ", x, y, z);
    
    // encerrar
    printf ( "\n\nApertar ENTER para terminar." );
    getchar( ); // aguardar por ENTER
    return ( 0 ); // voltar ao SO (sem erros)
} // fim main( )

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 5
b.) -5
c.) 123456789
---------------------------------------------- historico
Versao Data Modificacao
0.1 29/03 esboco
0.2 29/03 mudanca de versao
---------------------------------------------- testes
Versao Teste
0.1 01. (ok) leitura e exibicao de inteiro
0.2 01. (ok) leitura e exibicao de real
0.3 01. (ok) leitura e exibicao de letra
0.4 01. (ok) leitura e exibicao de valores logicos
0.5 01. (ok) leitura e exibicao de cadeias de caracteres
0.6 01. (ok) leitura e exibicao de produto
0.7 01. (ok) leitura e exibicao de exponentes
0.8 01. (ok) leitura e exibicao de operacoes com caracteres
*/