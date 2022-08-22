#include <iostream>
#include "Erro.hpp"
#include "Bernardo.hpp"

#ifndef _MAINCLASS_H_
#define _MAINCLASS_H_

using namespace std;

class Ed14: public Erro{
    private:
    string s;
    int chaveNum;
    int chaveMai;
    int chaveMin;

    public:
    Ed14(){
        srand(time(0));
        setErro(0);
        chaveNum = randrange(1, 10); //chave para numeros 
        chaveMai = randrange(1, 27); //chave para letras maiusculas
        chaveMin = randrange(1, 27); //chave para letras minusculas
        s = "";
    }

    ~Ed14(){}

    string getString(){
        return this->s;
    }

    void setString(){
        this->s = readLine();
    }


    /**
        Funcao para converter conteudo para valor inteiro, se possivel.
        @return valor inteiro equivalente, se valido;
        (-1), caso contrario

        Exemplos para testes:
        0
        4
        4.0
        4.4
        -4.0
        -4.4
        -4
        asd
        4.a
        -4.a
        4.4.4
        -4.4.4
        +4.4.4
        +4
        +4.0
        +4.4
    */
    int getInt(){
        int resposta = 0;
        int howManyDots = 0;
        int dot = -1;
        int casas = 1;
        bool positivo = true;
        bool temSinal = false;

        if(this->s.empty()){
            setErro(1);
            return -1;
        }

        for(int i=0; i<this->s.length() || s[i-1] == '.'; i++){ //verificar se string e' valida
            if(i == 0 && (s[0] == '-' || s[0] == '+')){
                if(s[0] == '-')
                    positivo = false;
                else if(s[0] == '+')
                    positivo = true;
                temSinal = true;
                i = 1;
            }
            if(s[i] == '.'){
                dot = i;
                howManyDots++;
            }else if(!isNumber(s[i]) || howManyDots > 1){
                setErro(1);
                return -1;
            }
        }

        if(dot != -1) 
            for(int i=dot+1; i<this->s.length(); i++) //verificar se parte decimal e' diferente de 0
                if(s[i] != '0'){
                    setErro(1);
                    return -1;
                }

        for(int i=(dot==-1?this->s.length()-1:dot-1); i>=(temSinal?1:0); i--){ //converter para int
            resposta += ((s[i] - 48) * casas);
            casas *= 10;
        }

        return (positivo ? resposta : resposta * -1);
    }


    /**
        Funcao para converter conteudo para valor real, se possivel.
        @return valor real equivalente, se valido;
        (0.0), caso contrario

        Exemplos para testes: 
        0
        4
        4.0
        4.4
        -4.0
        -4.4
        -4
        asd
        4.a
        -4.a
        4.4.4
        -4.4.4
        +4.4.4
        +4
        +4.0
        +4.4
    */
    double getDouble(){
        int dot;
        int howManyDots = 0;
        double casas = 0.0;
        double parteInteira = 0.0;
        double parteDecimal = 0.0;
        double resposta;
        bool positivo = true;
        bool temSinal = false;

        if(this->s.empty()){
            setErro(2);
            return -1;
        }

        for(int i=0; i<this->s.length(); i++){ //verificar se string e' valida
            if(i == 0 && (s[0] == '-' || s[0] == '+')){
                if(s[0] == '-')
                    positivo = false;
                else if(s[0] == '+')
                    positivo = true;
                temSinal = true;
                i = 1;
            }
            if(s[i] == '.'){
                dot = i;
                howManyDots++;
            }else if(!isNumber(s[i]) || howManyDots > 1){
                setErro(2);
                return 0.0;
            }
        }

        if(howManyDots == 0)
            dot = s.length();
        else if(howManyDots == 1){
            casas = 10.0;
            for(int i=dot+1; i<this->s.length(); i++){ //somar parte decimal
                parteDecimal += ((s[i] - 48)/casas);
                casas *= 10;
            }
        }

        casas = 1.0;
        for(int i=dot-1; i>=(temSinal?1:0); i--){ //somar parte inteira
            parteInteira += ((s[i] - 48) * casas);
            casas *= 10;
        }

        resposta = parteInteira + parteDecimal;

        return (positivo ? resposta : resposta * -1);
    }


