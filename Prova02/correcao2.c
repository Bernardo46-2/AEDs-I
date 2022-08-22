//Bernardo Marques Fernandes - 774119
//AEDs I - Correcao da Segunda Prova

#include "Bernardo.h"
#include <time.h>

void questao01(){
    clear();
    printf("\nQuestao 01");
    printf("\nBernardo Marques Fernandes - 774119\n");

    int array[]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int x=0, y=0, z=0;

    for(x=3; x<7; x++){
        z=array[x];
        for(y=x; y<10; y++){
            array[y]=array[y+1];
        }
        array[y-1]=z;
    }

    printf("\nQual a saida esperada?");
    printf("\na) 0 1 2 4 6 8 3 5 7 9");
    printf("\nb) 0 1 2 4 6 3 8 7 5 9");
    printf("\nc) 0 1 2 4 8 6 5 3 7 9");
    printf("\nd) 0 1 2 4 8 6 5 3 9 7");

    printf("\n\nResposta: A");
    printf("\n");
    for(x=0; x<10; x++){
        printf("%d ", array[x]);
    }

    endf();
}

void questao02(){
    clear();
    printf("\nQuestao 02");
    printf("\nBernardo Marques Fernandes - 774119\n");

    int array[][3]={{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
    int x=0, y=0, z=0;

    for(x=0; x<3; x++){
        z=array[2-x][2-x];
        for(y=2; y>=0; y--){
            array[y][x]=array[x][y];
            if(x==y){
                array[x][y]=z;
            }
        }
    }

    printf("\nQual a saida equivalente?");
    printf("\na) {{8, 7, 2}, {3, 4, 5}, {5, 2, 7}}");
    printf("\na) {{8, 2, 1}, {1, 4, 7}, {2, 7, 8}}");
    printf("\na) {{8, 1, 2}, {1, 4, 5}, {2, 5, 8}}");
    printf("\na) {{8, 2, 7}, {3, 5, 4}, {2, 5, 7}}");

    printf("\n\nResposta: C\n");
    for(x=0; x<3; x++){
        for(y=0; y<3; y++){
            printf("%d\t", array[x][y]);
        }
        printf("\n");
    }

    endf();
}

char* substring(int start, int end, char *source){
    char* destiny=null;
    int x=0, y=0;

    destiny=malloc(strlen(source)*sizeof(char));
    destiny[y]='\0';

    for(x=start; x<end; x++){
        destiny[y]=source[x];
        y++;
    }

    return destiny;
}

void questao03(){
    clear();
    printf("\nQuestao 03");
    printf("\nBernardo Marques Fernandes - 774119\n");

    printf("\nQual chamada tera o resultado correto?");
    printf("\na) \"bcd\" = substring(1, 4, \"abcde\")");
    printf("\nb) \"e\" = substring(4, 6, \"abcde\")");
    printf("\nc) \"abc\" = substring(0, 3, \"abcde\")");
    printf("\nd) \"de\" = substring(3, 5, \"abcde\")");

    printf("\n\nRespostas: ");
    printf("\na) ");
    printf(substring(1, 4, "abcde"));
    printf("\nb) ");
    printf(substring(4, 6, "abcde"));
    printf("\nc) ");
    printf(substring(0, 3, "abcde"));
    printf("\nd) ");
    printf(substring(3, 5, "abcde"));

    printf("\n\nResposta: B");

    endf();
}

int f04(int x, char*s){
    int result=0;

    if(0<=x && x<strlen(s)){
        result=(s[x]=='0' || s[x]=='1') && f04(x+1, s);
    }else{
        result=1;
    }

    return result;
}

void questao04(){
    clear();
    printf("\nQuestao 04");
    printf("\nBernardo Marques Fernandes - 774119\n");

    printf("\nQual chamada tera o resultado falso(0)?");
    printf("\na) f04(3, \"01|O\"");
    printf("\nb) f04(2, \"0|10\"");
    printf("\nc) f04(1, \"O110\"");
    printf("\nd) f04(0, \"0110\"");

    printf("\n\nRespostas: ");
    printf("\na) %d", f04(3, "01|O"));
    printf("\nb) %d", f04(2, "0|10"));
    printf("\nc) %d", f04(1, "O110"));
    printf("\nd) %d", f04(0, "0110"));

    printf("\n\nResposta: A");

    endf();
}

int f05(char* s1, char* s2){
    int result=0;
    int x=0, y=0, z=0;

    for(x=0; x<strlen(s1); x++){
        for(y=1; y<strlen(s2); y++){
            if(s1[x]==s2[y]){
                z++;
                y=strlen(s2);
            }
        }
    }
    result=(z==strlen(s1));
    return result;
}

void questao05(){
    clear();
    printf("\nQuestao 05");
    printf("\nBernardo Marques Fernandes - 774119\n");

    printf("\nQual chamada terá o resultado verdadeiro(1)?");
    printf("\na) f05(\"alice\", \"celia\")");
    printf("\na) f05(\"aroma\", \"amora\")");
    printf("\na) f05(\"pato\", \"apto\")");
    printf("\na) f05(\"alegria\", \"galeria\")");

    printf("\n\nRespostas: ");
    printf("\na) %d", f05("alice", "celia"));
    printf("\na) %d", f05("aroma", "amora"));
    printf("\na) %d", f05("pato", "apto"));
    printf("\na) %d", f05("alegria", "galeria"));

    printf("\n\nResposta: B");

    endf();
}

struct s_ac{
    int a;
    char c;
};

void questao06a(){
    struct s_ac s[5];
    int x=0, y=0;

    for(x=0; x<5; x++){
        s[x].a=x;
        s[x].c=(char)('A'+x);
    }

    while(x>0){
        y=5;
        while(y>0){
            if(x-1==s[y-1].a){
                printf("%d%c", s[y-1].a, s[y-1].c);
                y=0;
            }
            y-=2;
        }
        x--;
    }
}

void questao06(){
    clear();
    printf("\nQuestao 06");
    printf("\nBernardo Marques Fernandes - 774119\n");

    printf("\nQual a saida esperada?");
    printf("\na) 4E3C2B");
    printf("\nb) 5E3C1A");
    printf("\nc) 4E2C0A");
    printf("\nd) 5D2C0B");

    printf("\n\nResposta = C\n");
    questao06a();

    endf();
}

int f07(char* s){
    int achar=0;
    int x=0, y=0, z=0;

    for(x=0; x<strlen(s); x++){
        if(s[x]=='-'){
            if(0<=x && x<strlen(s) && ((s[x-1]==s[x+1] && s[x+1]=='r') || (s[x-1]=='i'))){
                achar=1;
            }
        }
    }
    return achar;
}

void questao07(){
    clear();
    printf("\nQuestao 07");
    printf("\nBernardo Marques Fernandes - 774119\n");

    printf("\nQual a saida tera o resultado FALSO(0)?");
    printf("\na) f07(\"anti-horario\")");
    printf("\nb) f07(\"inter-relacao\")");
    printf("\nc) f07(\"super-homem\")");
    printf("\nd) f07(\"anti-inflamatorio\")");

    printf("\n\nResposta: ");
    printf("\na) %d", f07("anti-horario"));
    printf("\nb) %d", f07("inter-relacao"));
    printf("\nc) %d", f07("super-homem"));
    printf("\nd) %d", f07("anti-inflamatorio"));

    printf("\n\nResposta: C");

    endf();
}

void questao08(char* filename){
    clear();
    printf("\nQuestao 08");
    printf("\nBernardo Marques Fernandes - 774119\n");

    FILE* ler=fopen(filename, "r");
    double primeiro, meio, ultimo;
    int i=0;

    for(i; !feof(ler); i++){
        if(i==0)
            fscanf(ler, "%lf", &primeiro);
        else
            fscanf(ler, "%lf", &ultimo);
    }

    fclose(ler);
    if(i%2==0){
        printf("\nArquivo possui quantidade par de numeros");
        endf();
        return;
    }

    FILE* ler2=fopen(filename, "r");

    for(int j=0; j<=i/2; j++){
        fscanf(ler2, "%lf", &meio);
    }

    fclose(ler2);
    double media=(primeiro+meio+ultimo)/3.0;

    FILE* apd=fopen(filename, "a");
    fprintf(apd, "\n%lf", media);
    fclose(apd);

    printf("\nMedia acrescentada no arquivo");

    endf();
}

double questao09a(int rows, int columns, int matrix[][columns]){
    if(rows!=columns){
        printf("\nERRO: a matriz nao e' quadrada");
        int x=readInt();
        return questao09a(x, x, matrix);
    }

    int soma1=0, soma2=0;

    for(int i=0; i<rows; i++){
        for(int j=(i+1); j<columns; j++){
            soma1+=matrix[i][j];
        }
    }

    soma1--;

    if(soma1==0){
        printf("\nERRO: o denominador nao pode ser 0");
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                matrix[i][j]=randInt(0, 101);
            }
        }
        return questao09a(rows, columns, matrix);
    }

    for(int i=0; i<rows; i++){
        for(int j=(columns-i); j<columns; j++){
            soma2+=matrix[i][j];
        }
    }

    return (double)soma2/(double)soma1;
}

