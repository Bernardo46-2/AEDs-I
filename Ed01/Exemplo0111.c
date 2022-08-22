/*
Exemplo0111 - v0.0. - 29 / 03 / 2022
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
    double y = 0.0;

    //identificar
    printf ("Exemplo0111\n");
    printf ("Author: Bernardo Marques Fernandes - 774119\n");
    printf ("\n");

    //acoes
    printf ("Insira o valor do lado de um quadrado: ");
    scanf ("%i", &x);
    getchar ();

    y = (1.0*(x*x)/4);

    printf ("\nO quarto da area do quadrado e' = %lf\n", y);

    //encerrar
    printf ("\nAperte ENTER para terminar.\n");
    getchar ();
    return (0);
}