//Bernardo Marques Fernandes - 774119
//AEDs I - Ed14

#include "bibliotecas/Bernardo.hpp"
#include "bibliotecas/Erro.hpp"
#include "bibliotecas/Main_Class.hpp"

using namespace std;

void exemplo01(){
    introf("14", "01");

    Ed14 ex01;
    ex01.setString();

    cout<<"\nstring: "<<ex01.getString()<<"\tint: "<<ex01.getInt();
    ex01.printErroMsg();

    endf();
}

void exemplo02(){
    introf("14", "02");

    Ed14 ex02;
    ex02.setString();

    cout<<"\nstring: "<<ex02.getString()<<"\tdouble: "<<ex02.getDouble();
    ex02.printErroMsg();

    endf();
}

void exemplo03(){
    introf("14", "03");

    Ed14 ex03;
    ex03.setString();

    cout<<"\nstring: "<<ex03.getString()<<"\tboolean: "<<ex03.getBoolean();
    ex03.printErroMsg();

    endf();
}

void exemplo04(){
    introf("14", "04");

    Ed14 ex04;
    ex04.setString();

    if(ex04.contains(readString("Digite uma substring a ser procurada: ")))
        cout<<"\nA substring esta presente na string original";
    ex04.printErroMsg();

    endf();
}

void exemplo05(){
    introf("14", "05");

    Ed14 ex05;
    ex05.setString();

    cout<<"\nstring: "<<ex05.getString()<<"\tupper string: "<<ex05.toUpperCase();
    ex05.printErroMsg();

    endf();
}

void exemplo06(){
    introf("14", "06");

    Ed14 ex06;
    ex06.setString();

    cout<<"\nstring: "<<ex06.getString()<<"\tlower string: "<<ex06.toLowerCase();
    ex06.printErroMsg();

    endf();
}

void exemplo07(){
    introf("14", "07");

    Ed14 ex07;
    ex07.setString();

    char original = readChar();
    char novo = readChar("\nDigite outro caractere: ");

    string novaString = ex07.replace(original, novo);

    cout<<"\nstring: "<<ex07.getString()<<"\tcaracteres trocados: "<<novaString;

    endf();
}

void exemplo08(){
    introf("14", "08");

    Ed14 ex08;
    ex08.setString();

    string* sequencia = ex08.split(sequencia);

    for(int i=0; i<ex08.countWords(); i++)
        cout<<"\nsequencia ["<<i+1<<"]:"<<"\t"<<sequencia[i];

    cout<<"\n\nQuantidade de sequencias: "<<ex08.countWords();

    endf();
}

void exemplo09(){
    introf("14", "09");

    Ed14 ex09;
    ex09.setString();

    cout<<"\nstring original: "<<ex09.getString();
    cout<<"\nstring criptografada: "<<ex09.encrypt();

    endf();
}

void exemplo10(){
    introf("14", "10");

    Ed14 ex10;
    ex10.setString();

    cout<<"\nstring original: "<<ex10.getString();
    cout<<"\nstring encriptada: "<<ex10.encrypt();
    cout<<"\nstring descriptada: "<<ex10.decrypt();

    endf();
}

void exemploE1(){
    introf("14", "E1");

    Ed14 exE1;
    exE1.setString();

    char c = readChar();
    string* sequencia = exE1.split(sequencia, c);

    for(int i=0; i<exE1.countWords(c); i++)
        cout<<"\nsequencia ["<<i+1<<"]:"<<"\t"<<sequencia[i];

    cout<<"\n\nQuantidade de sequencias: "<<exE1.countWords(c);

    endf();
}

void exemploE2(){
    introf("14", "E2");

    Ed14 exE2;
    exE2.setString();

    cout<<"\nstring: "<<exE2.getString();
    exE2.inverter();
    cout<<"\tstring invertida: "<<exE2.getString();

    endf();
}

int main(){
    int opcao;
    bool sair = false;
    
    do{
        opcao = menu("14");
        switch(opcao){
            case 0: sair=quit(); break;
            case 1: exemplo01(); break;
            case 2: exemplo02(); break;
            case 3: exemplo03(); break;
            case 4: exemplo04(); break;
            case 5: exemplo05(); break;
            case 6: exemplo06(); break;
            case 7: exemplo07(); break;
            case 8: exemplo08(); break;
            case 9: exemplo09(); break;
            case 10: exemplo10(); break;
            case 11: exemploE1(); break;
            case 12: exemploE2(); break;
            default: std::cout<<"\nValor Invalido\nPress ENTER"; getchar();
        }
    }while(!sair);

    clear();
    return 0;
}