void questao09(){
    clear();
    srand(time(0));
    printf("\nQuestao 09");
    printf("\nBernardo Marques Fernandes - 774119\n");

    int rows=readInt(), columns=readInt();
    int matrix[rows][columns];

    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            matrix[i][j]=randInt(0, 101);
        }
    }

    double resposta=questao09a(rows, columns, matrix);

    if(resposta==-1)
        printf("\nERRO: A matriz possui dimensoes diferentes ou o denominador da resposta e' igual a 0");
    else{
        printf("\n\nResultado = %lf\n\n", resposta);
        
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                printf("%3d ", matrix[i][j]);
            }
            printf("\n");
        }
    }

    endf();
}

void questao10a(int* a, int*b){
    if(*a>*b){
        int temp;
        temp=*a;
        *a=*b;
        *b=temp;
    }
}

void questao10(){
    clear();
    printf("\nQuestao 10");
    printf("\nBernardo Marques Fernandes - 774119\n");

    int x=readInt();
    int y=readInt();

    int* a=&x;
    int* b=&y;

    printf("\na = %d", *a);
    printf("\nb = %d\n", *b);

    questao10a(a, b);

    printf("\na = %d", *a);
    printf("\nb = %d", *b);

    endf();
}

int main(){
    clear();
    int opcao;
    bool sair=false;

    do{
        clear();
        printf("\nAEDs I - Correcao da Segunda Prova");
        printf("\nBernardo Marques Fernandes - 774119\n");
        printf("\n0 - Sair");
        printf("\n1 - Questao 01");
        printf("\n2 - Questao 02");
        printf("\n3 - Questao 03");
        printf("\n4 - Questao 04");
        printf("\n5 - Questao 05");
        printf("\n6 - Questao 06");
        printf("\n7 - Questao 07");
        printf("\n8 - Questao 08");
        printf("\n9 - Questao 09");
        printf("\n10 - Questao 10");
        printf("\n");
        opcao=readInt();

        switch(opcao){
            case 0: sair=quit(); break;
            case 1: questao01(); break;
            case 2: questao02(); break;
            case 3: questao03(); break;
            case 4: questao04(); break;
            case 5: questao05(); break;
            case 6: questao06(); break;
            case 7: questao07(); break;
            case 8: questao08("questao08.txt"); break;
            case 9: questao09(); break;
            case 10: questao10(); break;
            default: printf("\nValor invalido!"); endf(); break; 
        }
    }while(sair==false);

    clear();
    return 0;
}