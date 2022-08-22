/*
Exemplo0401 - v1.0. - 15 / 04 / 2022
Author: Bernardo Marques Fernandes 
*/

// dependencias
#include "io.h" // para definicoes proprias

/*
Funcao para determinar se valor inteiro e' positivo
@return true, se positivo; false, caso contrario
@param x - valor a ser testado
*/
bool positive (int x)
{
    //definir dado local
    bool result = false;
    //testar condicao
    if (x>0)
    {
        result = true;
    }
    return (result);
}

/*Funcao para determinar se valor inteiro pertence a intervalo aberto
@return true se pertencer; false caso contrario
@param x - valor a ser testado
*/
bool belongsTo (int x, int inferior, int superior)
{
    //definir dado local
    bool result = false;
    //testar a condicao
    if (inferior < x && x < superior)
    {
        result = true;
    }
    return(result);
}

/*
Funcao para determinar se valor inteiro e' par
@return true, se par; false, caso contrario
*/
bool even (int x)
{
    //definir dado local
    bool result = false;
    //testar condicao (resto inteiro da divisao igual a 0)
    if (x % 2 == 0)
    {
        result = true;
    }
    return (result);
}

/*Funcao para determinar se caractere e' letra minuscula
@return true se minusculo, false caso contrario
@param x - valor a ser testado
*/
bool isLowerCase (char x)
{
    return ('a'<=x && x<='z');
}

/*
Funcao para determinar se caractere e' digito
@return true, se par ; false caso contrario
@param x - valor a ser testado
*/
bool isDigit (char x)
{
    return ('0'<=x && x<='9');
}

/*
Funcao para concatenar 'a cadeia de caracteres mainsum digito
@return cadeia de caracteres acrescida de mais um digito
@param digits - cadeia de caracteres
@param digit - simbolo a ser acrescentado 'a cadeia de caracteres
*/
chars concatADigit (chars string, char digit)
{
    return(IO_concat (string, IO_toString_c(digit)));
}

bool isUpperCaseUntilK (char x)
{
    return ('A'<=x && x<'K');
}

bool isUpperCaseUntilK2 (chars string, int posicao)
{
    return('A'<=string[posicao] && string[posicao]<'K');
}

bool isLetterUntilK (chars string, int posicao)
{
    return (('A'<=string[posicao] && string[posicao]<'K') || ('a'<=string[posicao] && string[posicao]<'k'));
}

bool isDigit2 (chars string, int posicao)
{
    return ('0'<=string[posicao] && string[posicao]<='9');
}

bool isAlphaNumeric (chars string, int posicao)
{
    return ('0'<=string[posicao] && string[posicao]<='9' || 'A'<=string[posicao] && string[posicao]<'Z' || 'a'<=string[posicao] && string[posicao]<'z');
}

chars menorString (chars string1, chars string2)
{
    chars menorString = IO_new_chars(STR_SIZE);
    if (strlen(string1)<strlen(string2))
    {
        strcpy (menorString, string1);
    }
    else
    {
        strcpy (menorString, string2);
    }
    return(menorString);
}

/**
Method00 - nao faz nada.
*/
void method00 ( )
{
    // nao faz nada
} // fim method00 ( )

/**
Method01 - Repeticao para ler certa quantidade de valores.
*/
void method01 ( )
{
    // definir dado
    int quantidade = 0;
    int valor = 0;
    int controle = 0;

    // identificar
    IO_id ( "EXEMPLO0401 - Method01 - v1.0" );
    
    // ler do teclado
    quantidade = IO_readint ( "Entrar com uma quantidade: " );
    
    // repetir para a quantidade de vezes informada
    controle = 1;
    while ( controle <= quantidade )
    {
        // ler valor do teclado
        valor = IO_readint ( IO_concat (IO_concat ( "", IO_toString_d ( controle ) ),": " ) );
        // passar ao proximo valor
        controle = controle + 1;
    } // fim repetir
    
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )

