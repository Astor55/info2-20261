#ifndef FICHAS_H
#define FICHAS_H


unsigned short CrearPiezaT();


unsigned short CrearPiezaL();


unsigned short CrearPiezaJ();


unsigned short CrearPiezaZ();


unsigned short CrearPiezaO();


unsigned short PiezaElegir(int cual);


bool celda_activa(unsigned short pieza, int fila, int columna);


void ImprimirPieza(unsigned short pieza);


unsigned short RotarPieza(unsigned short pieza);


bool Colision(char** tablero, unsigned short pieza, int x, int y);


void Fijar_pieza(char** tablero, unsigned short pieza, int x, int y);


#endif // FICHAS_H
