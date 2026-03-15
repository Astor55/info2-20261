#ifndef FUNCIONES_TABLERO_H
#define FUNCIONES_TABLERO_H

char **tablero();
void imprimir_tablero(char **table, int alto, int ancho);
void borrar_pieza_del_tablero(char** tab, char pieza[4][4], int x, int y);
void dibujar_pieza_del_tablero(char** tab, char pieza[4][4], int x, int y);
char **actualizacion_tablero(char jugada, char ** tabl);


#endif // FUNCIONES_TABLERO_H
