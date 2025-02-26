
// Tablero.cpp
#include "Tablero1.h"
#include <cstdlib>
#include <ctime>

Tablero::Tablero() {
    construirTablero();
}

void Tablero::construirTablero() {
    inicio = new NodoCasilla();
    NodoCasilla *filaActual = inicio;
    for (int i = 0; i < filas; i++) {
        NodoCasilla *columnaActual = filaActual;
        for (int j = 1; j < columnas; j++) {
            NodoCasilla *nuevo = new NodoCasilla();
            columnaActual->derecha = nuevo;
            nuevo->izquierda = columnaActual;
            columnaActual = nuevo;
        }
        if (i < filas - 1) {
            NodoCasilla *nuevaFila = new NodoCasilla();
            filaActual->abajo = nuevaFila;
            nuevaFila->arriba = filaActual;
            filaActual = nuevaFila;
        }
    }
}

void Tablero::bloquearCasillas() {
    int cant = 10;
    srand(time(0));
    int contador = 0;
    while (contador < cant) {
        int x = rand() % filas;
        int y = rand() % columnas;
        NodoCasilla *casilla = getCasilla(x, y);
        if (casilla && !casilla->bloqueado) {
            casilla->bloqueado = true;
            contador++;
        }
    }
}

NodoCasilla* Tablero::getCasilla(int x, int y) {
    NodoCasilla *temp = inicio;
    for (int i = 0; i < x; i++) {
        if (temp->abajo) temp = temp->abajo;
        else return nullptr;
    }
    for (int j = 0; j < y; j++) {
        if (temp->derecha) temp = temp->derecha;
        else return nullptr;
    }
    return temp;
}

void Tablero::setFicha(int x, int y, Ficha *ficha) {
    NodoCasilla *casilla = getCasilla(x, y);
    if (casilla && !casilla->bloqueado && !casilla->ocupado) {
        casilla->contenido = ficha;
        casilla->ocupado = true;
    }
}

void Tablero::imprimirTablero() {
    NodoCasilla *filaActual = inicio;
    while (filaActual) {
        NodoCasilla *columnaActual = filaActual;
        while (columnaActual) {
            if (columnaActual->bloqueado) cout << "[X] ";
            else if (columnaActual->ocupado) cout << "[F] ";
            else cout << "[ ] ";
            columnaActual = columnaActual->derecha;
        }
        cout << endl;
        filaActual = filaActual->abajo;
    }
}
