//Ed05 - v1.0 - 22/04/2022
//Author: Bernardo Marques Fernandes - 774119

#include "io.h"

void method01()
{
    IO_id ("Ed05 - Exemplo0511 - v1.0");
    //dados
    int n=0;
    int x=0;

    //acoes
    printf ("\nInsira um valor: ");
    scanf ("%d", &n);
    getchar();
    printf("\n");

    for (int controle=0; controle<n; controle++)
    {
        x=x+7;
        printf("%d\n", x);
    }

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}

void method02()
{
    IO_id ("Ed05 - Exemplo0512 - v1.0");
    //dados
    int n=0;
    int x=0;

    //acoes
    printf ("\nInsira um valor: ");
    scanf ("%d", &n);
    getchar();
    printf("\n");

    for (int controle=0; controle<n; controle++)
    {
        x=x+7;
        if (x%2==0)
        {
            printf("%d\n", x);
        }
        else
        {
            controle--;
        }
    }

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}

void multiplosImparesDecrescente(int quantidade, int multiplo)
{
    int x=0;
    int numeros[quantidade];

    for (int controle=0; controle<quantidade; controle++)
    {
        x=x+multiplo;
        if (x%2==0)
        {
            controle--;
        }
        else
        {
            numeros[controle]=x;
        }
    }

    printf ("\n%d multiplos de %d em ordem decrescente: \n", quantidade, multiplo);

    for (int controle=quantidade-1; controle>=0; controle--)
    {
        printf ("%d\n", numeros[controle]);
    }
}

void method03()
{
    IO_id ("Ed05 - Exemplo0513 - v1.0");

    int n=0;

    printf ("Insira uma quantidade: ");
    scanf ("%d", &n);
    getchar();

    multiplosImparesDecrescente(n, 7);

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}

void multiplosDenominadoresCrescente (int quantidade, int multiplo)
{
    int x=0;

    printf ("\n%d multiplos de %d em ordem crescente nos denominadores: \n", quantidade, multiplo);

    for (int controle=0; controle<quantidade; controle++)
    {
        x=x+multiplo;
        printf ("%d/%d\n", 1, x);
    }
}

void method04()
{
    IO_id ("Ed05 - Exemplo0514 - v1.0");

    int n=0;

    printf ("Insira uma quantidade: ");
    scanf ("%d", &n);
    getchar();

    multiplosDenominadoresCrescente(n, 7);

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}

void potenciaDenominador(int n, int x)
{
    int expoente=1;
    int potencia=0;

    printf ("\n%d\n", 1);
    //printf ("%d/%d\n", 1.0, x);

    for (int controle=0; controle<n; controle++)
    {
        potencia=pow(x, expoente);
        printf ("%d/%d\n", 1, potencia);
        expoente++;
    }
}

void method05()
{
    IO_id ("Ed05 - Exemplo0515 - v1.0");

    int n=0;
    int x=0;

    printf ("Insira uma quantidade: ");
    scanf ("%d", &n);
    getchar();
    printf ("Insira um valor para x: ");
    scanf ("%d", &x);
    getchar();

    potenciaDenominador(n, x);

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}

void somarValoresImparesNaoMultiplos3(int n, int inicio)
{
    int numero=inicio;
    int total=0;

    printf ("\n");

    for (int controle=0; controle<n; controle++)
    {
        if (numero%3==0)
        {
            controle--;
        }
        else if (controle==n-1)
        {
            total=total+numero;
            printf("%d = %d\n", numero, total);
        }
        else
        {
            printf ("%d + ", numero);
            total=total+numero;
        }
        numero=numero+2;
    }
}

void method06()
{
    IO_id ("Ed05 - Exemplo0516 - v1.0");

    int n=0;

    printf ("Insira uma quantidade: ");
    scanf ("%d", &n);
    getchar();

    if (n<=0)
    {
        printf ("\nValor Invalido\n");
    }
    else if (n==1)
    {
        printf ("\n%d = %d\n", 7, 7);
    }
    else if (n>10000)
    {
        printf ("\nValor muito grande\n");
    }
    else
    {
        somarValoresImparesNaoMultiplos3(n, 7);
    }

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}

