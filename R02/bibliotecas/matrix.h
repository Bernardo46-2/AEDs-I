#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef
    struct s_intMatrix{
        int rows;
        int columns;
        int** data;
    }intMatrix;


intMatrix* initMatrix(int n, int r, int c);
intMatrix* freadMatrix(char* filename);
bool matrixSize(intMatrix* matrix);
bool matrixData(intMatrix* matrix);
bool correctMatrix(intMatrix* matrix);
bool squareMatrix(intMatrix* matrix);
void fillMatrix(int n, intMatrix* matrix);
void freeMatrix(intMatrix* matrix);
void printMatrix(intMatrix* matrix);
void fprintMatrix(char* filename, intMatrix* matrix);
void crescentTridiagonal(intMatrix* matrix);


//iniciar matriz
intMatrix* initMatrix(int n, int r, int c){
    intMatrix* matrix=(intMatrix*)malloc(sizeof(intMatrix));
    matrix->rows=r;
    matrix->columns=c;

    if(!matrix || !matrixSize(matrix))
        printf("\nErro ao alocar memoria");
    else{
        matrix->data=(int**)malloc(matrix->rows*sizeof(int*));

        if(!matrix->data)
            printf("\nErro ao alocar memoria");
        else{
            for(int i=0; i<matrix->rows; i++)
                matrix->data[i]=newIntArray(matrix->columns);

            if(!matrixData(matrix))
                printf("\nErro ao alocar memoria");
            else
                fillMatrix(n, matrix);
        }
    }
    return matrix;
}


//liberar matriz
void freeMatrix(intMatrix* matrix){
    if(matrix){
        if(matrixData(matrix)){
            for(int i=0; i<matrix->rows; i++)
                if(matrix->data[i])
                    free(matrix->data[i]);
            free(matrix->data);
        }
        free(matrix);
    }
}


//verificar se as dimensoes estao corretas
bool matrixSize(intMatrix* matrix){
    return (matrix->rows>0 && matrix->columns>0);
}


//verificar se ha espaco
bool matrixData(intMatrix* matrix){
    if(!matrix->data)
        return false;

    if(matrixSize(matrix))
        for(int i=0; i<matrix->rows; i++)
            if(!matrix->data[i])
                return false;

    return true;
}


//verificar se a matrix esta correta
bool correctMatrix(intMatrix* matrix){
    return matrixSize(matrix) && matrixData(matrix);
}


//verificar se a matrix é quadrada
bool squareMatrix(intMatrix* matrix){
    return correctMatrix(matrix) && matrix->rows==matrix->columns;
}


//preencher matrix com um numero N
void fillMatrix(int n, intMatrix* matrix){
    if(correctMatrix(matrix))
        for(int i=0; i<matrix->rows; i++)
            for(int j=0; j<matrix->columns; j++)
                matrix->data[i][j]=n;
}


//printar matriz
void printMatrix(intMatrix* matrix){
    if(correctMatrix(matrix)){
        printf("\n\n");

        for(int i=0; i<matrix->rows; i++){
            for(int j=0; j<matrix->columns; j++)
                printf("\t%d", matrix->data[i][j]);
            printf("\n");
        }
    }
}


//gravar matriz no arquivo
void fprintMatrix(char* filename, intMatrix* matrix){
    if(correctMatrix(matrix)){
        FILE* file=fopen(filename, "w");

        fprintf(file, "%d\n", matrix->rows);
        fprintf(file, "%d\n", matrix->columns);

        for(int i=0; i<matrix->rows; i++)
            for(int j=0; j<matrix->columns; j++)
                fprintf(file, "%d\n", matrix->data[i][j]);

        fclose(file);
    }
}


//ler matriz do arquivo
intMatrix* freadMatrix(char* filename){
    intMatrix* matrix;
    FILE* file=fopen(filename, "r");

    if(!file)
        printf("\nERRO: arquivo nao encontrado");
    else{
        int r, c;

        fscanf(file, "%d", &r);
        fscanf(file, "%d", &c);

        matrix=initMatrix(0, r, c);

        for(int i=0; !feof(file) && i<matrix->rows; i++)
            for(int j=0; !feof(file) && j<matrix->columns; j++)
                fscanf(file, "%d", &matrix->data[i][j]);

        fclose(file);
    }
    return matrix;
}


//gerar matriz com tridiagonal crescente
void crescentTridiagonal(intMatrix* matrix){
    if(squareMatrix(matrix)){
        int n=0;

        for(int i=0; i<matrix->rows; i++)
            for(int j=0; j<matrix->columns; j++)
                if(i-1<=j && j<=i+1){
                    n++;
                    matrix->data[i][j]=n;
                }else
                    matrix->data[i][j]=0;
    }
}

//gerar matriz com tridiagonal decrescente
void decrescentTridiagonal(intMatrix* matrix){
    if(squareMatrix(matrix)){
        int n=((matrix->columns-2)*3)+4;

        for(int i=0; i<matrix->rows; i++)
            for(int j=0; j<matrix->columns; j++)
                if(i-1<=j && j<=i+1){
                    matrix->data[j][i]=n;
                    n--;
                }else
                    matrix->data[j][i]=0;
    }
}

//verificar se possui caracteristica potencia por linha
bool powerPerRow(intMatrix* matrix){
    if(!correctMatrix(matrix))
        return false;

    for(int i=0; i<matrix->rows; i++)
        for(int j=0; j<matrix->columns; j++)
            if(matrix->data[i][j]!=(int)po(i+1, j))
                return false;

    return true;
}

//verificar se possui caracteristica potencia por coluna
bool powerPerColumn(intMatrix* matrix){
    if(!correctMatrix(matrix))
        return false;

    for(int i=0; i<matrix->rows; i++)
        for(int j=0; j<matrix->columns; j++)
            if(matrix->data[j][i]!=(int)po(i+1, j))
                return false;

    return true;
}