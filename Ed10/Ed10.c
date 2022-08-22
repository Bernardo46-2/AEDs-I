//Bernardo Marques Fernandes - 774119
//AEDs I - Ed10

#include "Bernardo.h"


//--Arranjos--//

typedef
    struct s_ed10Array{
        int length;
        int* data;
        int x;
    }array10;

void freeArray(array10* array){
    if(array!=null){
        if(array->data!=null){
            free(array->data);
        }
        free(array);
    }
}

/* array10* newIntArray(){
    array10* array = (array10*) malloc (sizeof(array10));

    if (array==NULL){
        printf ("\nSem espaco!");
    }else{
        array->length=readQuantity();
        array->x=0;
        array->data=(int*) malloc (array->length*sizeof(int));
    }
    return array;
} */

void fprintArray(char* filename, array10 array){
    FILE* arquivo = fopen(filename, "w");

    fprintf (arquivo, "%d\n", array.length);
    if(array.data){
        for (array.x=0; array.x<array.length; array.x++)
            fprintf (arquivo, "%d\n", array.data[array.x]);
    }

    printf ("\nNumeros foram gravados no arquivo \"%s\"", filename);
    fclose(arquivo);
}

void exemplo11(){
    printf ("\n\n--Exemplo1011--\n");

    array10 array;
    array.length=readQuantity();
    array.data=(int*) malloc(array.length*sizeof(int));

    if(array.data){
        printf ("\nLimite inferior do intervalo");
        int a=readInt();
        printf ("\nLimite superior do intervalo");
        int b=readInt();

        for (array.x=0; array.x<array.length; array.x++){
            array.data[array.x]=randInt(a, b);
        }
        
        fprintArray("dados.txt", array);
        free(array.data);
    }

    endf();
}

array10 fscanArray(char* filename){
    FILE* arquivo = fopen(filename, "r");
    array10 array;

    if(arquivo){
        fscanf(arquivo, "%d", &array.length);
        if(array.length<=0){
            printf("\nErro: tamanho do vetor invalido!");
        }else{
            array.data=intArray(array.length);

            if(array.length){
                array.x=0;

                while(!feof(arquivo) && array.x<array.length){
                    fscanf(arquivo, "%d", &array.data[array.x]);
                    array.x++;
                }
            }
        }
    }
    return array;
}

int procurar(array10 array, int n){
    for (array.x=0; array.x<array.length; array.x++)
        if(array.data[array.x]==n)
            return array.x;
    return -1;
}

void exemplo12(){
    printf ("\n\n--Exemplo1012--\n");

    array10 array=fscanArray("dados.txt");
    
    printf("\nNumero para ser procurado");
    int n=readInt();
    
    int posicao=procurar(array, n);
    if(posicao==-1)
        printf("\nO numero %d nao foi encontrado", n);
    else
        printf("\nO numero %d foi encontrado e esta na posicao [%d]", n, posicao);

    if(array.data)
        free(array.data);

    endf();
}

bool comparar(array10 array1, array10 array2){
    if (array1.length!=array2.length)
        return false;
    
    for (array1.x=0; array1.x<array1.length; array1.x++)
        if (array1.data[array1.x]!=array2.data[array1.x])
            return false;

    return true;
}

void exemplo13(){
    printf ("\n\n--Exemplo1013--\n");

    array10 array1=fscanArray("dados1.txt");
    array10 array2=fscanArray("dados2.txt");

    printf ("\narray1 e array2 %s", comparar(array1, array2)?"sao iguais":"nao sao iguais");

    if (array1.data)
        free(array1.data);
    if (array2.data)
        free(array2.data);

    endf();
}

array10 somar (array10 array1, array10 array2){
    array10 soma;
    soma.length=array1.length;
    soma.data=intArray(soma.length);

    for(soma.x=0; soma.x<soma.length; soma.x++)
        soma.data[soma.x]=array1.data[soma.x]+array2.data[soma.x];

    return soma;
}

void printArray(array10 array){
    if(array.data)
        for(array.x=0; array.x<array.length; array.x++)
            printf("\narray[%d] = %d", array.x, array.data[array.x]);
}

