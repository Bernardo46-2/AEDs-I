/*
 Exemplo1301 - v0.0. - __ / __ / _____
 Author: ________________________
*/

// ----------------------------------------------- classes
#include "Contato.hpp" // classe para tratar dados de pessoas

// ----------------------------------------------- definicoes globais
using namespace std;

// ----------------------------------------------- metodos
/**
 Method00 - nao faz nada.
*/
void method00 ( )
{
    // nao faz nada
} // fim method00 ( )

/**
 Method01 - Testar definicoes da classe.
*/
void method01 ( )
{
    system("cls");
    // definir dados
    Contato pessoa1;
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato ( );

    // identificar
    cout << "\nEXEMPLO1301 - Method01 - v0.0\n" << endl;

    // encerrar
    pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )

/**
 Method02 - Testar atribuicoes.
*/
void method02 ( )
{
    system("cls");
    // definir dados
    Contato pessoa1;
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato ( );

    // identificar
    cout << "\nEXEMPLO1302 - Method02 - v0.0\n" << endl;

    // testar atribuicoes
    pessoa1.setName ( "Pessoa_01" );
    pessoa1.setFone ( "111" );
    pessoa3->setName ( "Pessoa_03" );
    pessoa3->setFone ( "333" );
    cout << "pessoa1 - { " << pessoa1.getNome ( ) << ", " << pessoa1.getFone ( ) << " }" << endl;
    cout << "pessoa3 - { " << pessoa3->getNome ( ) << ", " << pessoa3->getFone ( ) << " }" << endl;

    // encerrar
    pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )

/**
 Method03 - Testar recuperacao de dados.
*/
void method03 ( )
{
    system("cls");
    // definir dados
    Contato pessoa1;
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato ( );
    
    // identificar
    cout << "\nEXEMPLO1303 - Method03 - v0.0\n" << endl;
    
    // testar atribuicoes
    pessoa1.setName ( "Pessoa_01" );
    pessoa1.setFone ( "111" );
    pessoa3->setName ( "Pessoa_03" );
    pessoa3->setFone ( "333" );
    cout << "pessoa1 - " << pessoa1.toString ( ) << endl;
    cout << "pessoa3 - " << pessoa3->toString ( ) << endl;
    
    // encerrar
    pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )

/**
 Method04 - Testar construtor alternativo.
*/
void method04 ( )
{
    system("cls");
    // definir dados
    Contato pessoa1 ( "Pessoa_01", "111" );
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato ( "Pessoa_03", "333" );

    // identificar
    cout << "\nEXEMPLO1304 - Method04 - v0.0\n" << endl;

    // testar atribuicoes
    cout << "pessoa1 - " << pessoa1.toString ( ) << endl;
    cout << "pessoa3 - " << pessoa3->toString ( ) << endl;

    // encerrar
    pause ( "Apertar ENTER para continuar" );
} // fim method04 ( )

/**
 Method05 - Testar construtor alternativo.
*/
void method05 ( )
{
    system("cls");
    // definir dados
    Contato pessoa1 ( "Pessoa_01", "111" );
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato ( "", "333" );

    // identificar
    cout << "\nEXEMPLO1305 - Method05 - v0.0\n" << endl;

    // testar atribuicoes
    cout << "pessoa1 - " << pessoa1.toString ( ) << " (" << pessoa1.getError( ) << ")" << endl;
    cout << "pessoa3 - " << pessoa3->toString ( ) << " (" << pessoa3->getError( ) << ")" << endl;

    // encerrar
    pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )

/**
 Method06 - Testar construtor alternativo.
*/
void method06 ( )
{
    system("cls");
    // definir dados
    Contato pessoa1 ( "Pessoa_01", "111" );
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato ( "", "333" );

    // identificar
    cout << "\nEXEMPLO1306 - Method06 - v0.0\n" << endl;

    // testar atribuicoes
    if ( ! pessoa1.hasError( ) )
        cout << "pessoa1 - " << pessoa1.toString( ) << endl;
    else
        cout << "pessoa1 tem erro (" << pessoa1.getError( ) << ")" << endl;
    if ( ! pessoa3->hasError( ) )
        cout << "pessoa3 - " << pessoa3->toString( ) << endl;
    else
        cout << "pessoa3 tem erro (" << pessoa3->getError( ) << ")" << endl;

    // encerrar
    pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )

/**
 Method07 - Testar atribuicoes e tratamento de erro.
*/
void method07 ( )
{
    system("cls");
    // definir dados
    Contato pessoa1 ( "Pessoa_01", "111" );
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato ( "", "333" );
    
    // identificar
    cout << "\nEXEMPLO1307 - Method07 - v0.0\n" << endl;
    
    // testar atribuicoes
    pessoa2 = &pessoa1; // copiar endereco de objeto
    if ( ! pessoa2->hasError( ) )
        cout << "pessoa1 - " << pessoa2->toString( ) << endl;
    else
        cout << "pessoa1 tem erro (" << pessoa2->getError( ) << ")" << endl;

    pessoa2 = pessoa3; // vincular-se a outro objeto
    if ( ! pessoa2->hasError( ) )
        cout << "pessoa3 - " << pessoa2->toString( ) << endl;
    else
        cout << "pessoa3 tem erro (" << pessoa2->getError( ) << ")" << endl;

    // encerrar
    pause("Apertar ENTER para continuar");
} // fim method07 ( )

