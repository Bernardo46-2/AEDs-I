//Bernardo Marques Fernandes - 774119
//R01

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

/* 
Bernardo Marques Fernandes - 774119

FAZER um procedimento ( exercicio01 ) para:
- ler um valor inteiro (n) do teclado para indicar uma quantidade;
- ler outros tantos valores inteiros (x) do teclado, um por vez, até atingir a quantidade;
- dizer para cada valor lido quais são os seus divisores.

Exemplos:
n = 5
x = { 22, 121, 440, 581, 814 }
*/
void exercicio01(){
    printf ("\n--R01 - Exercicio01--\n");

    int n=0;
    int numero=0;

    printf ("\nInsira uma quantidade: ");
    scanf ("%d", &n);
    getchar();

    for (int i=0; i<n; i++){
        printf ("\nInsira um numero: ");
        scanf ("%d", &numero);
        getchar();

        printf ("Divisores de %d: \n", numero);
        for (int j=1; j<=numero/2; j++){
            if (numero%j==0)
                printf ("%d ",j);
        }
        printf ("%d", numero);
        printf ("\n");
    }

    printf ("\nAperte ENTER para continuar");
    getchar();
}

/* 
Bernardo Marques Fernandes - 774119

FAZER um procedimento ( exercicio02 ) para:
- ler um valor inteiro (n) do teclado para indicar uma quantidade;
- ler outros tantos valores inteiros (x) do teclado, um por vez, até atingir a quantidade;
- dizer para cada valor lido é primo ou não.

Exemplos:
n = 5
x = { -293, -107, 153, 199, 811 }
*/

bool isPrime(int x){
    bool prime=true;
    if (x==0 || x==1 || x==-1)
        prime=false;
    else if (x>0){
        for (int i=2; i<=x/2; i++)
            if (x%i==0) prime=false;
    }else if (x<0){
        for (int i=x/2; i<=-2; i++)
            if (x%i==0) prime=false;
    }
    return prime;
}

void exercicio02(){
    printf ("\n--R01 - Exercicio02--\n");

    int n=0;
    int numero=0;
    int divisores=0;

    printf ("\nInsira uma quantidade: ");
    scanf ("%d", &n);
    getchar();

    for (int i=0; i<n; i++){
        printf ("\nInsira um numero: ");
        scanf ("%d", &numero);
        getchar();
        
        printf ("%d %s primo\n", numero, isPrime(numero)?"e'":"nao e'");
    }

    printf ("\nAperte ENTER para continuar");
    getchar();
}

/* 
Bernardo Marques Fernandes - 774119 

FAZER um procedimento ( exercicio03 ) para:
- ler uma cadeia de caracteres do teclado;
- dizer se cada símbolo é um operador lógico (&,|,!), aritmético (+,-,*,/,%), relacional (>,<,=),
separadores (espaço, ponto, vírgula, ponto-e-vírgula, dois-pontos, sublinha) 
ou outro símbolo qualquer.

DICA: Definir e usar funções para identificar cada um desses tipos de símbolo.
Exemplos:
"for(x=0;x<y&&y>=0;x=x+1)"
*/

bool ehLogico (char c){
    return (c=='!' || c=='|' || c=='&');
}

bool ehAritmetico (char c){
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='%');
}

bool ehRelacional (char c){
    return (c=='>' || c=='<' || c=='=');
}

bool ehSeparador (char c){
    return (c==' ' || c=='.' || c==',' || c==';' || c==':' || c=='_');
}

bool ehLetraMaiuscula (char c){
    return ('A'<=c && c<='Z');
}

bool ehLetraMinuscula (char c){
    return ('a'<=c && c<='z');
}

bool ehNumero (char c){
    return ('0'<=c && c<='9');
}

bool ehParenteses (char c){
    return (c=='(' || c==')' || c=='[' || c==']' || c=='{' || c=='}');
}