void exemplo14(){
    printf ("\n\n--Exemplo1014--\n");

    array10 array1=fscanArray("dados1.txt");
    array10 array2=fscanArray("dados2.txt");
    array10 soma;

    if (array1.length!=array2.length)
        printf ("\nArrays tem tamanho diferente");
    else{
        soma=somar(array1, array2);
    }
    printf("\nArray 1:");
    printArray(array1);
    printf("\n\nArray 2:");
    printArray(array2);
    printf("\n\nSoma dos arrays:");
    printArray(soma);

    if (array1.data)
        free(array1.data);
    if (array2.data)
        free(array2.data);
    if (soma.data)
        free(soma.data);

    endf();
}

bool crescente(array10 array){
    if(array.data)
        for(array.x=0; array.x<array.length-1; array.x++)
            if(array.data[array.x]>array.data[array.x+1])
                return false;
    return true;
}

void exemplo15(){
    printf ("\n\n--Exemplo1015--\n");

    array10 array=fscanArray("exemplo15.txt");

    printf("\nO array %s na ordem crescente", crescente(array)?"esta":"nao esta");

    if(array.data)
        free(array.data);

    endf();
}


//--Matrizes--//

typedef
    struct s_ed10Matrix{
        int rows;
        int columns;
        int** data;
        int x;
        int y;
    }matrix10;

void freeMatrix(matrix10* matrix){
    if(matrix!=null){
        if(matrix->data!=null){
            for(matrix->x=0; matrix->x<matrix->rows; matrix->x++)
                free(matrix->data[matrix->x]);
            free(matrix->data);
        }
        free(matrix);
    }
}

matrix10* newMatrix(int rows, int columns){
    matrix10* matrix=(matrix10*)malloc(sizeof(matrix10));

    if(matrix!=null){
        matrix->rows=0;
        matrix->columns=0;
        matrix->data=null;

        if(rows>0 && columns>0){
            matrix->rows=rows;
            matrix->columns=columns;
            matrix->data=malloc(rows*sizeof(int*));

            if(matrix->data)
                for(matrix->x=0; matrix->x<matrix->rows; matrix->x++)
                    matrix->data[matrix->x]=malloc(columns*sizeof(int));
        }
        matrix->x=0;
        matrix->y=0;
    }
    return matrix;
}

void printMatrix(matrix10* matrix){
    if(matrix!=null && matrix->data!=null){
        for(matrix->x=0; matrix->x<matrix->rows; matrix->x++){
            for(matrix->y=0; matrix->y<matrix->columns; matrix->y++)
                printf("\nmatrix[%d][%d] = %d", matrix->x, matrix->y, matrix->data[matrix->x][matrix->y]);
            printf("\n");
        }
    }
}

void fprintMatrix(char* filename, matrix10* matrix){
    FILE* arquivo=fopen(filename, "w");

    if(matrix==null){
        printf("\nERRO: nao ha dados");
        return;
    }
    if(arquivo){
        fprintf(arquivo, "%d", matrix->rows);
        fprintf(arquivo, "\n%d", matrix->columns);

        if(matrix->data!=null)
            for(matrix->x=0; matrix->x<matrix->rows; matrix->x++)
                for(matrix->y=0; matrix->y<matrix->columns; matrix->y++)
                    fprintf(arquivo, "\n%d", matrix->data[matrix->x][matrix->y]);
        fclose(arquivo);
    }
}

matrix10* fscanMatrix(char* filename){
    matrix10* matrix=null;
    int rows=0;
    int columns=0;
    FILE* arquivo=fopen(filename, "r");

    fscanf(arquivo, "%d", &rows);
    fscanf(arquivo, "%d", &columns);
    if(rows<=0 || columns<=0){
        printf("\nERRO: tamanho invalido");
    }else{
        matrix=newMatrix(rows, columns);

        if(matrix!=null && matrix->data==null){
            matrix->rows=0;
            matrix->columns=0;
            matrix->x=0;
            matrix->y=0;
        }else{
            if(matrix!=null){
                matrix->x=0;
                while(!feof(arquivo) && matrix->x<matrix->rows){
                    matrix->y=0;
                    while(!feof(arquivo) && matrix->y<matrix->columns){
                        fscanf(arquivo, "%d", &(matrix->data[matrix->x][matrix->y]));
                        matrix->y++;
                    }
                    matrix->x++;
                }
                matrix->x=0;
                matrix->y=0;
            }
        }
    }

    return matrix;
}

