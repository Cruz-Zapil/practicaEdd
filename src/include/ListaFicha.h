#ifndef LISTAFICHA_H
#define LISTAFICHA_H

#include <iostream>
#include <string>
#include "Ficha.h"

using namespace std;

class NodoListFicha
{

public:
    Ficha *ficha;
    NodoListFicha *siguiente;

    NodoListFicha(Ficha *ficha)
    {
        this->ficha = ficha;
        this->siguiente = NULL;
    };
};

class ListFicha
{

private:
    NodoListFicha *primero;
    NodoListFicha *ultimo;
    int size;

public:
    ListFicha()
    {
        this->primero = NULL;
        this->ultimo = NULL;
        this->size = 0;
    };

    void insertar(Ficha *ficha)
    {

        NodoListFicha *nuevo = new NodoListFicha(ficha);

        if (this->primero == NULL)
        {
            this->primero = nuevo;
            this->ultimo = nuevo;
        }
        else
        {
            this->ultimo->siguiente = nuevo;
            this->ultimo = nuevo;
        }
        this->size++;
    };

    void eliminar(Ficha *ficha)
    {
        NodoListFicha *actual = this->primero;
        NodoListFicha *anterior = NULL;

        while (actual != NULL)
        {
            if (actual->ficha == ficha)
            {
                if (anterior == NULL)
                {
                    this->primero = actual->siguiente;
                }
                else
                {
                    anterior->siguiente = actual->siguiente;
                }
                delete actual;
                this->size--;
                return;
            }
            anterior = actual;
            actual = actual->siguiente;
        }
    };

    void imprimir()
    {
        NodoListFicha *actual = this->primero;

        while (actual != NULL)
        {
            cout << actual->ficha->getLetra() << "--> "<< actual->ficha->getValor() <<endl;
            actual = actual->siguiente;
        }
        cout << endl;
    };

    Ficha *buscar(char letra)
    {

        NodoListFicha *actual = this->primero;

        while (actual != NULL)
        {
            if (actual->ficha->getLetra() == letra)
            {
                return actual->ficha;
            }
            actual = actual->siguiente;
        }
        return NULL;
    };

    NodoListFicha *getPrimero()
    {
        return this->primero;
    };

    int getSize()
    {
        return this->size;
    };

   
   /// bubble Sort
    void ordenarListAlfabe()
    {
        if (this->primero == nullptr || this->primero->siguiente == nullptr)
        {
            return; // Lista vacía o con un solo elemento, ya está ordenada
        }

        bool cambiado;
        do     /// O(n)
        {
            cambiado = false;
            NodoListFicha *actual = this->primero;
            NodoListFicha *siguiente = actual->siguiente;

            while (siguiente != nullptr)    /// O(n)
            {
                if (actual->ficha->getLetra() > siguiente->ficha->getLetra())
                {
                    // Intercambiar fichas
                    Ficha *temp = actual->ficha;
                    actual->ficha = siguiente->ficha;
                    siguiente->ficha = temp;

                    cambiado = true;
                }
                actual = siguiente;
                siguiente = siguiente->siguiente;
            }
        } while (cambiado);
    };

/// complegidad algoritmica O(n²) 
// es simple y rapido simpre y cuando las lista no son demasiado Grandes 

};

#endif