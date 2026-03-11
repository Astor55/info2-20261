
using namespace std;

char **tablero(int alto, ancho){ // Funcion la cual crea el tablero del tetris, retorna un apuntador de apuntadores para poder trabajar sobre el tablero

    char **tab = new char *[alto]; // creamos el apunt de apunt y a su valor le guardamos espacio en el Heap, siendo guardada un arreglo estatico a char con dimension "Alto"

    for (int a = 0; a < alto ; a++){


        tab[a] = new char[ancho]; // Este ciclo se encarga de que a cada fila creada en la matriz, se le asigna un arreglo el cual seran las columnas


        for (int j = 0; j < ancho ; j++){ // En este ciclo se rellenan las columnas con | si son esquinas o * si son elementos dentro de la matriz

            if (j == ancho - 1 || j == 0){

                    tab[a][j] = '|';
            }

            else{

                tab[a][j] = '*';

            }
        }


    }

    return tab; // Se retorna el tablero ya relleno con los espacios y las esquinas


}