double somarValoresInversosImparesNaoMultiplos3(int n, double inicio)
{
    double denominador=inicio;
    double fracao=(1.0/denominador);
    double soma=0;

    for (int controle=0; controle<n; controle++)
    {
        denominador=denominador+2;
        if (fmod(denominador, 3)==0)
        {
            controle--;
        }
        else
        {
            soma=soma+fracao;
            fracao=1.0/denominador;
        }
    }
    return(soma);
}

void method07()
{
    IO_id ("Ed05 - Exemplo0517 - v1.0");

    int n=0;

    printf ("Insira uma quantidade: ");
    scanf ("%d", &n);
    getchar();

    if (n<=0)
    {
        printf ("\nValor Invalido\n");
    }
    else if (n==1)
    {
        printf ("\n1/%d = 1/%d\n", 7, 7);
    }
    else if (n>10000)
    {
        printf ("\nValor muito grande\n");
    }
    else
    {
        printf ("\n");
        double numero=7.0;
        for (int controle=0; controle<n; controle++)
        {
            if (fmod(numero, 3)==0)
            {
                controle--;
            }
            else if (controle==n-1)
            {
                printf("1/%lf = %lf\n", numero, somarValoresInversosImparesNaoMultiplos3(n, 7.0));
            }
            else
            {
                printf ("1/%lf + ", numero);
            }
            numero=numero+2;
        }
    }

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}

int somarValoresInteiros (int quantidade, int inicio)
{
    int soma=0;
    int x=inicio;
    if (quantidade!=1)
    {
        for (int controle=0; controle<quantidade; controle++)
        {
            soma=soma+x;
            x++;
        }
    }
    return (soma);
}

void method08()
{
    IO_id ("Ed05 - Exemplo0518 - v1.0");

    int n=0;

    printf ("Insira uma quantidade: ");
    scanf("%d", &n);
    getchar();

    if (n<=0)
    {
        printf ("\nValor Invalido\n");
    }
    else if (n==1)
    {
        printf ("\n%d = %d\n", 7, 7);
    }
    else if (n>10000)
    {
        printf ("\nValor muito grande\n");
    }
    else
    {
        printf ("\n");

        int numero=7;
        for (int controle=0; controle<n; controle++)
        {
            if (controle==n-1)
            {
                printf ("%d = %d", numero, somarValoresInteiros(n, 7));
            }
            else
            {
                printf ("%d + ", numero);
            }
            numero++;
        }
        printf ("\n");
    }

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}

int somarValoresQuadrados (int quantidade, int inicio)
{
    int soma=0;
    int x=inicio;
    int quadrado=0;
    if (quantidade!=1)
    {
        for (int controle=0; controle<quantidade; controle++)
        {
            soma=soma+(x*x);
            x++;
        }
    }
    return (soma);
}

void method09()
{
    IO_id ("Ed05 - Exemplo0519 - v1.0");

    int n=0;

    printf ("Insira uma quantidade: ");
    scanf("%d", &n);
    getchar();

    if (n<=0)
    {
        printf ("\nValor Invalido\n");
    }
    else if (n==1)
    {
        printf ("\n%d = %d\n", 7, 7);
    }
    else if (n>10000)
    {
        printf ("\nValor muito grande\n");
    }
    else
    {        
        printf ("\n");

        int numero=7;
        for (int controle=0; controle<n; controle++)
        {
            if (controle==n-1)
            {
                printf ("%d = %d", numero*numero, somarValoresQuadrados(n, 7));
            }
            else
            {
                printf ("%d + ", numero*numero);
            }
            numero++;
        }
        printf ("\n");
    }

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}

double somarValoresInversos (int quantidade, double inicio)
{
    double soma=0;
    double denominador=inicio;
    double fracao=(1.0/denominador);

    for (int controle=0; controle<quantidade; controle++)
    {
        soma=soma+fracao;
        denominador++;
        fracao=(1.0/denominador);
    }
    return(soma);
}

