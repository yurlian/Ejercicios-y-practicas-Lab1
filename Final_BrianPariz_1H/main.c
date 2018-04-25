#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Funciones.h"

int main()
{
    char seguir = 's';
    int opcion, flagCargar = 0;

    ArrayList* listaTicket = al_newArrayList();
    ArrayList* listaProblemas = al_newArrayList();

    while(seguir == 's')
    {
        printf("1- Leer Tickets\n");
        printf("2- Procesar Informacion\n");
        printf("3- Mostrar estadisticas\n");
        printf("4- Salir\n\n");

        opcion = 0;
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            if(flagCargar == 0)
            {
                if(CargarTickets(listaTicket) == 0 && CargarProblemas(listaProblemas) == 0)
                {
                    printf("\nTickets cargados con exito!\n\n");
                    flagCargar = 1;
                }
                else
                    printf("\nError!\n\n");
            }
            else
                printf("\nError! Los tickets ya han sido cargados previamente.\n\n");
            break;

        case 2:
            if(flagCargar == 1)
            {
                if(procesarInformacion(listaTicket, listaProblemas) == 0)
                    printf("Informacion procesada con exito!\n\n");
                else
                    printf("\nError!\n\n");
            }
            else
                printf("\nPrimero carge los tickets!\n\n");
            break;

        case 3:
            if(flagCargar == 1)
            {
                if(mostrarEstadisticas(listaTicket, listaProblemas) != 0)
                    printf("\nError!\n\n");
            }
            else
                printf("\nPrimero carge los tickets!\n\n");
            break;

        case 4:
            printf("\nAdios, vuelve pronto!\n\n");
            seguir = 'n';
            break;

        default:
            printf("\nReingrese una opcion correcta\n\n");
            break;
        }

        system("\n\npause");
        system("cls");
    }

    return 0;
}
