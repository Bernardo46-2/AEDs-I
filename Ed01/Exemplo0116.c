/*
Exemplo0116 - v0.0. - 29 / 03 / 2022
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
    double area = 0.0;
    double perimetro = 0.0;

    //identificar
    printf ("Exemplo0116\n");
    printf ("Author: Bernardo Marques Fernandes - 774119\n");
    printf ("\n");

    //acoes
    printf ("Insira o valor do lado de um triangulo equilatero: ");
    scanf ("%lf", &lado);
    getchar ();

    area = ((pow((lado/2),2)*sqrt(3))/4);
    perimetro = ((lado/2)*3);

    printf ("\nA area do triangulo com metade do lado e' = %lf\n", area);
    printf ("\nO perimetro do triangulo com metade do lado e' = %lf\n", perimetro);

    //encerrar
    printf ("\nAperte ENTER para terminar.\n");
    getchar ();
    return (0);
}