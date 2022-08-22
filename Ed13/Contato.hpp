#ifndef _CONTATO_H_
#define _CONTATO_H_

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <iomanip>
using std::setw;
#include <string>
using std::string;
#include <fstream>
using std::ofstream;
using std::ifstream;

void pause(std::string text){
    std::string dummy;
    std::cin.clear();
    std::cout<<std::endl<<text;
    std::cin.ignore();
    std::getline(std::cin, dummy);
    std::cout<<std::endl<<std::endl;
}

#include "Error.hpp"

/*
Codigos de erro:

0 - nao ha erro
1 - nome vazio
2 - fone vazio
3 - ja tem nome
4 - ja tem fone
5 - fone invalido
6 - endereco residencial vazio
7 - endereco profissional vazio
*/

class Contato: public Error{
    private:
    string nome;
    string fone[10];
    string enderecoResidencial;
    string enderecoProfissional;

    void validFone(string newFone){
        if(in(newFone, "-")==false){
            setError(5);
            return;
        }
        
        for(int i=0; i<newFone.length(); i++){
            if(i!=newFone.length()-5 && isNumber(newFone[i])==false){
                setError(5);
            }
        }
    }

    public:
    ~Contato(){}

    Contato(){
        setError(0);

        nome="";
        for(int i=0; i<10; i++){
            fone[i]="";
        }
    }

    void setName(std::string nome){
        if(nome.empty())
            setError(1); 
        else
            this->nome=nome;
    }

    void setFone(std::string newFone){
        if(newFone.empty())
            setError(2);
        else{
            for(int i=0; i<10; i++){
                if(this->fone[i].empty()){
                    this->fone[i]=newFone;
                    break;
                }
            }
        }
    }

    std::string getNome(){
        return this->nome;
    }

    std::string getFone(int position){
        return this->fone[position];
    }

    std::string toString(){
        string s="\n{ ";

        if(this->nome.empty()==false)
            s+=getNome();
        
        for(int i=0; i<10; i++)
            if(this->fone[i].empty()==false){
                s+=", ";
                s+=getFone(i);
            }

        if(!this->enderecoResidencial.empty()){
            s+=", ";
            s+=getResidentialAddress();
        }

        if(!this->enderecoProfissional.empty()){
            s+=", ";
            s+=getProfessionalAddress();
        }
        
        s+=" }\n";

        return s;
    }

    Contato(std::string nome_inicial, std::string fone_inicial){
        setError(0);

        setName(nome_inicial);
        setFone(fone_inicial);
    }

    Contato(Contato const &another){
        setError(0);

        setName(another.nome);

        for(int i=0; i<10; i++){
            setFone(another.fone[i]);
        }
    }

    bool isNameEmpty(){
        return this->nome.empty();
    }

    void readName(){
        std::string newName=readString("\nNome: ");
        
        if(!isNameEmpty()){
            setError(3);
        }else if(newName.empty()){
            setError(1);
        }else{
            setName(newName);
            setError(0);
        }
    }
    
    void readFone(){
        std::string newFone;

        do{
            newFone=readString("\nFone: ");

            if(numberOfFones()==10){
                setError(4);
            }else if(newFone.empty()){
                setError(2);
            }else{
                setFone(newFone);
                setError(0);
            }
        }while(readYN("Gravar outro telefone?") && numberOfFones()<10);
        
        validFone(newFone);
    }

    int numberOfFones(){
        int n=0;

        for(int i=0; i<10; i++)
            if(this->fone[i].empty()==false)
                n++;

        return n;
    }

    void printNumberOfFones(){
        cout<<"\n"<<this->nome<<" tem "<<numberOfFones()<<" telefones";
    }

    void fromFile(string filename){
        ifstream file(filename);

        if(file.is_open()){
            int howManyFones;
            file>>howManyFones;

            string tempName;
            string tempFone;

            file>>tempName;
            setName(tempName);

            for(int i=0; i<howManyFones; i++){
                file>>tempFone;
                setFone(tempFone);
                validFone(tempFone);
            }

            file>>this->enderecoResidencial;
            file>>this->enderecoProfissional;
            
            if(tempName.empty())
                setError(1);
            else if(tempFone.empty())
                setError(2);
            
            file.close();
        }else{
            cout<<"\nArquivo nao encontrado";
        }
    }

    void toFile(string filename){
        ofstream file(filename);

        int n=numberOfFones();
        file<<n<<endl;
        
        file<<this->nome<<endl;
        
        for(int i=0; i<10; i++)
            if(this->fone[i].empty()==false)
                file<<this->fone[i]<<endl;

        file<<this->enderecoResidencial;
        file<<this->enderecoProfissional;

        cout<<"\nDados salvos no arquivo \""<<filename<<"\"";

        file.close();
    }

    void print(){
        if(hasError()){
            cout<<"\n\n"<<this->nome<<" tem erro ("<<getError()<<")";
        }else{
            cout<<"\n\n"<<toString();
        }
    }

    void printError(){
        switch(getError()){
            case 0: break;
            case 1: cout<<"\nErro (1): Nome vazio"; break;
            case 2: cout<<"\nErro (2): Telefone vazio"; break;
            case 3: cout<<"\nErro (3): Nome ja preenchido"; break;
            case 4: cout<<"\nErro (4): Todos telefones ja preenchidos"; break;
            case 5: cout<<"\nErro (5): Fone invalido"; break;
            case 6: cout<<"\nErro (6): Endereco residencial vazio"; break;
            case 7: cout<<"\nErro (7): Endereco profissional vazio"; break;
        }
    }

    void editFone(int posicao){
        if(posicao<0 || posicao>=10){
            cout<<"\nTelefone invalido";
        }else{
            cout<<"\nEditando telefone "<<posicao+1;
            this->fone[posicao]=readString("\nFone: ");
            validFone(this->fone[posicao]);
        }
    }

    void removeFone(int posicao){
        if(posicao<0 || posicao>=10){
            cout<<"\nTelefone invalido";
        }else{
            setError(0);
            cout<<"\nTelefone "<<posicao+1<<" removido";
            this->fone[posicao]="";
        }
    }

    void readRAddress(){
        this->enderecoResidencial=readString("\nEndereco residencial: ");
        if(this->enderecoResidencial.empty())
            setError(6);
    }

    void readPAddress(){
        this->enderecoProfissional=readString("\nEndereco profissional: ");
        if(this->enderecoProfissional.empty())
            setError(7);
    }

    std::string getResidentialAddress(){
        return this->enderecoResidencial;
    }

    std::string getProfessionalAddress(){
        return this->enderecoProfissional;
    }
};

using ref_Contato = Contato*;
#endif