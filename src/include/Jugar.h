#ifndef JUGAR_H
#define JUGAR_H


#include <iostream>
#include "ListaPalabra.h"
#include "Turno.h"
#include "ListaFicha.h"
#include "Ficha.h"
#include "Tablero1.h"


using namespace std;

class Jugar{

    private:
    Tablero tablero;

    ListaPalabra listaPalabra;
    Turno listTurno;
    int cantJugadores;
    ListFicha  listaFicha;

    public:

    void jugar();
    void crearJugadores();
    void lecturaArchivo();
    void dividirFichas();
    void turnoJugador();

};



#endif