#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_SIZE=100;

//--Arrays--//

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
        printf("\narray[%d]: %d", k, array[k]);
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
    printf ("\nNumeros foram gravados no arquivo \"%s\"\n", filename);
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


//--Matrix--//


int readMatrixFlines (char* filename){
    int n;
    FILE *ptr = fopen (filename, "r");
    fscanf(ptr, "%d", &n);
    fclose(ptr);
    return n;
}

int readMatrixFcolumns (char* filename){
    int n;
    FILE *ptr = fopen (filename, "r");
    fscanf(ptr, "%d", &n);
    fscanf(ptr, "%d", &n);
    fclose(ptr);
    return n;
}

void intBuildMatrix (int option, int lines, int columns, int matrix[][columns]){
    int total=columns*lines;
    int posicao=0;
	for(int i=0; i<lines; i++){
        for (int j=0; j<columns; j++){
            switch (option){
                case 1: 
                    matrix[i][j]=posicao;
                    posicao++; 
                    break;
                case 2:
                    matrix[i][j]=total;
                    total--; 
                    break;
                case 3: matrix[i][j]=rand(); break;
                default: matrix[i][j]=0; break;
            }
        }
	}
}

void intPrintMatrix (int lines, int columns ,int matrix[][columns]){
	for(int i=0; i<lines; i++){
        for (int j=0; j<columns; j++)
            printf("\nmatrix[%d][%d]: %d", i, j, matrix[i][j]);
    }
}

void intFprintfMatrix (char filename[], int lines, int columns, int matrix[][columns]){
    FILE *arquivo=NULL;

    if (strlen(filename)<=0){
        printf("\nERRO: Nome de arquivo invalido. \n");
    }else{
        FILE *arquivo = fopen (filename, "w");
        
        fprintf(arquivo, "%d\n", lines);
        fprintf(arquivo, "%d\n", columns);
        for (int i=0; i<lines; i++){
            for (int j=0; j<columns; j++){
                fprintf(arquivo, "%d\n", matrix[i][j]);
            }
        }
        fclose(arquivo);
    }
    printf ("\nNumeros foram gravados no arquivo \"%s\"\n", filename);
}

void intFscanfMatrix (char* filename, int lines, int columns, int matrix[][columns]){
    int n=0;
    FILE *arquivo = fopen (filename, "r");
    
    fscanf(arquivo, "%d", &n);
    if (lines>=n){
        fscanf(arquivo, "%d", &n);
        if (columns>=n){
            for (int i=0; !feof(arquivo) && i<lines; i++){
                for (int j=0; !feof(arquivo) && j<columns; j++)
                    fscanf(arquivo, "%d", &matrix[i][j]);
            }
        }
    }
    fclose(arquivo);
}

void intScanMatrix (int lines, int columns, int matrix[][columns]){
	for(int i=0; i<lines; i++){
        for(int j=0; j<lines; j++){
            printf("matrix[%d][%d]: ", i, j);
            scanf ("%d", &matrix[i][j]);
            getchar();
        }
	}
}


//--double positiveMatrix--//

void doublePrintMatrix (int lines, int columns, double matrix[][columns]){
	for(int i=0; i<lines; i++){
        for (int j=0; j<columns; j++)
            printf("\nmatrix[%d][%d]: %lf", i, j, matrix[i][j]);
    }
}

void doubleScanMatrix (int lines, int columns, double matrix[][columns]){
	for(int i=0; i<lines; i++){
        for(int j=0; j<lines; j++){
            printf("matrix[%d][%d]: ", i, j);
            scanf ("%lf", &matrix[i][j]);
            getchar();
        }
	}
}

void doubleFprintfMatrix (char filename[], int lines, int columns, double matrix[][columns]){
    FILE *arquivo=NULL;

    if (strlen(filename)<=0){
        printf("\nERRO: Nome de arquivo invalido. \n");
    }else{
        FILE *arquivo = fopen (filename, "w");
        
        fprintf(arquivo, "%d\n", lines);
        fprintf(arquivo, "%d\n", columns);
        for (int i=0; i<lines; i++){
            for (int j=0; j<columns; j++){
                fprintf(arquivo, "%lf\n", matrix[i][j]);
            }
        }
        fclose(arquivo);
    }
    printf ("\nNumeros foram gravados no arquivo \"%s\"\n", filename);
}