/**
Method02.
*/
void method02 ( )
{
    // identificar
    IO_id ( "EXEMPLO0402 - Method02 - v1.0" );

    //definir dado
    int quantidade = 0;
    int valor = 0;
    int controle = 0;
    int contador = 0;

    //ler do teclado
    quantidade = IO_readint ("Entrar com uma quantidade: ");

    //repetir para a quantidade de vezes informada
    controle = 1;
    while (controle <= quantidade)
    {
        //ler valor do teclado
        valor = IO_readint (IO_concat (IO_concat ("", IO_toString_d (controle)), ":"));
        //ler e contar se valor for positivo
        if (positive (valor))
        {
            contador++;
        }
        //passar para o proximo valor
        controle++;
    }
    //mostrar quantidade de valores positivos
    IO_printf ("%s%d\n", "Positivos = ", contador);

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )

/**
Method03.
*/
void method03 ( )
{
    // identificar
    IO_id ( "EXEMPLO0403 - Method03 - v1.0" );

    //definir dados
    int quantidade = 0;
    int valor = 0;
    int controle = 0;
    int contador = 0;

    //ler do teclado
    quantidade = IO_readint ("Entrar com uma quantidade: ");

    //repetir para a quantidade de vezes informada
    controle = 1;
    while (controle <= quantidade)
    {
        //ler valor do teclado
        valor = IO_readint (IO_concat (IO_concat ("", IO_toString_d (controle)), ":"));
        //testar e contar se o valor for positivo
        if (belongsTo (valor, 0, 100))
        {
            contador = contador +1;
        }
        //passar para o proximo valor
        controle = controle + 1;
    }
    //mostrar quantidade de valores positivos
    IO_printf ("%s%d\n", "Positivos menores que 100 = ", contador);

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )

