//Bernardo Marques Fernandes - 774119
//AEDs I - R02

#include "bibliotecas/Bernardo.h"
#include "bibliotecas/array.h"
#include "bibliotecas/matrix.h"
#include "bibliotecas/method10.h"
#include <time.h>

/**
 * Bernardo Marques Fernandes - 774119
 * 
 * ler array de arquivo "dados1.txt" 
 * verificar se esta em ordem decrescente
 * se nao estiver, ordena-lo
 * salvar no arquivo "decrescente.txt"
 * 
 * resultado esperado: 86 45 43 34 10 8 2 -42 -64 -76 
*/
void method01(){
    clear();
    printf("\n\n-- R02 - Method01 --\n");

    intArray array=freadArray("arquivos/dados1.txt", array);

    printf("\nArray original:");
    printArray(array);

    if(!isDecrescentArray(array)){
        decrescentBSArray(array);
        
        printf("\nArray em ordem decrescente: ");
        printArray(array);

        fprintArray("arquivos/decrescente.txt", array);
    }

    if(array.data)
        free(array.data);

    endf();
}

/** 
 * Bernardo Marques Fernandes - 774119
 *
 * ler array de arquivo "decrescente.txt"
 * inverter ordem dos elementos
 * salvar em arquivo "invertidos.txt"
 * 
 * resultado esperado: -76 -64 -42 2 8 10 34 43 45 86
 */
void method02(){
    clear();
    printf("\n\n-- R02 - Method02 --\n");

    intArray array=freadArray("arquivos/decrescente.txt", array);

    printf("\nArray original:");
    printArray(array);

    invertArray(array);
    printf("\nArray invertido:");
    printArray(array);

    fprintArray("arquivos/invertidos.txt", array);

    if(array.data)
        free(array.data);

    endf();
}

/**
 * Bernardo Marques Fernandes - 774119
 * 
 * ler array de arquivo "dados1.txt"
 * procurar menor valor do array
 * procurar segundo menor valor
 * imprimir segundo menor
 * 
 * resultado esperado: -64
 */
void method03(){
    clear();
    printf("\n\n-- R02 - Method03 --\n");

    intArray array=freadArray("arquivos/dados1.txt", array);

    printf("\nArray original:");
    printArray(array);

    int secondLowest=findSecondLowest(array, findLowestValue(array));

    printf("\nO segundo menor valor do array e': %d", secondLowest);

    if(array.data)
        free(array.data);

    endf();
}

/**
 * Bernardo Marques Fernandes - 774119
 * 
 * ler 2 arrays de arquivo "dados1.txt" e "dados2.txt"
 * filtrar e mostrar elementos comuns entre eles
 * gravar elementos iguais em "filtrados.txt"
 * gravar quantidade de elementos na primeira linha
 * 
 * resultado esperado: 2 -76 10 -42
 */
void method04(){
    clear();
    printf("\n\n-- R02 - Method04 --\n");

    intArray array1=freadArray("arquivos/dados1.txt", array1);
    intArray array2=freadArray("arquivos/dados2.txt", array2);
    intArray array3=filter(array1, array2);

    printf("\nArray 1:");
    printArray(array1);
    printf("\nArray 2:");
    printArray(array2);
    printf("\nElementos comuns:");
    printArray(array3);

    fprintArray("arquivos/filtrados.txt", array3);

    if(array1.data)
        free(array1.data);
    if(array2.data)
        free(array2.data);
    if(array3.data)
        free(array3.data);

    endf();
}


/**
 * Bernardo Marques Fernandes - 774119
 * 
 * ler string do arquivo "binarios1.txt"
 * salvar em cadeia de caracteres todos os 0 e 1
 * converter e armazenar em uma arranjo de inteiros
 * converter o binario gerado para decimal
 */
void method05(){
    srand(time(0));
    clear();
    printf("\n\n-- R02 - Method05 --\n");

    //gerar arquivo aleatorio
    FILE* write=fopen("arquivos/binarios1.txt", "w");

    for(int i=0; i<20; i++)
        fprintf(write, "%d", randInt(0, 5));
    fclose(write);

    
    intArray bin=freadBinary("arquivos/binarios1.txt", bin);
    int dec=binToDec(bin);

    printf("\nNumero binario:\n");
    for(int i=0; i<bin.length; i++)
        printf("%d", bin.data[i]);

    printf("\nNumero em decimal:\n");
    printf("%d", dec);

    endf();
}


