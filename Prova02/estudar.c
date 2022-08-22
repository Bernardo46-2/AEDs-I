#include "Bernardo.h"
#include <time.h>

//--ordenar array com recursividade--//

void crescenteArray(int i, int length, int* array){
    int j=i;
    int temp;
    if(i<length){
        if(j<length-1){
            if(array[j]>array[j+1]){
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
            crescenteArray(j+1, length, array);
        }
        crescenteArray(i+1, length, array);
    }
}

void decrescenteArray(int i, int length, int* array){
    int j=i;
    int temp;
    if(i<length){
        if(j<length-1){
            if(array[j]<array[j+1]){
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
            decrescenteArray(j+1, length, array);
        }
        decrescenteArray(i+1, length, array);
    }
}

void inverterArray(int i, int length, int* array){
    int temp;
    if(i<length/2){
        temp=array[i];
        array[i]=array[length-(i+1)];
        array[length-(i+1)]=temp;
        inverterArray(i+1, length, array);
    }
}

void ordenarArray(){
    clear();
    srand(time(0));

    int n=readQuantity();
    int* array=(int*)malloc(n*sizeof(int));
    
    for(int i=0; i<n; i++){
        array[i]=randInt(0, 101);
        //array[i]=i;
    }

    for(int i=0; i<n; i++)
        printf("\narray[%d] = %d", i, array[i]);

    printf("\n\n0 - ordenar crescente");
    printf("\n1 - ordenar decrescente");
    printf("\n2 - inverter");
    printf("\n");
    int opcao=readInt();
    switch(opcao){
        case 0: crescenteArray(0, n, array); break;
        case 1: decrescenteArray(0, n, array); break;
        case 2: inverterArray(0, n, array); break;
        default: printf("\nValor invalido!"); endf(); break;
    }

    for(int i=0; i<n; i++)
        printf("\narray[%d] = %d", i, array[i]);

    if(array) free(array);
    endf();
}

void swap(int* a, int*b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void pointers(){
    clear();
    int* ptr;
    int x=5;
    ptr=&x;

    printf("\nptr = %d", ptr);
    printf("\nptr* = %d", *ptr);
    printf("\n");    

    int teste1=1;
    int teste2=2;

    int* a=&teste1;
    int* b=&teste2;

    printf("\na = %d", a);
    printf("\na* = %d", *a);
    printf("\nb = %d", b);
    printf("\nb* = %d", *b);
    printf("\n");

    swap(a, b);
    
    printf("\na = %d", a);
    printf("\na* = %d", *a);
    printf("\nb = %d", b);
    printf("\nb* = %d", *b);

    endf();
}

int main(){
    int opcao;

    do{
        clear();
        printf("\n\n--Estudar para prova--\n");
        printf("\n0 - parar");
        printf("\n1 - ordenar array recursivo");
        printf("\n2 - ponteiros");
        printf("\n");
        opcao=readInt();

        switch(opcao){
            case 0: break;
            case 1: ordenarArray(); break;
            case 2: pointers(); break;
            default: printf("\nValor invalido"); endf(); break;
        }
    }while(opcao!=0);

    endf();
    clear();
    return 0;
}