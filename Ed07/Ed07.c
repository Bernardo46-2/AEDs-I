//Bernardo Marques Fernandes - 774119
//Ed07

#include "io.h"

void exemplo0711a(char* filename, int n){
    FILE* arquivo = fopen (filename, "w");
    int numero=0;

    for (int i=0; i<n; i++){
        if (numero%3==0 && numero%2!=0){
            fprintf (arquivo, "%d\n", numero);
        }else{
            i--;
        }
        numero++;
    }

    fclose (arquivo);
}

void exemplo0711(){
    IO_id ("Ed07 - Exemplo0711 - v1.0");

    int n=0;

    printf ("Insira um numero: ");
    scanf ("%d", &n);
    getchar();

    exemplo0711a ("Exemplo0711.txt", n);
    printf ("\nNumeros foram gravados\n");

    printf ("\nAperte ENTER para continuar");
    getchar();
}

void exemplo0712a(char* filename, int n){
    FILE* arquivo = fopen (filename, "w");
    int maiorNum=6+((n-1)*6);

    for (int i=0; i<n; i++){
        fprintf (arquivo, "%d\n", maiorNum);
        maiorNum-=6;
    }

    fclose (arquivo);
}

void exemplo0712(){
    IO_id ("Ed07 - Exemplo0712 - v1.0");

    int n=0;

    printf ("Insira um numero: ");
    scanf ("%d", &n);
    getchar();

    exemplo0712a("Exemplo0712.txt", n);
    printf ("\nNumeros foram gravados\n");

    printf ("\nAperte ENTER para continuar");
    getchar();
}

void exemplo0713a(char* filename, int n){
    FILE* arquivo = fopen(filename, "w");
    int numero=1;

    for (int i=0; i<n; i++){
        fprintf (arquivo, "%d\n", numero);
        numero*=5;
    }

    fclose (arquivo);
}

void exemplo0713(){
    IO_id ("Ed07 - Exemplo0713 - v1.0");

    int n=0;

    printf ("Insira um numero: ");
    scanf ("%d", &n);
    getchar();

    exemplo0713a ("Exemplo0713.txt", n);
    printf ("\nNumeros foram gravados\n");

    printf ("\nAperte ENTER para continuar");
    getchar();
}

void exemplo0714a(char* filename, int n){
    FILE* arquivo = fopen (filename, "w");
    int maiorNum=pow(3, n-1);

    for (int i=0; i<n; i++){
        if (i==n-1){
            fprintf (arquivo, "%d\n", 1);
        }else{
            fprintf (arquivo, "%lf\n", 1.0/maiorNum);
            maiorNum/=3;
        }
    }

    fclose (arquivo);
}

void exemplo0714(){
    IO_id ("Ed07 - Exemplo0714 - v1.0");

    int n=0;

    printf ("Insira um numero: ");
    scanf ("%d", &n);
    getchar();

    exemplo0714a("Exemplo0714.txt", n);
    printf ("\nNumeros foram gravados\n");

    printf ("\nAperte ENTER para continuar");
    getchar();
}

void exemplo0715a (char* filename, int n, int x){
    FILE* arquivo = fopen (filename, "w");
    int expoente=1;

    for (int i=0; i<n; i++){
        if (i!=0){
            fprintf (arquivo, "%lf\n", 1.0/pow(x, expoente));
            expoente+=2;
        }else{
            fprintf (arquivo, "%d\n", 1);
        }
    }

    fclose (arquivo);
}

void exemplo0715(){
    IO_id ("Ed07 - Exemplo0715 - v1.0");

    int n=0, x=0;

    printf ("Insira um valor (n): ");
    scanf ("%d", &n);
    getchar();
    printf ("\nInsira um valor (x): ");
    scanf ("%d", &x);
    getchar();

    exemplo0715a ("Exemplo0715.txt", n, x);
    printf ("\nNumeros foram gravados\n");

    printf ("\nAperte ENTER para continuar");
    getchar();
}

