#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

void questao1(){
    printf ("\n\n--Questao 1--\n\n");

    bool b=false;
    char c='0';
    double d=0.0;
    int x=0;

    b=(x<=5) && (d<=1/2);
    c=(char)(((int)'0'+1)-48);
    d=7/8+(int)(double)3/4;
    x=(int)(M_PI*1.0)/3;

    printf ("a) b = %d\n", b); //1
    printf ("b) c = %d\n", c); //1
    printf ("c) d = %d\n", d); //0
    printf ("d) x = %d\n", x); //1

    printf ("\nResposta = c\n");

    printf ("\nAperte ENTER parar continuar\n");
    getchar();
}

void questao2(){
    printf ("\n\n--Questao 2--\n\n");

    int x=0;
    int y=0;
    int n=5;

    y=n*(n+1)/2+1;
    for(x=1; x<=n; x++){
        y-=x;
        printf ("%d ", y);
    }

    printf ("\n\na) 16 15 11 7 2\n");
    printf ("b) 15 13 10 6 1\n");
    printf ("c) 14 12 9 5 0\n");
    printf ("d) 15 13 11 8 4\n");

    printf ("\nResposta = b\n");

    printf ("\nAperte ENTER parar continuar\n");
    getchar();
}

void questao3(){
    printf ("\n\n--Questao 3--\n\n");
    
    for(int x=1; x<=5; x++){
        printf ("x = %d\n", 2*x-1);
    }
    printf ("\n");
    for (int x=1; x<=5*3; x+=3){
        printf ("x = %d\n", x-x/3);
    }
    printf ("\n");

    printf ("\na) 5+3 e 2*x-3\n");
    printf ("b) 5+3 e 3*x/2-3\n");
    printf ("c) 5*3 e 3*x/2\n");
    printf ("d) 5*3 e x-x/3\n");

    printf ("\nResposta = d\n");

    printf ("\nAperte ENTER parar continuar\n");
    getchar();
}

void questao4(){
    printf ("\n\n--Questao 4--\n\n");

    int a=10;
    int b=20;
    int c=30;
    int maior=0;

    if(c>b>a || c>a>b){
        maior=c;
    }
    else if(b>c>a || b>a>c){
        maior=b;
    }
    else if(a>b>c || a>c>b){
        maior=a;
    }
    printf ("Maior = %d\n", maior);

    printf ("\na) Maior = 0\n");
    printf ("b) Maior = 10\n");
    printf ("c) Maior = 20\n");
    printf ("d) Maior = 30\n");

    printf ("\nResposta = a\n");

    printf ("\nAperte ENTER para continuar\n");
    getchar();
}


void questao5(){
    printf ("\n\n--Questao 5--\n\n");
    int x=0;
    int y=0;

    for (x=1; x<=5; x++){
        for (y=(x+1)/3; y>0; y--){
            printf (" ");
        }
        for (y=1; y<=x/2+1; y++){
            printf ("%d", y);
        }
        printf ("\n");
    }

    printf ("\n\nResposta = a\n");

    printf ("\nAperte ENTER parar continuar\n");
    getchar();
}

bool mercosul(char* placa){
    bool correto=true;
    bool repeticao=true;
    int x=0; //posicao

    for (x=0; x<3; x++){ //testar 3 primeiros digitos
        if (!('A'<=placa[x] && placa[x]<='Z')){
            correto=false;
        }
    }
    
    x=3;
    if (!('0'<=placa[x] && placa[x]<='9')){ //testar 4o digito 
        correto=false;
    }

    x=4;
    if (!('A'<=placa[x] && placa[x]<='Z')){ //testar 5o digito
        correto=false;
    }

    for (x=5; x<7; x++){ //testar ultimos 2 digitos
        if (!('0'<=placa[x] && placa[x]<='9')){
            correto=false;
        }
    }

    return (correto);
}

void questao6(){
    printf ("\n\n--Questao 6--\n\n");

    char placa[8];
    int total=0;

    printf ("\nDigite \"0000000\" para parar\n");

    printf ("\nplaca = ");
    scanf ("%s", placa);
    getchar();

    while ((strcmp(placa, "0000000")!=0)){
        printf ("\n%s, %s\n\n", placa, mercosul(placa)?"placa esta correta":"placa nao esta correta");

        if (mercosul(placa)){
            total++;
        }

        printf ("\nDigite \"0000000\" para parar\n");
        printf ("\nplaca = ");
        scanf ("%s", placa);
        getchar();
    }
    printf ("\nTotal = %d\n", total);

    printf ("\nAperte ENTER parar continuar\n");
    getchar();
}

