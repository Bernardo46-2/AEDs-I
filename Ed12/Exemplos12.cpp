#include "Bernardo.hpp"
#include "myMatrix.hpp"
#include "io.hpp"

void exemplo01(){
    clear();
    introf("12", "01");

    // definir dados
    Matrix <int> int_matrix ( 2, 2, 0 );
    int_matrix.set ( 0, 0, 1 ); int_matrix.set ( 0, 1, 2 );
    int_matrix.set ( 1, 0, 3 ); int_matrix.set ( 1, 1, 4 );
    
    // identificar
    cout << "\nEXEMPLO1210 - Method01 - v0.0\n" << endl;

    // mostrar dados
    int_matrix.print ( );

    // encerrar
    endf();
}

void exemplo02(){
    clear();
    introf("12", "02");

    // definir dados
    Matrix <int> matrix ( 2, 2, 0 );
    
    // identificar
    cout << endl << "EXEMPLO1210 - Method02 - v0.0" << endl;
    
    // ler dados
    matrix.read ( );
    
    // mostrar dados
    matrix.print ( );

    endf();
}

void exemplo03(){
    clear();
    introf("12", "03");

    // definir dados
    Matrix <int> matrix ( 2, 2, 0 );
    
    // identificar
    cout << endl << "EXEMPLO1210 - Method03 - v0.0" << endl;
    
    // ler dados
    matrix.read ( );
    
    // mostrar dados
    matrix.print ( );
    
    // gravar dados
    matrix.fprint( "MATRIX1.TXT" );

    endf();
}

void exemplo04(){
    clear();
    introf("12", "04");

    // definir dados
    Matrix <int> matrix ( 1, 1, 0 );

    // identificar
    cout << endl << "EXEMPLO1210 - Method04 - v0.0" << endl;

    // ler dados
    matrix.fread ( "MATRIX1.TXT" );

    // mostrar dados
    matrix.print ( );

    endf();
}

void exemplo05(){
    clear();
    introf("12", "05");

    // definir dados
    Matrix <int> int_matrix1 ( 1, 1, 0 );
    Matrix <int> int_matrix2 ( 1, 1, 0 );

    // identificar
    cout << endl << "EXEMPLO1210 - Method05 - v0.0" << endl;

    // ler dados
    int_matrix1.fread ( "MATRIX1.TXT" );

    // mostrar dados
    cout << "\nOriginal\n" << endl;
    int_matrix1.print ( );

    // copiar dados
    int_matrix2 = int_matrix1;

    // mostrar dados
    cout << "\nCopia\n" << endl;
    int_matrix2.print ( );

    endf();
}

void exemplo06(){
    clear();
    introf("12", "06");

    // definir dados
    Matrix <int> int_matrix ( 2, 2, 0 );
    int_matrix.set ( 0, 0, 0 ); int_matrix.set ( 0, 1, 0 );
    int_matrix.set ( 1, 0, 0 ); int_matrix.set ( 1, 1, 0 );
    
    // identificar
    cout << endl << "EXEMPLO1210 - Method06 - v0.0" << endl;
    
    // mostrar dados
    int_matrix.print ( );
    
    // testar condicao
    cout << "Zeros = " << int_matrix.isZeros ( ) << endl;
    
    // ler dados
    int_matrix.fread ( "MATRIX1.TXT" );
    
    // mostrar dados
    int_matrix.print ( );
    
    // testar condicao
    cout << "Zeros = " << int_matrix.isZeros ( ) << endl;

    endf();
}

void exemplo07(){
    clear();
    introf("12", "07");

    // definir dados
    Matrix <int> int_matrix1 ( 1, 1, 0 );
    Matrix <int> int_matrix2 ( 1, 1, 0 );
    
    // identificar
    cout << endl << "EXEMPLO1210 - Method07 - v0.0" << endl;
    
    // ler dados
    
    int_matrix1.fread ( "MATRIX1.TXT" );
    // mostrar dados
    
    cout << "\nMatrix_1\n";
    int_matrix1.print ( );
    
    // copiar dados
    int_matrix2 = int_matrix1;
    
    // mostrar dados
    cout << "\nMatrix_2\n";
    int_matrix2.print ( );
    
    // testar condicao
    cout << "Diferentes = " << (int_matrix1!=int_matrix2) << endl;
    
    // alterar dados
    int_matrix2.set ( 0, 0, (-1) );
    
    // mostrar dados
    cout << "\nMatrix_1\n";
    int_matrix1.print ( );
    
    // mostrar dados
    cout << "\nMatrix_2\n";
    int_matrix2.print ( );
    
    // testar condicao
    cout << "Diferentes = " << (int_matrix1!=int_matrix2) << endl;

    endf();
}

