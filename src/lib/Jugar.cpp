
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "Ficha.h"
#include "Persona.h"
#include "tinyfiledialogs.h"
#include "Jugar.h"
#include "Turno.h"
#include "ListaFicha.h"

using namespace std;

void Jugar::jugar()
{

    crearJugadores();
    lecturaArchivo();
    dividirFichas();

    tablero.construirTablero();
    tablero.bloquearCasillas();

    tablero.imprimirTablero();
    turnoJugador();
}

void Jugar::crearJugadores()
{
    string nombre;

    do
    {
        cout << " Ingrese la cantidad de Jugadores: " << endl;
        cin >> cantJugadores;

        if (cantJugadores >= 2)
        {
            for (int i = 0; i < cantJugadores; i++)
            {
                cout << "Jugador " << i + 1 << endl;
                cout << "Ingrese su nombre: ";
                cin >> nombre;

                listTurno.encolar(new Persona(nombre, 0));
            }
        }
        else
        {
            cout << "Ingrese un número mayor a 2" << endl;
        }

    } while (cantJugadores < 2);
}

void Jugar::lecturaArchivo()
{

    /// lectura de archivo
    const char *filtro[] = {"*.csv"};
    const char *archivo = tinyfd_openFileDialog("Seleccionar archivo CSV", "", 1, filtro, "Archivos CSV", 0);

    if (archivo)
    {
        cout << "Archivo seleccionado: " << archivo << endl;
        ifstream file(archivo);

        if (!file)
        {
            cout << " Error al abrir el archivo :c";
        }

        string linea;

        while (getline(file, linea))
        { // Lee línea por línea

            stringstream ss(linea);
            string palabra;

            while (getline(ss, palabra, ','))
            {
                /// guardar las palabras
                listaPalabra.insertar(palabra);

                /// guardar las fichas en una lista
                for (char letra : palabra)
                {
                    listaFicha.insertar(new Ficha(letra));
                }
            }
        }

        file.close(); // Cierra el archivo
    }
    else
    {
        cout << "No se seleccionó ningún archivo." << endl;
    }
}

void Jugar::dividirFichas()
{
    int cantFichas = listaFicha.getSize() / cantJugadores;
    int resto = listaFicha.getSize() % cantJugadores;

    for (int i = 0; i < cantJugadores; i++)
    {
        ListFicha *listaFichaPorJuagador = new ListFicha(); // Lista para cada jugador

        // Asignar fichas equitativamente
        for (int j = 0; j < cantFichas; j++)
        {
            NodoListFicha *nodo = listaFicha.getPrimero();
            if (nodo)
            {
                Ficha *ficha = nodo->ficha;
                listaFichaPorJuagador->insertar(ficha);
                listaFichaPorJuagador->ordenarLista();
                listaFicha.eliminar(ficha);
            }
        }

        // Asignar fichas extras si hay un resto
        if (resto > 0 && listaFicha.getSize() > 0)
        {
            NodoListFicha *nodoExtra = listaFicha.getPrimero();
            Ficha *fichaExtra = nodoExtra->ficha;
            listaFichaPorJuagador->insertar(fichaExtra);
            listaFicha.eliminar(fichaExtra);
            resto--;
        }

        // Obtener el jugador del turno actual
        NodoTurno *turnoActual = listTurno.getFrente();

        if (turnoActual)
        {
            Persona *jugador = turnoActual->jugador;

            if (jugador)
            {
                jugador->insertarFichas(listaFichaPorJuagador);
            }
            else
            {
                cout << " Error: NodoTurno no tiene un jugador asociado." << endl;
            }

            listTurno.moverFrenteFinal(); // Avanzar turno
                                          //  jugador->mostrar();
                                          //  jugador->imprimirFichas();
        }
        else
        {
            cout << " Error: La cola de turnos está vacía." << endl;
        }
    }

    cout << "Fichas restantes: " << listaFicha.getSize() << endl;
}

/// turno de jugadores

void Jugar::turnoJugador()
{
    NodoTurno *turnoActual = listTurno.getFrente();

    if (turnoActual)
    {
        Persona *jugador = turnoActual->jugador;

        if (jugador)
        {
            cout << "Turno de " << jugador->getNombre() <<", Con un Punteo de: "<< jugador->getPunteo() << endl;
            cout <<" Sus fichas son: "<<endl;

            if (jugador->getFichas()->getSize() != 0){

                jugador->imprimirFichas();
                cout << "Seleccione una ficha: ";
                char letra;
                cin >> letra;

                Ficha *ficha = jugador->buscarFicha(letra);

                if (ficha)
                {
                    cout << "Ficha seleccionada: " << ficha->getLetra() << endl;
                    cout << "Ingrese la posición (x, y): ";
                    int x, y;
                    cin >> x >> y;

                    if (tablero.setFicha(x, y, ficha))
                    { 
                        jugador->getFichas()->eliminar(ficha);
                        /// analizar palabra

                    }

                    tablero.imprimirTablero();
                    listTurno.moverFrenteFinal(); // Avanzar turno
                }
                else
                {
                    cout << " Error: Ficha no encontrada." << endl;
                }
            }
            else
            {
                cout << " Error: NodoTurno no tiene un jugador asociado." << endl;
            }
        }
        else
        {
            cout << " Error: La cola de turnos está vacía." << endl;
        }
    }
    else
    {
        cout << " Error: El jugador no tiene fichas." << endl;
        listTurno.moverFrenteFinal(); // Avanzar turno
    }
}

/// mostrar turno
