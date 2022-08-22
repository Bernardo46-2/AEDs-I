#include "Bernardo.hpp"
#include "myMatrix.hpp"

int main(){
    clear();
    srand(time(0));
    Matrix<int>matrix1(3, 3, 0);
    Matrix<int>matrix2(3, 3, 0);
    Matrix<int>soma(3, 3, 0);

    matrix1.random();
    matrix2.random();
    soma=soma.somar(matrix1, matrix2);

    matrix1.print();
    matrix2.print();
    soma.print();

    endf();
    return 0;
}