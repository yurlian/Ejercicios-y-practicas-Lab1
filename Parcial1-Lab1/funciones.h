#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    int idCategoria;
    float sueldo;
    int estado;

}eProgramador;

typedef struct
{
    int id;
    char descripcion[20];
    float pagoXHora;

}eCategoria;

typedef struct
{
    int idProyecto;
    char nombre[20];
}eProyecto;

void inicializarProgramadores(eProgramador[], int);
int buscarLibre(eProgramador[], int);
int buscarXId(eProgramador[], int, int);
int buscarCategoria(eCategoria[], int, int);
void mostrarCategorias(eCategoria[], int);
void mostrarCategoria(eCategoria);
int altaProgramador(eProgramador[], int, eCategoria[], int);
void obtenerDescripcion(char[], eCategoria[], int, int);
int cantidadXcategoria(eProgramador[], int, eCategoria[], int, char[]);
void mostrarProgramadores(eProgramador[], int, eCategoria[], int);
void mostrarProgramador(eProgramador, eCategoria[], int);

#endif // FUNCIONES_H_INCLUDED