    /**
        Funcao para converter conteudo para valor lógico, se possivel.
        Nota: Considerar válidos: { true, false, T, F, 0, 1 }
        @return valor logico equivalente, se valido;
        false, caso contrario

        Exemplos para testes:
        true
        TRUE
        TrUe
        false
        FALSE
        FaLsE
        T
        t
        F
        f
        1
        0
        verdadeiro
        falso
    */
    bool getBoolean(){
        if(upper(this->s)=="TRUE" || upper(this->s)=="T" || this->s=="1")
            return true;
        else if(upper(this->s)=="FALSE" || upper(this->s)=="F" || this->s=="0")
            return false;
        else{
            setErro(3);
            return false;
        }
    }


    /**
        Funcao para verificar se o parametro esta’ contido no conteudo.
        @return true , se contiver (em qualquer posicao);
        false, caso contrario

        Exemplos para testes:
        abcdef, abc
        abcdef, abd
    */
    bool contains(std::string texto){
        if(texto.length() > 0 && texto.length() <= s.length())
            for(int i = 0, j = 0; i < s.length(); i++)
                if(s[i] == texto[j]){
                    j++;
                    
                    if(j == texto.length())
                        return true;
                }
        
        setErro(4);
        return false;
    }


    /**
        Funcao para converter letras para maiusculas.
        @return valor equivalente em maiusculas, se houver;
        o proprio valor, caso contrario

        Exemplos para testes:
        abcdef
        AbCdEf
        ABCDEF
        abcdef123
        AbCdEf123
        ABCDEF123
    */
    string toUpperCase(){
        for(int i=0; i<this->s.length(); i++)
            if('a'<=s[i] && s[i]<='z')
                s[i]-=32;
        return s;
    }


    /**
        Funcao para converter letras para minusculas.
        @return valor equivalente em minusculas, se houver;
        o proprio valor, caso contrario
        
        Exemplos para testes:
        abcdef
        AbCdEf
        ABCDEF
        abcdef123
        AbCdEf123
        ABCDEF123
    */
    string toLowerCase(){
        for(int i=0; i<this->s.length(); i++)
            if('A'<=s[i] && s[i]<='Z')
                s[i]+=32;
        return s;
    }


    /**
        Funcao para trocar todas as ocorrencias de certo caractere por outro novo.
        @return valor com substituicoes, se houver;
        o proprio valor, caso contrario

        Exemplos para testes:
        teste, e, a
    */
    string replace(char original, char novo){
        string s2 = this->s;

        for(int i=0; i<s2.length(); i++)
            if(s2[i] == original)
                s2[i] = novo;
        return s2;
    }


    /**
        Funcao para separar todas as sequencias de caracteres separadas por espaços em branco.
        @param sequencia - arranjo para armazenar possiveis cadeias de caracteres identificadas
        @return quantidade de sequencias de caracteres identificadas, se houver;
        zero, caso contrario

        Exemplos para testes:
        abc
        abc def ghi
    */
    string* split(string* sequencia){
        int quantidade = 0;

        for(int i=0; i<this->s.length(); i++){ //contar quantas vezes dividir string
            if(i == 0 && s[i] != ' ')
                quantidade++;
            /* else if(i == 0 && s[i] == ' ')
                continue; */
            else if(s[i-1] == ' ' && s[i] != ' ')
                quantidade++;
        }

        sequencia = new string[quantidade];

        if(!sequencia){
            setErro(5);
            printErroMsg();
        }

        int x = 0;
        for(int i=0; i<this->s.length(); i++){ //copiar strings para array
            for(; i<s.length() && s[i]!=' '; i++)
                sequencia[x] += s[i];

            x++;
        }

        return sequencia;
    }

    int countWords(){
        int quantidade = 0;

        for(int i=0; i<this->s.length(); i++){
            if(i == 0 && s[i] != ' ')
                quantidade++;
            else if(i == 0 && s[i] == ' ')
                continue;
            else if(s[i-1] == ' ' && s[i] != ' ')
                quantidade++;
        }

        return quantidade;
    }


