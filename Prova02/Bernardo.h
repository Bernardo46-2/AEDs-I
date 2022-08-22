#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define null NULL


//--identificar caractere--//

bool isLogic (char c)                               {return (c=='!' || c=='|' || c=='&');}
bool isArithmetic (char c)                          {return (c=='+' || c=='-' || c=='*' || c=='/' || c=='%');}
bool isRelational (char c)                          {return (c=='>' || c=='<' || c=='=');}
bool isSeparator (char c)                           {return (c==' ' || c=='.' || c==',' || c==';' || c==':' || c=='_');}
bool isUpperCase (char c)                           {return ('A'<=c && c<='Z');}
bool isLowerCase (char c)                           {return ('a'<=c && c<='z');}
bool isLetter (char c)                              {return (('A'<=c && c<='Z') || ('a'<=c && c<='z'));}
bool isNumber (char c)                              {return ('0'<=c && c<='9');}
bool isEven (int x)                                 {return (x%2==0);}
bool isOdd (int x)                                  {return (x%2!=0);}
int largest2 (int x, int y)                         {if (x<y) x=y; return x;}
int largest3 (int x, int y, int z)                  {if (x<y) x=y; if(x<z) x=z; return x;}
double largest2db (double x, double y)              {if (x<y) x=y; return x;}
double largest3db (double x, double y, double z)    {if (x<y) x=y; if(x<z) x=z; return x;}

int randInt (int a, int b){
    if (a==b)
        return a;
    else if (a<b)
        return (rand()%(b+1-a)+a);
    else
        return (rand()%(a+1-b)+b);
}

bool isPrime (int x){
    bool prime=true;
    if (x==0 || x==1) 
        prime=false;
    else{
        for (int i=2; i<=x/2; i++)
            if (x%i==0) prime=false;
    }
    return prime;
}

bool isPrimeAll(int x){
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


//--ler valores--//

void flush(){
    while(getchar()!='\n');
}

int readQuantity(){
    int x;
    printf ("\nDigite uma quantidade: ");
    scanf ("%d", &x);
    flush();
    if (x<=0){
        printf ("ERRO: quantidade precisa ser maior que zero\n");
        x=readQuantity();
    }
    return x;
}

int readInt(){
    int x;
    printf ("\nDigite um numero: ");
    scanf ("%d", &x);
    flush();
    return x;
}

int readIntNat(bool includeZero){
    int x;
    printf ("\nDigite um numero: ");
    scanf ("%d", &x);
    flush();
    if (x<=0 && includeZero==false){
        printf ("ERRO: numero precisa ser maior que zero\n");
        x=readIntNat(includeZero);
    }else if(x<0 && includeZero==true){
        printf ("ERRO: numero nao pode ser negativo\n");
        x=readIntNat(includeZero);
    }
    return x;
}

double readDouble(){
    double x;
    printf ("\nDigite um numero: ");
    scanf ("%lf", &x);
    flush();
    return x;
}

double readDoubleNat(bool includeZero){
    double x;
    printf ("\nDigite um numero: ");
    scanf ("%d", &x);
    flush();
    if (x<=0 && includeZero==false){
        printf ("ERRO: numero precisa ser maior que zero\n");
        x=readDoubleNat(includeZero);
    }else if(x<0 && includeZero==true){
        printf ("ERRO: numero nao pode ser negativo\n");
        x=readDoubleNat(includeZero);
    }
    return x;
}

char readChar(){
    char x;
    printf ("\nDigite um caractere: ");
    scanf ("%c", &x);
    flush();
    return x;
}

int readIntC(char* frase){
    int x;
    printf("\n%s ", frase);
    scanf("%d", &x);
    flush();
    return x;
}

int readIntNatC(char* frase){
    int x;
    printf ("\n%s ", frase);
    scanf ("%d", &x);
    flush();
    if (x<=0){
        printf ("ERRO: numero precisa ser maior que zero\n");
        x=readIntNatC(frase);
    }
    return x;
}


//--matematica--//

int fac(int x){
    if (x<0){
        printf ("Valor Invalido!\n");
        return fac(readInt());
    }else if (x==0 || x==1)
        return 1;
    else
        return x*fac(x-1);
}

double po(double base, double exponent){
    double result=base;
    if(exponent==0){
        return 1;
    }else if(exponent<0){
        exponent*=-1;
        for(int i=0; i<exponent-1; i++){
            result*=base;
        }
        return 1/result;
    }else if(exponent>0){
        for(int i=0; i<exponent-1; i++){
            result*=base;
        }
    }
    return result;
}


//--arrays--//

int* newIntArray(int n){
    return (int*)malloc(n*sizeof(int));
}

double* newDoubleArray(int n){
    return (double*)malloc(n*sizeof(double));
}

bool* newBoolArray(int n){
    return (bool*)malloc(n*sizeof(bool));
}

char* newCharArray(int n){
    return (char*)malloc((n+1)*sizeof(char));
}


//--alterar string--//

char upper(char c){
    if('a'<=c && c<='z'){
        c-=32;
    }
    return c;
}

char lower(char c){
    if('A'<=c && c<='Z'){
        c+=32;
    }
    return c;
}


//--praticidade--//

void clear(){
    //printf("\e[H\e[2J\e[3J");
    system("cls");
}

bool readYN(char* string){
    bool x;
    printf("\n%s", string);
    printf("\n\n0 - nao\n1 - sim\n-> ");
    scanf("%d", &x);
    flush();

    if(x==0)
        return false;
    else if(x==1)
        return true;
    else 
        return readYN(string);
}

void introf(char* ed, char* ex){
    printf("\n\n--Ed%s - Exemplo%s%s--", ed, ed, ex);
    printf("\nBernardo Marques Fernandes - 774119\n");
}

void endf(){
    printf ("\n\nPress ENTER");
    getchar();
}

bool quit(){
    clear();
    return readYN("\nTem certeza que deseja sair?");
}

int menu(char* ed){
    printf ("\n\nEd%s\n", ed);
    printf ("Bernardo Marques Fernandes - 774119\n");
    printf ("\n0 - parar");
    for (int i=1; i<=12; i++){
        if (i<11) printf ("\n%d - Exemplo%s%d", i, ed, i+10);
        else if (i==11) printf ("\n%d - Exemplo%sE1", i, ed);
        else printf ("\n%d - Exemplo%sE2\n", i, ed);
    }
    int opcao=readInt();
    return opcao;
}

/*

#include "Bernardo.h"

int main(){
    int opcao;
    bool sair=false;
    do{
        opcao=menu("00");
        switch(opcao){
            case 0: sair=quit(); break;
            case 1: exemplo11(); break;
            case 2: exemplo12(); break;
            case 3: exemplo13(); break;
            case 4: exemplo14(); break;
            case 5: exemplo15(); break;
            case 6: exemplo16(); break;
            case 7: exemplo17(); break;
            case 8: exemplo18(); break;
            case 9: exemplo19(); break;
            case 10: exemplo20(); break;
            case 11: exemploE1(); break;
            case 12: exemploE2(); break;
            default: printf ("\nValor Invalido\nPress ENTER"); getchar();
        }
    }while (sair==false);

    return 0;
}

*/