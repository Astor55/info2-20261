#include <iostream>
#include <random>
#include "fichas.h"
#include "funciones_tablero.h"


void verificacion(int &alto, int &ancho);

void Limpiar_Pantalla();

void limpiarBuffer();

using namespace std;


int main()
{
    int alto;

    int ancho;

    verificacion(alto, ancho);

    char **tab = tablero(alto, ancho);

    random_device rd;

    mt19937 gen(rd());

    uniform_int_distribution <int> dist(0, 5);

    unsigned short pieza = ElegirPieza(dist(gen));

    int x;

    int y;

    Centrar(ancho, x, y);

    while (true)
        {

        Limpiar_Pantalla();

        actualizacion_tablero(tab, pieza, alto, ancho, x, y);

        if (game_over(tab, ancho))
        {

            cout << "\n GAME OVER \n";

            liberar_memoria(tab, alto);

            break;

        }

        char jugada;

        cin >> jugada;

        if (jugada != 'W' && jugada != 'w' &&
            jugada != 'A' && jugada != 'a' &&
            jugada != 'S' && jugada != 's' &&
            jugada != 'D' && jugada != 'd' &&
            jugada != 'Q' && jugada != 'q')
        {

            cout << "Comando invalido\n";

            while (cin.get() != '\n'); // limpiar basura

            continue;

        }

        if (jugada == 'W' || jugada == 'w'){

            unsigned short copia = RotarPieza(pieza);

            if (!Colision(tab, copia, x, y, alto, ancho))
            {

                pieza = copia;

            }

        }

        else if(jugada == 'S' || jugada == 's')
        {

            if(!Colision(tab, pieza, x, y + 1, alto, ancho))
            {

                y++;

            }

            else
            {

                Fijar_pieza(tab, pieza, x, y);

                eliminacion_fila(tab, alto, ancho);

                pieza = ElegirPieza(dist(gen));

                Centrar(ancho, x, y);

                if(Colision(tab, pieza, x, y, alto, ancho))
                {

                    Limpiar_Pantalla();

                    actualizacion_tablero(tab, pieza, alto, ancho, x, y);

                    cout << "\n GAME OVER \n";

                    liberar_memoria(tab, alto);

                    break;

                }

            }

        }

        else if(jugada == 'D' || jugada == 'd')
        {

            if(!Colision(tab, pieza, x + 1, y, alto, ancho))
            {

                x++;

            }

        }

        else if(jugada == 'A' || jugada == 'a')
        {

            if(!Colision(tab, pieza, x - 1, y, alto, ancho))
            {

                x--;

            }

        }

        else if(jugada == 'Q' || jugada == 'q')
        {

            cout << "Gracias Por Jugar! ;)";

            liberar_memoria(tab, alto);

            break;

        }

    }

    return 0;

}


void verificacion(int &alto, int &ancho)

{

    do
    {

        cout << "Ingrese el alto: ";

        cin >> alto;

        if(cin.fail())
        {

            limpiarBuffer();

            cout << "Entrada invalida.\n";

            continue;

        }

        cout << "Ingrese el ancho (un numero multiplo de 8): ";

        cin >> ancho;

        if (cin.fail())
        {

            limpiarBuffer();

            cout << "Entrada invalida.\n";

            continue;

        }

    }

    while (ancho % 8 != 0 || alto < 8 || alto > 15 || ancho < 8 || ancho > 24);

}

void Limpiar_Pantalla()
{

    for (int i= 0; i < 40; i++)
    {

        cout << endl;

    }

}

void limpiarBuffer()
{
    cin.clear(); // limpia error

    while (cin.get() != '\n'); // vacía el buffer
}