bool isArmstrong (int n){
    bool correto=false;
    int x=0;
    int numero=n;
    int digitos[3];

    if (99<=n && n<=999){
        for (int i=0; i<3; i++){
            x=numero%10;
            digitos[i]=x;
            numero/=10;
        }
    }

    //testar numero de armstrong
    if (0<=n && n<=9){
        correto=true;
    }
    else if (100<=n && n<=999){
        if (pow(digitos[0], 3) + pow(digitos[1], 3) + pow(digitos[2], 3) == n){
            correto=true;
        }
    }

    return(correto);
}

int contar(){
    int n=0;
    int contador=0;

    while (n<999){
        if (isArmstrong(n)){
            contador++;
        }
        n++;
    }
    return(contador);
}

void questao7(){
    printf ("\n\n--Questao 7--\n\n"); //determinar numeros de armstrong de 0 a 999

    int n=0;

    printf("Numeros de Armstrong no intervalo [0, 999]: \n\n");

    while (n<999){
        if (isArmstrong(n)){
            printf ("%d\n", n);
        }
        n++;
    }
    printf ("\nTotal = %d\n", contar());

    printf ("\nAperte ENTER parar continuar\n");
    getchar();
}

double somatorioA(int n){
    double resultado=0;
    double a=1, b=2;
    double padrao1=(1.0/a);

    for (int i=1; i<=n; i++){
        if (i%3==0){
            resultado-=1/b;
            b+=2;
        }else{
            resultado+=1/a;
            a+=2;
        }
    }

    return(resultado); //se n==6, resultado esperado = 0.92
}

void questao8a(){
    printf ("\n\n--Questao 8a--\n\n"); // 1/1 + 1/3 - 1/2 + 1/5 + 1/7 - 1/4....

    int k=0;

    printf ("Sequencia: 1/1 + 1/3 - 1/2 + 1/5 + 1/7 - 1/4....\n\n");
    printf ("Insira um valor: ");
    scanf ("%d", &k);
    getchar();

    printf ("\nSoma de %d numeros da sequencia = %lf\n", k, somatorioA(k));

    printf ("\nAperte ENTER parar continuar\n");
    getchar();
}

double somatorioB (int n){
    double resultado=0;
    double a=1.0, b=13.0, c=2.0;

    for (int i=1; i<=n; i++){
        if (i%3==0){ //testar se e' o terceiro digito da sequencia
            resultado-=(1.0/c);
            c+=2;
        }else if (i%2==0){ //testar se e' o segundo digito
            resultado+=b;
            b=pow(ceil(b/2), -1.0);
        }else{ //testar se e' o primeiro
            resultado+=(1.0/a);
            a+=4;
        }
    }

    return (resultado); //se n==6, resultado esperado = 13.59
}

void questao8b(){
    printf ("\n\n--Questao 8b--\n\n"); //1/1 + 13 - 1/2 + 1/5 + 1/7 - 1/4....

    int k=0;

    printf ("Sequencia: 1/1 + 13 - 1/2 + 1/5 + 1/7 - 1/4....\n\n");
    printf ("Insira um valor: ");
    scanf ("%d", &k);
    getchar();

    printf ("\nSoma de %d numeros da sequencia = %lf\n", k, somatorioB(k));

    printf ("\nAperte ENTER parar continuar\n");
    getchar();
}

int main(){
    int opcao=0;

    do{
        printf ("\n\n--Correcao prova 1--\n\n");
        printf ("[0] Parar\n");
        printf ("[1] Questao 1\n");
        printf ("[2] Questao 2\n");
        printf ("[3] Questao 3\n");
        printf ("[4] Questao 4\n");
        printf ("[5] Questao 5\n");
        printf ("[6] Questao 6\n");
        printf ("[7] Questao 7\n");
        printf ("[8] Questao 8 versao A\n");
        printf ("[9] Questao 8 versao B\n\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
            case 0:
            break;
            case 1:
            questao1();
            break;
            case 2:
            questao2();
            break;
            case 3:
            questao3();
            break;
            case 4:
            questao4();
            break;
            case 5:
            questao5();
            break;
            case 6:
            questao6();
            break;
            case 7:
            questao7();
            break;
            case 8:
            questao8a();
            break;
            case 9:
            questao8b();
            break;
            default:
            printf ("Valor invalido\n");
            printf ("\nAperte ENTER para continuar\n");
            getchar();
        }
    }while(opcao!=0);

    printf ("\nAperte ENTER para terminar\n");
    getchar();
    return 0;
}