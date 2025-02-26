#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "Persona.h"
#include "Turno.h"
#include "tinyfiledialogs.h"
#include "ListaPalabra.h"


using namespace std;

int main()
{

    /// tunos
    Turno enColar;
    int cantidadJugadores;
    string nombre;

   

    cout << "¡Hola, mundo!" << endl;

    do
    {
        cout << " Ingrese la cantidad de Jugadores: " << endl;
        cin >> cantidadJugadores;

        if (cantidadJugadores >= 2){

            for (int i = 0; i < cantidadJugadores; i++)
            {
                cout << "Jugador " << i + 1 << endl;
                cout << "Ingrese su nombre: ";
                cin >> nombre;

                enColar.encolar(Persona(nombre, 0));
            }
        }else {
            cout << "Ingrese un número mayor a 2" << endl;
        }

    } while (cantidadJugadores < 2);

    return 0;
}
