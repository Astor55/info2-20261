#include <iostream>
#include "fichas.h"


int main()
{
    unsigned short pieza = 0;
    char comando;

    while(true)
    {

        std::cout << "\nElige una pieza:\n";
        std::cout << "1: T\n";
        std::cout << "2: L\n";
        std::cout << "3: J\n";
        std::cout << "4: Z\n";
        std::cout << "5: O\n";
        std::cout << "q: salir\n";

        std::cin >> comando;

        if(comando == 'q')
            break;

        if(comando == '1') pieza = CrearPiezaT();
        if(comando == '2') pieza = CrearPiezaL();
        if(comando == '3') pieza = CrearPiezaJ();
        if(comando == '4') pieza = CrearPiezaZ();
        if(comando == '5') pieza = CrearPiezaO();

        std::cout << "\nPieza actual:\n";
        ImprimirPieza(pieza);

        std::cout << "\nPresiona 'w' para rotar (x para cambiar pieza)\n";

        while(true)
        {
            std::cin >> comando;

            if(comando == 'w')
            {
                pieza = RotarPieza(pieza);

                std::cout << "\nRotada:\n";
                ImprimirPieza(pieza);
            }
            else
            {
                break;
            }
        }
    }

    return 0;
}
