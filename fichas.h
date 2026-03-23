#ifndef FICHAS_H
#define FICHAS_H

// Creacion de las peizas del tetris
unsigned short CrearPiezaT();
unsigned short CrearPiezaL();
unsigned short CrearPiezaJ();
unsigned short CrearPiezaZ();
unsigned short CrearPiezaO();
unsigned short  CrearPiezaRecta();

// seleccion de la pieza
unsigned short ElegirPieza(int cual);

// verificacion de celdas activas
bool celda_activa(unsigned short pieza, int x, int y);

// dibujar la pieza para jugar
void ImprimirPieza(unsigned short pieza);

// Rotacion de la pieza en juego
unsigned short RotarPieza(unsigned short pieza);

// verificar espacios que no puede cruzar la pieza en el tablero
bool Colision(char** tablero, unsigned short pieza, int x, int y, int alto, int ancho);

// Dibujar pieza en el lugar que se dejará
void Fijar_pieza(char** tablero, unsigned short pieza, int x, int y);


#endif // FICHAS_H

