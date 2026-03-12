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

/*
Imprime en consola la representación visual de una pieza.
Los bits activos se muestran como '#' y los inactivos como '.'.
*/
void ImprimirPieza(unsigned short pieza)
{

    for(int i = 15; i >= 0; i--)

    {

        if(pieza & (1 << i))

            cout << "[ ]";

        else

            cout << "   ";


        if(i % 4 == 0)

            cout << endl;

    }

}
