#ifndef LISTAFICHA_H
#define LISTAFICHA_H

#include <iostream>
#include <string>
#include "Ficha.h"

using namespace std;


class NodoListFicha{

    public:

        Ficha *ficha;
        NodoListFicha *siguiente;

        NodoListFicha(Ficha *ficha){
            this->ficha = ficha;
            this->siguiente = NULL;
        };

  


};


class ListFicha {

    private:
        NodoListFicha *primero;
        NodoListFicha *ultimo;
        int size;

    public:

        ListFicha(){
            this->primero = NULL;
            this->ultimo = NULL;
            this->size = 0;
        };

        void insertar(Ficha *ficha){

            NodoListFicha *nuevo = new NodoListFicha(ficha);

            if(this->primero == NULL){
                this->primero = nuevo;
                this->ultimo = nuevo;
            }else{
                this->ultimo->siguiente = nuevo;
                this->ultimo = nuevo;
            }
            this->size++;

        };


        void eliminar(Ficha *ficha){

            NodoListFicha *actual = this->primero;
            NodoListFicha *anterior = NULL;

            while(actual != NULL){
                if(actual->ficha == ficha){
                    if(anterior == NULL){
                        this->primero = actual->siguiente;
                    }else{
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
        
        
        void imprimir(){

            NodoListFicha *actual = this->primero;

            while(actual != NULL){
                cout << actual->ficha->getLetra() << " ";
                actual = actual->siguiente;
            }
            cout << endl;

        };

        Ficha *buscar(char letra){
            
            NodoListFicha *actual = this->primero;

            while(actual != NULL){
                if(actual->ficha->getLetra() == letra){
                    return actual->ficha;
                }
                actual = actual->siguiente;
            }
            return NULL;

        };

        NodoListFicha *getPrimero(){
            return this->primero;
        };

        int getSize(){
            return this->size;            
        };

};






#endif