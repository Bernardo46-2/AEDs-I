// Bernardo Marques Fernandes - 774119
// Ed06

#include "io.h"

void Exemplo0611a(int n, int inicio){
    if (n>0){
        printf ("%d\n", inicio);
        Exemplo0611a (n-1, inicio+2);
    }
}

void Exemplo0611(){
    printf ("\nExemplo0611\n\n");
    
    int n=0;

    printf ("Insira uma quantidade: ");
    scanf ("%d", &n);
    getchar();

    printf ("\n");
    Exemplo0611a(n, 7);

    IO_pause ("Aperte ENTER para continuar");
}

void Exemplo0612a(int n, int inicio){
    if (n>0){
        printf ("%d\n", inicio);
        Exemplo0612a(n-1, inicio-7);
    }
}

void Exemplo0612(){
    printf ("\nExemplo0612\n\n");

    int n=0;

    printf ("Insira uma quantidade: ");
    scanf ("%d", &n);
    getchar();

    printf ("\n");
    Exemplo0612a(n, 7*n);

    IO_pause ("Aperte ENTER para continuar");
}

void Exemplo0613a(int n, int inicio){
    if (n>0 && inicio==1){
        printf ("%d\n", inicio);
        Exemplo0613a(n-1, inicio+6);        
    }else if (n>0){
        printf ("%d\n", inicio);
        Exemplo0613a(n-1, inicio+7);
    }
}

void Exemplo0613(){
    printf ("\nExemplo0613\n\n");

    int n=0;

    printf ("Insira uma quantidade: ");
    scanf ("%d", &n);
    getchar();

    printf ("\n");
    Exemplo0613a(n, 1);

    IO_pause ("Aperte ENTER para continuar");
}

void Exemplo0614a (int x){
    if(x>=0){
        printf ("1/%d\n", (int)pow(7, x));
        Exemplo0614a(x-1);
    }
}

void Exemplo0614(){
    printf ("\nExemplo0614\n\n");

    int n=0;

    printf ("Insira uma quantidade: ");
    scanf ("%d", &n);
    getchar();

    printf ("\n");
    Exemplo0614a(n-1);

    IO_pause ("Aperte ENTER para continuar");
}

void Exemplo0615a(chars palavra, int x){
    if (x<strlen(palavra)){
        printf ("%c\n", palavra[x]);
        Exemplo0615a(palavra, x+1);
    }
}

void Exemplo0615(){
    printf ("\nExemplo0615\n\n");

    char palavra[80];

    printf ("Insira uma palavra: ");
    scanf ("%s", palavra);
    getchar();

    printf ("\n");
    Exemplo0615a(palavra, 0);

    IO_pause ("Aperte ENTER para continuar");
}

int Exemplo0616b(int x, int inicio, int resultado){
    if (x>0){
        resultado=resultado+Exemplo0616b(x-1, inicio+2, inicio);
    }
    return(resultado);
}

void Exemplo0616a(int x, int inicio){
    if (x>1){
        printf ("%d + ", inicio);
        Exemplo0616a(x-1, inicio+2);
    }else if(x==1)
    {
        printf ("%d = ", inicio);
    }
}

void Exemplo0616(){
    printf ("\nExemplo0617\n\n");

    int n=0;

    printf ("Insira uma quantidade: ");
    scanf ("%d", &n);
    getchar();

    printf ("\n");
    Exemplo0616a(n, 7);
    printf ("%d", Exemplo0616b(n, 7, 0));

    IO_pause ("Aperte ENTER para continuar");
}

double Exemplo0617b (int x, int inicio, double resultado){
    /* por algum motivo isso nao funciona
    if (x>0){
        resultado=resultado+(1.0/(1.0*inicio));
        Exemplo0617b(x-1, inicio+2, resultado);
    }*/
    if (x>0){
        resultado=resultado+Exemplo0617b(x-1, inicio+2, 1.0/(1.0*inicio));
    }
    return(resultado);
}

void Exemplo0617a(int x, int inicio){
    if(x>1){
        printf ("1/%d + ", inicio);
        Exemplo0617a(x-1, inicio+2);
    }else if(x==1){
        printf ("1/%d = ", inicio);
        Exemplo0617a(x-1, inicio+2);
    }
}