void exercicio03(){
    printf ("\n--R01 - Exercicio03--\n");

    char string[80];

    printf ("\nInsira uma cadeia de caracteres: ");
    gets (string);

    for (int i=0; i<strlen(string); i++){
        if (ehLogico(string[i])) 
            printf ("\n%c = Logico", string[i]);
        else if (ehAritmetico(string[i])) 
            printf ("\n%c = Aritmetico", string[i]);
        else if (ehRelacional(string[i])) 
            printf ("\n%c = Relacional", string[i]);
        else if (ehSeparador(string[i])) 
            printf ("\n%c = Separador", string[i]);
        else if (ehLetraMaiuscula(string[i])) 
            printf ("\n%c = Letra maiuscula", string[i]);
        else if (ehLetraMinuscula(string[i])) 
            printf ("\n%c = Letra minuscula", string[i]);
        else if (ehNumero(string[i])) 
            printf ("\n%c = Numero", string[i]);
        else if (ehParenteses(string[i])) 
            printf ("\n%c = Parenteses/Colchetes/Chaves", string[i]);
    }

    printf ("\n\nAperte ENTER para continuar");
    getchar();
}

/* 
Bernardo Marques Fernandes - 774119 

FAZER um procedimento ( exercicio04 ) para:
- ler um cadeia de caracteres (s) do teclado;
- testar cada símbolo na cadeia, um por vez,
e contar separadamente quantos desses são letras maiúsculas, minúsculas, dígitos e 
operadores (lógicos, aritméticos e relacionais) e separadores.

DICA: Definir e reutilizar funções já definidas para identificar cada tipo de símbolo (ver acima).
Exemplos:
"for(X=0;X<y&&y>=0;X=X+1)"
*/
void exercicio04(){
    printf ("\n--R01 - Exercicio04--\n");

char string[80];
    int logico=0, aritmetico=0, relacional=0, separador=0, maiuscula=0, minuscula=0, numero=0, parenteses=0;

    printf ("\nInsira uma cadeia de caracteres: ");
    gets (string);

    for (int i=0; i<strlen(string); i++){
        if (ehLogico(string[i])) logico++;
        else if (ehAritmetico(string[i])) aritmetico++;
        else if (ehRelacional(string[i])) relacional++;
        else if (ehSeparador(string[i])) separador++;
        else if (ehLetraMaiuscula(string[i])) maiuscula++;
        else if (ehLetraMinuscula(string[i])) minuscula++;
        else if (ehNumero(string[i])) numero++;
        else if (ehParenteses(string[i])) parenteses++;
    }

    printf ("\nCaracteres logicos: %d", logico);
    printf ("\nCaracteres aritmeticos: %d", aritmetico);
    printf ("\nCaracteres relacionais: %d", relacional);
    printf ("\nCaracteres separadores: %d", separador);
    printf ("\nLetras maiusculas: %d", maiuscula);
    printf ("\nLetras minusculas: %d", minuscula);
    printf ("\nNumeros: %d", numero);
    printf ("\nParenteses/Colchetes/Chaves: %d", parenteses);

    printf ("\n\nAperte ENTER para continuar");
    getchar();
}

/* 
Bernardo Marques Fernandes - 774119 

FAZER um procedimento ( exercicio05 ) para:
- ler um valor inteiro (n) do teclado;
- ler outros (n) valores reais (x) do teclado, um por vez;
- calcular e mostrar a média dos valores menores que -23.75;
a média dos que estão entre -23.75 e 65.25, inclusive esses;
e a média dos maiores que 65.25. Dizer qual a maior média de todas.

DICA: Definir e usar função para calcular o maior dentre três valores.
Exemplos:
n = 10
x = { -15.25, -12.50, 0.0, 6.75, 20.50, 50.0, 70.25, 85.25, 92.50, 98.75 }
*/

double maiorNum (double valor1, double valor2, double valor3){
    if (valor1>valor2 && valor1>valor3) return (valor1);
    else if (valor2>valor3 && valor2>valor1) return (valor2);
    else if (valor3>valor1 && valor3>valor2) return (valor3);
}

