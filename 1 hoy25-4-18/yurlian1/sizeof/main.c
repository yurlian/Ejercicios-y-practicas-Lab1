#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dato;

    dato = sizeof(char);
    printf("char. %d \n", dato);

    dato = sizeof(int);
    printf("int: %d \n", dato);

    dato = sizeof(float);
    printf("float: %d \n", dato);

    dato = sizeof(double);
    printf("double: %d \n", dato);

    dato = sizeof(long);
    printf("long: %d \n", dato);

    dato = sizeof(void);
    printf("void: %d \n ",dato);

    return 0;
}