void Exemplo0617(){
    printf ("\nExemplo0616\n\n");

    int n=0;

    printf ("Insira uma quantidade: ");
    scanf ("%d", &n);
    getchar();

    printf ("\n");
    Exemplo0617a(n, 7);
    printf ("%lf\n", Exemplo0617b(n, 7, 0.0)); //resultado esperado = 0.4884670885 (se n==5)

    IO_pause ("Aperte ENTER para continuar");
}

int fibonacci(int x){
    int resposta=0;
    
    if (x==1 || x==2)
        resposta=1;
    else if (x>1)
        resposta=fibonacci(x-1)+fibonacci(x-2);
    return(resposta);
}

//imprimir e somar numeros pares de fibonacci
void Exemplo0618a(int x, int y, int soma){
    if (x>0){
        if (fibonacci(y)%2==0){
            soma+=fibonacci(y);
            if (x==1)
                printf("%d = %d", fibonacci(y), soma);
            else
                printf("%d + ", fibonacci(y));
            x--;
        }
        Exemplo0618a(x, y+1, soma);
    }
}

void Exemplo0618(){
    printf ("\nExemplo0618\n\n");

    int n=0;

    printf ("Insira um valor: ");
    scanf ("%d", &n);
    getchar();

    printf ("\n");
    Exemplo0618a(n, 1, 0);
    printf ("\n");

    IO_pause ("Aperte ENTER para continuar");
}

int Exemplo0619a(chars palavra, int x){
    int contador=0;

    if (x<strlen(palavra)){
        if ('0'<=palavra[x] && palavra[x]<='9'){
            if ((int)palavra[x]%2==0)
                contador=1;
        }
        contador=contador+Exemplo0619a(palavra, x+1);
    }
    return(contador);
}

void Exemplo0619(){
    printf ("\nExemplo0619\n\n");

    char palavra[80];

    printf ("Insira uma palavra: ");
    scanf ("%s", palavra);
    getchar();

    printf ("\nA palavra escrita possui %d numeros pares.\n", Exemplo0619a(palavra, 0));

    IO_pause ("Aperte ENTER para continuar");
}

int Exemplo0620a(chars palavra, int x){
    int contador=0;
    if (x<strlen(palavra)){
        if ('A'<=palavra[x] && palavra[x]<='Z'){
            contador=1;
        }
        contador=contador+Exemplo0620a(palavra, x+1);
    }
    return(contador);
}

void Exemplo0620(){
    printf ("\nExemplo0620\n\n");
    
    char palavra[80];

    printf ("Insira uma palavra: ");
    scanf ("%s", palavra);
    getchar();

    printf ("\nA palavra escrita possui %d letras maiusculas.\n", Exemplo0620a(palavra, 0));


    IO_pause ("Aperte ENTER para continuar");
}

//escrever expressao
void Exemplo06E1b(int x, int n, int expoente){
    if(expoente==0){
        printf ("1 + ");
        Exemplo06E1b(x, n-1, expoente+2);
    }else if(n>1){
        printf ("%d^%d + ", x, expoente);
        Exemplo06E1b(x, n-1, expoente+2);
    }else if(n==1){
        printf ("%d^%d = ", x, expoente);
    }
}

//calcular resultado
int Exemplo06E1a(int x, int n, int expoente){
    int resultado=0;
    if (n>0)
        resultado=pow(x, expoente)+Exemplo06E1a(x, n-1, expoente+2);
    return (resultado);
}

void Exemplo06E1(){
    printf ("\nExemplo06E1\n\n");

    int x=0;
    int n=0;

    printf ("Insira um valor: ");
    scanf ("%d", &x);
    getchar();
    printf ("Insira uma quantidade: ");
    scanf ("%d", &n);
    getchar();

    printf ("\nf(%d, %d) = ", x, n);
    Exemplo06E1b(x, n, 0);
    printf ("%d\n", Exemplo06E1a(x, n, 0)); //se x==3, n==3 = 91 //se x==2, n==3 = 21

    IO_pause ("Aperte ENTER para continuar");
}

