//Bernardo Marques Fernandes - 774119
//AEDs I - Ed11

#include "Bernardo.hpp"
#include "myArray.hpp"

void exemplo11(){
    std::cout<<"\n\n--Ed11 - Exemplo1111--\n";

    int n=readIntNatC("\nDigite o tamanho do array: ");
    Array <int> intArray(n, 0);

    srand(time(0));
    intArray.random();
    intArray.fprint("dados.txt");

    intArray.free();
    endf();
}

void exemplo12(){
    std::cout<<"\n\n--Ed11 - Exemplo1112--\n";

    Array<int>intArray;
    intArray.fread("dados.txt");

    std::cout<<"\nArray: \n";
    intArray.print();
    int maior=intArray.findLargest();
    std::cout<<"\nO maior numero do array e' \""<<maior<<"\"";

    intArray.free();
    endf();
}

void exemplo13(){
    std::cout<<"\n\n--Ed11 - Exemplo1113--\n";

    Array<int>intArray;
    intArray.fread("dados.txt");

    std::cout<<"\nArray: \n";
    intArray.print();
    int menor=intArray.findLowest();
    std::cout<<"\nO menor numero do array e' \""<<menor<<"\"";

    intArray.free();
    endf();
}

void exemplo14(){
    std::cout<<"\n\n--Ed11 - Exemplo1114--\n";

    Array<int>intArray;
    intArray.fread("dados.txt");

    std::cout<<"\nArray: \n";
    intArray.print();
    int soma=intArray.sumValues();
    std::cout<<"\nA soma de todos os numeros do array e' \""<<soma<<"\"";

    intArray.free();
    endf();
}

void exemplo15(){
    std::cout<<"\n\n--Ed11 - Exemplo1115--\n";

    Array<int>intArray;
    intArray.fread("dados.txt");

    std::cout<<"\nArray: \n";
    intArray.print();
    int media=intArray.findMean();
    std::cout<<"\nA media dos numeros do array e' \""<<media<<"\"";

    intArray.free();
    endf();
}

void exemplo16(){
    std::cout<<"\n\n--Ed11 - Exemplo1116--\n";

    Array<int>intArray;
    intArray.fread("dados.txt");

    std::cout<<"\nArray: \n";
    intArray.print();
    bool teste=intArray.allZeros();
    std::cout<<"\nO array "<<(teste?"possui":"nao possui")<<" apenas zeros";

    intArray.free();
    endf();
}

void exemplo17(){
    std::cout<<"\n\n--Ed11 - Exemplo1117--\n";

    Array<int>intArray;
    intArray.fread("dados.txt");

    std::cout<<"\nArray: \n";
    intArray.print();
    bool teste=intArray.decrescent();
    std::cout<<"\nO array "<<(teste?"esta":"nao esta")<<" ordenado decrescentemente";

    intArray.free();
    endf();
}

void exemplo18(){
    std::cout<<"\n\n--Ed11 - Exemplo1118--\n";

    Array<int>intArray;
    intArray.fread("dados.txt");

    int procurado=readIntC("\nDigite o numero a ser procurado: ");
    int posicaoA=readIntC("Digite o limite inferior para a procura: ");
    int posicaoB=readIntC("Digite o limite superior para a procura: ");

    int existe=intArray.findValue(procurado, posicaoA, posicaoB);
    
    std::cout<<"\nArray: \n";
    intArray.print();
    if(existe==-1)
        std::cout<<"\nO numero "<<procurado<<" nao existe entre as posicoes informadas";
    else
        std::cout<<"\nO numero "<<procurado<<" existe entre as posicoes informadas e esta na posicao ["<<existe<<"]";

    intArray.free();
    endf();
}

void exemplo19(){
    std::cout<<"\n\n--Ed11 - Exemplo1119--\n";

    Array<int>intArray1;
    intArray1.fread("dados.txt");
    Array<int>intArray2(intArray1);
    intArray2.scale(readIntC("\nDigite uma constante para escalar array: "));

    std::cout<<"\nArray: \n";
    intArray1.print();
    std::cout<<"\nArray escalado por constante: \n";
    intArray2.print();

    intArray1.free();
    intArray2.free();
    endf();
}

void exemplo20(){
    std::cout<<"\n\n--Ed11 - Exemplo1120--\n";

    Array<int>intArray;
    intArray.fread("dados.txt");

    std::cout<<"\nArray:\n";
    intArray.print();
    intArray.ordenDecrescent();
    std::cout<<"\nArray ordenado decrescentemente:\n";
    intArray.print();

    intArray.free();
    endf();
}

void exemploE1(){
    std::cout<<"\n\n--Ed11 - Exemplo11E1--\n";

    Array<int>intArray1;
    Array<int>intArray2;
    intArray1.fread("exemploE1a.txt");
    intArray2.fread("exemploE1a.txt");

    std::cout<<"\nArray 1:\n";
    intArray1.print();
    std::cout<<"Array 2:\n";
    intArray2.print();

    if(intArray1!=intArray2)
        std::cout<<"\nOs arrays sao diferentes";
    else
        std::cout<<"\nOs arrays sao iguais";

    endf();
    intArray2.fread("exemploE1b.txt");

    std::cout<<"\n\nArray 1:\n";
    intArray1.print();
    std::cout<<"Array 2:\n";
    intArray2.print();
    
    if(intArray1!=intArray2)
        std::cout<<"\nOs arrays sao diferentes";
    else
        std::cout<<"\nOs arrays sao iguais";

    intArray1.free();
    intArray2.free();
    endf();
}

void exemploE2(){
    std::cout<<"\n\n--Ed11 - Exemplo11E2--\n";

    int n=readIntNat();
    Array<int>intArray1(n, 0);
    Array<int>intArray2(n, 0);
    Array<int>intArray3;
    srand(1);
    intArray1.random();
    srand(2);
    intArray2.random();
    intArray3=intArray1-intArray2;

    std::cout<<"\nArray 1:\n";
    intArray1.print();
    std::cout<<"Array 2:\n";
    intArray2.print();
    std::cout<<"Diferencas entre Array 1 e Array 2:\n";
    intArray3.print();

    intArray1.free();
    intArray2.free();
    intArray3.free();
    endf();
}

int main(){
    int opcao;
    do{
        opcao=menu("11");
        switch(opcao){
            case 0: break;
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
    }while (opcao!=0);

    endf();
    return 0;
}