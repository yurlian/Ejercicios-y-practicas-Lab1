#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"

#define CANT 3
#define ESC 27

int main()
{
    EEmpleado empleado[CANT];
    int i;
    char opcion;

    do{
        system("cls");
        printf("1- Agregar empleado\n");
        printf("2- Borrar empleado\n");
        printf("3- Modificar empleado\n");
        printf("4- Imprimir lista\n");
        printf("ESC- Salir\n");

        opcion = getch();

        switch(opcion)
        {
            case '1':
                alta(empleado, CANT);
                break;
            case '2':
                printf("Baja...");
                break;
            case '3':
                printf("Modificar...");
                break;
            case '4':
                listar(empleado, CANT);
                system("pause");
                break;
            case 'ESC':
                break;
        }

    }while(opcion != ESC);

    return 0;
}
