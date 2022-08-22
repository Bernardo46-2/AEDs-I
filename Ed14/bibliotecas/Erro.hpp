#include <string>

#ifndef _ERRO_H_
#define _ERRO_H_

class Erro{
    /*
    Codigos de erro:

    0. Nao ha erro.
    1. Nao foi possivel retornar o valor inteiro
    2. Nao foi possivel retornar o valor real
    3. Nao foi possivel retornar o valor logico
    4. Nao foi possivel encontrar a substring
    5. Nao foi possivel alocar memoria para dividir string
    6. Nao foi possivel inverter string
    */

    private:
    int erro;

    public:
    ~Erro(){}

    Erro(){
        erro = 0;
    }

    static const std::string NO_ERROR;

    int getErro(){
        return erro;
    }

    bool hasError(){
        return getErro() != 0;
    }
    
    virtual std::string getErroMsg(){
        std::string erroMsg = "";

        switch(this->erro){
            case 0: break;
            case 1: erroMsg = "\n\n[ERRO] Nao foi possivel converter valor para inteiro"; break;
            case 2: erroMsg = "\n\n[ERRO] Nao foi possivel converter valor para real"; break;
            case 3: erroMsg = "\n\n[ERRO] Nao foi possivel converter valor para valor logico"; break;
            case 4: erroMsg = "\n\n[ERRO] Nao foi possuvel encontrar a substring"; break;
            case 5: erroMsg = "\n\n[ERRO] Nao foi possivel alocar memoria para dividir string"; break;
            case 6: erroMsg = "\n\n[ERRO] Nao foi possivel inverter a string"; break;
            default: erroMsg = "\n\nCodigo de erro invalido"; break;
        }

        return erroMsg;
    }

    void printErroMsg(){
        std::string erroMsg = getErroMsg();
        std::cout<<erroMsg;
    }

    protected:
    void setErro(int codigo){
        this->erro = codigo;
    }
};

const std::string Erro::NO_ERROR = "[ERRO] Nao ha' erro.";

#endif