matrix10* transpostaMatrix(matrix10* matrix){
    matrix10* transposta=newMatrix(matrix->rows, matrix->columns);
    
    if(matrix->rows==matrix->columns)
        if(matrix!=null && matrix->data!=null)
            for(transposta->x=0; transposta->x<transposta->rows; transposta->x++)
                for(transposta->y=0; transposta->y<transposta->columns; transposta->y++)
                    transposta->data[transposta->x][transposta->y]=matrix->data[transposta->y][transposta->x];
    return transposta;
}

void exemplo16(){
    printf ("\n\n--Exemplo1016--\n");

    matrix10* matrix1=fscanMatrix("exemplo16.txt");
    matrix10* matrix2;

    if(matrix1->rows!=matrix1->columns)
        printf("\nTamanhos invalidos");
    else{    
        matrix2=transpostaMatrix(matrix1);

        printf("\nMatrix 1:\n");
        printMatrix(matrix1);
        printf("\nMatrix 2 (transposta):\n");
        printMatrix(matrix2);
    }

    freeMatrix(matrix1);
    freeMatrix(matrix2);

    endf();
}

bool zeroMatrix(matrix10* matrix){
    if(matrix->data)
        for(matrix->x=0; matrix->x<matrix->rows; matrix->x++)
            for(matrix->y=0; matrix->y<matrix->columns; matrix->y++)
                if(matrix->data[matrix->x][matrix->y]!=0)
                    return false;
    return true;
}

void exemplo17(){
    printf ("\n\n--Exemplo1017--\n");

    matrix10* matrix=fscanMatrix("exemplo17.txt");

    printf("\nA matrix possui %s", zeroMatrix(matrix)?"apenas zeros":"numeros que nao sao zero");

    freeMatrix(matrix);

    endf();
}

bool compareMatrix(matrix10* matrix1, matrix10* matrix2){
    if(matrix1->data && matrix2->data)
        if(matrix1->rows==matrix2->rows && matrix1->columns==matrix2->columns)
            for(matrix1->x=0; matrix1->x<matrix1->rows; matrix1->x++)
                for(matrix1->y=0; matrix1->y<matrix1->columns; matrix1->y++)
                    if (matrix1->data[matrix1->x][matrix1->y]!=matrix2->data[matrix1->x][matrix1->y])
                        return false;
        return true;
    return false; //caso nao existam dados
}

void exemplo18(){
    printf ("\n\n--Exemplo1018--\n");

    matrix10* matrix1=fscanMatrix("exemplo18a.txt");
    matrix10* matrix2=fscanMatrix("exemplo18b.txt");

    printf("\nAs matrizes %s iguais", compareMatrix(matrix1, matrix2)?"sao":"nao sao");

    freeMatrix(matrix1);
    freeMatrix(matrix2);

    endf();
}

matrix10* sumMatrix(matrix10* matrix1, matrix10* matrix2){
    matrix10* soma=newMatrix(matrix1->rows, matrix2->columns);

    if(matrix1->data && matrix2->data)
        for(soma->x=0; soma->x<soma->rows; soma->x++)
            for(soma->y=0; soma->y<soma->columns; soma->y++)
                soma->data[soma->x][soma->y]=matrix1->data[soma->x][soma->y]+matrix2->data[soma->x][soma->y];
    return soma;
}

