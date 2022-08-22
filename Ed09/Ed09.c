//Bernardo Marques Fernandes - 774119
//Ed09

#include "Bernardo.h"
#include "arraysNmatrixes.h"

void exemplo11(){
    printf ("\n\n--Exemplo0911--\n");

    printf ("\nQuantidade de linhas da matriz");
    int a=readIntNat();
    printf ("\nQuantidade de colunas da matriz");
    int b=readIntNat();
    double positiveMatrix[a][b];

    printf ("\n");
    doubleScanPositiveMatrix (a, b, positiveMatrix);
    doublePrintMatrix (a, b, positiveMatrix);

    endf();
}

void exemplo12(){
    printf ("\n\n--Exemplo0912--\n");

    printf ("\nQuantidade de linhas da matriz");
    int a=readIntNat();
    printf ("\nQuantidade de colunas da matriz");
    int b=readIntNat();
    double positiveMatrix[a][b];

    printf ("\n");
    doubleScanPositiveMatrix (a, b, positiveMatrix);
    doubleFprintfMatrix ("matrix01.txt", a, b, positiveMatrix);
    endf();
    printf ("\nEsvaziar matriz:\n");
    doubleBuildMatrix (0, a, b, positiveMatrix); //esvaziar matriz antes de ler no arquivo
    doublePrintMatrix (a, b, positiveMatrix);
    endf();
    printf ("\nMatriz lida do arquivo:\n");
    doubleFscanfMatrix ("matrix01.txt", a, b, positiveMatrix);
    doublePrintMatrix (a, b, positiveMatrix);

    endf();
}

void exemplo13(){
    printf ("\n\n--Exemplo0913--\n");

    printf ("\nQuantidade de linhas e colunas da matriz");
    int a=readIntNat();
    double positiveMatrix[a][a];

    printf ("\n");
    doubleScanPositiveMatrix (a, a, positiveMatrix);
    printf ("\nDiagonal:\n");
    printDiagonalPositiveMatrix (a, a, positiveMatrix);

    endf();
}

void exemplo14(){
    printf ("\n\n--Exemplo0914--\n");

    printf ("\nQuantidade de linhas e colunas da matriz");
    int a=readIntNat();
    double positiveMatrix[a][a];

    printf ("\n");
    doubleScanPositiveMatrix (a, a, positiveMatrix);
    printf ("\nDiagonal:\n");
    printSDiagonalPositiveMatrix (a, a, positiveMatrix);

    endf();
}

void exemplo15(){
    printf ("\n\n--Exemplo0915--\n");
    
    printf ("\nQuantidade de linhas e colunas da matriz");
    int a=readIntNat();
    double positiveMatrix[a][a];

    printf ("\n");
    doubleScanPositiveMatrix (a, a, positiveMatrix);
    printf ("\nDiagonal:\n");
    printLDiagonalTriangleDoubleMatrix (a, a, positiveMatrix);

    endf();
}

void exemplo16(){
    printf ("\n\n--Exemplo0916--\n");

    printf ("\nQuantidade de linhas e colunas da matriz");
    int a=readIntNat();
    double positiveMatrix[a][a];

    printf ("\n");
    doubleScanPositiveMatrix (a, a, positiveMatrix);
    printf ("\nDiagonal:\n");
    printUDiagonalTriangleDoubleMatrix (a, a, positiveMatrix);

    endf();
}

void exemplo17(){
    printf ("\n\n--Exemplo0917--\n");

    printf ("\nQuantidade de linhas e colunas da matriz");
    int a=readIntNat();
    double positiveMatrix[a][a];

    printf ("\n");
    doubleScanPositiveMatrix (a, a, positiveMatrix);
    printf ("\nDiagonal:\n");
    printSLDTriangleDoubleMatrix (a, a, positiveMatrix);

    endf();
}

void exemplo18(){
    printf ("\n\n--Exemplo0918--\n");

    printf ("\nQuantidade de linhas e colunas da matriz");
    int a=readIntNat();
    double positiveMatrix[a][a];

    printf ("\n");
    doubleScanPositiveMatrix (a, a, positiveMatrix);
    printf ("\nDiagonal:\n");
    printSLUTriangleDoubleMatrix (a, a, positiveMatrix);

    endf();
}

void exemplo19(){
    printf ("\n\n--Exemplo0919--\n");

    printf ("\nQuantidade de linhas e colunas da matriz");
    int a=readIntNat();
    double positiveMatrix[a][a];

    printf ("\n");
    doubleScanPositiveMatrix (a, a, positiveMatrix);
    printf ("\nA matriz inserida possui %s abaixo e na diagonal principal", allZerosLTriangleDoubleMatrix (a, a, positiveMatrix)?"apenas zeros":"numeros diferentes de zero");
    
    endf();
}

void exemplo20(){
    printf ("\n\n--Exemplo0920--\n");

    printf ("\nQuantidade de linhas e colunas da matriz");
    int a=readIntNat();
    double positiveMatrix[a][a];

    printf ("\n");
    doubleScanPositiveMatrix (a, a, positiveMatrix);
    printf ("\nA matriz inserida possui %s acima e na diagonal principal", allZerosUTriangleDoubleMatrix (a, a, positiveMatrix)?"apenas zeros":"numeros diferentes de zero");
    
    endf();
}

void exemploE1(){
    printf ("\n\n--Exemplo09E1--\n");

    printf ("\nQuantidade de linhas da matriz");
    int a=readIntNat();
    printf ("\nQuantidade de colunas da matriz");
    int b=readIntNat();
    double positiveMatrix[a][a];

    doubleBuildMatrix (2, a, b, positiveMatrix);
    printf ("\nMatriz:");
    doublePrintMatrix (a, b, positiveMatrix);
    endf();
    doubleFprintfMatrix ("Exemplo09E1.txt", a, b, positiveMatrix);

    endf();
}

void exemploE2(){
    printf ("\n\n--Exemplo09E2--\n");

    printf ("\nQuantidade de linhas da matriz");
    int a=readIntNat();
    printf ("\nQuantidade de colunas da matriz");
    int b=readIntNat();
    double positiveMatrix[a][a];

    doubleBuildMatrix09E2 (a, b, positiveMatrix);
    printf ("\nMatriz:");
    doublePrintMatrix (a, b, positiveMatrix);
    endf();
    doubleFprintfMatrix ("Exemplo09E2.txt", a, b, positiveMatrix);

    endf();
}

int main(){
    int opcao;

    do{
        opcao=menu("09");
        switch(opcao){
            case 0: break;
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
    }while (opcao!=0);

    endf();
    return 0;
}