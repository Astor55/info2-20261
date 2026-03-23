#ifndef FUNCIONES_TABLERO_H
#define FUNCIONES_TABLERO_H

char **tablero(int alto, int ancho);

void imprimir_tablero(char **table, int alto, int ancho);

void borrar_pieza_del_tablero(char** tab, unsigned short pieza, int x, int y);

void dibujar_pieza_del_tablero(char** tab, unsigned short pieza, int x, int y);

void actualizacion_tablero(char **tabl,unsigned short pieza, int alto, int ancho, int x, int y);

void eliminacion_fila(char **tab, int alto, int ancho);

bool game_over(char **tab,int ancho);

void Centrar(int ancho, int &x, int &y);

void liberar_memoria(char **tab, int alto);

#endif // FUNCIONES_TABLERO_H
