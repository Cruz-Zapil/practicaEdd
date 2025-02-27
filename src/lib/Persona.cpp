#include "Persona.h"

Persona::Persona(string n, int e) {
    nombre = n;
    punteo = e;
}

void Persona::mostrar() {
    cout << "Nombre: " << nombre << ", Punteo Acumulado: " << punteo << endl;
}


void Persona::insertarFichas(ListFicha *listFichas) {
    listFicha = listFichas;
}

ListFicha *Persona::getFichas() {
    return listFicha;
}

void Persona::eliminarFicha(Ficha *ficha) {
    listFicha->eliminar(ficha);
}


void Persona::imprimirFichas() {
    listFicha->imprimir();
}

Ficha *Persona::buscarFicha(char letra) {
    return listFicha->buscar(letra);
}




void Persona::setPunteo(int p) {
    punteo = punteo + p;
}

int Persona::getPunteo() {
    return punteo;
}

string Persona::getNombre() {
    return nombre;
}

