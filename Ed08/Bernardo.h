//11 - identificar caracteres
//55 - ler valores
//138 - arrays
//199 - praticidade

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

//--identificar caractere--//

bool isLogic (char c){return (c=='!' || c=='|' || c=='&');}
bool isArithmetic (char c){return (c=='+' || c=='-' || c=='*' || c=='/' || c=='%');}
bool isRelational (char c){return (c=='>' || c=='<' || c=='=');}
bool isSeparator (char c){return (c==' ' || c=='.' || c==',' || c==';' || c==':' || c=='_');}
bool isUpperCase (char c){return ('A'<=c && c<='Z');}
bool isLowerCase (char c){return ('a'<=c && c<='z');}
bool isLetter (char c){return (('A'<=c && c<='Z') || ('a'<=c && c<='z'));}
bool isNumber (char c){return ('0'<=c && c<='9');}
bool isParenteses (char c){return (c=='(' || c==')' || c=='[' || c==']' || c=='{' || c=='}');}
bool isEven (int x){return (x%2==0);}
bool isOdd (int x) {return (x%2!=0);}
int largest2 (int x, int y) {if (x<y) x=y; return x;}
int largest3 (int x, int y, int z) {if (x<y) x=y; if(x<z) x=z; return x;}
int randomInt (int a, int b) {return (rand()%(b+1-a)+a);}
double largest2db (double x, double y) {if (x<y) x=y; return x;}
double largest3db (double x, double y, double z) {if (x<y) x=y; if(x<z) x=z; return x;}

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

int readQuantity(){
    int x=0;
    printf ("\nInsira uma quantidade: ");
    scanf ("%d", &x);
    getchar();
    if (x<=0){
        printf ("ERRO: quantidade precisa ser maior que zero\n");
        x=readQuantity();
    }
    return x;
}

int readInt(){
    int x=0;
    printf ("\nInsira um numero: ");
    scanf ("%d", &x);
    getchar();
    return x;
}

int readIntNat(){
    int x=0;
    printf ("\nInsira um numero: ");
    scanf ("%d", &x);
    getchar();
    if (x<=0){
        printf ("ERRO: numero precisa ser maior que zero\n");
        x=readIntNat();
    }
    return x;
}

float readfloat(){
    float x;
    printf ("\nInsira um numero: ");
    scanf ("%f", &x);
    getchar();
    return x;
}

float readFloatNat(){
    float x=0;
    printf ("\nInsira um numero: ");
    scanf ("%f", &x);
    getchar();
    if (x<=0){
        printf ("ERRO: numero precisa ser maior que zero\n");
        x=readFloatNat();
    }
    return x;
}

double readDouble(){
    double x;
    printf ("\nInsira um numero: ");
    scanf ("%lf", &x);
    getchar();
    return x;
}

double readDoubleNat(){
    double x=0;
    printf ("\nInsira um numero: ");
    scanf ("%lf", &x);
    getchar();
    if (x<=0){
        printf ("ERRO: numero precisa ser maior que zero\n");
        x=readDoubleNat();
    }
    return x;
}

char readchar(){
    char x;
    printf ("\nInsira um caractere: ");
    scanf ("%c", &x);
    getchar();
    return x;
}


//--Arrays--//

const int MAX_SIZE=100;

int readArrayFsize (char* filename){
    int n;
    FILE *ptr = fopen (filename, "r");
    fscanf(ptr, "%d", &n);
    fclose(ptr);
    return n;
}

void intBuildArray (int option, int length ,int array[]){
	for(int k=0; k<length; k++){
        switch (option){
            case 1: array[k]=k; break;
            case 2: array[k]=length-k; break;
            case 3: array[k]=rand(); break;
            default: array[k]=0; break;
        }
	}
}

void intPrintArray (int length ,int array[]){
	for(int k=0; k<length; k++)
        printf("array[%d]: %d\n", k, array[k]);
}

void intFprintfArray (char filename[], int length, int array[]){
    FILE *arquivo=NULL;

    if (strlen(filename)<=0){
        printf("\nERRO: Nome de arquivo invalido. \n");
    }else{
        FILE *arquivo = fopen (filename, "w");
        
        fprintf(arquivo, "%d\n", length);
        for (int k=0; k<length; k++){
            fprintf(arquivo, "%d\n", array[k]);
        }
        fclose(arquivo);
    }
    printf ("\nNumeros foram gravados no arquivo \"%s\"", filename);
}

void intFscanfArray (char* filename, int length, int array[]){
    int k=0, x=0, n=0;
    FILE *arquivo = fopen (filename, "r");
    
    fscanf(arquivo, "%d", &n);
    if (length>=n){
        while (!feof(arquivo) && k<length){
            fscanf(arquivo, "%d", &array[k]);
            k++;
        }
    }
    fclose(arquivo);
}

void intScanArray (int length ,int array[]){
    int x=0;
	for(int k=0; k<length; k++){
        printf("array[%d]: ", k);
        scanf ("%d", &x);
        array[k]=x;
        getchar();
	}
}

//--praticidade--//

void endF(){
    printf ("\n\nPress ENTER");
    getchar();
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

/* Colar na main

    int opcao;
    do{
        opcao=menu("00");
        switch(opcao){
            case 0: break;
            case 1: Exemplo11(); break;
            case 2: Exemplo12(); break;
            case 3: Exemplo13(); break;
            case 4: Exemplo14(); break;
            case 5: Exemplo15(); break;
            case 6: Exemplo16(); break;
            case 7: Exemplo17(); break;
            case 8: Exemplo18(); break;
            case 9: Exemplo19(); break;
            case 10: Exemplo20(); break;
            case 11: ExemploE1(); break;
            case 12: ExemploE2(); break;
            default: printf ("\nValor Invalido\nPress ENTER"); getchar();
        }
    }while (opcao!=0);
} 
*/