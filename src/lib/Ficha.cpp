#include "Ficha.h"

Ficha::Ficha( char letra){
    valor = setValor();
    this->letra = letra;

}

int Ficha::setValor(){
    /// seleccinar un valor 
    int valor  = rand() % 15;
    return valor;  

}

int Ficha::getValor(){
    return valor;
}

void Ficha::setLetra(char letra){
    this->letra = letra;
}

char Ficha::getLetra(){
    return letra;
}

