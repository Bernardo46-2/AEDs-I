#ifndef _MYARRAY_HPP_
#define _MYARRAY_HPP_

#include <iostream>
using std::cin ;
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <string>
using std::string;

#include <fstream>
using std::ofstream;
using std::ifstream;
template <typename T>

class Array{
    private:
    T optional;
    int length;
    T *data;

    public:
    Array(int n, T initial){
        optional=initial;
        length=0;
        data=nullptr;

        if(n>0){
            length=n;
            data=new T[length];
        }
    }
    
    void free(){
        if(data!=nullptr){
            delete(data);
            data=nullptr;
        }
    }
    
    void set(int position, T value){
        if(0<=position && position<length){
            data[position]=value;
        }
    }
    
    T get(int position){
        T value=optional;
        if (0<=position && position<length){
            value=data[position];
        }
        return value;
    }

    T findLargest(){
        int maior=data[0];
        for(int i=0; i<length; i++)
            if(maior<data[i])
                maior=data[i];
        return maior;
    }

    T findLowest(){
        int menor=findLargest();
        for(int i=0; i<length; i++)
            if(menor>data[i])
                menor=data[i];
        return menor;
    }

    T sumValues(){
        int sum=0;
        for(int i=0;i<length; i++)
            sum+=data[i];
        return sum;
    }

    T findMean(){
        return sumValues()/length;
    }

    void random(){
        //srand(time(0));
        for(int i=0; i<length; i++){
            data[i]=rand()%101;
        }
    }

    bool allZeros(){
        for(int i=0; i<length; i++)
            if(data[i]!=0)
                return false;
        return true;
    }

    bool decrescent(){
        for(int i=0; i<length-1; i++)
            if(data[i]<data[i+1])
                return false;
        return true;
    }

    int findValue(T value, int a, int b){
        if(0<=a && a<=b && b<=length)
            for(a; a<=b; a++)
                if(data[a]==value)
                    return a;
        return -1;
    }

    void scale(int n){
        for(int i=0; i<length; i++)
            data[i]=data[i]*n;
    }

    void ordenDecrescent(){
        T temp;
        for(int i=0; i<length; i++){
            for(int j=0; j<length-1; j++){
                if(data[j]<data[j+1]){
                    temp=data[j];
                    data[j]=data[j+1];
                    data[j+1]=temp;
                }
            }
        }
    }
    
    void print(){
        cout<<endl;
        for(int x=0; x<length; x=x+1){
            cout<<setw(2)<<x<<" : "<<setw(5)<<data[x]<<endl;
        }
        cout<<endl;
    }

    void read(){
        cout<<endl;
        for(int x=0; x<length; x=x+1){
            cout<<setw(3)<<x<<" : ";
            cin>>data[x];
        }
        cout<<endl;
    }

    void fprint(string fileName){
        ofstream afile;
        afile.open(fileName);
        afile<<length<<endl;
        for(int x=0; x<length; x=x+1){
            afile<<data[x]<<endl;
        }
        cout<<"\nO array foi guardado no arquivo \""<<fileName<<"\"";
        afile.close();
    }

    void fread(string fileName){
        ifstream afile;
        int n=0;
        afile.open(fileName);
        afile>>n;
        if(n<=0){
            cout<<"\nERROR: Invalid length.\n"<<endl;
        }else{
            length=n;
            data=new T[n];
            for(int x=0; x<length; x=x+1){
                afile>>data[x];
            }
        }
        afile.close();
    }

    Array(){
        length=0;
        data=nullptr;
    }

    Array(int length, int other[]){
        if(length<=0){
            cout<<"\nERROR: Missing data.\n"<<endl;
        }else{
            this->length=length;
            data=new T[this->length];
            for(int x=0; x<this->length; x=x+1){
                data[x]=other[x];
            }
        }
    }

    Array(const Array& other){
        if(other.length<=0){
            cout<<"\nERROR: Missing data.\n"<<endl;
        }else{
            length=other.length;
            data=new T[other.length];
            for(int x=0; x<length; x=x+1){
                data[x]=other.data[x];
            }
        }
    } 

    Array& operator=(const Array <T> other){
        if(other.length<=0){
            cout<<"\nERROR: Missing data.\n" << endl;
        }else{
            this->length=other.length;
            this->data=new T[other.length];
            for(int x=0; x<this->length; x=x+1){
                data[x]=other.data[x];
            }
        }
        return ( *this );
    }

    bool operator==(const Array <T> other){
        bool result = false;
        int x = 0;
        if(other.length==0 || length!=other.length){
            cout << "\nERROR: Missing data.\n" << endl;
        }else{
            x=0;
            result=true;
            while(x<this->length && result){
                result=result && (data[x]==other.data[x]);
                x=x+1;
            }
        }
        return ( result );
    }

    bool operator!=(const Array<T> other){
        if(other.length==0){
            cout<<"\nERROR: Missing data.\n"<<endl;
        }else{
            if(this->length != other.length){
                return true;
            }else{
                for(int i=0; i<length; i++){
                    if(this->data[i]!=other.data[i])
                        return true;
                }
            }
        }
        return false;
    }

    Array& operator+(const Array <T> other){
        static Array <T> result(other);
        if(other.length<=0){
            cout<<"\nERROR: Missing data.\n"<<endl;
        }else{
            for(int x=0; x<this->length; x=x+1){
                result.data[x]=result.data[x]+this->data[x];
            }
        }
        return result;
    }

    Array& operator-(const Array<T> other){
        static Array<T>result(other);
        if(other.length<=0){
            cout<<"\nError: Missing data\n"<<endl;
        }else{
            for(int i=0; i<this->length; i++){
                result.data[i]=this->data[i]-result.data[i];
            }
        }
        return result;
    }

    const int getLength(){
        return length;
    } 
    
    T& operator[](const int position){
        static T value=optional;
        if(position<0 || length<=position){
            cout<<endl<<"\nERROR: Invalid position.\n"<<endl;
        }else{
            value=data[position];
        }
        return value;
    }
};
#endif