void doubleBuildMatrix (int option, int lines, int columns, double matrix[][columns]){
    double total=(double)columns*(double)lines;
    double posicao=0;
	for(int i=0; i<lines; i++){
        for (int j=0; j<columns; j++){
            switch (option){
                case 1: 
                    matrix[i][j]=posicao;
                    posicao++; 
                    break;
                case 2:
                    matrix[i][j]=total;
                    total--; 
                    break;
                case 3: matrix[i][j]=rand(); break;
                default: matrix[i][j]=0; break;
            }
        }
	}
}

void doubleScanPositiveMatrix (int lines, int columns, double matrix[][columns]){
	for(int i=0; i<lines; i++){
        for(int j=0; j<lines; j++){
            do{
                printf("matrix[%d][%d]: ", i, j);
                scanf ("%lf", &matrix[i][j]);
                getchar();
                if (matrix[i][j]<0)
                    printf ("Insira apenas valores positivos\n");
            }while (matrix[i][j]<0);
        }
	}
}

void doubleFscanfMatrix (char* filename, int lines, int columns, double matrix[][columns]){
    int n=0;
    FILE *arquivo = fopen (filename, "r");
    
    fscanf(arquivo, "%d", &n);
    if (lines>=n){
        fscanf(arquivo, "%d", &n);
        if (columns>=n){
            for (int i=0; !feof(arquivo) && i<lines; i++){
                for (int j=0; !feof(arquivo) && j<columns; j++)
                    fscanf(arquivo, "%lf", &matrix[i][j]);
            }
        }
    }
    fclose(arquivo);
}

void printDiagonalPositiveMatrix (int lines, int columns, double matrix[][columns]){
    for(int i=0; i<lines; i++)
        printf("\n%lf", matrix[i][i]);
}

void printSDiagonalPositiveMatrix (int lines, int columns, double matrix[][columns]){
    for(int i=0, j=columns-1; i<lines; i++, j--)
        printf("\n%lf", matrix[i][j]);
}

void printLDiagonalTriangleDoubleMatrix (int lines, int columns, double matrix[][columns]){
    for (int i=0; i<lines; i++){
        for (int j=0; j<=i; j++){
            printf ("\n%lf", matrix[i][j]);
        }
    }
}

void printUDiagonalTriangleDoubleMatrix (int lines, int columns, double matrix[][columns]){
    for (int i=0; i<lines; i++){
        for (int j=i; j<columns; j++){
            printf ("\n%lf", matrix[i][j]);
        }
    }
}

void printSLDTriangleDoubleMatrix (int lines, int columns, double matrix[][columns]){
    for (int i=0; i<lines; i++){
        for (int j=columns-(i+1); j<columns; j++){
            printf ("\n%lf", matrix[i][j]);
        }
    }
}

void printSLUTriangleDoubleMatrix (int lines, int columns, double matrix[][columns]){
    for (int i=0; i<lines; i++)
        for (int j=0; j<columns-i; j++)
            printf ("\n%lf", matrix[i][j]);
}

bool allZerosLTriangleDoubleMatrix (int lines, int columns, double matrix[][columns]){
    for (int i=0; i<lines; i++)
        for (int j=0; j<=i; j++)
            if (matrix[i][j]!=0)
                return false;
    return true;
} 

bool allZerosUTriangleDoubleMatrix (int lines, int columns, double matrix[][columns]){
    for (int i=0; i<lines; i++)
        for (int j=i; j<columns; j++)
            if (matrix[i][j]!=0)
                return false;
    return true;
}

void doubleBuildMatrix09E2 (int lines, int columns, double matrix[][columns]){
    double total=(double)lines*(double)columns;

    for (int i=0; i<lines; i++)
        for (int j=0; j<columns; j++){
            matrix[j][i]=total;
            total--;
        }
}