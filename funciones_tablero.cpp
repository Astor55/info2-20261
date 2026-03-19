#include "funciones_tablero.h"
#include <iostream>
using namespace std;



char **tablero(int alto, int  ancho){


    /*
    Esta funcion recibe una altura X y una anchura Y, las cuales son las dimensiones de una matriz
    la cual cada uno de sus elementos seran apuntadores a char, la funcion unicamente la crea para poder
    ser utilizada durante la ejecucion del programa, por lo mismo es que no se libera el espacio en memoria
    reservado

 */
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


void borrar_pieza_del_tablero(char **tab, unsigned char pieza[4], int x, int y){ // x es la columna en la que se encuentra la figura, y Y la fila

    /*

    Una vez el usuario haya realizado un moviemiento, para actulizar la posicion de la pieza en el tablero
    esta se debe borrar de donde estaba antes, esta funcion realiza la eliminacion de la pieza
     */

    for (int fila = 0; fila < 4; fila++){

        for(int columna = 0; columna < 4; columna++){

            if (pieza[fila] & (1 <<(3 << columna))){

                tab[y + fila][x + columna] = '.';
            }


        }
    }
}

void dibujar_pieza_del_tablero(char **tab, unsigned char pieza[4], int x, int y){ // x es la columna de la nueva posocion en la que se encuentra la figura, y Y la fila


    /*

    Una vez la posicion anterior de la pieza fue eliminada, se procesa la nueva posicion de la ficha.

     */
    for(int fila = 0; fila < 4; fila++){

        for(int columna = 0; columna < 4; columna++){

            if(pieza[fila] & (1 << (3 - columna))){

                tab[y + fila][x + columna] = '#';
            }
        }
    }
}



void actualizacion_tablero(unsigned char pieza[4], char **tabl, int alto, int ancho, int x, int y){

    /*

    Esta funcion se encarga de imprimir el tablero actualizado con el movimiento realizado por el usuario
     */

    for(int fila = 0; fila < alto; fila++){

        for(int columna = 0; columna < ancho; columna++){

            bool dibujado = false;

            for(int i = 0; i <4; i++){ // recorre toda la ficha y verifica si en la posicion (i,j) hay un # y si la fila y verifica si concuerda con la posicion real de la fichja en el tablero

                for(int j = 0; j <4; j++){

                    if ((pieza[i] & (1 << (3-j))) && fila == y+i && columna == x+j){

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


void eliminacion_fila(char **tab, int alto, int ancho){

    /*

    Esta funcion se encarga de verificar si una fila se encuentra llena por completo, por tanto se elimina.
    Basicamente lo que hace es identificar la fila llena, despues se reemplazan los elementos que tenia esa
    fila con los elementos que tiene la fila anterior, y asi con todas las filas para dar esa simulacion de
    caida, al final se suma una a las filas para confirmar si en esa misma posicion hubo otra fila llena, caso
    que puede pasar si se llenan dos filas o hasta mas al mismo instante.

     */

    for(int filas = alto -1; filas >= 0; filas--){

        bool filallena = true;

        for(int columnas = 0; columnas < ancho; columnas++){

            if(tab[filas][columnas] == '.'){

                filallena = false;
                break;
            }


        }

        if (filallena == true){

            for(int i = filas; i > 0; i--){

                for(int j = 0; j < ancho; j++){

                    tab[i][j] = tab[i - 1][j];
                }
            }

            for(int k = 0; k < ancho; k++){

                tab[0][k] = '.';
            }

            filas++;
        }
    }
}

bool game_over(char **tab, int ancho){

    /*

    Esta funcion se encarga de detectar cuando hay un posible "Game Over"
    verificando si en algun elemento de la primera fila, hay una posicion
    ocupada.

     */

    for(int columna = 0; columna < ancho; columna++){

        if(tab[0][columna] == '#'){

            return true; // Si detecata un espacio ocupada en la primera fila, se confirma game over, debido a que no se pueden acumular mas piezas
        }

      }


    return false; // Si no detecta un espacio ocupado en la primera fila, el juego sigue hasta que se verifique otra vez la condicion
}