void exercicio05(){
    printf ("\n--R01 - Exercicio05--\n");

    int n=0;
    double numero=0;

    printf ("\nInsira uma quantidade: ");
    scanf ("%d", &n);
    getchar();

    int quantidade1=0;
    int quantidade2=0;
    int quantidade3=0;

    double media1=0;
    double media2=0;
    double media3=0;

    for (int i=0; i<n; i++){
        printf ("\nInsira um numero: ");
        scanf ("%lf", &numero);
        getchar();

        if(numero<-23.75){
            media1+=numero;
            quantidade1++;
        }else if(-23.75<=numero && numero<=65.25){
            media2+=numero;
            quantidade2++;
        }else if(65.25<numero){
            media3+=numero;
            quantidade3++;
        }         
    }

    if (quantidade1==0)
        media1=0;
    else
        media1/=(double)quantidade1;

    if (quantidade2==0)
        media2=0;
    else
        media2/=(double)quantidade2;
    if (quantidade3==0)
    
        media3=0;
    else
        media3/=(double)quantidade3;

    //mostrar medias
    printf ("\nMedia dos numeros menores que -23.75: %lf", media1);
    printf ("\nMedia dos numeros maiores que -23.75 e menores que 65.25: %lf", media2);
    printf ("\nMedia dos numeros maiores que 65.25: %lf", media3);

    //maior media
    printf ("\n\nA maior das tres medias e': %lf", maiorNum(media1, media2, media3));

    printf ("\n\nAperte ENTER para continuar");
    getchar();
}

/* 
Bernardo Marques Fernandes - 774119 

FAZER um procedimento ( exercicio06 ) para:
- ler dois valores inteiros (a) e (b) do teclado,
- ler outros valores inteiros do teclado, um por vez,
até que o último valor seja igual a (-1).
- para cada valor lido que estiver no intervalo aberto ]a:b[;
calcular e mostrar a soma dos cubos dos inversos (1/x3) dos ímpares.
DICA: Evitar divisão por zero mediante uso de alternativa dupla.
Definir e usar funções para testar o pertencimento ao intervalo,
e para calcular a soma.

Exemplos:
a = 20
b = 60
x = { -20, -11, 0, 1, 10, 21, 36, 51, 70, 80, -1 }
*/
void exercicio06(){
    printf ("\n--R01 - Exercicio06--\n");

    int a, b, x;
    double fracao=0.0;
    double resultado=0.0;

    do{
        printf ("\nInsira um valor (a): ");
        scanf ("%d", &a);
        getchar();
        printf ("\nInsira um valor (b): ");
        scanf ("%d", &b);
        getchar();
        if (a>=b){
            printf ("\nERRO: (a) nao pode ser maior ou igual a (b)");
            printf ("\nAperte ENTER para continuar");
            getchar();
        }
    }while (a>=b);

    while (x!=-1){
        printf ("\nInsira um numero (-1 para encerrar): ");
        scanf ("%d'", &x);
        getchar();

        if (x<a || x>b){
            printf ("Numero fora do intervalo ]%d:%d[\n", a, b);
        }else if (x%2==0){
            printf ("Numero e' par. Nao cumpre os requisitos do exercicio.\n");
        }else if (x==0){
            printf ("Numero nao pode ser 0\n");
        }else if (x%2!=0 && (a<x && x<b)){
            fracao=1.0/pow((1.0*x), 3.0);
            resultado+=fracao;
            printf ("1/%d^3 = %lf\n", x, fracao);
        }
    }
    printf ("\nResultado da soma das fracoes: %lf", resultado);

    printf ("\nAperte ENTER para continuar");
    getchar();
}

