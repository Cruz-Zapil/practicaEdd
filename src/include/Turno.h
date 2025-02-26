#ifndef TURNO_H
#define TURNO_H

#include "Persona.h"

using namespace std;

class NodoTurno
{

public:

    Persona dato;
    NodoTurno *siguiente;

    NodoTurno(Persona dato) : dato(dato), siguiente(nullptr) {}
};

class Turno
{

private:
    NodoTurno *frente;
    NodoTurno *finalCola;

public:
    Turno() : frente(nullptr), finalCola(nullptr) {}

    // Método para encolar un objeto Persona
    void encolar(const Persona &persona)
    {
        NodoTurno *nuevo = new NodoTurno(persona);
        if (finalCola)
        {
            finalCola->siguiente = nuevo;
        }
        finalCola = nuevo;
        if (!frente)
        {
            frente = nuevo;
        }
    }

    // Método para desencolar
    void desencolar()
    {
        if (esVacia())
        {
            cout << "La cola está vacía" << endl;
            return;
        }
        NodoTurno *temp = frente;
        frente = frente->siguiente;
        if (!frente)
        {
            finalCola = nullptr;
        }
        delete temp;
    }

    // Método para ver obtener el frente de la cola y desplazarlo al final

    NodoTurno* getFrente()
    {
        if (esVacia())
        {
            cout << "La cola está vacía" << endl;
            return nullptr;
        }
        return frente;
    }

    /// metodo para mover el frente al final

    void moverFrenteFinal()
    {
        if (esVacia())
        {
            cout << "La cola está vacía" << endl;
            return;
        }

        if (frente == finalCola)
        {
            cout << "Solo hay un elemento, no se mueve" << endl;
            return;
        }

        NodoTurno *temp = frente; // Guardamos el nodo a mover

        frente = frente->siguiente; // Avanzamos el frente
        temp->siguiente = nullptr;  // Quitamos la referencia al siguiente nodo

        finalCola->siguiente = temp; // Conectamos el último nodo con el nuevo nodo final
        finalCola = temp;            // Actualizamos el final de la cola
    }


    // Método para verificar si la cola está vacía
    bool esVacia() const
    {
        return frente == nullptr;
    }

    // Método para imprimir toda la cola
    void imprimir() const
    {
        NodoTurno *actual = frente;
        while (actual)
        {
            actual->dato.mostrar();
            actual = actual->siguiente;
        }
    }

    // Destructor para liberar memoria
    ~Turno()
    {
        while (!esVacia())
        {
            desencolar();
        }
    }
};

#endif
