/*
Exemplo0118 - v0.0. - 29 / 03 / 2022
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
    double comprimento = 0.0;
    double largura = 0.0;
    double altura = 0.0;
    double volume = 0.0;

    //identificar
    printf ("Exemplo0118\n");
    printf ("Author: Bernardo Marques Fernandes - 774119\n");
    printf ("\n");

    //acoes
    printf ("Insira o valor do comprimento de um paralelepipedo: ");
    scanf ("%lf", &comprimento);
    printf ("Insira o valor da largura de um paralelepipedo: ");
    scanf ("%lf", &largura);
    printf ("Insira o valor da altura de um paralelepipedo: ");
    scanf ("%lf", &altura);
    getchar ();

    volume = ((6*comprimento)*(6*largura)*(6*altura));

    printf ("\nO volume do paralelepipedo com seis vezes o as medidas e' = %lf\n", volume);

    //encerrar
    printf ("\nAperte ENTER para terminar.\n");
    getchar ();
    return (0);
}