/* 
Bernardo Marques Fernandes - 774119 

FAZER um procedimento ( exercicio07 ) para:
- ler dois valores reais (a) e (b) do teclado,
- ler outros valores reais do teclado, um por vez,
até que o último valor seja igual a zero,
e não considerá-lo para os cálculos. 
- contar quantos desses valores estão dentro ou fora
do intervalo definido pelo intervalo aberto ]a:b[;
- para os valores fora do intervalo, calcular separadamente
as porcentagens dos que estiverem acima e abaixo do intervalo, nessa ordem.
DICA: Evitar divisão por zero mediante uso de alternativas duplas.
Reutilizar a função para testar o pertencimento (ou não) ao intervalo.
Exemplos:
a = 20
b = 60
x = { -20, -10, 1, 10, 20, 30, 60, 70, 80, 0 }
*/
void exercicio07(){
    printf ("\n--R01 - Exercicio07--\n");

    double a, b, x;
    double dentro=0.0, fora=0.0, total=0.0;

    do{
        printf ("\nInsira um valor (a): ");
        scanf ("%lf", &a);
        getchar();
        printf ("\nInsira um valor (b): ");
        scanf ("%lf", &b);
        getchar();
        if (a>=b){
            printf ("\nERRO: (a) nao pode ser maior ou igual a (b).");
            printf ("\nAperte ENTER para continuar");
            getchar();
        }
    }while (a>=b);

    do{
        printf ("\nInsira um numero (0 para encerrar): ");
        scanf ("%lf", &x);
        getchar();

        if (x==0)
            break;
        else if (x<=a || x>=b)
            fora++;
        else
            dentro++;
        total++;
    }while (x!=0);

    printf ("\nResultados:");
    printf ("\n%lf%% dos numeros estao dentro do intervalo ]%lf:%lf[.", (dentro/total)*100, a, b);
    printf ("\n%lf%% dos numeros estao fora do intervalo ]%lf:%lf[.", (fora/total)*100, a, b);

    printf ("\n\nAperte ENTER para continuar");
    getchar();
}

/* 
Bernardo Marques Fernandes - 774119 

FAZER um procedimento ( exercicio08 ) para:
- ler três valores reais (x,y,z) do teclado, um por vez;
- dizer se esses valores estão em ordem crescente,
decrescente ou em nenhuma dessas ordens e, nesse caso, o menor e o maior.
DICA: Usar testes com maior número de comparações usando conectivos lógicos ( &&, || e ! ).
Definir funções para testar as ordens crescente e decrescente.
Exemplos:
x = 10, y = 20, z = 30
x = 30, y = 20, z = 10
x = 10, y = 10, z = 10
*/

int maiorNumInt (int valor1, int valor2, int valor3){
    if (valor1>valor2 && valor1>valor3)
        return (valor1);
    else if (valor2>valor3 && valor2>valor1)
        return (valor2);
    else if (valor3>valor1 && valor3>valor2)
        return (valor3);
}

int menorNumInt (int valor1, int valor2, int valor3){
    if (valor1<valor2 && valor1<valor3)
        return (valor1);
    else if (valor2<valor1 && valor2<valor3)
        return (valor2);
    else if (valor3<valor1 && valor3<valor2)
        return (valor3);
}

bool crescente2num (int x, int y){
    return (x<y);
}

bool ordemCrescente (int x, int y, int z){
    return (x<y && y<z);
}

bool ordemDecrescente (int x, int y, int z){
    return (x>y && y>z);
}

