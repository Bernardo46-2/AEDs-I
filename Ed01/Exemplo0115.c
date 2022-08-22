/*
Exemplo0115 - v0.0. - 29 / 03 / 2022
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
    double x = 0;
    double y = 0;
    double z = 0.0;

    //identificar
    printf ("Exemplo0115\n");
    printf ("Author: Bernardo Marques Fernandes - 774119\n");
    printf ("\n");

    //acoes
    printf ("Insira o valor da base de um triangulo: ");
    scanf ("%lf", &x);
    printf ("Insira o valor da altura de um triangulo: ");
    scanf ("%lf", &y);
    getchar ();

    z = ((x*(y/5))/2);

    printf ("\nA area do triangulo com um quinto da altura e' = %lf\n", z);

    //encerrar
    printf ("\nAperte ENTER para terminar.\n");
    getchar ();
    return (0);
}