/*
Exemplo0120 - v0.0. - 29 / 03 / 2022
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
    double raio = 0;
    double volume = 0;

    //identificar
    printf ("Exemplo0120\n");
    printf ("Author: Bernardo Marques Fernandes - 774119\n");
    printf ("\n");

    //acoes
    printf ("Insira o valor do raio de uma esfera: ");
    scanf ("%lf", &raio);
    getchar ();

    volume = ((4/3)*(M_PI)*(pow((raio*3/8),3)));

    printf ("\nO volume da esfera com tres oitavos do raio e' = %lf\n", volume);

    //encerrar
    printf ("\nAperte ENTER para terminar.\n");
    getchar ();
    return (0);
}