void exercicio08(){
    printf ("\n--R01 - Exercicio08--\n");

    int x, y, z, maior, menor;
    bool crescente=false;

    printf ("\nInsira um valor (x): ");
    scanf ("%d", &x);
    getchar();
    printf ("\nInsira um valor (y): ");
    scanf ("%d", &y);
    getchar();
    printf ("\nInsira um valor (z): ");
    scanf ("%d", &z);
    getchar();
    printf ("\n");

    //testar igualdade
    if (x==y || y==z || z==x){
        if (x==y && y==z && z==x){
            printf ("\nTodos os numeros sao iguais");
            printf ("\nOrdem: nem crescente, nem decrescente");
        }else if (x==y){
            if (crescente2num(x, z)){
                menor=x;
                maior=z;
                crescente=true;
            }else{
                maior=x;
                menor=z;
                crescente=false;
            }
        }else if (y==z){
            if (crescente2num(x, z)){
                menor=x;
                maior=z;
                crescente=true;
            }else{
                maior=x;
                menor=z;
                crescente=false;
            }
        }else if (z==x){
            if (crescente2num(x, y)){
                menor=x;
                maior=y;
                crescente=true;
            }else{
                maior=x;
                menor=y;
                crescente=false;
            }
            printf ("\nMaior numero: %d", maior);
            printf ("\nMenor numero: %d", menor);
        }
        //testar numeros diferentes
    }else{
        if (ordemCrescente(x, y, z)){
            menor=x;
            maior=z;
            crescente=true;
            printf ("\nMaior: %d", maior);
            printf ("\nMenor: %d", menor);
            printf ("\nOrdem: %s", crescente?"crescente":"decrescente");
        }else if (ordemDecrescente(x, y, z)){
            menor=z;
            maior=x;
            crescente=false;
            printf ("\nMaior: %d", maior);
            printf ("\nMenor: %d", menor);
            printf ("\nOrdem: %s", crescente?"crescente":"decrescente");
        }else{
            maior=maiorNumInt(x, y, z);
            menor=menorNumInt(x, y, z);
            printf ("\nMaior: %d", maior);
            printf ("\nMenor: %d", menor);
            printf ("\nOrdem: nem crescente, nem decrescente");
        }
    }

    printf ("\n\nAperte ENTER para continuar");
    getchar();
}

/* 
Bernardo Marques Fernandes - 774119 

FAZER um procedimento ( exercicio09 ) para:
- ler três caracteres (x,y,z) do teclado, um por vez;
- dizer se esses valores estão em ordem crescente,
decrescente ou em nenhuma dessas ordens.
DICA: Usar uma função lógica para comparar os códigos inteiros de cada caractere,
e dizer se o segundo sucede o primeiro em ordem alfabética.
Definir funções para testar as ordens alfabéticas crescente e decrescente.
Exemplos:
x = '1', y = '2', z = '3'
x = '3', y = '2', z = '1'
x = '1', y = '1', z = '1'
*/

bool ordemCrescenteChar (char x, char y, char z){
    return (x<y && y<z);
}

bool ordemDecrescenteChar (char x, char y, char z){
    return (x>y && y>z);
}

void exercicio09(){
    printf ("\n--R01 - Exercicio09--\n");

    char x, y, z;

    printf ("\nInsira um caractere (x): ");
    scanf ("%c", &x);
    getchar();
    printf ("\nInsira um caractere (y): ");
    scanf ("%c", &y);
    getchar();
    printf ("\nInsira um caractere (z): ");
    scanf ("%c", &z);
    getchar();

    if (x==y && y==z){
        printf ("\nTodos os caracteres sao iguais");
    }else if (x==y && y!=z){
        if (x>z)
            printf ("\nOrdem decrescente.");
        else
            printf ("\nOrdem crescente.");
    }else if (y==z && y!=x){
        if (y>x)
            printf ("\nOrdem decrescente.");
        else
            printf ("\nOrdem crescente.");
    }else if (z==x && z!=y){
        if (z>y)
            printf ("\nOrdem decrescente.");
        else
            printf ("\nOrdem crescente.");
    }else if (x!=y && y!=z && z!=x){
        if (ordemCrescenteChar(x, y, z))
            printf ("\nOrdem crescente.");
        else if (ordemDecrescente(x, y, z))
            printf ("\nOrdem decrescente");
        else
            printf ("\nOrdem nem crescente, nem decrescente");
    }

    printf ("\n\nAperte ENTER para continuar");
    getchar();
}

