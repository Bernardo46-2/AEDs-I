#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef
    struct s_supermercados{
        int length;
        char** nome;
        int* codigo;
        double* produto;
    }supermercados;


supermercados* freadSupermercados(char* filename);
double calcularMedia();
void freeSupermercados(supermercados* sp);
void printSupermercados(supermercados* sp);
void printPrecosAbaixoDaMedia(double media, supermercados* sp);


//ler supermercados de arquivo
supermercados* freadSupermercados(char* filename){
    FILE* file=fopen(filename, "r");
    supermercados* sp;
    int n;

    if(!file)
        printf("\nERRO: arquivo nao encontrado");
    else{
        fscanf(file, "%d", &n);

        if(n<=0)
            printf("\nERRO: quantidade invalida");
        else{
            sp=(supermercados*)malloc(sizeof(supermercados));

            if(!sp)
                printf("\nERRO: falha ao alocar memoria");
            else{
                sp->length=n;
                sp->codigo=(int*)malloc(n*sizeof(int));
                sp->produto=(double*)malloc(n*sizeof(double));
                sp->nome=(char**)malloc(n*sizeof(char*));

                for(int i=0; i<sp->length; i++){
                    sp->nome[i]=(char*)calloc(80, sizeof(char));

                    fscanf(file, "%s", sp->nome[i]);
                    fscanf(file, "%d", &sp->codigo[i]);
                    fscanf(file, "%lf", &sp->produto[i]);
                }
            }
        }
        fclose(file);
    }

    return sp;
}


//liberar supermercados
void freeSupermercados(supermercados* sp){
    if(sp){
        for(int i=0; i<sp->length; i++)
            if(sp->nome[i])
                free(sp->nome[i]);

        if(sp->nome)
            free(sp->nome);
        if(sp->codigo)
            free(sp->codigo);
        if(sp->produto)
            free(sp->produto);
        free(sp);
    }
}

//printar supermercados
void printSupermercados(supermercados* sp){
    if(!sp){
        printf("\nTamanho invalido");
        return;
    }

    printf("\nSupermercados: \n");

    for(int i=0; i<sp->length; i++){
        printf("\nNome: %s", sp->nome[i]);
        printf("\nCodigo: %d", sp->codigo[i]);
        printf("\nPreco do produto: %.2lf", sp->produto[i]);
        printf("\n");
    }

    printf("\n");
}


//calcular media dos produtos
double calcularMedia(supermercados* sp){
    double media=0;

    for(int i=0; i<sp->length; i++)
        media+=sp->produto[i];

    media/=sp->length;

    return media;
}


//printar precos
void printPrecosAbaixoDaMedia(double media, supermercados* sp){
    printf("\nPrecos abaixo da media (%.2lf):\n", media);

    printf("\nNome     -      Codigo  -  Preco");
    for(int i=0; i<sp->length; i++)
        if(sp->produto[i]<media)
            printf("\n%s  -  %d  -  %.2lf", sp->nome[i], sp->codigo[i], sp->produto[i]);
}