void exemplo0716a (char* readFile, char* writeFile, int n){
    FILE* ler = fopen (readFile, "r");
    FILE* escrever = fopen (writeFile, "w");
    double numero=0.0;
    double resultado=0.0;
    int i=0;

    while (!feof (ler) && i<n){
        fscanf (ler, "%lf", &numero);
        resultado+=numero;
        i++;
    }
    fclose (ler);

    fprintf (escrever, "%d numeros\nresultado: %lf\n", n, resultado);
    fclose (escrever);
}

void exemplo0716(){
    IO_id ("Ed07 - Exemplo0716 - v1.0");

    int n=0;

    printf ("Insira um numero: ");
    scanf ("%d", &n);
    getchar();

    exemplo0716a ("Exemplo0715.txt", "Resultado06.txt", n);
    printf ("\nResultados foram gravados\n");

    printf ("\nAperte ENTER para continuar");
    getchar();
}

void exemplo0717a(char* readFile, char* writeFile, int n){
    FILE* ler = fopen (readFile, "r");
    FILE* escrever = fopen (writeFile, "w");
    double resultado=0.0;
    double numero=0.0;
    int i=0;

    while (!feof(ler) && i<n){
        fscanf (ler, "%lf", &numero);
        resultado+=numero;
        i++;
    }
    fclose (ler);

    fprintf (escrever, "%d numeros\nresultado: %lf", n, resultado);
    fclose (escrever);
}

void exemplo0717(){
    IO_id ("Ed07 - Exemplo0717 - v1.0");

    int n=0;

    printf ("Insira um numero: ");
    scanf ("%d", &n);
    getchar();

    exemplo0717a("Exemplo0714.txt", "Resultado07.txt", n);
    printf ("\nResultados foram gravados\n");

    printf ("\nAperte ENTER para continuar");
    getchar();
}

int fibonacci (int n){
    int resultado=0;
    if (n==1 || n==2)
        resultado=1;
    else
        resultado=fibonacci(n-1)+fibonacci(n-2);
    return resultado;
}

void exemplo0718a (char* filename, int n){
    FILE* ptr = fopen (filename, "w");
    int x=1;

    for (int i=0; i<n; i++){
        int numero=fibonacci(x);

        if (numero%2==0){
            fprintf (ptr, "%d\n", numero);
        }else{
            i--;
        }
        x++;
    }

    fclose(ptr);
}

void exemplo0718(){
    IO_id ("Ed07 - Exemplo0718 - v1.0");

    int n=0;

    printf ("Insira um numero: ");
    scanf ("%d", &n);
    getchar();

    exemplo0718a("Resultado08.txt", n);
    printf ("\nResultados foram gravados\n");

    printf ("\nAperte ENTER para continuar");
    getchar();
}

void exemplo0719a(char* readFile, char* writeFile){
    FILE* ler = fopen (readFile, "r");
    FILE* escrever = fopen (writeFile, "w");
    char linha[80];
    int maiusculas=0;

    while (!feof (ler)){
        fscanf (ler, "%s", linha);
        fprintf (escrever, "%s ", linha);

        for (int i=0; i<strlen(linha); i++){
            if ('A'<=linha[i] && linha[i]<='Z'){
                maiusculas++;
            }
        }
    }
    fprintf (escrever, "\nMaiusculas: %d", maiusculas);
    
    fclose (ler);
    fclose (escrever);
}

void exemplo0719(){
    IO_id ("Ed07 - Exemplo0719 - v1.0");

    exemplo0719a("Exemplo0719.txt", "Resultado09.txt");
    printf ("Resultados foram gravados\n");

    printf ("\nAperte ENTER para continuar");
    getchar();
}

void exemplo0720a (char* filename, char* linha){
    FILE* ptr = fopen (filename, "w");
    int numeros=0;

    //contar numeros
    for (int i=0; i<strlen(linha); i++){
        if ('7'<=linha[i] && linha[i]<='9'){
            numeros++;
        }
    }

    //escrever numeros
    fprintf (ptr, "%s\n", linha);
    fprintf (ptr, "Quantidade de numeros maiores ou iguais a 7: %d", numeros);

    fclose (ptr);
}

