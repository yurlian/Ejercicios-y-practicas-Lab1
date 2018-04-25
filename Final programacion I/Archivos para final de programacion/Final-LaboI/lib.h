typedef struct
{
    char nota[10];
    int duracion;
    int volumen;

}Emelodia;

typedef struct
{
    char nota[10];
    int frecuencia;

}Efrecuencia;

typedef struct
{
    char nombre[3];
    int freq;
    int duration;
    int volume;
}Enota;



void copiarMelodia(ArrayList *plist);


char menu();

Emelodia *new_melodia();
Efrecuencia *new_frecuencia();
Enota *new_nota();
int cargarMelodia(ArrayList* this);
int cargarFrecuencia(ArrayList* this);
void crearEstructuraNota(ArrayList*lista_melodia,ArrayList*lista_frecuencia,ArrayList *lista_nota);

