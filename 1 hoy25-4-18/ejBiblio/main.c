#include <stdio.h>
#include <stdlib.h>
#include "misFunc.h"

int main()
{
    int nro1, nro2, resultado;

    printf("Ingrese primer operando:");
    scanf("%d", &nro1);

    printf("\nIngrese segundo operando:");
    scanf("%d", &nro2);

    system("cls");

    resultado = sumar(nro1, nro2);

    printf("La suma es: %d", resultado);

    resultado = restar(nro1, nro2);

    printf("\nLa resta es: %d", resultado);

    return 0;
}
