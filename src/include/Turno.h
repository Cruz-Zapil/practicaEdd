#ifndef TURNO_H
#define TURNO_H

#include "Persona.h"

using namespace std;

class NodoTurno
{

public:
    Persona *jugador;
    NodoTurno *siguiente;

    NodoTurno(Persona *_jugador)
    {
        jugador = _jugador;
        siguiente = nullptr;
    }
};

class Turno
{

private:
    NodoTurno *frente;
    NodoTurno *finalCola;

public:
    Turno() : frente(nullptr), finalCola(nullptr) {}



    // Método para encolar un objeto Persona

    /// complegidad  O(1)
    void encolar(Persona *persona)
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

    // metodo para obtener el jugador:

    Persona *getJugador()
    {
        if (esVacia())
        {
            cout << "La cola está vacía" << endl;
            return nullptr;
        }
        return frente->jugador;
    }

    /// metodo para ver si los jugadores tienen fichas

    bool jugadoresConFichas()
    {
        NodoTurno *actual = frente;
        while (actual)
        {
            if (actual->jugador->getConFicha())
            {
                return true;
            }
            actual = actual->siguiente;
        }
        return false;
    }

    // Método para ver obtener el frente de la cola y desplazarlo al final


    NodoTurno *getFrente()
    {
        if (esVacia())
        {
            cout << "La cola está vacía" << endl;
            return nullptr;
        }
        return frente;
    }

    /// metodo para mover el frente al final
    
    /// Complejidad O(1)
    void moverFrenteFinal()
    {
        if (esVacia())  /// O(1)
        {
            cout << "La cola está vacía" << endl;
            return;
        }

        if (frente == finalCola)  /// O(1)
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
            if (actual->jugador)
            {
                actual->jugador->mostrar();
            }
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
