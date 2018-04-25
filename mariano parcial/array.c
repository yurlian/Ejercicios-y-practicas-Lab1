#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

void cargarArray(sEmpleado* arrayEmpleados,int length)
{
    int i;
    char auxChar[50];

    if(arrayEmpleados != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            arrayEmpleados[i].legajo = i;
            sprintf(auxChar,"Nombre_%i",i);
            strcpy(arrayEmpleados[i].nombre,auxChar);
            arrayEmpleados[i].fechaIngreso.dia = 15;
            arrayEmpleados[i].fechaIngreso.mes = 3;
            arrayEmpleados[i].fechaIngreso.anio = 2000;
        }
        arrayEmpleados[8].fechaIngreso.dia = 1;
        arrayEmpleados[8].fechaIngreso.mes = 1;
        arrayEmpleados[8].fechaIngreso.anio = 2000;

        arrayEmpleados[18].fechaIngreso.dia = 1;
        arrayEmpleados[18].fechaIngreso.mes = 10;
        arrayEmpleados[18].fechaIngreso.anio = 2000;

        arrayEmpleados[28].fechaIngreso.dia = 2;
        arrayEmpleados[28].fechaIngreso.mes = 1;
        arrayEmpleados[28].fechaIngreso.anio = 2010;

        arrayEmpleados[6].fechaIngreso.dia = 16;
        arrayEmpleados[6].fechaIngreso.mes = 1;
        arrayEmpleados[6].fechaIngreso.anio = 2006;

        arrayEmpleados[22].fechaIngreso.dia = 1;
        arrayEmpleados[22].fechaIngreso.mes = 11;
        arrayEmpleados[22].fechaIngreso.anio = 2001;

        arrayEmpleados[33].fechaIngreso.dia = 21;
        arrayEmpleados[33].fechaIngreso.mes = 1;
        arrayEmpleados[33].fechaIngreso.anio = 2002;

    }

}


void mostrarArray(sEmpleado* arrayEmpleados,int length)
{
    int i;

    if(arrayEmpleados != NULL && length > 0)
        printf("LEGAJO\tNombre\tINGRESO\n");
        for(i=0;i<length;i++)
        {
            printf("%d\t%s\t%2d/%2d/%4d\n", arrayEmpleados[i].legajo,arrayEmpleados[i].nombre, arrayEmpleados[i].fechaIngreso.dia = 1, arrayEmpleados[i].fechaIngreso.mes, arrayEmpleados[i].fechaIngreso.anio);
        }

}



void bubleSort(sEmpleado* arrayEmpleados,int length)
{

}

void insertionSort(sEmpleado* arrayEmpleados,int length)
{

}

void quickSort(sEmpleado* arrayEmpleados,int length)
{

}


void swap(sEmpleado* auxEmpleadoA,sEmpleado* auxEmpleadoB)
{
    sEmpleado auxiliar;
    auxiliar = *auxEmpleadoA;
    *auxEmpleadoA = *auxEmpleadoB;
    *auxEmpleadoB = auxiliar;
}