void method10()
{
    IO_id ("Ed05 - Exemplo0520 - v1.0");

    int n=0;

    printf ("Insira uma quantidade: ");
    scanf ("%d", &n);
    getchar();

    if (n<=0)
    {
        printf ("\nValor Invalido\n");
    }
    else if (n==1)
    {
        printf ("\n1/%d = 1/%d\n", 7, 7);
    }
    else if (n>10000)
    {
        printf ("\nValor muito grande\n");
    }
    else
    {
        int numero=7;
        printf ("\n");
        for (int controle=0; controle<n; controle++)
        {
            if (controle==n-1)
            {
                printf ("1/%d = %lf", numero, somarValoresInversos(n, 7.0));
            }
            else
            {
                printf ("1/%d + ", numero);
            }
            numero++;
        }
        printf ("\n");
    }
    
    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}

int fatorial (int n)
{
    int x=n;
    int resultado=n;
    if (n==0)
    {
        resultado=1;
    }
    else
    {
        for (int controle=0; controle<n-1; controle++)
        {
            x--;
            resultado=resultado*x;
        }
    }
    return(resultado);
}

void methodE1()
{
    IO_id ("Ed05 - Exemplo05E1 - v1.0");

    int n=0;

    printf ("Insira um valor inteiro positivo: ");
    scanf ("%d", &n);
    getchar();

    if (n<0)
    {
        printf ("\nValor Invalido\n");
    }
    else
    {
        printf ("\n%d! = %d\n", n, fatorial(n));
    }

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}

double funcaoExemploE2 (int n)
{
    double resultado=1.0;
    double numerador=2.0;
    double denominador=3.0;

    for (int controle=0; controle<n; controle++)
    {
        resultado=resultado*(1.0+(numerador/fatorial(denominador)));
        numerador++;
        denominador++;
    }
    return (resultado);
}

void methodE2()
{
    IO_id ("Ed05 - Exemplo05E2 - v1.0");

    int n=0;

    printf ("Insira um valor: ");
    scanf ("%d", &n);
    getchar();
    printf ("\n");

    int numerador=2;
    int denominador=3;

    for (int controle=0; controle<n; controle++)
    {
        if (controle==n-1)
        {
            printf ("(1 + %d/%d!) = %lf\n", numerador, denominador, funcaoExemploE2(n));
        }
        else
        {
            printf ("(1 + %d/%d!) + ", numerador, denominador);
        }
        numerador++;
        denominador++;
    }

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}

int main()
{
    IO_id ("Ed05 - v1.0");

    int x=0;

    do
    {
        printf ("\nEscolha uma opcao: \n");
        printf ("0 - parar\n");
        printf ("1 - method01\n");
        printf ("2 - method02\n");
        printf ("3 - method03\n");
        printf ("4 - method04\n");
        printf ("5 - method05\n");
        printf ("6 - method06\n");
        printf ("7 - method07\n");
        printf ("8 - method08\n");
        printf ("9 - method09\n");
        printf ("10 - method10\n");
        printf ("11 - method11\n");
        printf ("12 - method12\n");

        printf ("\nEscolha: ");
        scanf ("%d", &x);
        getchar();

        switch (x)
        {
            case 0:
            break;
            case 1:
            method01();
            break;
            case 2:
            method02();
            break;
            case 3:
            method03();
            break;
            case 4:
            method04();
            break;
            case 5:
            method05();
            break;
            case 6:
            method06();
            break;
            case 7:
            method07();
            break;
            case 8:
            method08();
            break;
            case 9:
            method09();
            break;
            case 10:
            method10();
            break;
            case 11:
            methodE1();
            break;
            case 12:
            methodE2();
            break;
            default:
            printf ("Valor invalido");
            break;
        }
    }while (x!=0);

    IO_pause ("Aperte ENTER para terminar");
    return 0;
}