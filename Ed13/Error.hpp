#ifndef _ERRO_H_
#define _ERRO_H_

#include "Bernardo.hpp"

class Error{
    private:
    int erro;
    
    protected:
    void setError(int codigo){
        erro=codigo;
    }

    public:
    ~Error(){}
    
    Error(){
        erro=0;
    }

    int getError(){
        return erro;
    }

    bool hasError(){
        return getError()!=0;
    }
};
#endif