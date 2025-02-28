#ifndef LISTAPALABRA_H
#define LISTAPALABRA_H

#include <iostream>

using namespace std;

class NodoPalabra
{

public:
    string palabra;
    NodoPalabra *siguiente;

    NodoPalabra(string palabra)
    {
        this->palabra = palabra;
        this->siguiente = NULL;
    }
};

class ListaPalabra
{

private:
    NodoPalabra *primero;
    NodoPalabra *ultimo;
    int size;

public:
    ListaPalabra()
    {
        this->primero = NULL;
        this->ultimo = NULL;
        this->size = 0;
    }

    void insertar(string palabra)
    {

        NodoPalabra *nuevo = new NodoPalabra(palabra);

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
    }

    void eliminar(string palabra)
    {
        NodoPalabra *actual = this->primero;
        NodoPalabra *anterior = NULL;
        while (actual != NULL)
        {
            if (actual->palabra == palabra)
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
    }

    void imprimir()
    {
        NodoPalabra *actual = this->primero;
        while (actual != NULL)
        {
            cout << actual->palabra << endl;
            actual = actual->siguiente;
        }
    }

    int getSize()
    {
        return this->size;
    }

    bool buscar(string palabra)
    {
        if (!primero) return false; // lista vacia 

        NodoPalabra *actual = primero;
        NodoPalabra *anterior = nullptr;

        while (actual)
        {
            if (actual->palabra == palabra)
            {
                // Si es el primer nodo
                if (anterior == nullptr)
                {
                    primero = actual->siguiente;
                }
                else
                {
                    anterior->siguiente = actual->siguiente;
                }

                delete actual; // Liberamos memoria
                return true;   // Palabra encontrada y eliminada
            }

            anterior = actual;
            actual = actual->siguiente;
        }
        return false;
    }

    string getPalabra(int index)
    {
        NodoPalabra *actual = this->primero;
        int contador = 0;
        while (actual != NULL)
        {
            if (contador == index)
            {
                return actual->palabra;
            }
            contador++;
            actual = actual->siguiente;
        }
        return "";
    }

    void setPalabra(int index, string palabra)
    {
        NodoPalabra *actual = this->primero;
        int contador = 0;
        while (actual != NULL)
        {
            if (contador == index)
            {
                actual->palabra = palabra;
                return;
            }
            contador++;
            actual = actual->siguiente;
        }
    }

    void eliminar(int index)
    {
        NodoPalabra *actual = this->primero;
        NodoPalabra *anterior = NULL;
        int contador = 0;
        while (actual != NULL)
        {
            if (contador == index)
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
            contador++;
        }
    }
};

#endif // LISTAPALABRAS_H
