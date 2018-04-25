#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {
    int dia;
    int mes;
    int anio;

}EFecha;

typedef struct {
    char nombre[50];
    int legajo;
    float salario;
    EFecha fn;
    int estado;

}EEmpleado;

void inicializar(EEmpleado[], int);
void alta(EEmpleado[], int);
void listar(EEmpleado[], int);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EEmpleado lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EEmpleado lista[], int dni);


#endif // FUNCIONES_H_INCLUDED

