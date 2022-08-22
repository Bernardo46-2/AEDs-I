//Bernardo Marques Fernandes - 774119
//AEDs I - Ed12

#include "Bernardo.hpp"
#include "myMatrix.hpp"
using namespace std;

void exemplo11(){
    introf("12", "11");
    srand(time(0));

    int m=readInt("\nDigite a quantidade de linhas da matriz: ");
    int n=readInt("\nDigite a quantidade de colunas da matriz: ");

    Matrix<int>randMatrix(m, n, 0);
    randMatrix.random();
    randMatrix.print();
    randMatrix.fprint("dados.txt");

    randMatrix.~Matrix();
    endf();
}

void exemplo12(){
    introf("12", "12");

    int x=readInt();

    Matrix<int>matrix;
    matrix.fread("dados.txt");

    matrix.scale(x);
    matrix.print();

    matrix.~Matrix();
    endf();
}

void exemplo13(){
    introf("12", "13");

    Matrix<int>matrix;
    matrix.fread("dados1.txt");
    matrix.print();

    cout<<"A matrix do arquivo "<<(matrix.isIdentity()?"e'":"nao e'")<<" identidade";

    matrix.~Matrix();
    endf();
}

void exemplo14(){
    introf("12", "14");

    Matrix<int>matrix1(1, 1, 0);
    Matrix<int>matrix2(1, 1, 0);
    matrix1.fread("dados1.txt");
    matrix2.fread("dados2.txt");

    cout<<"\nMatrix 1:\n";
    matrix1.print();
    cout<<"\nMatrix 2:\n";
    matrix2.print();

    cout<<"\nAs matrizes "<<((matrix1==matrix2)?"sao'":"nao sao'")<<" iguais";

    matrix1.~Matrix();
    matrix2.~Matrix();
    endf();
}

void exemplo15(){
    introf("12", "15");
    srand(time(0));

    Matrix<int>matrix1(4, 4, 0);
    Matrix<int>matrix2(4, 4, 0);
    Matrix<int>sum;
    matrix1.random();
    matrix2.random();
    sum=matrix1+matrix2;

    cout<<"\nMatrix 1:";
    matrix1.print();
    cout<<"\nMatrix 2:";
    matrix2.print();
    cout<<"\nSoma:";
    sum.print();

    //matrix1.~Matrix();
    //matrix2.~Matrix();
    //sum.~Matrix();
    endf();
}

void exemplo16(){
    introf("12", "16");
    srand(time(0));

    int row1;
    int row2;
    Matrix<int>matrix(4, 4, 0);
    matrix.random();

    cout<<"\nMatrix:";
    matrix.print();

    do{
        row1=readIntNat("\nDigite uma linha para somar: ", true);
        row2=readIntNat("\nDigite outra linha: ", true);
        
        if(row1>=matrix.getRows() || row2>=matrix.getRows()){
            cout<<"\nValores sao maiores do que o numero de linhas da matrix"<<endl;
        }
    }while(row1>=matrix.getRows() || row2>=matrix.getRows());

    matrix.sumRows(row1, row2, readInt());
    cout<<"\nSoma das linhas:";
    matrix.print();

    matrix.~Matrix();
    endf();
}

void exemplo17(){
    introf("12", "17");
    srand(time(0));

    int column1;
    int column2;
    Matrix<int>matrix(4, 4, 0);
    matrix.random();

    cout<<"\nMatrix:";
    matrix.print();

    do{
        column1=readIntNat("\nDigite uma coluna para subtrair: ", true);
        column2=readIntNat("\nDigite outra coluna: ", true);
        
        if(column1>=matrix.getColumns() || column2>=matrix.getColumns()){
            cout<<"\nValores sao maiores do que o numero de colunas da matrix"<<endl;
        }
    }while(column1>=matrix.getColumns() || column2>=matrix.getColumns());

    matrix.subColumns(column1, column2, readInt());
    cout<<"\nDiferenca das colunas:";
    matrix.print();

    matrix.~Matrix();
    endf();
}

void exemplo18(){
    introf("12", "18");
    srand(time(0));

    Matrix<int>matrix(4, 4, 0);
    matrix.random();

    if(readYN("Imprimir matriz?"))
        matrix.print();

    int x=readInt("\nDigite um numero a ser procurado: ");
    int row=matrix.findRow(x);

    if(row==-1)
        cout<<"\nO numero nao esta na matrix";
    else
        cout<<"\nO numero esta na linha "<<row;

    matrix.~Matrix();
    endf();
}

void exemplo19(){
    introf("12", "19");
    srand(time(0));

    Matrix<int>matrix(4, 4, 0);
    matrix.random();

    if(readYN("Imprimir matriz?"))
        matrix.print();

    int x=readInt("\nDigite um numero a ser procurado: ");
    int column=matrix.findColumn(x);

    if(column==-1)
        cout<<"\nO numero nao esta na matrix";
    else
        cout<<"\nO numero esta na coluna "<<column;

    matrix.~Matrix();
    endf();
}

void exemplo20(){
    introf("12", "20");
    srand(time(0));

    Matrix<int>matrix(4, 2, 0);
    
    cout<<"\nMatrix original:";
    matrix.random();
    matrix.print();

    cout<<"\nMatrix transposta:";
    matrix.transpor();
    matrix.print();

    matrix.~Matrix();
    endf();
}

void exemploE1(){
    introf("12", "E1");

    Matrix<int>matrix;
    matrix.fread("exemploE1.txt");
    matrix.print();

    cout<<"\nA matrix "<<(matrix.exE1()?"segue":"nao segue")<<" os criterios do exemploE1";

    matrix.~Matrix();
    endf();
}

void exemploE2(){
    introf("12", "E2");

    Matrix<int>matrix;
    matrix.fread("exemploE2.txt");
    matrix.print();

    cout<<"\nA matrix "<<(matrix.exE2()?"segue":"nao segue")<<" os criterios do exemploE2";

    matrix.~Matrix();
    endf();
}

int main(){
    int opcao;
    bool sair=false;
    
    do{
        opcao=menu("12");
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