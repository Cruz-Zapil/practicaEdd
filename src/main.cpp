#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "Persona.h"
#include "Turno.h"
#include "tinyfiledialogs.h"
#include "ListaPalabra.h"
#include "Jugar.h"


using namespace std;

int main()
{
    ///Juego

    
        /// Menu principal
        int opcion=0;
        Jugar juego;


        cout << "***************************" << endl;
        cout << "** Bienvenido a Ahorcado **" << endl;
        cout << "***************************" << endl;
        cout << "Seleccione una opcion" << endl;

        cout << "1. Jugar" << endl;
        cout << "2. Instrucciones" << endl;
        cout << "3. Salir" << endl;
        
        cin >> opcion;

        switch(opcion){
            case 1:
                cout << "Jugar" << endl;
                juego.crearJugadores();
                juego.lecturaArchivo();
                juego.dividirFichas();

                break;
            case 2:
                cout << "Instrucciones" << endl;


                break;
            case 3:
                cout << "Salir" << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }

    

    return 0;
}