void exemplo19(){
    printf ("\n\n--Exemplo1019--\n");
    
    matrix10* matrix1=fscanMatrix("exemplo19a.txt");
    matrix10* matrix2=fscanMatrix("exemplo19b.txt");
    matrix10* soma;

    if(matrix1->rows!=matrix2->rows || matrix1->columns!=matrix2->columns)
        printf("\nErro: dimensoes das matrizes sao diferentes");
    else{
        soma=sumMatrix(matrix1, matrix2);

        printf("\nMatriz 1 :\n");
        printMatrix(matrix1);
        printf("\nMatriz 2 :\n");
        printMatrix(matrix2);
        printf("\nSoma :\n");
        printMatrix(soma);
    }

    freeMatrix(matrix1);
    freeMatrix(matrix2);
    freeMatrix(soma);

    endf();
}

matrix10* multiplyMatrix(matrix10* matrix1, matrix10* matrix2){
    matrix10* produto=newMatrix(matrix1->rows, matrix2->columns);

    if(matrix1->data && matrix2->data){
        for(produto->x=0; produto->x<produto->rows; produto->x++){
            for(produto->y=0; produto->y<produto->columns; produto->y++){
                produto->data[produto->x][produto->y]=0;
                for(int i=0; i<matrix2->rows; i++)
                    produto->data[produto->x][produto->y]+=matrix1->data[produto->x][i]*matrix2->data[i][produto->y];
            }
        }    
    }
    return produto;
}

void exemplo20(){
    printf ("\n\n--Exemplo1020--\n");

    matrix10* matrix1=fscanMatrix("exemplo20a.txt");
    matrix10* matrix2=fscanMatrix("exemplo20b.txt");
    matrix10* produto;

    if(matrix1->columns!=matrix2->rows)
        printf("\nErro: dimensoes das matrizes nao sao validas");
    else{
        produto=multiplyMatrix(matrix1, matrix2);

        printf("\nMatriz 1 :\n");
        printMatrix(matrix1);
        printf("\nMatriz 2 :\n");
        printMatrix(matrix2);
        printf("\nProduto :\n");
        printMatrix(produto);
    }

    freeMatrix(matrix1);
    freeMatrix(matrix2);
    freeMatrix(produto);

    endf();
}

array10 ordenar(array10 array){
    int swap;

    if(array.data)
        for(int i=0; i<array.length; i++)
            for(array.x=0; array.x<array.length-1; array.x++)
                if(array.data[array.x]<array.data[array.x+1]){
                    swap=array.data[array.x+1];
                    array.data[array.x+1]=array.data[array.x];
                    array.data[array.x]=swap;
                }
    return array;
}

void exemploE1(){
    printf ("\n\n--Exemplo10E1--\n");

    array10 array=fscanArray("exemploE1.txt");
    array10 ordenado;

    printf("\nArranjo original:\n");
    printArray(array);

    if(array.data){
        ordenado=ordenar(array);
    }

    printf("\n\nArranjo ordenado:\n");
    printArray(ordenado);

    if(array.data)
        free(array.data);

    endf();
}

bool identidadeMatrix(matrix10* matrix){
    if(matrix->rows!=matrix->columns)
        return false;
    else
        for(matrix->x=0; matrix->x<matrix->rows; matrix->x++)
            for(matrix->y=0; matrix->y<matrix->columns; matrix->y++)
                if(matrix->x==matrix->y){
                    if(matrix->data[matrix->x][matrix->y]!=1)
                        return false;
                }else{
                    if(matrix->data[matrix->x][matrix->y]!=0)
                        return false;
                }
    return true;
}

void exemploE2(){
    printf ("\n\n--Exemplo10E2--\n");

    matrix10* matrix1=fscanMatrix("exemploE2a.txt");
    matrix10* matrix2=fscanMatrix("exemploE2b.txt");

    printf("\nMatriz 1:\n");
    printMatrix(matrix1);
    printf("\n\nMatriz 2:\n");
    printMatrix(matrix2);
    printf("\n\nProduto :\n");
    printMatrix(multiplyMatrix(matrix1, matrix2));
    
    printf("\nO produto das matrizes %s uma matriz identidade", identidadeMatrix(multiplyMatrix(matrix1, matrix2))?"e'":"nao e'");

    freeMatrix(matrix1);
    freeMatrix(matrix2);

    endf();
}

int main(){
    int opcao;
    do{
        opcao=menu("10");
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