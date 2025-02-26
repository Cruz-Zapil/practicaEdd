#include "Ficha.h"

Ficha::Ficha( char l){
    valor = setValor();
    letra = l;

}


int Ficha::setValor(){
    /// seleccinar un valor 
     
    int valor  = rand() % 15;
    return valor;  

}

int Ficha::getValor(){
    return valor;
}

void Ficha::setLetra(char l){
    letra = l;
}

char Ficha::getLetra(){
    return letra;
}

