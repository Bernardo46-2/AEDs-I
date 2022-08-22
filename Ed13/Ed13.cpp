//Bernardo Marques Fernandes - 774119
//AEDs I - Ed13

#include "Contato.hpp"
using namespace std;

void exemplo11(){
    introf("13", "11");

    Contato pessoa;
    pessoa.readName();

    cout<<pessoa.toString();

    endf();
}

void exemplo12(){
    introf("13", "12");
    
    Contato pessoa;
    pessoa.readFone();

    cout<<pessoa.toString();

    endf();
}

void exemplo13(){
    introf("13", "13");

    Contato pessoa;
    pessoa.readName();
    pessoa.readFone();

    if(pessoa.hasError()){
        cout<<"\n\nPessoa tem erro("<<pessoa.getError()<<")";
    }else{
        cout<<pessoa.toString();
    }

    endf();
}

void exemplo14(){
    introf("13", "14");

    Contato pessoa;
    pessoa.fromFile("pessoa1.txt");

    pessoa.print();
    pessoa.printError();

    endf();
}

void exemplo15(){
    introf("13", "15");

    Contato pessoa("pessoa2", "87654-3210");
    pessoa.print();
    pessoa.printError();
    pessoa.toFile("pessoa2.txt");

    endf();
}

void exemplo16(){
    introf("13", "16");

    Contato pessoa;
    pessoa.readName();
    pessoa.readFone();
    pessoa.print();
    pessoa.printError();

    endf();
}

void exemplo17(){
    introf("13", "17");

    Contato pessoa;
    pessoa.readName();
    pessoa.readFone();
    pessoa.print();
    pessoa.printNumberOfFones();
    pessoa.printError();

    endf();
}

void exemplo18(){
    introf("13", "18");
    
    Contato pessoa;
    pessoa.readName();
    pessoa.readFone();
    pessoa.print();
    pessoa.editFone(1);
    pessoa.print();

    endf();
}

void exemplo19(){
    introf("13", "19");
    
    Contato pessoa;
    pessoa.readName();
    pessoa.readFone();
    pessoa.print();
    pessoa.editFone(1);
    pessoa.print();

    endf();
}

void exemplo20(){
    introf("13", "20");

    Contato pessoa;
    pessoa.readName();
    pessoa.readFone();
    pessoa.print();
    pessoa.removeFone(1);
    pessoa.print();

    endf();
}

void exemploE1(){
    introf("13", "E1");

    Contato pessoa;
    pessoa.readName();
    pessoa.readFone();
    pessoa.print();
    pessoa.printNumberOfFones();
    pessoa.printError();

    endf();
}

void exemploE2(){
    introf("13", "E2");

    Contato pessoa;
    pessoa.readName();
    pessoa.readFone();
    pessoa.readRAddress();
    pessoa.readPAddress();
    pessoa.print();
    pessoa.printError();

    endf();
}

int main(){
    int opcao;
    bool sair=false;
    
    do{
        opcao=menu("13");
        switch(opcao){
            case 0: sair=quit(); break;
            case 1: exemplo11(); break;
            case 2: exemplo12(); break;
            case 3: exemplo13(); break;
            case 4: exemplo14(); break;
            case 5: exemplo15(); break;
            case 6: exemplo16(); break;
            case 7: exemplo17(); break;
            case 8: exemplo18(); break;
            case 9: exemplo19(); break;
            case 10: exemplo20(); break;
            case 11: exemploE1(); break;
            case 12: exemploE2(); break;
            default: std::cout<<"\nValor Invalido\nPress ENTER"; getchar();
        }
    }while(sair==false);

    clear();
    return 0;
}