
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

bool Tablero::setFicha(int x, int y, Ficha *ficha) {

    NodoCasilla *casilla = getCasilla(x, y);
    if (casilla && !casilla->bloqueado && !casilla->ocupado) {
        casilla->contenido = ficha;
        casilla->ocupado = true;
        return true;
    }else {
        cout << "Casilla bloqueada o ocupada" << endl;
    }
    return false;

}

void Tablero::imprimirTablero() {
    int contadorF=0;
    

    NodoCasilla *filaActual = inicio;

    cout <<"   0   1   2   3   4   5   6   7   8   9   10  11  12  13  14"<<endl;
    while (filaActual) {

        if (contadorF<10){
            cout << contadorF<<" ";

        }else {
            cout << contadorF;
        }

        NodoCasilla *columnaActual = filaActual;
        while (columnaActual) {

         
            if (columnaActual->bloqueado)
            {
                cout << "[█] ";
            } 
            else if (columnaActual->ocupado){
                cout << "["<<columnaActual->contenido->getLetra()<<"] ";
            }else {
                cout << "[ ] ";
            }
            
            columnaActual = columnaActual->derecha;
            
        }
        contadorF++;

        cout << endl;
        filaActual = filaActual->abajo;
    }
}

string Tablero::analizarH(int x, int y) {

    

    string palabra;
    punteoH = 0;
    NodoCasilla* inicio = getCasilla(x, y);

    while (inicio && inicio->izquierda && inicio->izquierda->contenido) {
        inicio = inicio->izquierda;
    }

      while (inicio && inicio->contenido) {
        palabra+= inicio->contenido->getLetra();
        punteoH += inicio->contenido->getValor();
        inicio = inicio->derecha;
    }
    cout<< " Palabra Horizontal : "<< palabra<<endl;
    return palabra;
}


string Tablero::analizarV(int x, int y) {

    string palabra;
    punteoV = 0;
    NodoCasilla* inicio = getCasilla(x, y);

    while (inicio && inicio->arriba && inicio->arriba->contenido) {
        inicio = inicio->arriba;
    }

      while (inicio && inicio->contenido) {
        palabra+= inicio->contenido->getLetra();
        punteoV += inicio->contenido->getValor();
        inicio = inicio->abajo;
    }


    cout<< " Palabra Vertical : "<< palabra<<endl;
    return palabra;
}

int Tablero::getPunteoH() {
    return punteoH;
}

int Tablero::getPunteoV() {
    return punteoV;
}