/* isso foi apenas para treinar

int somatorio(int x){
    int resposta=0;
    if(x>0)
        resposta=x+somatorio(x-1);
    return(resposta);
} */

int fatorial (int x){
    int resposta=0;
    if(x==0 || x==1)
        resposta=1;
    else if(x>1)
        resposta=x*fatorial(x-1);
    return(resposta);
}

//escrever expressao
void Exemplo06E2a(int n, int numerador, int denominador){
    if(n>0){
        if(numerador==1 && denominador==1 && n==1){
            printf ("1 = ");
        }
        else if(numerador==1 && denominador==1){
            printf ("1 + ");
            Exemplo06E2a(n-1, numerador, denominador+1);
        }
        else if(numerador==1 && denominador==2 && n==1){
            printf ("1/2! = ");
        }
        else if(numerador==1 && denominador==2){
            printf ("1/2! + ");
            Exemplo06E2a(n-1, numerador+1, denominador+1);
        }
        else if(numerador==2, denominador==3 && n==1){
            printf ("2/3! = ");
        }
        else if(numerador==2, denominador==3){
            printf ("2/3! + ");
            Exemplo06E2a(n-1, numerador+2, denominador+2);
        }
        else if(n==1){
            printf ("%d/%d! = ", numerador, denominador);
        }
        else{
            printf ("%d/%d! + ", numerador, denominador);
            Exemplo06E2a(n-1, numerador+2, denominador+2);
        }
    }
}

//calcular resultado
double Exemplo06E2b(int n, int numerador, int denominador){
    double resposta=0.0;
    double fracao=((1.0*numerador)/(1.0*fatorial(denominador)));

    if(n>0){
        if(fracao==1.0){
            resposta=1.0+Exemplo06E2b(n-1, numerador, denominador+1);
        }
        else if(fracao==0.5){
            resposta=fracao+Exemplo06E2b(n-1, numerador+1, denominador+1);
        }
        else{
            resposta=fracao+Exemplo06E2b(n-1, numerador+2, denominador+2);
        }
    }
    return(resposta);
}

void Exemplo06E2(){
    printf ("\nExemplo06E2\n\n");

    int n=0;

    printf ("Insira um numero: ");
    scanf ("%d", &n);
    getchar();

    printf ("\n");
    Exemplo06E2a(n, 1, 1);
    printf ("%lf\n", Exemplo06E2b(n, 1, 1));

    IO_pause ("Aperte ENTER para continuar");
}

int main(){
    int opcao=0;
    do{
        IO_id ("Ed06 - v1.0");
        
        printf ("Opcoes:\n");
        printf ("0 - parar\n");
        printf ("1 - Exemplo0611\n");
        printf ("2 - Exemplo0612\n");
        printf ("3 - Exemplo0613\n");
        printf ("4 - Exemplo0614\n");
        printf ("5 - Exemplo0615\n");
        printf ("6 - Exemplo0616\n");
        printf ("7 - Exemplo0617\n");
        printf ("8 - Exemplo0618\n");
        printf ("9 - Exemplo0619\n");
        printf ("10 - Exemplo0620\n");
        printf ("11 - Exemplo06E1\n");
        printf ("12 - Exemplo06E2\n");
        printf ("\nEscolha uma opcao: ");
        scanf ("%d", &opcao);
        getchar();

        switch(opcao){
            case 0:
            break;
            case 1:
            Exemplo0611();
            break;
            case 2:
            Exemplo0612();
            break;
            case 3:
            Exemplo0613();
            break;
            case 4:
            Exemplo0614();
            break;
            case 5:
            Exemplo0615();
            break;
            case 6:
            Exemplo0616();
            break;
            case 7:
            Exemplo0617();
            break;
            case 8:
            Exemplo0618();
            break;
            case 9:
            Exemplo0619();
            break;
            case 10:
            Exemplo0620();
            break;
            case 11:
            Exemplo06E1();
            break;
            case 12:
            Exemplo06E2();
            break;
            default:
            printf ("\nValor invalido\n");
            printf ("\nAperte ENTER para continuar\n");
            getchar();
        }
    }while (opcao!=0);

    printf ("\nAperte ENTER para terminar");
    getchar();
    return 0;
}