#ifndef _MYMATRIX_H_
#define _MYMATRIX_H_

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

class Matrix{
    private:
    T optional;
    int rows;
    int columns;
    T** data;
    
    public:
    Matrix(){
        this->rows=0;
        this->columns=0;
        data=nullptr;
    }
    
    Matrix(int rows, int columns, T initial){
        bool OK=true;
        this->optional=initial;
        this->rows=rows;
        this->columns=columns;

        data=new T*[rows];
        if(data!=nullptr){
            for(int x=0;x<rows; x++){
                data[x]=new T[columns];
                OK=OK && (data[x]!=nullptr);
            }
            if(!OK){
                data=nullptr;
            }
        }
    }
    
    ~Matrix(){
        if(data!=nullptr){
            for(int x=0; x<rows; x++){
                delete(data[x]);
            }
            delete(data);
            data=nullptr;
        }
    }
    
    void set(int row, int column, T value){
        if(row<0 || row>=rows || column<0 || column>=columns){
            cout << "\nERROR: Invalid position.\n";
        }else{
            data[row][column]=value;
        }
    }
    
    T get(int row, int column){
        T value=optional;
        if(row<0 || row>=rows || column<0 || column>=columns){
            cout<<"\nERROR: Invalid position.\n";
        }else{
            value=data[row][column];
        }
        return value;
    }

