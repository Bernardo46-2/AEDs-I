#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>

char* f01(const char* s) {
    int n = strlen(s) - 1;
    char* r = (char*)calloc(n, sizeof(char));
    char* ps = (char*)s + n;
    char* pr = r + n;

    *(pr + 1) = '\0';
    
    while(ps - (char*)s > 0) {
        *pr = *ps;
        pr--;
        ps--;
    }

    *(pr + n) = *s;

    return pr + 1;
}

char* f02(const char* s) {
    int n = strlen(s) - 1;
    char* r = (char*)calloc(n, sizeof(char));
    char* ps = (char*)s + n - 1;
    char* pr = r + n;

    *(pr + 1) = '\0';
    
    while(ps - (char*)s >= 0) {
        *pr = *ps;
        pr--;
        ps--;
    }

    return pr + 1;
}

char* f03(const char* s) {
    int n = strlen(s);
    char* r = (char*)calloc(n, sizeof(char));
    char* ps = (char*)s + 1;
    char* pr = r;

    while(*ps) {
        *pr = *ps;
        pr++;
        ps++;
    }

    *pr = '\0';

    return r;
}

char* f04(const char* s) {
    int n = strlen(s);
    char* r = (char*)calloc(n, sizeof(char));
    char* ps = (char*)s;
    char* pr = r;

    do {
        *pr = *ps;
        ++pr;
        ++ps;
    } while(s + n/2 - ps > 0);

    ps = ps + 1;

    while(*ps) {
        *pr = *ps;
        pr++;
        ps++;
    }

    *pr = '\0';

    return r;
}

void method_01(void) {
    std::cout<<"\n1 - ["<<f01("01234567")<<"]\n";
    std::cout<<"\n2 - ["<<f02("01234567")<<"]\n";
    std::cout<<"\n3 - ["<<f03("01234567")<<"]\n";
    std::cout<<"\n4 - ["<<f04("01234567")<<"]\n";
}



class Fracao {
    protected:
    int n;
    int d;
    Fracao* link;

    public:
    int getN() {
        return this->n;
    }

    int getD() {
        return this->d;
    }

    Fracao() {
        this->link = nullptr;
        this->n = 0;
        this->d = 1;
    }

    Fracao(int a, int b) {
        this->link = nullptr;
        this->n = a;
        this->d = b == 0 ? 1 : b;
    }

    Fracao(int a, int b, Fracao* proxima) {
        this->link = proxima;
        this->n = a;
        this->d = b == 0 ? 1 : b;
    }

    Fracao* somar(Fracao* f) {
        Fracao* resposta = new Fracao();
        
        resposta->d = this->d * f->d;
        resposta->n = (this->n * f->d) + (this->d * f->n);

        return resposta; 
    }

    Fracao* simplificar() {
        int aux = this->n > this->d ? this->d : this -> n;
        int x, y;

        for(int i = aux; i >= 2; i--) {
            if(n % i == 0 && d % i == 0) {
                x = n / i;
                y = d / i;
                i = 0;
            }
        }

        Fracao* fracaoSimplificada = new Fracao(x, y);
        
        return fracaoSimplificada;
    }

    Fracao* maior(Fracao* f[]) {
        Fracao* maior = this;
        Fracao* cursor = this;

        while(cursor->link != nullptr) {
            if((double)maior->n / (double)maior->d > (double)cursor->n / (double)cursor->d) {
                maior = cursor;
            }

            cursor = cursor->link;
        }

        return maior;
    }

    Fracao* conectar(Fracao* f) {
        this->link = f;

        return this;
    }

    Fracao* proxima() {
        return this->link;
    }

    int mdc() {
        int aux = this->n <= this->d ? this->n : this->d;
        int resposta = 0;

        for(int i = aux; i >= 2; i--) {
            if(this->n % i == 0 && this->d % i == 0) {
                resposta = i;
                i = 0;
            }
        }

        return resposta;
    }

    int comparar(Fracao* f) {
        int resposta;

        if((double)this->n / (double)this->d < (double)f->n / (double)f->d) {
            resposta = -1;
        } else if((double)this->n / (double)this->d > (double)f->n / (double)f->d) {
            resposta = 1;
        } else {
            resposta = 0;
        }

        return resposta;
    }

    void ler(std::string nome, int n, Fracao* f[]) {
        std::ifstream file;
        file.open(nome);
        
        int i = 0;
        Fracao* cursor = nullptr;

        if(file.is_open()) {
            for(int i = 0; !file.eof() && i < n; i++) {
                int x, y;

                file>>x;
                file>>y;

                f[i] = new Fracao(x, y);

                if(i != 0) {
                    f[i - 1] = f[i - 1]->conectar(f[i]);
                }
            }
        }

        if(cursor)
            delete cursor;

        file.close();
    }

    std::string to_String(void) {
        std::ostringstream buffer;
        
        buffer<<this->n<<"/"<<this->d;

        return buffer.str();
    }
};

void method_02(void) {
    Fracao* f1 = new Fracao(2, 3);
    Fracao* f2 = new Fracao(4, 9);
    Fracao* f3 = new Fracao();
    Fracao* f4[5];
    Fracao* f5 = new Fracao(1, 1, nullptr);

    f4[0]->ler("A03.txt", 5, f4);
    
    for(int x = 0; x < 5; x++)
        f5 = f5->conectar(f4[x]);

    std::cout<<"01. f1 = "<<f1->to_String()<<"\n";
    std::cout<<"02. f2 = "<<f2->to_String()<<"\n";
    std::cout<<"03. f3 = "<<f3->to_String()<<"\n";

    f3 = f3->somar(f1);
    std::cout<<"04. f3 = "<<f3->to_String()<<"\n";
    f3 = f3->somar(f2);
    std::cout<<"05. f3 = "<<f3->to_String()<<"\n";

    std::cout<<"06. MDC = "<<f3->mdc()<<"\n";
    std::cout<<"07. f3 = "<<f3->simplificar()->to_String()<<"\n";

    std::cout<<"08. ? = "<<f1->comparar(f2)<<"\n";

    std::cout<<"09. >= "<<f4[0]->maior(f4)->to_String()<<"\n";

    while(f5) {
        std::cout<<"10. f5 = "<<f5->to_String()<<"\n";
        f5 = f5->proxima();
    }

    /* 
    saida:

    01. f1 = 2/3
    02. f2 = 4/9
    03. f3 = 0/1
    04. f3 = 2/3
    05. f3 = 30/27
    06. MDC = 3
    07. f3 = 10/9
    08. ? = 1
    09. > = 13/16
    10. f5 = 0/1
    10. f5 = 7/9
    10. f5 = 13/16
    10. f5 = 3/8
    10. f5 = 1/5
    10. f5 = 1/1
    */
}

int main() {
    system("cls");

    std::cout<<"\nCorrecao da prova 3\n";
    
    std::cout<<"\nQuestao 1)\n";
    method_01();
    std::cout<<"\n\nQuestao 2)\n\n";
    method_02();

    std::cout<<"\nPress <enter>";
    getchar();
    return 0;
}
