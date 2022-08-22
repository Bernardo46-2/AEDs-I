//Bernardo Marques Fernandes - 774119
//Ed08

#include "Bernardo.h"

void Exemplo11(){
    printf ("\n\n--Ed08 - Exemplo0811--\n");

    int tamanho=readQuantity();
    int array[tamanho];

    for (int i=0; i<tamanho; i++){
        do{
            array[i]=readIntNat();
            if (array[i]%2!=0) printf ("Insira apenas numeros pares\n");
        }while (array[i]%2!=0);
    }
    intPrintArray(tamanho, array);

    endF();
}

void Exemplo12(){
    printf ("\n\n--Ed08 - Exemplo0812--\n");

    int tamanho=readQuantity();
    int array[tamanho];

    for (int i=0; i<tamanho; i++){
        do{
            array[i]=readIntNat();
            if (array[i]%2!=0) printf ("Insira apenas numeros pares\n");
        }while (array[i]%2!=0);
    }
    intFprintfArray ("Exemplo0812.txt", tamanho, array); 

    endF();
}

void Exemplo13(){ //gerarInt() esta na biblioteca
    printf ("\n\n--Ed08 - Exemplo0813--\n");

    int tamanho=readQuantity(), a=readInt(), b=readInt();
    int array[tamanho];

    for (int i=0; i<tamanho; i++){
        array[i]=randomInt(a, b);
    }
    intFprintfArray("Exemplo0813.txt", tamanho, array);

    endF();
}

int acharMenor(char* filename){
    int atual;
    int menor=0;
    int tamanho;

    FILE *arquivo=fopen (filename, "rt");
    fscanf(arquivo, "%d", &tamanho);
    if (tamanho > 0)
        fscanf(arquivo, "%d", &menor);
    for (int i=0; (!feof(arquivo) && i<tamanho); i++){
        fscanf(arquivo, "%d", &atual);
        if (menor>atual)
            menor=atual;
    }
    fclose(arquivo);
    return (menor);
}

void Exemplo14(){
    printf ("\n\n--Ed08 - Exemplo0814--\n");

    int menor=acharMenor ("DADOS.TXT");

    printf ("\nMenor numero do arranjo e' %d", menor);

    endF();
}

int acharMaior(char* filename){
    int atual;
    int maior=0;
    int tamanho;

    FILE *arquivo=fopen (filename, "rt");
    fscanf(arquivo, "%d", &tamanho);
    if (tamanho > 0)
        fscanf(arquivo, "%d", &maior);
    for (int i=0; (!feof(arquivo) && i<tamanho); i++){
        fscanf(arquivo, "%d", &atual);
        if (maior<atual)
            maior=atual;
    }
    fclose(arquivo);
    return (maior);
}

void Exemplo15(){
    printf ("\n\n--Ed08 - Exemplo0815--\n");

    int maior=acharMaior ("DADOS.TXT");

    printf ("Maior numero do arranjo e' %d", maior);

    endF();
}

int calcularMediaArquivo(char* filename){
    int media=0, tamanho, numero;

    FILE* ptr = fopen (filename, "r");

    fscanf (ptr, "%d", &tamanho);
    for (int i=0; i<tamanho; i++){
        fscanf (ptr, "%d", &numero);
        media+=numero;
    }
    media/=tamanho;
    fclose (ptr);

    return media;
}

void Exemplo16(){
    printf ("\n\n--Ed08 - Exemplo0816--\n");

    int tamanho=readArrayFsize("DADOS.TXT");
    int array[tamanho];
    int media=calcularMediaArquivo ("DADOS.TXT");
    
    intFscanfArray ("DADOS.TXT", tamanho, array);

    FILE* maior = fopen ("ValoresMaioresQueMedia.txt", "w");
    FILE* menor = fopen ("ValoresMenoresQueMedia.txt", "w");

    for (int i=0; i<tamanho; i++){
        if (array[i]>=media)
            fprintf (maior, "%d\n", array[i]);
        else
            fprintf (menor, "%d\n", array[i]);
    }    
    fclose (maior);
    fclose (menor);

    printf ("\nNumeros foram guardados em arquivos \"%s\" e \"%s\"", "ValoresMaioresQueMedia.txt", "ValoresMenoresQueMedia.txt");

    endF();
}

bool estaOrdenadoDecrescente (int array[], int length){
    for (int i=0; i<length-1; i++)
        if (array[i]>array[i+1]) return true;
    return false;
}

void Exemplo17(){
    printf ("\n\n--Ed08 - Exemplo0817--\n");

    int array1[10]; //crescente
    intBuildArray (1, 10, array1);
    int array2[10]; //decrescente
    intBuildArray (2, 10, array2);

    printf ("\nArray 1 = ");
    for (int i=0; i<10; i++)
        printf ("%d ", array1[i]);

    printf ("\nArray 2 = ");
    for (int i=0; i<10; i++)
        printf ("%d ", array2[i]);
    
    printf ("\n");
    printf ("\nArray 1 %s ordenado de maneira decrescente", estaOrdenadoDecrescente(array1, 10)?"esta":"nao esta");
    printf ("\nArray 2 %s ordenado de maneira decrescente", estaOrdenadoDecrescente(array2, 10)?"esta":"nao esta");

    endF();
}

bool acharValor (int valor, int posicaoInicial, int length, int array[]){
    for (int i=posicaoInicial; i<length; i++){
        if (array[i]==valor) 
            return true;
    }
    return false;
}

