/*
Exemplo0114 - v0.0. - 29 / 03 / 2022
Author: Bernardo Marques Fernandes - 774119
Para compilar em terminal (janela de comandos):
Linux : gcc -o exemplo0101 exemplo0101.c
Windows: gcc -o exemplo0101 exemplo0101.c
Para executar em terminal (janela de comandos):
Linux : ./exemplo0101
Windows: exemplo0101
*/

//dependencias
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    //dados
    int x = 0;
    int y = 0;
    int w = 0;
    int z = 0;

    //identificar
    printf ("Exemplo0114\n");
    printf ("Author: Bernardo Marques Fernandes - 774119\n");
    printf ("\n");

    //acoes
    printf ("Insira o valor do lado de um retangulo: ");
    scanf ("%i", &x);
    printf ("Insira o valor do outro lado do retangulo: ");
    scanf ("%i", &y);
    getchar ();

    w = (2*x)*(2*y);
    z = (2*x)+(2*y)+(2*x)+(2*y);

    printf ("\nA area do quadrado com o dobro do lado e' = %d\n", w);
    printf ("\nO perimetro do quadrado com o dobro do lado e' = %d\n", z);

    //encerrar
    printf ("\nAperte ENTER para terminar.\n");
    getchar ();
    return (0);
}