/**
 * Bernardo Marques Fernandes - 774119
 * 
 * ler matriz do arquivo "matrix1.txt"
 * ler quantidade N para indicar linhas e colunas
 * gravar matrix no arquivo "matrix2.txt" com
 * as caracteristicas abaixo:
 * 
 *  1  2  0  0
 *  3  4  5  0
 *  0  6  7  8
 *  0  0  9 10
 */
void method06(){
    clear();
    printf("\n\n-- R02 - Method06 --\n");

    int n=readInt();
    intMatrix* matrix;
    matrix=initMatrix(0, n, n);

    crescentTridiagonal(matrix);

    printMatrix(matrix);
    fprintMatrix("arquivos/matrix1.txt", matrix);
    
    freeMatrix(matrix);
    endf();
}


/**
 * Bernardo Marques Fernandes - 774119
 * 
 * ler dados do arquivo "matrix1.txt"
 * ler quantidade N para indicar linhas e colunas
 * gravar matrix no arquivo "matrix2.txt" com
 * as caracteristicas abaixo:
 * 
 *  10  9  0  0
 *   8  7  6  0
 *   0  5  4  3
 *   0  0  2  1
 */
void method07(){
    clear();
    printf("\n\n-- R02 - Method07 --\n");

    int n=readInt();
    intMatrix* matrix;
    matrix=initMatrix(0, n, n);

    decrescentTridiagonal(matrix);

    printMatrix(matrix);
    fprintMatrix("arquivos/matrix2.txt", matrix);

    freeMatrix(matrix);
    endf();
}


/**
 * Bernardo Marques Fernandes - 774119
 * 
 * ler matriz do arquivo "matrix3.txt"
 * verificar se a matriz apresenta a
 * caracteristica abaixo:
 * 
 *   1  1  1  1
 *   1  2  4  8
 *   1  3  9 27
 *   1  4 16 64
 */
void method08(){
    clear();
    printf("\n\n-- R02 - Method08 --\n");

    intMatrix* matrix=freadMatrix("arquivos/matrix3.txt");

    printMatrix(matrix);
    printf("\nA matrix %s a caracteristica de potencias por linha", powerPerRow(matrix)?"apresenta":"nao apresenta");

    freeMatrix(matrix);
    endf();
}


/**
 * Bernardo Marques Fernandes - 774119
 * 
 * ler matriz do arquivo "matrix4.txt"
 * verificar se a matriz apresenta a
 * caracteristica abaixo:
 * 
 *   1  1  1  1
 *   1  2  3  4
 *   1  4  9 16
 *   1  8 27 64
 */
void method09(){
    clear();
    printf("\n\n-- R02 - Method09 --\n");

    intMatrix* matrix=freadMatrix("arquivos/matrix4.txt");

    printMatrix(matrix);
    printf("\nA matrix %s a caracteristica de potencias por coluna", powerPerColumn(matrix)?"apresenta":"nao apresenta");

    freeMatrix(matrix);
    endf();
}


/**
 * Bernardo Marques Fernandes - 774119
 * 
 * ler do arquivo "dados3.txt":
 * uma quantidade N de supermercados cujos precos de produtos serao avaliados
 * ler o nome e o codigo de cada supermercado
 * ler o preco de um produto de cada supermercado
 * calcular o preco medio desse produto
 * informar pelo menos 2 supermercados com o preco abaixo da media
 * 
 * resultado esperado: 
 * media: 3.83
 * supermercados abaixo da media: 1, 2 e 4
 */
void method10(){
    clear();
    printf("\n\n-- R02 - Method10 --\n");

    supermercados* sp=freadSupermercados("arquivos/dados3.txt");

    printSupermercados(sp);
    endf();
    printPrecosAbaixoDaMedia(calcularMedia(sp), sp);

    freeSupermercados(sp);
    endf();
}


int main(){
    int opcao;
    bool sair=false;
    
    do{
        clear();
        printf("\n-- AEDs I - R02 --");
        printf("\nBernardo Marques Fernandes - 774119\n");
        printf("\n0 - Sair");
        printf("\n1 - Metodo 1");
        printf("\n2 - Metodo 2");
        printf("\n3 - Metodo 3");
        printf("\n4 - Metodo 4");
        printf("\n5 - Metodo 5");
        printf("\n6 - Metodo 6");
        printf("\n7 - Metodo 7");
        printf("\n8 - Metodo 8");
        printf("\n9 - Metodo 9");
        printf("\n10 - Metodo 10");
        opcao=readInt();

        switch(opcao){
            case 0: sair=quit(); break;
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
            default: printf ("\nValor Invalido"); endf(); break;
        }
    }while(!sair);

    clear();
    return 0;
}