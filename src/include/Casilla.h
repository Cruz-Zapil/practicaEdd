#ifndef CASILLA_H
#define CASILLA_H

#include <iostream>
#include "Ficha.h"
using namespace std;

class Casilla
{

private:
    bool bloqueado = false;
    bool isOcupado = false;
    Ficha *contenido = nullptr;
    bool estadoH = true;
    bool estadoV = true;

public:
    Casilla()
    {
        contenido = nullptr;
    }

    void setBloqueado(bool bloqueado)
    {
        this->bloqueado = bloqueado;
    }
    bool getBloqueado()
    {
        return this->bloqueado;
    }

    void setOcupado(bool ocupado)
    {
        this->isOcupado = ocupado;
    }

    bool getOcupado()
    {
        return this->isOcupado;
    }


    void setContenido(Ficha *contenido)
    {
        this->contenido = contenido;
    }

    Ficha *getContenido()
    {
        return this->contenido;
    }

    void setEstadoH(bool estadoH)
    {
        this->estadoH = estadoH;
    }
    bool getEstadoH()
    {
        return this->estadoH;
    }
    void setEstadoV(bool estadoV)
    {
        this->estadoV = estadoV;
    }
    bool getEstadoV()
    {
        return this->estadoV;
    }

    ~Casilla()
    {
        delete contenido; // Liberamos memoria si fue asignada dinámicamente
    }
};

#endif