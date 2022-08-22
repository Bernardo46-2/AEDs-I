#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define null NULL

typedef 
    struct s_intArray{
        int length;
        int* data;
    }intArray;

intArray initArray(int n){
    intArray array;

    if(n<=0){
        array.length=0;
        array.data=malloc(0);
    }else{
        array.length=n;
        array.data=(int*)malloc(n*4);
    }

    return array;
}

bool hasInt(intArray array, int n){
    for (int i=0; i<array.length; i++)
        if(array.data[i]==n)
            return true;
    return false;
}

intArray freadArray(char* filename, intArray array){
    FILE* file=fopen(filename, "r");

    if(!file)
        printf("\nERRO: arquivo nao foi encontrado");
    else{
        fscanf(file, "%d", &array.length);
        if(array.length<=0)
            printf("\nERRO: tamanho do array invalido");
        else{
            array.data=(int*)malloc(array.length*4);

            if(!array.data)
                printf("\nERRO: ocorreu um problema ao criar o array");
            else
                for(int i=0; !feof(file) || i<array.length; i++)
                    fscanf(file, "%d", &array.data[i]);
        }
    }

    fclose(file);
    return array;
}

void fprintArray(char* filename, intArray array){
    if(!array.data || array.length<=0){
        printf("\nERRO: dados do array invalidos");
        return;
    }

    FILE* file=fopen(filename, "w");

    fprintf(file, "%d\n", array.length);
    for(int i=0; i<array.length; i++)
        fprintf(file, "%d\n", array.data[i]);

    printf("\nArray foi salvo no arquivo \"%s\"", filename);

    fclose(file);
}

void randArray(intArray array){
    for(int i=0; i<array.length; i++)
        array.data[i]=randInt(0, 100);
}

void printArray(intArray array){
    printf("\n");
    for(int i=0; i<array.length; i++)
        printf("%d ", array.data[i]);
    printf("\n");
}

bool isDecrescentArray(intArray array){
    for(int i=0; i<array.length; i++)
        for(int j=0; j<array.length-1; j++)
            if(array.data[j]<array.data[j+1])
                return false;
    return true;
}

void decrescentBSArray(intArray array){
    for(int i=0; i<array.length; i++)
        for(int j=0; j<array.length-1; j++)
            if(array.data[j]<array.data[j+1]){
                int temp=array.data[j];
                array.data[j]=array.data[j+1];
                array.data[j+1]=temp;
            }
}

void invertArray(intArray array){
    if(!array.data || array.length<=0){
        printf("\nERRO: dados do array invalidos");
        return;
    }

    for(int i=0; i<array.length/2; i++){
        int temp=array.data[i];
        array.data[i]=array.data[array.length-(i+1)];
        array.data[array.length-(i+1)]=temp;
    }
}

int findLowestValue(intArray array){
    int lowest;

    if(!array.data || array.length<=0)
        printf("\nERRO: dados do array invalidos");
    else{
        lowest=array.data[0];

        for(int i=0; i<array.length; i++)
            if(array.data[i]<lowest)
                lowest=array.data[i];
    }

    return lowest;
}

int findSecondLowest(intArray array, int lowest){
    int secondLowest;

    if(!array.data || array.length<=0)
        printf("\nERRO: dados do array invalidos");
    else{
        secondLowest=INT_MAX;

        for(int i=0; i<array.length; i++){
            if(secondLowest>array.data[i] && array.data[i]>lowest)
                secondLowest=array.data[i];
        }
    }

    return secondLowest;
}

intArray filter(intArray array1, intArray array2){
    static intArray array3;

    if(!array1.data || array1.length<=0 || !array2.data || array2.length<=0){
        printf("\nERRO: dados do array invalidos\nRetornando array1");
        return array1;
    }else{
        array3.length=0;
        int x=0;
        if(array1.length>array2.length){
            for(int i=0; i<array1.length; i++){                
                if(hasInt(array3, array1.data[i])){
                    continue;
                }

                for(int j=0; j<array2.length; j++){
                    if(array1.data[i]==array2.data[j]){
                        array3.length++;
                        array3.data=(int*)realloc(array3.data, array3.length*sizeof(int));

                        x++;
                        array3.data[x-1]=array1.data[i];
                        break;
                    }
                }
            }
        }else{
            for(int i=0; i<array2.length; i++){                
                if(hasInt(array3, array2.data[i])){
                    continue;
                }

                for(int j=0; j<array1.length; j++){
                    if(array2.data[i]==array1.data[j]){
                        array3.length++;
                        array3.data=(int*)realloc(array3.data, array3.length*sizeof(int));

                        x++;
                        array3.data[x-1]=array2.data[i];
                        break;
                    }
                }
            }
        }
    }

    return array3;
}

intArray freadBinary(char* filename, intArray array){
    FILE* read=fopen(filename, "r");
    char trash;
    array.length=0;

    if(!read)
        printf("\nERRO: arquivo nao foi encontrado");
    else{
        while(!feof(read)){
            fscanf(read, "%c", &trash);
            
            if(trash=='0' || trash=='1')
                array.length++;
        }
        fclose(read);

        if(array.length<=0)
            printf("\nERRO: tamanho do array invalido");
        else{
            char* dummy=(char*)malloc(array.length*sizeof(char));
            array.data=(int*)malloc(array.length*sizeof(int));

            if(!dummy && !array.data)
                printf("\nERRO: falha na alocacao de memoria");
            else{
                FILE* read2=fopen(filename, "r");

                for(int i=0; !feof(read2) && i<array.length;){
                    fscanf(read2, "%c", &trash);

                    if(trash=='1' || trash=='0'){
                        i++;
                        dummy[i-1]=trash;
                    }
                };

                for(int i=0; i<array.length; i++)
                    array.data[i]=dummy[i]-48;

                free(dummy);
                fclose(read2);
            }
        }
    }

    return array;
}

int binToDec(intArray array){
    int n=0;
    
    if(array.length<=0){
        printf("\nERRO: tamanho do array invalido");
        return 0;
    }

    for(int i=array.length-1, expoente=0; i>=0; i--, expoente++){
        n+=array.data[i]*(int)po(2, expoente);
    }

    return n;
}