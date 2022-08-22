/*
Exemplo0104 - v0.0. - 29 / 03 / 2022
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
                    //Nota: em alguns compiladores pode haver
                    //problemas quanto ao uso dessa biblioteca,
                    //caso acontecer, considerar uso de definicoes alternativas

/*
Funcao principal.
@return codigo de encerramento
@param argc - quantidade de parametros na linha de comandos
@param argv - arranjo com o grupo de parametros na linha de comandos
*/

int main ( int argc, char* argv [ ] )
{
    // definir dado
    bool x = false; //definir variavel com valor inicial. OBS.: indispensavel usar minusculas
    int y = 0; //definir variavel auxiliar
    
    // identificar
    printf ( "%s\n", "Exemplo0104 - Programa = v0.0" );
    printf ( "%s\n", "Autor: Bernardo Marques Fernandes" );
    printf ( "\n" ); // mudar de linha
    
    // mostrar valor inicial
    printf ( "%s%d\n", "x = ", x );
    // OBS.: O formato para equivalente inteiro -> %d
    
    // ler do teclado
    printf ( "Entrar com um valor inteiro: " );
    scanf ( "%d", &y ); //usar equivalente inteiro -> 0 = false
    
    getchar ( ); // OBS.: Limpar a entrada de dados

    //garantir valor logico no intervalo [0:1]
    x = (y!=0);
    
    // mostrar valor lido
    printf ( "%s%d\n", "x = ", x );
    
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
*/