/*
Exemplo0113 - v0.0. - 29 / 03 / 2022
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
    int z = 0;

    //identificar
    printf ("Exemplo0113\n");
    printf ("Author: Bernardo Marques Fernandes - 774119\n");
    printf ("\n");

    //acoes
    printf ("Insira o valor de um lado de um retangulo: ");
    scanf ("%i", &x);
    printf ("Insira o valor do outro lado do retangulo: ");
    scanf ("%i", &y);
    getchar ();

    z = ((x*y)/3);

    printf ("\nO terco da area do retangulo e' = %d\n", z);

    //encerrar
    printf ("\nAperte ENTER para terminar.\n");
    getchar ();
    return (0);
}