    void print(){
        cout<<endl;
        for(int x=0; x<rows; x++){
            for(int y=0; y<columns; y++){
                cout<<data[x][y]<<"\t";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    void read(){
        cout<<endl;
        for(int x=0; x<rows; x++){
            for(int y=0; y<columns; y++){
                cout<<setw(2)<<x<<", "<<setw(2)<<y<<": ";
                cin>>data[x][y];
            }
        }
        cout<<endl;
    }

    void fprint(string fileName){
        ofstream afile;
        afile.open(fileName);
        afile<<rows<<endl;
        afile<<columns<<endl;
        for(int x=0; x<rows; x++){
            for(int y=0; y<columns; y++){
                afile<<data[x][y]<<endl;
            } 
        }
        cout<<"\nOs dados da matrix foram salvos no arquivo \""<<fileName<<"\""<<endl;
        afile.close();
    } 

    void fread(string fileName){
        ifstream afile;
        int m=0;
        int n=0;
        afile.open(fileName);
        afile>>m;
        afile>>n;
        if(m<=0 || n<=0){
            cout<<"\nERROR: Invalid dimensions for matrix.\n"<<endl;
        }else{
            rows=m;
            columns=n;

            data=new T*[rows];
            for(int x=0; x<rows; x++){
                data[x]=new T[columns];
            } 

            for(int x=0; x<rows; x++){
                for(int y=0; y<columns; y++){
                    afile>>data[x][y];
                } 
            } 
        } 
        afile.close();
    } 

    bool isZeros(){
        bool result=false;
        int x=0;
        int y=0;
        if(rows>0 && columns>0){
            result=true;
            while(x<rows && result){
                y=0;
                while(y<columns && result){
                    result=result && (data[x][y]==0);
                    y++;
                } 
                x++;
            } 
        } 
        return result;
    } 

    Matrix& operator=(const Matrix<T>other){
        if(other.rows==0 || other.columns==0){
            cout<<"\nERROR: Missing data.\n"<<endl;
        }else{
            this->rows=other.rows;
            this->columns=other.columns;
            this->data=new T*[rows];
            
            for(int x=0; x<rows; x++){
                this->data[x]=new T[columns];
            } 
            for(int x=0; x<this->rows; x++){
                for(int y=0; y<this->columns; y++){
                    data[x][y]=other.data[x][y];
                } 
            } 
        } 
        return *this;
    } 

    bool operator!=(const Matrix<T>other){
        bool result=false;
        int x=0;
        int y=0;
        if(other.rows==0 || rows!=other.rows || other.columns==0 || columns!=other.columns){
            cout<<"\nERROR: Missing data.\n"<<endl;
        }else{
            x=0;
            while(x<rows && !result){
                y=0;
                while(y<columns && !result){
                    result=(data[x][y]!=other.data[x][y]);
                    y++;
                } 
                x++;
            } 
        } 
        return result;
    } 

    Matrix& operator-(const Matrix<T>other){
        static Matrix<T>result(1, 1, 0);
        int x=0;
        int y=0;
        
        if(other.rows==0 || rows!=other.rows || other.columns==0 || columns!=other.columns){
            cout<<"\nERROR: Missing data.\n"<<endl;
        }else{
            result.rows=rows;
            result.columns=other.columns;
            result.data=new T*[result.rows];
            
            for(int x=0; x<result.rows; x++){
                result.data[x]=new T[result.columns];
            } 
            
            for(int x=0; x<result.rows; x++){
                for(int y=0; y<result.columns; y++){
                    result.data[x][y]=data[x][y]-other.data[x][y];
                } 
            } 
        } 
        return result;
    } 

    Matrix& operator*(const Matrix<T>other){
        static Matrix<T>result(1, 1, 0);
        int x=0;
        int y=0;
        int z=0;
        int sum=0;
        if(rows<=0 || columns==0 || other.rows<=0 || other.columns==0 || columns != other.rows){
            cout<<endl<<"ERROR: Invalid data."<<endl;
            result.data[0][0]=0;
        }else{
            result.rows=rows;
            result.columns=other.columns;
            result.data=new T*[result.rows];
            
            for(int x=0; x<result.rows; x++){
                result.data[x]=new T[result.columns];
            } 
            
            for(x=0; x<result.rows; x++){
                for(y=0; y<result.columns; y++){
                    sum=0;
                    for(z=0; z<columns; z++){
                        sum=sum+data[x][z]*other.data[z][y];
                    } 
                    result.data[x][y]=sum;
                } 
            } 
        } 
        return result;
    } 

    const int getRows(){
        return rows;
    }
    
    const int getColumns(){
        return columns;
    }

    void random(){
        for(int i=0; i<rows; i++)
            for(int j=0; j<columns; j++)
                data[i][j]=rand()%101;
    }

    void scale(T constante){
        for(int i=0; i<rows; i++)
            for(int j=0; j<columns; j++)
                data[i][j]*=constante;
    }

    bool isIdentity(){
        for(int i=0; i<rows; i++)
            for(int j=0; j<columns; j++)
                if(i==j){
                    if(data[i][j]!=1)
                        return false;
                }else if(data[i][j]!=0)
                    return false;
        return true;
    }

    bool operator==(const Matrix<T>other){
        if(other.rows==0 || other.columns==0)
            cout<<"\nERROR: Missing data.\n"<<endl;
        else if(rows!=other.rows || columns!=other.columns)
            return false;
        else
            for(int i=0; i<rows; i++)
                for(int j=0; j<columns; j++)
                    if(data[i][j]!=other.data[i][j])
                        return false;
        return true;
    }

    Matrix& operator+(const Matrix<T>other){
        static Matrix<T>sum;
    
        if(other.rows<=0 || other.columns<=0 || rows!=other.rows || columns!=other.columns)
            cout<<"\nERROR: Missing data"<<endl;
        else{
            sum.rows=rows;
            sum.columns=other.columns;
            sum.data=new T*[sum.rows];
            
            for(int x=0; x<sum.rows; x++)
                sum.data[x]=new T[sum.columns];

            for(int i=0; i<sum.rows; i++)
                for(int j=0; j<sum.columns; j++)
                    sum.data[i][j]=data[i][j]+other.data[i][j];
        }
        return sum;
    }

    void sumRows(int row1, int row2, T constant){
        for(int i=0; i<columns; i++){
            data[row1][i]+=data[row2][i];
            data[row1][i]*=constant;
        }
    }

    void subColumns(int column1, int column2, T constant){
        for(int i=0; i<rows; i++){
            data[i][column1]-=data[i][column2];
            data[i][column1]*=constant;
        }
    }

    int findRow(T value){
        for(int i=0; i<rows; i++)
            for(int j=0; j<columns; j++)
                if(data[i][j]==value)
                    return i;
        return -1;
    }

    int findColumn(T value){
        for(int i=0; i<rows; i++)
            for(int j=0; j<columns; j++)
                if(data[i][j]==value)
                    return j;
        return -1;
    }

    void transpor(){
        static Matrix<T>transposta(columns, rows, 0);
        
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                transposta.data[j][i]=data[i][j];
            }
        }

        rows=transposta.rows;
        columns=transposta.columns;

        data=(T**)realloc(data, rows*sizeof(T*));
        for(int i=0; i<rows; i++){
            data[i]=(T*)realloc(data[i], columns*sizeof(T));
        }
        
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                data[i][j]=transposta.data[i][j];
            }
        }
        
        transposta.~Matrix();
    }

    bool exE1(){
        T previous=data[0][0];

        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                if(i==0 && j==0)    
                    continue;
                else if(data[i][j]!=previous+1)
                    return false;
                previous=data[i][j];
            }
        }
        return true;
    }

    bool exE2(){
        T previous=data[0][0];

        for(int i=0; i<columns; i++){
            for(int j=0; j<rows; j++){
                if(i==0 && j==0)
                    continue;
                else if(data[j][i]!=previous+1)
                    return false;
                previous=data[j][i];
            }
        }
        return true;
    }

    Matrix& somar(const Matrix<T>other1, const Matrix<T>other2){
        static Matrix<T>sum;
    
        sum.rows=rows;
        sum.columns=columns;
        sum.data=new T*[sum.rows];
        
        for(int x=0; x<sum.rows; x++)
            sum.data[x]=new T[sum.columns];

        for(int i=0; i<sum.rows; i++)
            for(int j=0; j<sum.columns; j++)
                sum.data[i][j]=other1.data[i][j]+other2.data[i][j];
 
        return sum;
    }
};
#endif