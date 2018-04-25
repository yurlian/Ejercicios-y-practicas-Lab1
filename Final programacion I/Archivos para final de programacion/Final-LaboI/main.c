#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "utn.h"
#include "lib.h"


int main()
{
    ArrayList* lista_melodia = al_newArrayList();
    ArrayList* lista_frecuancia = al_newArrayList();
    arrayList* lista_nota = al_newArrayList();

    char salir='s';
    do
    {
        switch(menu())
        {
        case '1':
            cargarMelodia(lista_melodia);
            cargarFrecuencia(lista_frecuancia);
            crearEstructuraNota(lista_melodia,lista_frecuancia,lista_nota);

            break;
        case '2':
            system("cls");


            break;
        case '3':
            break;
        case '4':
            salir = 'n';
            break;
        }

    }while(salir == 's');
    return 0;
}

