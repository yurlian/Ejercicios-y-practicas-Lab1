#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "lib.h"
#include "funciones.h"


void main()
{
    ArrayList *melodiaArray = al_newArrayList();
    ArrayList *notaArray = al_newArrayList();


    Efrecuencias *frecuencia;

    int opcion = 0;

    //copiar(pList);
    while( opcion != 5)
    {
        opcion = menu(1,5);

        switch(opcion)
        {
        case 1:
            copiarMelodia(melodiaArray);
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            break;

        }
    }
}
