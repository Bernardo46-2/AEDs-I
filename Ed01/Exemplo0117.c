/*
Exemplo0117 - v0.0. - 29 / 03 / 2022
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
#include <math.h>

int main ()
{
    //dados
    double lado = 0.0;
    double sexto = 0.0;
    double volume = 0.0;

    //identificar
    printf ("Exemplo0117\n");
    printf ("Author: Bernardo Marques Fernandes - 774119\n");
    printf ("\n");

    //acoes
    printf ("Insira o valor do lado de um cubo: ");
    scanf ("%lf", &lado);
    getchar ();

    sexto = (lado/6);
    volume = (pow(sexto,3));

    printf ("\nO volume do cubo com um sexto do lado e' = %lf\n", volume);

    //encerrar
    printf ("\nAperte ENTER para terminar.\n");
    getchar ();
    return (0);
}