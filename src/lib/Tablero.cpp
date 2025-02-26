#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>

#include "Tablero.h"

int cantidad = 10;

Tablero::Tablero()
{ 
    // crear Casillas
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            casillas[i][j] = new Casilla();
        }
    }
}

void Tablero::bloquearCas(){
    /// contador
    int contador = 0;
    while (contador < 10)
    {
        int fila = rand() % 15; // Número entre 0 y 14
        int columna = rand() % 15;

        if (!casillas[fila][columna]->getBloqueado()){
            casillas[fila][columna]->setBloqueado(true);
            casillas[fila][columna]->setOcupado(true);
            contador++;
        }
    }
}


void Tablero::setFicha(int x, int y, Ficha* ficha){
       
    if ((!casillas[x][y]->getOcupado()) || (!casillas[x][y]->getBloqueado())){

        casillas[x][y]->setContenido(ficha);
        casillas[x][y]->setOcupado(true);
        
    }
}


void Tablero::recorrerCasV(){

}

void Tablero::recorrerCasH(){


    

}
