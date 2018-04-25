#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define CANT 50

int main()
{
    eProgramador programador[CANT];
    eProgramador plantel[CANT];
    eCategoria categorias[]= {{1, "Junior"},{2,"SemiSenior"},{3,"Senior"}};
    int cantJunior=0;
    int cantSemiSenior = 0;
    int cantSenior = 0;
    char opcion;
    char seguir = 's';

    do
    {
        printf("Menu de opciones\n\n");
        printf("1- Alta Programador\n");
        printf("2- Modificacion Programador\n");
        printf("3- Baja Programador\n");
        printf("4- Asignar programador a proyecto\n");
        printf("5- Mostrar programadores\n");
        printf("6- Mostrar proyectos\n");
        printf("7- Proyectos de programador\n");
        printf("8- Salir\n");
        printf("\nIngrese una opcion: ");
        opcion = getch();

        inicializarProgramadores(plantel, CANT);

        switch(opcion)
        {
        case '1':
            if(altaProgramador(plantel, CANT, categorias, 3))
            {
                printf("Alta exitosa!\n\n");
            }
            else
            {
                printf("No se pudo efectuar el alta\n\n");
            }
            system("pause");
            break;

        case '2':

            break;
        case '3':

            break;
        case '4':

            break;
        case '5':
            mostrarProgramadores(plantel, CANT, categorias, 3);
            break;

        case '6':
            cantJunior = cantidadXcategoria(plantel, CANT, categorias, 3, "Junior");
            cantSemiSenior = cantidadXcategoria(plantel, CANT, categorias, 3, "SemiSenior");
            cantSenior = cantidadXcategoria(plantel, CANT, categorias, 3, "Senior");

            printf("\nJunior: %d   SemiSenior: %d   Senior: %d\n\n", cantJunior, cantSemiSenior, cantSenior);

            system("pause");

            break;

        case '7':

            break;

        case '8':
            seguir = 'n';
            break;

        default:
            printf("\n\nOpcion invalida. Presione una tecla para reintentar\n");
            getch();
            system("cls");
            break;
        }

         }while(seguir=='s');

        return 0;
    }