void exemplo08(){
    clear();
    introf("12", "08");

    // definir dados
    Matrix <int> int_matrix1 ( 1, 1, 0 );
    Matrix <int> int_matrix2 ( 1, 1, 0 );
    Matrix <int> int_matrix3 ( 1, 1, 0 );
    
    // identificar
    cout << endl << "EXEMPLO1210 - Method08 - v0.0" << endl;
    
    // ler dados
    int_matrix1.fread ( "MATRIX1.TXT" );
    
    // mostrar dados
    cout << "\nMatrix_1\n";
    int_matrix1.print ( );
    
    // copiar dados
    int_matrix2 = int_matrix1;
    
    // mostrar dados
    cout << "\nMatrix_2\n";
    int_matrix2.print ( );
    
    // operar dados
    int_matrix3 = int_matrix1 - int_matrix2;
    
    // mostrar dados
    cout << "\nMatrix_3\n";
    int_matrix3.print ( );

    endf();
}

void exemplo09(){
    clear();
    introf("12", "09");

    // definir dados
    Matrix <int> int_matrix1 ( 2, 2, 0 );
    int_matrix1.set ( 0, 0, 1 );
    int_matrix1.set ( 0, 1, 0 );
    int_matrix1.set ( 1, 0, 0 );
    int_matrix1.set ( 1, 1, 1 );
    Matrix <int> int_matrix2 ( 1, 1, 0 );
    Matrix <int> int_matrix3 ( 1, 1, 0 );

    // identificar
    cout << endl << "EXEMPLO1210 - Method09 - v0.0" << endl;

    // ler dados
    int_matrix2.fread ( "MATRIX1.TXT" );

    // mostrar dados
    cout << "\nMatrix_1\n";
    int_matrix1.print ( );

    // mostrar dados
    cout << "\nMatrix_2\n";
    int_matrix2.print ( );

    // operar dados
    int_matrix3 = int_matrix1 * int_matrix2;

    // mostrar dados
    cout << "\nMatrix_3\n";
    int_matrix3.print ( );

    endf();
}

void exemplo10(){
    clear();
    introf("12", "10");

    // definir dados
    Matrix <int> int_matrix ( 3, 3, 0 );
    int x = 0;
    int y = 0;

    // identificar
    cout << endl << "EXEMPLO1210 - Method10 - v0.0" << endl;

    // ler dados
    int_matrix.fread ( "MATRIX1.TXT" );

    // mostrar dados
    cout << "\nMatrix\n";
    int_matrix.print ( );

    // operar dados
    for ( int x = 0; x < int_matrix.getRows ( ); x=x+1 ){
        for ( int y = 0; y < int_matrix.getColumns ( ); y=y+1 )
        {
            int_matrix.set ( x, y, int_matrix.get ( x, y ) * (-1) );
        } // end for
    } // end for
    
    // mostrar dados
    cout << "\nMatrix\n";
    int_matrix.print ( );

    endf();
}

int main(){
    int opcao;
    do{
        clear();
        opcao=menu("12");
        switch(opcao){
            case 0: break;
            case 1: exemplo01(); break;
            case 2: exemplo02(); break;
            case 3: exemplo03(); break;
            case 4: exemplo04(); break;
            case 5: exemplo05(); break;
            case 6: exemplo06(); break;
            case 7: exemplo07(); break;
            case 8: exemplo08(); break;
            case 9: exemplo09(); break;
            case 10: exemplo10(); break;
            default: std::cout<<"\nValor Invalido\nPress ENTER"; getchar();
        }
    }while (opcao!=0);

    endf();
    clear();
    return 0;
}