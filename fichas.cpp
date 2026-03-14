#include <iostream>
#include "fichas.h"

using namespace std;


/*

Crea la pieza T usando operaciones bitwise.

Se utiliza SHIFT (<<) para posicionar un bit en la celda correspondiente
dentro de una matriz lógica de 4x4 representada en 16 bits.

Luego se usa OR (|) para activar esos bits dentro de la variable que
representa la pieza.

Representación de la pieza:

        0 1 0 0
        1 1 1 0
        0 0 0 0
        0 0 0 0

*/
unsigned short CrearPiezaT()
{
    unsigned short pieza = 0;

    pieza |= (1 << 14);
    pieza |= (1 << 11);
    pieza |= (1 << 10);
    pieza |= (1 << 9);

    return pieza;
}


unsigned short CrearPiezaL()
{

    unsigned short pieza = 0;

    pieza |= (1 << 15);
    pieza |= (1 << 11);
    pieza |= (1 << 7);
    pieza |= (1 << 6);

    return pieza;

}


unsigned short CrearPiezaJ()
{

    unsigned short pieza = 0;

    pieza |= (1 << 14);
    pieza |= (1 << 10);
    pieza |= (1 << 6);
    pieza |= (1 << 7);

    return pieza;

}


unsigned short CrearPiezaZ()
{

    unsigned short pieza = 0;

    pieza |= (1 << 15);
    pieza |= (1 << 14);
    pieza |= (1 << 10);
    pieza |= (1 << 9);

    return pieza;

}


unsigned short CrearPiezaO()
{

    unsigned short pieza = 0;

    pieza |= (1 << 15);
    pieza |= (1 << 14);
    pieza |= (1 << 11);
    pieza |= (1 << 10);

    return pieza;

}


unsigned short ElegirPieza(int cual)
{

    switch (cual)
    {

    case 0: return CrearPiezaT();

    case 1: return CrearPiezaL();

    case 2: return CrearPiezaJ();

    case 3: return CrearPiezaZ();

    case 4: return CrearPiezaO();

    }

    return 0;
}


/*
Imprime en consola la representación visual de una pieza.
Los bits activos se muestran como '#' y los inactivos como '.'.

representacion visual

        . # . .
        # # # .
        . . . .
        . . . .
*/
void ImprimirPieza(unsigned short pieza)
{

    for(int i = 15; i >= 0; i--)

    {

        if(pieza & (1 << i))

            cout << "#";

        else

            cout << ".";


        if(i % 4 == 0)

            cout << endl;

    }

}


unsigned short RotarPieza(unsigned short pieza)
{



}



















