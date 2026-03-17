#include <iostream>
#include "fichas.h"

using namespace std;

#include <iostream>
#include "fichas.h"

using namespace std;

void imprimir_tablero(char** tablero, int ancho, int alto,
                      unsigned short pieza, int px, int py)
{
    for(int i = 0; i < alto; i++)
    {
        for(int j = 0; j < ancho; j++)
        {
            char dibujar = tablero[i][j];

            for(int f = 0; f < 4; f++)
            {
                for(int c = 0; c < 4; c++)
                {
                    if(celda_activa(pieza,f,c))
                    {
                        if(i == py+f && j == px+c)
                            dibujar = '#';
                    }
                }
            }

            cout << dibujar;
        }
        cout << endl;
    }
}


int main()
{
    int ancho = 12;
    int alto = 12;

    char** tablero = new char*[alto];

    for(int i=0;i<alto;i++)
    {
        tablero[i] = new char[ancho];

        for(int j=0;j<ancho;j++)
        {
            if(j==0 || j==ancho-1)
                tablero[i][j] = '|';
            else
                tablero[i][j] = '.';
        }
    }

    unsigned short pieza = CrearPiezaT();

    int x = 4;
    int y = 0;

    char opcion;

    while(true)
    {
        cout << "\n";
        imprimir_tablero(tablero,ancho,alto,pieza,x,y);

        cout << "\nA izquierda\n";
        cout << "D derecha\n";
        cout << "S bajar\n";
        cout << "W rotar\n";
        cout << "Q salir\n";

        cin >> opcion;

        int nuevoX = x;
        int nuevoY = y;
        unsigned short nuevaPieza = pieza;

        if(opcion=='a') nuevoX--;
        if(opcion=='d') nuevoX++;
        if(opcion=='s') nuevoY++;
        if(opcion=='w') nuevaPieza = RotarPieza(pieza);

        if(opcion=='q') break;

        if(!Colision(tablero,nuevaPieza,nuevoX,nuevoY))
        {
            x = nuevoX;
            y = nuevoY;
            pieza = nuevaPieza;
        }
        else
        {
            cout << "COLISION\n";
        }
    }
}
