#ifndef FICHAS_H
#define FICHAS_H


unsigned short PiezasT();


unsigned short PiezasL();


unsigned short PiezasJ();


unsigned short PiezasZ();


unsigned short PiezasO();


unsigned short PiezaElegir(int cual);


bool celda_activa(unsigned short pieza, int fila, int columna);


void ImprimirPiezas(unsigned short pieza);


unsigned short RotarPieza(unsigned short pieza);


bool Colision(char** tablero, unsigned short pieza, int x, int y);


void Fijar_pieza(char** tablero, unsigned short pieza, int x, int y);


#endif // FICHAS_H