    /**
        Funcao para codificar o conteudo segundo a cifra de César (pesquisar).
        @return valor equivalente codificado, se houver;
        o proprio valor, caso contrario

        OBS: Coloquei chaves diferentes para encriptar letras maiusculas, letras minusculas
        e numeros. Tambem fiz com que as chaves sejam geradas aleatoriamente. Toda vez que 
        chamar a funcao novas chaves serao geradas.

        Exemplos para testes:
        TeStE123
        AbCdEfGhIjKlMnOpQrStUvWxYz0123456789
    */
    string encrypt(){
        for(int i=0; i<this->s.length(); i++){
            if(isLowerCase(s[i])){
                if(s[i] + chaveMin > 122){
                    s[i] = 96 + (chaveMin - (122 - s[i]));
                }else{
                    s[i] += chaveMin;
                }
            }else if(isUpperCase(s[i])){
                if(s[i] + chaveMai > 90){
                    s[i] = 64 + (chaveMai - (90 - s[i]));
                }else{
                    s[i] += chaveMai;
                }
            }else if(isNumber(s[i])){
                if(s[i] + chaveNum > 57){
                    s[i] = 47 + (chaveNum - (57 - s[i]));
                }else{
                    s[i] += chaveNum;
                }
            }
        }

        return s;
    }

    
    /**
        Funcao para decodificar o conteudo previamente cifrado pela funcao acima.
        @return valor equivalente decodificado, se houver;
        o proprio valor, caso contrario

        OBS: Coloquei chaves diferentes para encriptar letras maiusculas, letras minusculas
        e numeros. Tambem fiz com que as chaves sejam geradas aleatoriamente. Toda vez que 
        chamar a funcao novas chaves serao geradas.

        Exemplos para testes:
        TeStE123
        AbCdEfGhIjKlMnOpQrStUvWxYz0123456789
    */
    string decrypt(){
        for(int i=0; i<this->s.length(); i++){
            if(isLowerCase(s[i])){
                if(s[i] - chaveMin < 97){
                    s[i] = 123 - (chaveMin - (s[i] - 97));
                }else{
                    s[i] -= chaveMin;
                }
            }else if(isUpperCase(s[i])){
                if(s[i] - chaveMai < 65){
                    s[i] = 91 - (chaveMai - (s[i] - 65));
                }else{
                    s[i] -= chaveMai;
                }
            }else if(isNumber(s[i])){
                if(s[i] - chaveNum < 48){
                    s[i] = 58 - (chaveNum - (s[i] - 48));
                }else{
                    s[i] -= chaveNum;
                }
            }
        }
        
        return s;
    }


    /**
        Acrescentar um método (e testes) para fragmentar o conteúdo usando um delimitador à escolha,
        diferente de espaço em branco. 

        Exemplos para teste:
        teste1/teste2/teste3    caractere '/'
        teste1/teste2/teste3    caractere 'e'
    */
    string* split(string* sequencia, char c){
        int quantidade = 0;

        for(int i=0; i<this->s.length(); i++){ //contar quantas vezes dividir string
            if(i == 0 && s[i] != c)
                quantidade++;
            else if(i == 0 && s[i] == c){
                continue;
            }
            else if(s[i-1] == c && s[i] != c)
                quantidade++;
        }

        sequencia = new string[quantidade];

        if(!sequencia){
            setErro(5);
            printErroMsg();
        }

        int x = 0;
        for(int i=0; i<this->s.length(); i++){ //copiar strings para array
            for(; i<s.length() && s[i]!=c; i++)
                sequencia[x] += s[i];

            x++;
        }

        return sequencia;
    }

    int countWords(char c){
        int quantidade = 0;

        for(int i=0; i<this->s.length(); i++){
            if(i == 0 && s[i] != c)
                quantidade++;
            else if(i == 0 && s[i] == c)
                continue;
            else if(s[i-1] == c && s[i] != c)
                quantidade++;
        }

        return quantidade;
    }

    /**
        Acrescentar um método (e testes) para inverter a ordem dos símbolos na cadeia de caracteres.

        Exemplos para teste:
        teste
        abcdef
    */
    void inverter(){
        if(s.empty()){
            setErro(6);
            return;
        }

        for(int i=0; i<this->s.length()/2; i++){
            char temp = s[i];
            s[i] = s[s.length() - (i + 1)];
            s[s.length() - (i + 1)] = temp;
        }
    }
};

#endif