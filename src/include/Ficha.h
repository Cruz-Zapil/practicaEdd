#ifndef FICHA_H
#define FICHA_H

#include <iostream>
using namespace std;

class Ficha{

    private:
        int valor;
        char letra;
        
    public:

        Ficha( char letra );
     
        int setValor();
        int getValor();
        void setLetra(char letra);
        char getLetra();
        

};

#endif