
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
        bool conFicha;


    public:
        Persona(string n, int e);

        void mostrar();
        void insertarFichas(ListFicha *listaFichas);
        ListFicha *getFichas();
        void eliminarFicha(Ficha *ficha);
        void imprimirFichas();
        bool getConFicha();
        
        Ficha *buscarFicha(char letra);


        void setPunteo(int p);

        int getPunteo();
        string getNombre();
};

#endif