void Exemplo18(){
    printf ("\n\n--Ed08 - Exemplo0818--\n");

    int length=readArrayFsize("DADOS.TXT");
    int array[length];
    int valor=readIntNat();
    int posicaoInicial;

    intFscanfArray ("DADOS.TXT", length, array);
    
    do{
        printf ("\nInsira a posicao inicial da procura: ");
        posicaoInicial=readInt();
        if (posicaoInicial<0)
            printf ("Posicao nao pode ser negativa");
    }while (posicaoInicial<0);

    printf ("\nComecando da posicao %d, o numero %d %s no array", posicaoInicial, valor, acharValor (valor, posicaoInicial, length, array)?"existe":"nao existe");

    endF();
}

int ondeAcharValor (int valor, int posicaoInicial, int length, int array[]){
    for (int i=posicaoInicial; i<length; i++){
        if (array[i]==valor) 
            return i;
    }
    return -1;
}

void Exemplo19(){
    printf ("\n\n--Ed08 - Exemplo0819--\n");

    int length=readArrayFsize("DADOS.TXT");
    int array[length];
    int valor=readIntNat();
    int posicaoInicial;

    intFscanfArray ("DADOS.TXT", length, array);
    
    do{
        printf ("\nInsira a posicao inicial da procura: ");
        posicaoInicial=readInt();
        if (posicaoInicial<0)
            printf ("Posicao nao pode ser negativa");
    }while (posicaoInicial<0);

    int posicaoNumero=ondeAcharValor(valor, posicaoInicial, length, array);

    if (posicaoNumero==-1)
        printf ("\nPartindo da posicao %d, o numero %d nao existe no array", posicaoInicial, valor);
    else{
        printf ("\n\nPartindo da posicao %d, o numero %d existe no array", posicaoInicial, valor);
        printf ("\nPode ser encontrado na posicao: array[%d]", posicaoNumero);
    }

    endF();
}

int acharQuantos (int valor, int posicaoInicial, int length, int array[]){
    int quantos=0;
    for (int i=posicaoInicial; i<length; i++){
        if (array[i]==valor) 
            quantos++;
    }
    return quantos;
}

void Exemplo20(){
    printf ("\n\n--Ed08 - Exemplo0820--\n");

    int length=readArrayFsize("DADOS.TXT");
    int array[length];
    int valor=readIntNat();
    int posicaoInicial;

    intFscanfArray ("DADOS.TXT", length, array);
    
    do{
        printf ("\nInsira a posicao inicial da procura: ");
        posicaoInicial=readInt();
        if (posicaoInicial<0)
            printf ("Posicao nao pode ser negativa");
    }while (posicaoInicial<0);

    int quantidade=acharQuantos(valor, posicaoInicial, length, array);
    
    int posicoes[quantidade]; //separar posicoes onde numero e' encontrado
    int x=0; //variavel auxiliar
    for (int i=0; i<quantidade; i++){
        posicoes[i]=ondeAcharValor (valor, posicaoInicial+x, length, array);
        x=posicoes[i]+1;
    }

    if (quantidade==0)
        printf ("\nPartindo da posicao %d, o numero %d nao existe no array", posicaoInicial, valor);
    else{
        printf ("\n\nPartindo da posicao %d, o numero %d existe no array", posicaoInicial, valor);
        printf ("\nPode ser encontrado na(s) posicao(oes): ");
        for (int i=0; i<quantidade; i++){
            if (i==quantidade-1)
                printf ("%d", posicoes[i]);
            else
                printf ("%d, ", posicoes[i]);
        }
    }

    endF();
}

int quantosDivisores (int n){
    int divisores=1;
    for (int i=1; i<=n/2; i++){
        if (n%i==0)
            divisores++;
    }
    return divisores;
}

void ExemploE1(){
    printf ("\n\n--Ed08 - Exemplo08E1--\n");

    int n=readIntNat();
    int divisores[quantosDivisores(n)];

    int k=0;
    for (int i=1; i<=n/2; i++){
        if (n%i==0){
            divisores[k]=i;
            k++;
        }
    }
    divisores[quantosDivisores(n)-1]=n;

    intFprintfArray ("DIVISORES.TXT", quantosDivisores(n), divisores);
    
    printf ("\n\nO numero %d possui %d divisores.", n, quantosDivisores(n));
    printf ("\nSao eles: ");
    for (int i=0; i<quantosDivisores(n); i++){
        if (i==quantosDivisores(n)-1)
            printf ("%d", divisores[i]);
        else
            printf ("%d, ", divisores[i]);
    }

    endF();
}

void ExemploE2(){
    printf ("\n\n--Ed08 - Exemplo08E2--\n");

    char palavra[80];
    int contador=0;

    FILE* ptr = fopen ("PALAVRAS.TXT", "r");

    printf ("\n10 primeiras palavras que comecam com 'A' ou 'a' do arquivo \"PALAVRAS.TXT\":\n");

    while (contador<10 && !feof(ptr)){
        fgets (palavra, 50, ptr);

        if (palavra[0]=='A' || palavra[0]=='a'){
            contador++;
            printf ("\n%s", palavra);
        }
    }

    fclose (ptr);
    endF();
}

int main(){
    int opcao;
    do{
        opcao=menu("08");
        switch(opcao){
            case 0: break;
            case 1: Exemplo11(); break;
            case 2: Exemplo12(); break;
            case 3: Exemplo13(); break;
            case 4: Exemplo14(); break;
            case 5: Exemplo15(); break;
            case 6: Exemplo16(); break;
            case 7: Exemplo17(); break;
            case 8: Exemplo18(); break;
            case 9: Exemplo19(); break;
            case 10: Exemplo20(); break;
            case 11: ExemploE1(); break;
            case 12: ExemploE2(); break;
            default: printf ("\nValor Invalido\nPress ENTER"); getchar();
        }
    }while (opcao!=0);
    endF();
    return 0;
}