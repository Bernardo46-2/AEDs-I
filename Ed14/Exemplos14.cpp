#include <iostream>
using std::cin ;
using std::cout;
using std::endl;
#include <iomanip>
using std::setw;
#include <string>
using std::string;
#include <fstream>
using std::ofstream;
using std::ifstream;

void pause ( std::string text )
{
    std::string dummy;
    std::cin.clear ( );
    std::cout << std::endl << text;
    std::cin.ignore( );
    std::getline(std::cin, dummy);
    std::cout << std::endl << std::endl;
}

#include "bibliotecas/Erro.hpp"

class MyString : public Erro
{
    public:
    /**
     * Funcao para obter mensagem
     * relativa ao código de erro.
     * @return mensagem sobre o erro
     */
    std::string getErroMsg ( )
    {
       return getErroMsg();
    } 
};


using namespace std;


/**
 Method00 - nao faz nada.
*/
void method00 ( )
{
    
}

/**
 Method01 - Testar definicoes da classe.
*/
void method01 ( )
{
    MyString *s = new MyString ( );
    
    cout << "\nEXEMPLO1401 - Method01 - v0.0\n" << endl;
    
    pause ( "Apertar ENTER para continuar" );
}

/*
 Funcao principal.
 @return codigo de encerramento
*/
int main ( int argc, char** argv )
{
    int x = 0;
    
    do
    {
        cout << "EXEMPLO1401 - Programa - v0.0\n " << endl;
    
        cout << "Opcoes " << endl;
        cout << " 0 - parar " << endl;
        cout << " 1 - testar definicoes " << endl;
    
        cout << endl << "Entrar com uma opcao: ";
        cin >> x;
    
        switch ( x )
        {
            case 0:
            method00 ( );
            break;
            case 1:
            method01 ( );
            break;
            default:
            cout << endl << "ERRO: Valor invalido." << endl;
        }
    }
    while ( x != 0 );
    
    pause ( "Apertar ENTER para terminar" );
    return ( 0 );
}