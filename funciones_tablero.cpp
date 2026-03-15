#include "funciones_tablero.h"
#include <iostream>
using namespace std;

/*
Esta funcion recibe una altura X y una anchura Y, las cuales son las dimensiones de una matriz
la cual cada uno de sus elementos seran apuntadores a char, la funcion unicamente la crea para poder
ser utilizada durante la ejecucion del programa, por lo mismo es que no se libera el espacio en memoria
reservado

 */

char **tablero(int alto, int  ancho){ // Funcion la cual crea el tablero del tetris, retorna un apuntador de apuntadores para poder trabajar sobre el tablero

    char **tab = new char *[alto]; // creamos el apunt de apunt y a su valor le guardamos espacio en el Heap, siendo guardada un arreglo estatico a char con dimension "Alto"

    for (int a = 0; a < alto ; a++){


        tab[a] = new char[ancho]; // Este ciclo se encarga de que a cada fila creada en la matriz, se le asigna un arreglo el cual seran las columnas


        for (int j = 0; j < ancho ; j++){ // En este ciclo se rellenan las columnas con | si son esquinas o * si son elementos dentro de la matriz

            if (j == ancho - 1 || j == 0){

                    tab[a][j] = '|';
            }

            else{

                tab[a][j] = '.';

            }
        }


    }

    return tab; // Se retorna el tablero ya relleno con los espacios y las esquinas
}


void imprimir_tablero(char **table, int alto, int ancho){

    /*
     Esta funcion se encarga de mostrar por pantalla el tablero generado por las dimensiones de alto y ancho
     ingresadas por el usuario

     */

    for (int i = 0; i < alto; i++){

        for (int p = 0; p < ancho ; p++){

            cout << table[i][p];
        }

        cout << endl;
    }
}


void borrar_pieza_del_tablero(char **tab, char pieza[4][4], int x, int y){ // x es la columna en la que se encuentra la figura, y Y la fila

    /*

    Una vez el usuario haya realizado un moviemiento, para actulizar la posicion de la pieza en el tablero
    esta se debe borrar de donde estaba antes, esta funcion realiza la eliminacion de la pieza
     */

    for (int fila = 0; fila < 4; fila++){

        for(int columna = 0; columna < 4; columna++){

            if (pieza[fila][columna] == '#'){

                tab[y + fila][x + columna] = '.';
            }


        }
    }
}

void dibujar_pieza_del_tablero(char **tab, char pieza[4][4], int x, int y){ // x es la columna de la nueva posocion en la que se encuentra la figura, y Y la fila


    /*

    Una vez la posicion anterior de la pieza fue eliminada, se procesa la nueva posicion de la ficha.

     */
    for(int fila = 0; fila < 4; fila++){

        for(int columna = 0; columna < 4; columna++){

            if(tab[fila][columna] == '#'){

                tab[fila + y][columna + x] = '#';
            }
        }
    }
}



char **actualizacion_tablero(char pieza[4][4], char **tabl, int alto, int ancho){

    /*

    Esta funcion se encarga de imprimir el tablero actualizado con el movimiento realizado por el usuario
     */

    for(int fila = 0; fila < alto; fila++){

        for(int columna = 0; columna < ancho; columna++){

            bool dibujado = false;

            for(int i = 0; i <4; i++){ // recorre toda la ficha y verifica si en la posicion (i,j) hay un # y si la fila y verifica si concuerda con la posicion real de la fichja en el tablero

                for(int j = 0; j <4; j++){

                    if (pieza[i][j == '#' && fila == y+i && columna == x+j]){

                        cout << '#';
                        dibujado = true;
                    }


                }

            }

            if (dibujado == false){ // si no entra al if, es porque en la posicion (i,j) no hay un #, por tanto se imprime el tablero normal

                cout << tabl[fila][columna];
            }



        }
        cout << endl;
    }
}