/**
Method04.
*/
void method04 ( )
{
    // identificar
    IO_id ( "EXEMPLO0404 - Method04 - v1.0" );

    //definir dados
    int quantidade = 0;
    int valor = 0;
    int controle = 0;
    int contador = 0;

    //ler do teclado
    quantidade = IO_readint ("Entrar com uma quantidade: ");

    //repetir para a quantidade de vezes informada
    controle = 1;
    while (controle <= quantidade)
    {
        //ler valor do teclado
        valor = IO_readint (IO_concat (IO_concat ("", IO_toString_d (controle)), ":"));
        //testar e contar se valor for positivo menor que 100 e par
        if (belongsTo(valor, 0, 100) && even (valor))
        {
            contador++;
        }

        //passar ao proximo valor
        controle++;
    }
    //mostrar a quantidade de valores positivos
    IO_printf ("%s%d\n", "Positivos menores que 100 e pares = ", contador);
    
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method04 ( )

/**
Method05.
*/
void method05 ( )
{
    // identificar
    IO_id ( "EXEMPLO0405 - Method05 - v1.0" );

    //definir dados
    int quantidade = 0;
    int valor = 0;
    int controle = 0;
    int contador = 0;
    bool ok = false;

    //ler do teclado
    quantidade = IO_readint ("Entrar com uma quantidade: ");

    //repetir para a quantidade de vezes informada
    controle = 1;
    while (controle <= quantidade)
    {
        //ler valor do teclado
        valor = IO_readint (IO_concat (IO_concat ("", IO_toString_d (controle)), ":"));
        //testar e contar se valor for positivo menor que 100 e par
        ok = belongsTo (valor, 0, 100);
        ok = ok && even(valor);
        if (ok)
        {
            contador++;
        }
        //mostrar a quantidade de valores positivos
        controle++;
    }
    IO_printf ("%s%d\n", "Positivos menores que 100 e pares = ", contador);
    
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )

/**
Method06.
*/
void method06 ( )
{
    // identificar
    IO_id ( "EXEMPLO0406 - Method06 - v1.0" );

    //definir dado
    chars palavra = IO_new_chars (STR_SIZE);
    int tamanho = 0;
    int posicao = 0;
    char simbolo = '_';
    int contador = 0;

    //ler do teclado
    printf("Entre com uma palavra: ");
    scanf("%s", palavra);
    getchar();

    //determinar a quantidade de simbolos na palavra
    tamanho = strlen(palavra);

    //repetir para a quantidade de vezes informada
    for (posicao = 0; posicao < tamanho; posicao++)
    {
        //isolar um simbolo por vez
        simbolo = palavra[posicao];
        //testar e contar se caractere e' letra minuscula
        if (isLowerCase(simbolo))
        {
            contador++;
        }
    }

    //mostrar quantidade de minusculas
    IO_printf ("%s%d\n", "Minusculas = ", contador);

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )

/**
Method07.
*/
void method07 ( )
{
    // identificar
    IO_id ( "EXEMPLO0407 - Method07 - v1.0" );

    //definir dados
    chars palavra = IO_new_chars (STR_SIZE);
    int tamanho = 0;
    int posicao = 0;
    char simbolo = '_';
    int contador = 0;

    //ler do teclado
    printf("Entre com uma palavra: ");
    scanf("%s", palavra);
    getchar();

    //determinar a quantidade de simbolos na palavra
    tamanho = strlen(palavra);

    //repetir para a quantidade de vezes informada
    for (posicao=0; posicao<tamanho; posicao++)
    {
        //isolar um simbolo por vez
        simbolo = palavra[posicao];
        //testar e contar se caractere e' letra minuscula
        if (isLowerCase(simbolo))
        {
            //mostrar
            IO_printf ("%c", simbolo);
            //contar
            contador++;
        }
    }

    //mostrar a quantidade de minusculas
    IO_printf ("\n%s%d\n", "Minusculas = ", contador);

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method07 ( )

/**
Method08.
*/
void method08 ( )
{
    // identificar
    IO_id ( "EXEMPLO0408 - Method08 - v1.0" );

    //definir dados
    chars palavra = IO_new_chars (STR_SIZE);
    int tamanho = 0;
    int posicao = 0;
    char simbolo = '_';
    int contador = 0;
    chars minusculas = IO_new_chars (STR_SIZE);

    strcpy (minusculas, STR_EMPTY); //vazio

    //ler do teclado
    printf("Entre com uma palavra: ");
    scanf("%s", palavra);
    getchar();

    //determinar a quantidade de vezes informada
    tamanho = strlen(palavra);

    //repetir para a quantidade de vezes informada
    for (posicao=0; posicao<tamanho; posicao++)
    {
        //isolar um simbolo por vez
        simbolo = palavra[posicao];
        //testar e contar as letras minusculas de uma palavra
        if (isLowerCase (simbolo))
        {
            //concatenar simbolo encontrado
            minusculas = IO_concat (minusculas, IO_toString_c(simbolo));
            //contar
            contador++;
        }
    }

    //mostrar a quantidade de minusculas
    IO_printf ("\n%s%d[%s]\n", "Minusculas = ", contador, minusculas);

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method08 ( )

/**
Method09.
*/
void method09 ( )
{
    // identificar
    IO_id ( "EXEMPLO0409 - Method09 - v1.0" );

    //definir dados
    chars palavra = IO_new_chars (STR_SIZE);
    int tamanho = 0;
    int posicao = 0;
    char simbolo = '_';
    int contador = 0;

    //determinar a quantidade de simbolos
    printf("Entre com caracteres: ");
    scanf("%s", palavra);
    getchar();

    //determinar a quantidade de vezes informada
    tamanho = strlen(palavra);

    //repetir a quantidade de vezes informada
    for (posicao=0; posicao<tamanho; posicao++)
    {
        //isolar um simbolo por vez
        simbolo = palavra[posicao];
        //testar e contar os algarismos em uma cadeia de caracteres
        if (isDigit(simbolo))
        {
            IO_printf ("%c", simbolo);
            //contar
            contador++;
        }
    }

    //mostrar a quantidade de digitos
    IO_printf ("\n%s%d\n", "Algarismos = ", contador);
    
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method09 ( )

/**
Method10.
*/
void method10 ( )
{
    // identificar
    IO_id ( "EXEMPLO0410 - Method10 - v1.0" );

    //definir dados
    chars palavra = IO_new_chars (STR_SIZE);
    int tamanho = 0;
    int posicao = 0;
    char simbolo = '_';
    chars digitos = IO_new_chars (STR_SIZE);

    strcpy (digitos, STR_EMPTY);

    //ler do teclado
    printf("Entre com caracteres: ");
    scanf("%s", palavra);
    getchar();

    //determinar a quantidade de simbolos na palavra
    tamanho = strlen(palavra);

    //repetir para a quantidade de vezes informada
    for (posicao=0; posicao<tamanho; posicao++)
    {
        //isolar um simbolo por vez
        simbolo = palavra[posicao];
        //tedtar e contar os algarismos em uma cadeia de caracteres
        if (isDigit (simbolo))
        {
            //concatenar simbolo encontrado
            digitos = IO_concat (digitos, IO_toString_c (simbolo));
            printf ("%c", simbolo);
        }
    }

    //mostrar a quantidade de digitos
    IO_printf ("\n%s%d[%s]\n", "Algarismos = ", strlen (digitos), digitos);
    
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method10 ( )

void method11()
{
    //identificar
    IO_id ("EXEMPLO0411 - Method11 - v1.0");
    double a = 0.0;
    double b = 0.0;
    int n = 0;
    double x =0;
    int dentro = 0;
    int fora = 0;

    printf ("Entre com o limite inferior de um intervalo (a): ");
    scanf ("%lf", &a);
    printf ("Entre com o limite superior de um intervalo (b): ");
    scanf ("%lf", &b);
    if (b<a)
    {
        printf ("ERRO (b<a)");
    }
    else
    {
        printf ("Entre com uma quantidade de valores a serem testados: ");
        scanf ("%d", &n);

        for (int controle = 0; controle<n; controle++)
        {
            x = IO_readdouble ("Entre com um valor: ");
            if (a<=x && x<=b)
            {
                dentro++;
            }
            else
            {
                fora++;
            }
        }
        printf ("Dos valores informados, %d estao dentro do intervalo [%lf,%lf] e %d estao fora", dentro, a, b, fora);
    }

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
}

void method12()
{
    //identificar
    IO_id ("EXEMPLO0412 - Method12 - v1.0");

    //dados
    chars palavra = IO_new_chars (STR_SIZE);
    char letra = '_';
    int contador = 0;

    printf ("Entre com uma palavra: ");
    scanf ("%s", palavra);
    getchar();
    for (int posicao=0; posicao<strlen(palavra); posicao++)
    {
        letra = palavra[posicao];
        if (isUpperCaseUntilK(letra))
        {
            contador++;
        }
    }

    printf ("\n%d letra(s) maiuscula(s) menor(es) que K\n", contador);
    
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
}

void method13()
{
    //identificar
    IO_id ("EXEMPLO0414 - Method13 - v1.0");

    //dados
    chars palavra = IO_new_chars (STR_SIZE);
    int contador = 0;

    printf ("Entre com uma palavra: ");
    scanf ("%s", palavra);
    getchar();
    for (int posicao=0; posicao<strlen(palavra); posicao++)
    {
        if (isUpperCaseUntilK2(palavra, posicao))
        {
            contador++;
        }
    }

    printf ("\n%d letra(s) maiuscula(s) menor(es) que K\n", contador);

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
}

void method14()
{
    //identificar
    IO_id ("EXEMPLO0414 - Method14 - v1.0");

    //dados
    chars palavra = IO_new_chars (STR_SIZE);
    int contador = 0;

    printf ("Entre com uma palavra: ");
    scanf ("%s", palavra);
    getchar();
    printf("\nLetra(s) maiuscula(s) menor(es) que K: ");
    for (int posicao=0; posicao<strlen(palavra); posicao++)
    {
        if (isUpperCaseUntilK2(palavra, posicao))
        {
            printf("%c ", palavra[posicao]);
        }
    }
    printf ("\n");

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
}

void method15()
{
    //identificar
    IO_id ("EXEMPLO0415 - Method15 - v1.0");

    //dados
    chars palavra = IO_new_chars (STR_SIZE);
    int contador = 0;

    printf ("Entre com uma palavra: ");
    scanf ("%s", palavra);
    getchar();
    for (int posicao=0; posicao<strlen(palavra); posicao++)
    {
        if (isLetterUntilK(palavra, posicao))
        {
            contador++;
        }
    }
    printf ("\n%d letra(s) menor(es) que K\n", contador);

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
}

void method16()
{
    //identificar
    IO_id ("EXEMPLO0416 - Method16 - v1.0");

    //dados
    chars palavra = IO_new_chars (STR_SIZE);

    printf ("Entre com uma palavra: ");
    scanf ("%s", palavra);
    getchar();
    printf("\nLetra(s) menor(es) que K: ");
    for (int posicao=0; posicao<strlen(palavra); posicao++)
    {
        if (isLetterUntilK(palavra, posicao))
        {
            printf("%c ", palavra[posicao]);
        }
    }
    printf ("\n");
    
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
}

void method17()
{
    //identificar
    IO_id ("EXEMPLO0417 - Method17 - v1.0");

    //dados
    chars palavra = IO_new_chars (STR_SIZE);
    int contador = 0;

    printf ("Entre com uma palavra: ");
    scanf ("%s", palavra);
    getchar();
    for (int posicao=0; posicao<strlen(palavra); posicao++)
    {
        if (isDigit2(palavra, posicao) && palavra[posicao] % 2 ==0)
        {
            contador++;
        }
    }
    printf ("\n%d Digitos sao pares\n", contador);

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
}

void method18()
{
    //identificar
    IO_id ("EXEMPLO0418 - Method18 - v1.0");

    //dados
    chars palavra = IO_new_chars (STR_SIZE);

    printf ("Entre com uma palavra: ");
    scanf ("%s", palavra);
    getchar();
    printf("\nSimbolos nao alfanumericos: ");
    for (int posicao=0; posicao<strlen(palavra); posicao++)
    {
        if (!(isAlphaNumeric(palavra, posicao)))
        {
            printf("%c ", palavra[posicao]);
        }
    }
    printf ("\n");

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
}

void method19()
{
    //identificar
    IO_id ("EXEMPLO0419 - Method19 - v1.0");

    chars palavra = IO_new_chars (STR_SIZE);

    printf ("Entre com uma palavra: ");
    scanf ("%s", palavra);
    getchar();
    printf("\nSimbolos alfanumericos: ");
    for (int posicao=0; posicao<strlen(palavra); posicao++)
    {
        if (isAlphaNumeric(palavra, posicao))
        {
            printf("%c ", palavra[posicao]);
        }
    }
    printf ("\n");


    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
}

void method20()
{
    //identificar
    IO_id ("EXEMPLO0420 - Method20 - v1.0");

    int n = 0;
    int alfanumericos = 0;
    int total = 0;
    int posicao = 0;
    chars palavra = IO_new_chars (STR_SIZE);

    printf ("Insira uma quantidade de palavras a serem testadas: ");
    scanf ("%d", &n);

    for (int controle=0; controle<n; controle++)
    {
        printf ("\nInsira uma palavra: ");
        scanf ("%s", palavra);
        getchar();
        alfanumericos=0;
        posicao=0;

        printf ("Alfanumericos: ");
        for (int x=0; x<strlen(palavra); x++)
        {
            if (isAlphaNumeric (palavra, posicao))
            {
                alfanumericos++;
                total++;
                printf ("%c", palavra[posicao]);
            }
            posicao++;
        }
        printf ("\nQuantidade de alfanumericos: %d", alfanumericos);
        printf("\n");
    }
    printf ("\nTotal de alfanumericos: %d\n", total);

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
}

void methodE1()
{
    //identificar
    IO_id ("EXEMPLO04E1 - MethodE1 - v1.0");

    int n = 0;
    int alfanumericos = 0;
    int total = 0;
    int posicao = 0;
    chars palavra = IO_new_chars (STR_SIZE);

    //n = IO_readint ("Insira uma quantidade de cadeias de caracteres a serem testadas: ");  
    
    printf ("Insira uma quantidade de cadeias de caracteres a serem testadas: ");
    scanf ("%d", &n);
    getchar();
    //por algum motivo isso faz o programa pedir infinitas palavras. IO_readint corrigiu 
    

    for (int controle=0; controle<n; controle++)
    {
        palavra = IO_readln ("Insira palavras: ");  //lembrete: limpar scanf sempre antes de IO_readln() ou gets(). (O usar IO_readint em vez de scanf)
        alfanumericos=0;
        posicao=0;

        printf ("Alfanumericos: ");
        for (int x=0; x<strlen(palavra); x++)
        {
            if (isAlphaNumeric (palavra, posicao))
            {
                alfanumericos++;
                total++;
                printf ("%c", palavra[posicao]);
            }
            posicao++;
        }
        printf ("\nQuantidade de alfanumericos: %d\n", alfanumericos);
    }
    printf ("\nTotal de alfanumericos: %d\n", total);
    printf ("\n");

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
}

void methodE2()
{
    //identificar
    IO_id ("EXEMPLO04E2 - MethodE2 - v1.0");

    //dados
    chars palavra1 = IO_new_chars (STR_SIZE);
    chars palavra2 = IO_new_chars (STR_SIZE);
    
    palavra1 = IO_readln("Insira uma cadeia de caracteres: ");
    palavra2 = IO_readln("Insira outra cadeia de caracteres: ");

    printf ("\nA cadeia de caracteres com o menor numero de digitos e': %s\n", menorString(palavra1, palavra2));

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
}

/*
Funcao principal.
@return codigo de encerramento
*/
int main ( )
{
    // definir dado
    int x = 0;
    
    // repetir até desejar parar
    do
    {
        // identificar
        IO_id ( "Ed04 - Programa - v1.0" );
        
        // ler do teclado
        IO_println ( "Opcoes" );
        IO_println ( " 0 - parar" );
        IO_println ( " 1 - ler certa quantidade de valores" );
        IO_println ( " 2 - ler valores e determinar se valor inteiro e' positivo" );
        IO_println ( " 3 - ler valores e determinar se valor inteiro pertence a intervalo aberto" );
        IO_println ( " 4 - ler valores e determinar se valor inteiro e' positivo, menor que 100 e par" );
        IO_println ( " 5 - ler valores e determinar se valor inteiro e' positivo, menor que 100 e par (alternativo)" );
        IO_println ( " 6 - ler palavras e contar letras minusculas" );
        IO_println ( " 7 - ler palavra, contar e mostrar letras minusculas" );
        IO_println ( " 8 - ler palavra, contar e mostrar letras minusculas (alternativo)" );
        IO_println ( " 9 - ler palavra e contar os algarismos" );
        IO_println ( "10 - ler palavra e contar os algarismos (alternativo)" );
        IO_println ( "11 - Exemplo0411" );
        IO_println ( "12 - Exemplo0412" );
        IO_println ( "13 - Exemplo0413" );
        IO_println ( "14 - Exemplo0414" );
        IO_println ( "15 - Exemplo0415" );
        IO_println ( "16 - Exemplo0416" );
        IO_println ( "17 - Exemplo0417" );
        IO_println ( "18 - Exemplo0418" );
        IO_println ( "19 - Exemplo0419" );
        IO_println ( "20 - Exemplo0420" );
        IO_println ( "21 - Exemplo04E1" );
        IO_println ( "22 - Exemplo04E2" );
        IO_println ( "" );
        x = IO_readint ( "Entrar com uma opcao: " );
        
        // testar valor
        switch ( x )
        {
            case 0:
            method00 ( );
            break;
            case 1:
            method01 ( );
            break;
            case 2:
            method02 ( );
            break;
            case 3:
            method03 ( );
            break;
            case 4:
            method04 ( );
            break;
            case 5:
            method05 ( );
            break;
            case 6:
            method06 ( );
            break;
            case 7:
            method07 ( );
            break;
            case 8:
            method08 ( );
            break;
            case 9:
            method09 ( );
            break;
            case 10:
            method10 ( );
            break;
            case 11:
            method11();
            break;
            case 12:
            method12();
            break;
            case 13:
            method13();
            break;
            case 14:
            method14();
            break;
            case 15:
            method15();
            break;
            case 16:
            method16();
            break;
            case 17:
            method17();
            break;
            case 18:
            method18();
            break;
            case 19:
            method19();
            break;
            case 20:
            method20();
            break;
            case 21:
            methodE1();
            break;
            case 22:
            methodE2();
            break;
            default:
            IO_pause ( "ERRO: Valor invalido." );
        } // fim escolher
    }while ( x != 0 );

    // encerrar
    IO_pause ( "Apertar ENTER para terminar" );
    return ( 0 );
} // fim main( )

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) -1
b.) 0
c.) 5 e { 1, 2, 3, 4, 5 }
---------------------------------------------- historico
Versao Data Modificacao
 0.1 __/__ esboco
---------------------------------------------- testes
Versao Teste
 0.1 01. ( OK ) identificacao de programa
 */