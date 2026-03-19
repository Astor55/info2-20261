#include <iostream>
#include "fichas.h"

using namespace std;


/*

Crean las piezas del tetris.

Se utiliza SHIFT (<<) para posicionar un bit en la celda correspondiente
dentro de una matriz lógica de 4x4 representada en 16 bits.

Luego se usa OR (|) para activar esos bits dentro de la variable que
representa la pieza.

Representación de la pieza(T):

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
ElegirPieza selecciona una pieza según un numero recibido.
    e   sto sirve como una base para generar las piezas aleatoriamente.
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

    default: return CrearPiezaT();

    }

    return 0;
}


/*
Imprime en consola la representación visual de una pieza.
Los bits activos se muestran como '#' y los inactivos como '.'.

representacion visual(T).

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
RotarPieza es una funcion que sirve para girar la pieza que está en el tablero
una vez el usuario usa el comando para rotar, se activará la funcion y esta se
reorgamizará 90° en sentido horario.

La rotacion se realiza manipulando los bits de la matriz 4x4
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


/*
celda_activa lo que hace es verificar si una celda está
activa dentro de la pieza, esto ayudapara ver si una celda
está activa para cuando se confirmen las colisiones.
*/
bool celda_activa(unsigned short pieza, int x, int y)
{

    int bit = (x * 4) + y;

    unsigned short mascara = 1 << bit;

    if (pieza & mascara)
    {

        return true;

    }

    else
    {

        return false;

    }
}



/*
Colision verifica si la pieza colisionará con el tablero
en una pusicion dada.

retornará el boolean correspondiente.
TRUE -> si hay colision
FALSE -> si no la hay
*/
bool Colision(char** tablero, unsigned short pieza, int x, int y, int alto, int ancho)
{

    for (int fila = 0; fila < 4; fila++)
    {

        for(int columna = 0; columna < 4; columna++)
        {

            if(celda_activa(pieza, fila, columna))
            {

                int tableroY = y + fila;

                int tableroX = x + columna;

                if(tableroY < 0 || tableroY >= alto
                    || tableroX <= 0 || tableroX >= ancho - 1) // limites del tablero
                {

                    return true;

                }
                if(tablero[tableroY][tableroX] != '.') // colisiona con lo que no sea vacio '.'
                {

                    return true;

                }
            }

        }

    }

    return false;

}


/*
Fijar_pieza se encarga de hace una copia de la pieza en el tablero una vez
se deja en la posicion deseada.
*/
void Fijar_pieza(char** tablero, unsigned short pieza, int x, int y)
{

    for(int fila = 0; fila < 4; fila++)
    {

        for(int columna = 0; columna < 4; columna++)
        {

            if(celda_activa(pieza, fila, columna))
            {

                tablero[y + fila][x + columna] = '#';

            }

        }

    }

}