/* 
Bernardo Marques Fernandes - 774119 

FAZER um procedimento com um método ( exercicio10 ) para:
- ler três cadeias de caracteres (x,y,z) do teclado, uma por vez;
- dizer se essas cadeias estão em ordem alfabética crescente,
decrescente ou em nenhuma dessas ordens e, nesse caso, a menor e a maior.

DICA: Usar strcmp( ) da biblioteca <string.h> e comparar o resultado com zero.
A função para a comparação poderá retornar um dentre
os seguintes resultados:
negativo, se a primeira cadeia preceder a segunda (resultado menor que zero);
nulo , se as cadeias forem iguais (resultado igual a zero);
positivo , se a primeira cadeia suceder a segunda (resultado maior que zero).

Exemplo:
char s1 [ ] = “abc”;
char s2 [ ] = “ABC”;
if ( strcmp ( s1, s2 ) != 0 )
{
IO_println ( “diferentes” );
} // end i
*/

bool crescenteStr (char* x, char* y, char* z){
    bool crescente=true;
    if (strcmp (x, y)>=0) //retorna maior que zero se for decrescente
        crescente=false;
    if (strcmp (y, z)>=0)
        crescente=false;
    return crescente;
} 

bool decrescenteStr (char* x, char* y, char* z){
    bool decrescente=true;
    if (strcmp (x, y)<=0) //retorna menor que zero se for crescente
        decrescente=false;
    if (strcmp (y, z)<=0)
        decrescente=false;
    return decrescente;
}

void exercicio10(){
    printf ("\n--R01 - Exercicio10--\n");

    char x[80];
    char y[80];
    char z[80];
    char maior[80];
    char menor[80];

    printf ("\nInsira uma palavra: ");
    scanf ("%s", x);
    getchar();
    printf ("\nInsira uma palavra: ");
    scanf ("%s", y);
    getchar();
    printf ("\nInsira uma palavra: ");
    scanf ("%s", z);
    getchar();

    if (crescenteStr (x, y, z))
        printf ("\nOrdem alfabetica crescente");
    else if (decrescenteStr (x, y, z))
        printf ("\nOrdem alfabetica decrescente");
    else{
        printf ("\nOrdem nao e' crescente nem decrescente");

        strcpy (maior, x);
        if (strcmp (maior, y)<=0)
            strcpy (maior, y);
        if (strcmp (maior, z)<=0)
            strcpy (maior, z);
        printf ("\nMaior: %s", maior);

        strcpy (menor, x);
        if (strcmp (maior, y)>=0)
            strcpy (menor, y);
        if (strcmp (maior, z)>=0)
            strcpy (menor, z);
        printf ("\nMenor: %s", menor);
    }

    printf ("\n");
    printf ("\n\nAperte ENTER para continuar");
    getchar();
}

int main(){
    int opcao=0;

    do{
        printf ("\n--R01--\n");
        printf ("\nMenu:");
        printf ("\n[0] Parar");
        printf ("\n[1] Exercicio01");
        printf ("\n[2] Exercicio02");
        printf ("\n[3] Exercicio03");
        printf ("\n[4] Exercicio04");
        printf ("\n[5] Exercicio05");
        printf ("\n[6] Exercicio06");
        printf ("\n[7] Exercicio07");
        printf ("\n[8] Exercicio08");
        printf ("\n[9] Exercicio09");
        printf ("\n[10] Exercicio10");

        printf ("\n\nOpcao: ");
        scanf ("%d", &opcao);
        getchar();

        switch(opcao){
            case 0:
            break;
            case 1:
            exercicio01();
            break;
            case 2:
            exercicio02();
            break;
            case 3:
            exercicio03();
            break;
            case 4:
            exercicio04();
            break;
            case 5:
            exercicio05();
            break;
            case 6:
            exercicio06();
            break;
            case 7:
            exercicio07();
            break;
            case 8:
            exercicio08();
            break;
            case 9:
            exercicio09();
            break;
            case 10:
            exercicio10();
            break;
            default:
            printf ("\nValor Invalido!");
            printf ("\nAperte ENTER parar continuar");
            getchar();
        }
    }while (opcao!=0);

    printf ("\nAperte ENTER para terminar");
    getchar();
    return 0;
}