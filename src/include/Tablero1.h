// Tablero.h
#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include "Casilla.h"
#include "Ficha.h"

using namespace std;

class NodoCasilla {
public:
    Ficha *contenido;
    bool bloqueado;
    bool ocupado;

    // Punteros a los vecinos
    NodoCasilla *arriba;
    NodoCasilla *abajo;
    NodoCasilla *izquierda;
    NodoCasilla *derecha;

    // Constructor
    NodoCasilla() {
        contenido = nullptr;
        bloqueado = false;
        ocupado = false;
        arriba = abajo = izquierda = derecha = nullptr;
    }
};

class Tablero {
private:
    NodoCasilla* inicio;
    int filas=15, columnas=15;

public:
    Tablero();
    void construirTablero();
    void bloquearCasillas();
    NodoCasilla* getCasilla(int x, int y);
    void setFicha(int x, int y, Ficha *ficha);
    void imprimirTablero();
};

#endif

