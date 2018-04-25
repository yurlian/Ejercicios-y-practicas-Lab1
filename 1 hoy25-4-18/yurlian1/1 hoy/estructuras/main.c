#include <stdio.h>
#include <stdlib.h>

struct fecha{
    int dia, mes, anio;
};

struct gente{
    char nombre[81];
    struct fecha f_nacimiento;
};

int main()
{
    struct gente persona;

    printf("Nombre: ");
    scanf("%[^\n]", persona.nombre);

    printf("\n\nFecha de nacimiento");
    printf("\nDia: ");
    scanf("%d", &persona.f_nacimiento.dia);

    printf("\nMes: ");
    scanf("%d", &persona.f_nacimiento.mes);

    printf("\nAño: ");
    scanf("%d", &persona.f_nacimiento.anio);

    system("cls");
    printf("%s nacio el %d/%d/%d", persona.nombre, persona.f_nacimiento.dia, persona.f_nacimiento.mes, persona.f_nacimiento.anio);

    return 0;
}