void exemplo0720(){
    IO_id ("Ed07 - Exemplo0720 - v1.0");

    char linha[80];

    printf ("Insira uma cadeia de caracteres: ");
    gets(linha);
    
    exemplo0720a ("Resultado10.txt", linha);
    printf ("\nResultados foram gravados\n");

    printf ("\nAperte ENTER para continuar");
    getchar();
}

void exemplo07E1a(char* filename, int n){
    FILE* ptr = fopen (filename, "w");
    int divisores=1;

    fprintf (ptr, "%d ", n);
    for (int i=n/2; i>=1; i--){
        if (n%i==0){
            fprintf (ptr, "%d ", i);
            divisores++;
        }
    }
    fprintf (ptr, "\nO numero %d possui %d divisores.\n", n, divisores);
    
    fclose (ptr);
}

void exemplo07E1(){
    IO_id ("Ed07 - Exemplo07E1 - v1.0");

    int n=0;

    printf ("Insira um numero: ");
    scanf ("%d", &n);
    getchar();

    exemplo07E1a ("ResultadoE1.txt", n);
    printf ("\nDivisores de %d foram gravados\n", n);

    printf ("\nAperte ENTER para continuar");
    getchar();
}

int exemplo07E2a (char* readFile, char* writeFile){
    FILE* ler = fopen (readFile, "r");
    FILE* escrever = fopen (writeFile, "w");
    char palavra[80];
    int contador=0;

    while (!feof (ler)){
        fscanf (ler, "%s", palavra);
        
        if (palavra[0]=='A' || palavra[0]=='a'){
            contador++;
        }
    }
    fprintf (escrever, "O arquivo lido possui %d palavras que comecam com 'A' ou 'a'\n", contador);

    fclose (ler);
    fclose (escrever);
    return contador;
}

void exemplo07E2(){
    IO_id ("Ed07 - Exemplo07E2 - v1.0");

    printf ("O arquivo lido possui %d palavras que comecam com 'A' ou 'a'\n", exemplo07E2a ("Exemplo07E2.txt", "ResultadoE2.txt"));
    printf ("Resultados foram gravados\n");

    printf ("\nAperte ENTER para continuar");
    getchar();
}

int main(){
    int opcao=0;

    do{
        printf ("\nEd07");
        printf ("\nBernardo Marques Fernandes - 774119\n");
        printf ("\n[0] Parar");
        printf ("\n[1] Exemplo0711");
        printf ("\n[2] Exemplo0712");
        printf ("\n[3] Exemplo0713");
        printf ("\n[4] Exemplo0714");
        printf ("\n[5] Exemplo0715");
        printf ("\n[6] Exemplo0716");
        printf ("\n[7] Exemplo0717");
        printf ("\n[8] Exemplo0718");
        printf ("\n[9] Exemplo0719");
        printf ("\n[10] Exemplo0720");
        printf ("\n[11] Exemplo07E1");
        printf ("\n[12] Exemplo07E2\n");

        printf ("\nEscolha uma opcao: ");
        scanf ("%d", &opcao);
        getchar();

        switch (opcao){
            case 0:
            break;
            case 1:
            exemplo0711();
            break;
            case 2:
            exemplo0712();
            break;
            case 3:
            exemplo0713();
            break;
            case 4:
            exemplo0714();
            break;
            case 5:
            exemplo0715();
            break;
            case 6:
            exemplo0716();
            break;
            case 7:
            exemplo0717();
            break;
            case 8:
            exemplo0718();
            break;
            case 9:
            exemplo0719();
            break;
            case 10:
            exemplo0720();
            break;
            case 11:
            exemplo07E1();
            break;
            case 12:
            exemplo07E2();
            break;
            default:
            printf ("\nValor invalido");
            printf ("\nAperte ENTER para continuar");
            getchar();
        }
    }while (opcao!=0);

    printf ("\nAperte ENTER para terminar");
    getchar();
    return 0;
}