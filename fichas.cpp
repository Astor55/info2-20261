#include <iostream>
#include "fichas.h"

using namespace std;


/*

Crean las piezas del tetris.

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
unsigned short CrearPiezaT() // se crea la pieza T del tetris 3x2
{
    unsigned short pieza = 0;

    pieza |= (1 << 14);
    pieza |= (1 << 11);
    pieza |= (1 << 10);
    pieza |= (1 << 9);

    return pieza;
}


unsigned short CrearPiezaL() //se crea la pieza L del tetris 2x3
{

    unsigned short pieza = 0;

    pieza |= (1 << 15);
    pieza |= (1 << 11);
    pieza |= (1 << 7);
    pieza |= (1 << 6);

    return pieza;

}


unsigned short CrearPiezaJ() // se crea la pieza J del tetris 2x3
{

    unsigned short pieza = 0;

    pieza |= (1 << 14);
    pieza |= (1 << 10);
    pieza |= (1 << 6);
    pieza |= (1 << 7);

    return pieza;

}


unsigned short CrearPiezaZ() // se crea la pieza Z del tetris 3x2
{

    unsigned short pieza = 0;

    pieza |= (1 << 15);
    pieza |= (1 << 14);
    pieza |= (1 << 10);
    pieza |= (1 << 9);

    return pieza;

}


unsigned short CrearPiezaO() // se crea la pieza O del tetris 2x2
{

    unsigned short pieza = 0;

    pieza |= (1 << 15);
    pieza |= (1 << 14);
    pieza |= (1 << 11);
    pieza |= (1 << 10);

    return pieza;

}


/*
ElegirPieza crea una serie de casos que al ejecutarse algun numero entre 0 y 4
que se reciba, entonces se elije que pieza se generará.
*/
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

representacion visual.

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


/*
RotarPieza es una funcion que sirve para rotar la pieza que está en el tablero
una vez el usuario usa el comando para rotar, se actuvará la funcion y esta se
reorgamizará 90° en sentido horario.
*/
unsigned short RotarPieza(unsigned short pieza)
{

    unsigned short NuevaPos = 0;

    for (int fila = 0; fila < 4; fila++)
    {

        for (int columna = 0; columna < 4; columna++)
        {

            int bit = (fila * 4) + columna;

            if (pieza &(1 << bit))
            {

                int NuevaFila = columna;

                int NuevaColumna = 3 - fila;

                int nuevoBit = (NuevaFila * 4) + NuevaColumna;

                NuevaPos |= (1 << nuevoBit);

            }

        }

    }

    return NuevaPos;

}



















