/*
Exemplo01E1 - v0.0. - 29 / 03 / 2022
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
    double area = 0;
    double dobro = 0;

    //identificar
    printf ("Exemplo01E1\n");
    printf ("Author: Bernardo Marques Fernandes - 774119\n");
    printf ("\n");

    //acoes
    printf ("Insira o valor do raio de uma circunferencia: ");
    scanf ("%lf", &raio);
    getchar ();

    area = (4*(M_PI)*(pow(raio, 2)));
    dobro = area*2;

    printf ("\nO dobro da Area da circunferencia e' = %lf\n", dobro);

    //encerrar
    printf ("\nAperte ENTER para terminar.\n");
    getchar ();
    return (0);
}