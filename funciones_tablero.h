#ifndef FUNCIONES_TABLERO_H
#define FUNCIONES_TABLERO_H

char **tablero();
void imprimir_tablero(char **table, int alto, int ancho);
void borrar_pieza_del_tablero(char** tab, unsigned char pieza[4], int x, int y);
void dibujar_pieza_del_tablero(char** tab, unsigned char pieza[4], int x, int y);
void actualizacion_tablero(unsigned char pieza[4], char **tabl, int alto, int ancho, int x, int y);
void eliminacion_fila(char **tab, int alto, int ancho);
bool game_over(char **tab,int ancho);


#endif // FUNCIONES_TABLERO_H