/**
 Method08 - Testar atribuicoes e tratamento de erro.
*/
void method08 ( )
{
    system("cls");
    // definir dados
    Contato pessoa1 ( "Pessoa_01", "111" );
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato ( "", "333" );
    ref_Contato pessoa4 = nullptr;
    
    // identificar
    cout << "\nEXEMPLO1308 - Method08 - v0.0\n" << endl;
    
    // testar atribuicoes
    pessoa2 = new Contato ( pessoa1 );

    if ( pessoa2 )
        cout << "pessoa2 - " << pessoa2->toString( ) << endl;
    else
        cout << "pessoa2 tem erro (" << pessoa2->getError( ) << ")" << endl;
    
    if ( pessoa3 ) // o teste de existencia deve ser feito previamente
    {
        pessoa2 = new Contato ( *pessoa3 );
        if ( pessoa2 )
            cout << "pessoa2 - " << pessoa2->toString( ) << endl;
        else
            cout << "pessoa2 tem erro (" << pessoa3->getError( ) << ")" << endl;
    } // fim se
    
    if ( pessoa4 ) // o teste de existencia deve ser feito previamente
    {
        pessoa2 = new Contato ( *pessoa4 );
        if ( pessoa2 )
            cout << "pessoa2 - " << pessoa2->toString( ) << endl;
        else
            cout << "pessoa2 tem erro (" << pessoa4->getError( ) << ")" << endl;
    } // fim se
    
    // encerrar
    pause ( "Apertar ENTER para continuar" );
} // fim method08 ( )

/**
 Method09 - Testar arranjo de objetos (1).
*/
void method09 ( )
{
    system("cls");
    // definir dados
    Contato pessoa [ 3 ];
    int x = 0;
    
    // identificar
    cout << "\nEXEMPLO1309 - Method09 - v0.0\n" << endl;
    
    // testar atribuicoes
    pessoa [ 0 ].setName ( "Pessoa_1" );
    pessoa [ 0 ].setFone ( "111" );
    pessoa [ 1 ].setName ( "Pessoa_2" );
    pessoa [ 1 ].setFone ( "222" );
    pessoa [ 2 ].setName ( "Pessoa_3" );
    pessoa [ 2 ].setFone ( "333" );
    
    for ( x=0; x < 3; x=x+1 )
    {
        cout << x << " : " << pessoa[ x ].toString( ) << endl;
    } // fim repetir

    // encerrar
    pause ( "Apertar ENTER para continuar" );
} // fim method09 ( )

/**
 Method10 - Testar arranjo de referencias para objetos (2).
*/
void method10 ( )
{
    system("cls");
    // definir dados
    Contato *pessoa [ 3 ];
    int x = 0;

    // identificar
    cout << "\nEXEMPLO1310 - Method10 - v0.0\n" << endl;

    // testar atribuicoes
    pessoa [ 0 ] = new Contato ( "Pessoa_1", "111" );
    pessoa [ 1 ] = new Contato ( "Pessoa_2", "222" );
    pessoa [ 2 ] = new Contato ( "Pessoa_3", "333" );
    
    for ( x=0; x < 3; x=x+1 )
    {
        cout << x << " : " << pessoa[ x ]->toString( ) << endl;
    } // fim repetir
    
    // encerrar
    pause ( "Apertar ENTER para continuar" );
} // fim method10 ( )


// ----------------------------------------------- acao principal
/*
 Funcao principal.
 @return codigo de encerramento
*/
int main ( int argc, char** argv )
{
    // definir dado
    int x = 0; // definir variavel com valor inicial
    
    // repetir até desejar parar
    do
    {
        system("cls");
        // identificar
        cout << "EXEMPLO1301 - Programa - v0.0\n " << endl;
    
        // mostrar opcoes
        cout << "Opcoes " << endl;
        cout << " 0 - parar " << endl;
        cout << " 1 - method 1" << endl;
        cout << " 2 - method 2 " << endl;
        cout << " 3 - method 3 " << endl;
        cout << " 4 - method 4 " << endl;
        cout << " 5 - method 5 " << endl;
        cout << " 6 - method 6 " << endl;
        cout << " 7 - method 7 " << endl;
        cout << " 8 - method 8 " << endl;
        cout << " 9 - method 9 " << endl;
        cout << " 10 - method 10 " << endl;
    
        // ler do teclado
        cout << endl << "Entrar com uma opcao: ";
        cin >> x;
    
        // escolher acao
        switch ( x )
        {
            case 0: method00(); break;
            case 1: method01(); break;
            case 2: method02(); break;
            case 3: method03(); break;
            case 4: method04(); break;
            case 5: method05(); break;
            case 6: method06(); break;
            case 7: method07(); break;
            case 8: method08(); break;
            case 9: method09(); break;
            case 10: method10(); break;
            default: cout << endl << "ERRO: Valor invalido." << endl;
        } // fim escolher
    }
    while ( x != 0 );
    
    // encerrar
    pause ( "Apertar ENTER para terminar" );
    return ( 0 );
} // fim main( )