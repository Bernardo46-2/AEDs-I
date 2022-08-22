#include <iostream>

#ifndef _BERNARDO_H_
#define _BERNARDO_H_

#define null nullptr

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
double largest2 (double x, double y)                {if (x<y) x=y; return x;}
double largest3 (double x, double y, double z)      {if (x<y) x=y; if(x<z) x=z; return x;}

int randrange (int a, int b){
    if (a==b)
        return a;
    else if (a<b)
        return (rand()%(b-a)+a);
    else
        return (rand()%(a-b)+b);
}

bool isPrime(int x){
    if (x==0 || x==1 || x==-1)
        return false;
    else if (x>0){
        for (int i=2; i<=x/2; i++)
            if (x%i==0) return false;
    }else if (x<0){
        for (int i=x/2; i<=-2; i++)
            if (x%i==0) return false;
    }
    return true;
}



//--ler valores--//

void flush(){
    while(getchar()!='\n');
}

int readInt(){
    int x;
    std::cout<<"\nDigite um numero: ";
    std::cin>>x;
    flush();
    return x;
}

int readInt(std::string s){
    int x;
    std::cout<<s;
    std::cin>>x;
    flush();
    return x;
}

int readInt(bool includeZero){
    int x;
    std::cout<<"\nDigite um numero: ";
    std::cin>>x;
    flush();
    if(x<=0 && includeZero==false){
        std::cout<<"\nDigite um numero maior que zero!";
        x=readInt(includeZero);
    }else if(x<0 && includeZero==true){
        std::cout<<"\nO numero nao pode ser negativo!";
        x=readInt(includeZero);
    }
    return x;
}

int readInt(std::string s, bool includeZero){
    int x;
    std::cout<<s;
    std::cin>>x;
    flush();
    if(x<=0 && includeZero==false){
        std::cout<<"\nDigite um numero maior que zero!";
        x=readInt(s, includeZero);
    }else if(x<0 && includeZero==true){
        std::cout<<"\nO numero nao pode ser negativo!";
        x=readInt(s, includeZero);
    }
    return x;
}

float readFloat(){
    float x;
    std::cout<<"\nDigite um numero: ";
    std::cin>>x;
    flush();
    return x;
}

float readFloat(std::string s){
    float x;
    std::cout<<s;
    std::cin>>x;
    flush();
    return x;
}

double readDouble(){
    double x;
    std::cout<<"\nDigite um numero: ";
    std::cin>>x;
    flush();
    return x;
}

double readDouble(std::string s){
    double x;
    std::cout<<s;
    std::cin>>x;
    flush();
    return x;
}

double readDouble(bool includeZero){
    double x;
    std::cout<<"\nDigite um numero: ";
    std::cin>>x;
    flush();
    if(x<=0){
        std::cout<<"\nDigite um numero maior que zero!";
        x=readDouble(includeZero);
    }
    return x;
}

double readDouble(std::string s, bool includeZero){
    double x;
    std::cout<<s;
    std::cin>>x;
    flush();
    if(x<=0 && includeZero==false){
        std::cout<<"\nDigite um numero maior que zero!";
        x=readDouble(s, includeZero);
    }else if(x<0 && includeZero==true){
        std::cout<<"\nO numero nao pode ser negativo!";
        x=readDouble(s, includeZero);
    }
    return x;
}

char readChar(){
    char x;
    std::cout<<"\nDigite um caractere: ";
    std::cin>>x;
    flush();
    return x;
}

char readChar(std::string s){
    char x;
    std::cout<<s;
    std::cin>>x;
    flush();
    return x;
}

std::string readString(){
    std::string s;
    std::cout<<"\nDigite uma string: ";
    std::cin>>s;
    flush();
    return s;
}

std::string readString(std::string s){
    std::cout<<s;
    std::cin>>s;
    flush();
    return s;
}

std::string readLine(){
    std::string s;
    std::cout<<"\nDigite uma string: ";
    std::getline(std::cin, s);
    return s;
}


//--strings--//

char upper(char c){
    if('a'<=c && c<='z')
        c-=32;
    return c;
}

char lower(char c){
    if('A'<=c && c<='Z')
        c+=32;
    return c;
}

std::string upper(std::string s){
    for(int i=0; i<s.length(); i++)
        s[i]=upper(s[i]);
    return s;
}

std::string lower(std::string s){
    for(int i=0; i<s.length(); i++)
        s[i]=lower(s[i]);
    return s;
}

std::string cap(std::string s){
    s[0]=upper(s[0]);
    return s;
}

std::string title(std::string s){
    for(int i=0; i<s.length(); i++)
        if(s[i]==' ' && isLetter(s[i+1]))
            s[i+1]=upper(s[i+1]);
    return s;
}

bool in(std::string s1, std::string s2){
    if(s2.length() > 0 && s2.length() <= s1.length())
        for(int i = 0, j = 0; i < s1.length(), j < s2.length(); i++)
            if(s1[i] == s2[j]){
                j++;
                
                if(j == s2.length())
                    return true;
            }

    return false;
}


//--matematica--//

int fac(int x){
    if(x<0){
        printf ("Valor Invalido!\n");
        return fac(readInt());
    }else if(x==0 || x==1)
        return 1;
    else
        return x*fac(x-1);
}

double po(double base, double exponent){
    double result=base;

    if(exponent==0)
        return 1;
    else if(exponent<0){
        exponent*=-1;
        for(int i=0; i<exponent-1; i++)
            result*=base;
        return 1/result;
    }else if(exponent>0)
        for(int i=0; i<exponent-1; i++)
            result*=base;
    
    return result;
}


//--outras funcoes--//

void clear(){
    system("cls||clear");
    //std::cout<<"\e[H\e[2J\e[3J";
}

bool readYN(std::string s){
    std::string opcao;
    std::cout<<std::endl<<s<<std::endl;

    std::cout<<"Digite SIM ou NAO";
    std::cout<<"\n-> ";
    std::cin>>opcao;
    flush();

    if(upper(opcao)=="SIM" || upper(opcao)=="S" || opcao=="1")
        return true;
    else if(upper(opcao)=="NAO" || upper(opcao)=="N" || opcao=="0")
        return false;
    else
        return readYN(s);
}

void introf(std::string ed, std::string ex){
    clear();
    std::cout<<"\n\n--Ed"<<ed<<" - Exemplo"<<ed<<ex<<"--";
    std::cout<<"\nBernardo Marques Fernandes - 774119\n";
}

void endf(){
    std::cout<<"\n\nPress ENTER";
    getchar();
}

bool quit(){
    clear();
    return readYN("\nTem certeza que deseja sair?");
}

int menu(std::string ed){
    clear();
    std::cout<<"\n\n--Ed"<<ed<<"--\n";
    std::cout<<"Bernardo Marques Fernandes - 774119\n";
    std::cout<<"\n0 - parar";
    for (int i=1; i<=12; i++){
        if (i<11) std::cout<<"\n"<<i<<" - Exemplo"<<ed<<i+10;
        else if (i==11) std::cout<<"\n"<<i<<" - Exemplo"<<ed<<"E1";
        else std::cout<<"\n"<<i<<" - Exemplo"<<ed<<"E2";
    }
    int opcao=readInt();
    return opcao;
}


/*

#include "Bernardo.hpp"

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
            default: std::cout<<"\nValor Invalido\nPress ENTER"; getchar();
        }
    }while(sair==false);

    clear();
    return 0;
}
    
*/

#endif