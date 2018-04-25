#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void inicializarProgramadores(eProgramador x[], int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
        x[i].id = -1;
    }
}
int buscarLibre(eProgramador x[], int tam)
{
    int indice = -1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(x[i].id == -1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
int buscarXId(eProgramador x[], int tam, int id)
{
    int indice = -1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(x[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
int buscarCategoria(eCategoria x[], int tam, int id)
{
    int indice = -1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(x[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
int altaProgramador(eProgramador p[], int tamP, eCategoria c[], int tamC)
{
    int valido = 0;
    int indice = buscarLibre(p, tamP);

    if(indice == -1)
    {
        printf("\nNo hay lugar en el sistema para mas programadores!\n\n");
        system("pause");
    }
    else
    {
        int id;
        int existe;
        printf("\nIngrese id: ");
        scanf("%d", &id);

        existe = buscarXId(p, tamP, id);

        if(existe != -1)
        {
            printf("\nExiste un programador con ese id!\n\n");
            system("pause");
        }
        else
        {
            p[indice].id = id;
            printf("\nIngrese Nombre: ");
            fflush(stdin);
            gets(p[indice].nombre);
            mostrarCategorias(c, tamC);
            printf("\nIngrese categoria: ");
            scanf("%d", &p[indice].idCategoria);
            printf("\nIngrese sueldo: ");
            scanf("%f", &p[indice].sueldo);

            valido = 1;
        }
    }
    return valido;
}
void mostrarCategorias(eCategoria c[], int tam)
{
    int i;
    for(i= 0; i<tam; i++)
    {
        mostrarCategoria(c[i]);
    }
    printf("\n");
}
void mostrarCategoria(eCategoria cat)
{
    printf("\n%d %s", cat.id, cat.descripcion);
}
void mostrarProgramadores(eProgramador p[], int tamP, eCategoria c[], int tamC)
{
    int i;
    printf("\nId   Nombre     Categoria     Sueldo\n\n");
    for(i=0; i< tamP; i++)
    {
        if(p[i].id != -1)
        {
             mostrarProgramador(p[i], c, tamC);
        }
    }
    printf("\n\n");

    system("pause");

}
void mostrarProgramador(eProgramador p, eCategoria c[], int tamC)
{
    char descripcionCat[20];

    obtenerDescripcion(descripcionCat, c, tamC, p.idCategoria);

    printf("\n%5d %s %s %.2f", p.id, p.nombre, descripcionCat, p.sueldo);
}
void obtenerDescripcion(char descripcion[],  eCategoria c[], int tamC, int idCat)
{
    int i;
    for(i=0; i< tamC; i++)
    {
        if(c[i].id == idCat)
        {
            strcpy(descripcion, c[i].descripcion);
        }
    }
}
int cantidadXcategoria(eProgramador p[], int tamP, eCategoria c[], int tamC, char descripcion[])
{
    int cantidad = 0;
    int i;
    int idCat;

    for(i=0; i< tamC; i++)
    {
        if(strcmp(c[i].descripcion, descripcion) == 0)
        {
            idCat = c[i].id;
            break;
        }
    }
    for(i=0; i< tamP; i++)
    {
        if(p[i].idCategoria == idCat)
        {
            cantidad++;
        }
    }
    return cantidad;
}
