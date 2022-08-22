/*
Exemplo01E2 - v0.0. - 29 / 03 / 2022
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
    double raio = 0.0;
    double volume = 0.0;
    double volume2 = 0.0;
    double area = 0.0;

    //identificar
    printf ("Exemplo01E2\n");
    printf ("Author: Bernardo Marques Fernandes - 774119\n");
    printf ("\n");

    //acoes
    printf ("Insira o valor do volume de uma esfera: ");
    scanf ("%lf", &volume);
    getchar ();

    volume2 = volume/2;
    raio = cbrt((volume2/M_PI)*(3.0/4.0));
    area = 4*(M_PI*pow(raio, 2));

    printf ("\nO raio da metade do volume e' = %lf\n", raio);
    printf ("A area da superficie e' = %lf\n", area);

    //encerrar
    printf ("\nAperte ENTER para terminar.\n");
    getchar ();
    return (0);
}