#include "ArrayList.h"
typedef struct
{
    char nota[1];
    int duracion;
    int volumen;

}Emelodia;

typedef struct
{
    char nota;
    int frecuencia;

}Efrecuencias;

typedef struct
{
    char nombre;
    int freq;
    int duration;
    int volume;

}Enota;

int menu(int limiteInf, int limiteSup);
Emelodia *new_melodia();
Efrecuencias *new_frecuencia();
Enota *new_nota();

void copiarMelodia(ArrayList *plist);
void copiarFrecuencia(ArrayList *plist,Efrecuencias *frecuencias);
