#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include "Casilla.h"
#include "Ficha.h"


class Tablero {
    

    private:
        Casilla* casillas[15][15]; // Arreglo de punteros a objetos Casilla

    public:
        Tablero();

        /// ingresar ficha en Casilla 
        void setFicha(int x, int y, Ficha* ficha);

        /// bloquear casillas 
        void bloquearCas();

        /// obtener casiilas por posicion 
        void getCasiila(int x, int y);

        /// recorrer casillas vertical 
        void recorrerCasV();
        
        /// analizar estado vertical
        bool analizarEstadoV(int x, int y);

        /// recorrer casillas horizintal
        void recorrerCasH();
        
        /// analizar estado horizontal 
        bool analizarEstadoH(int x, int y);

    
};

#endif