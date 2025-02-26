#ifndef JUGAR_H
#define JUGAR_H


#include <iostream>
#include "ListaPalabra.h"
#include "Turno.h"
#include "ListaFicha.h"
#include "Ficha.h"

using namespace std;

class Jugar{

    private:
    ListaPalabra listaPalabra;
    Turno listTurno;
    int cantJugadores;
    ListFicha  listaFicha;

    public:

    void crearJugadores();
    void lecturaArchivo();
    void dividirFichas();

};



#endif