
#ifndef PERSONA_H // Protección contra inclusiones múltiples
#define PERSONA_H

#include <iostream>

#include "ListaFicha.h"

using namespace std;

class Persona{

    private:
        string nombre;
        int punteo;
        ListFicha* listFicha;


    public:
        Persona(string n, int e);

        void mostrar();
        void insertarFichas(ListFicha *listaFichas);


        void eliminarFicha(Ficha *ficha);
        void imprimirFichas();
        
        Ficha *buscarFicha(string letra);


        void setPunteo(int p);

        int getPunteo();
        string getNombre();
};

#endif
