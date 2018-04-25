#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"

void alta(EEmpleado emp[], int cantidad){
    int i;

    for(i=0; i<cantidad; i++){
        printf("Legajo: ");
        scanf("%d", &emp[i].legajo);

        printf("Nombre: ");
        fflush(stdin);
        scanf("%s", emp[i].nombre);

        printf("Salario: ");
        scanf("%f", &emp[i].salario);

        printf("Dia: ");
        scanf("%d", &emp[i].fn.dia);

        printf("Mes: ");
        scanf("%d", &emp[i].fn.mes);

        printf("Año: ");
        scanf("%d", &emp[i].fn.anio);
    }
}

void listar(EEmpleado emp[], int cantidad){
    int i;

    printf("Legajo\tNombre\t\t\tFechaNac\tSalario\n\n");
    for(i=0; i<cantidad; i++){
        printf("%d\t%s\t\t\t%d/%d/%d\t%.2f\n", emp[i].legajo, emp[i].nombre, emp[i].fn.dia, emp[i].fn.mes, emp[i].fn.anio, emp[i].salario);
    }
}
