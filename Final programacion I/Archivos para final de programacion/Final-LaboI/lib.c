#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "ArrayList.h"
#include "utn.h"
#include "lib.h"




/** \brief Muestra el menu en pantalla y recibe las opciones
 *
 * \param -
 * \return un char.
 *
 */

char menu()
{
    char c;
    printf("1. Leer log\n");
    printf("2. Procesar informacion\n");
    printf("3. Mostrar estadisticas\n");
    printf("\n4. Salir\n\n");
    c=getch();
    return c;
}


Emelodia* new_melodia()
{
    Emelodia* this;
    this = (Emelodia*)malloc(sizeof(Emelodia));
    return this;
}

Efrecuencia* new_frecuencia()
{
    Efrecuencia* this;
    this = (Efrecuencia*)malloc(sizeof(Efrecuencia));
    return this;
}

Enota *new_nota()
{
    Enota* this;
    this = (Enota*)malloc(sizeof(Enota));
    return this;
}

int cargarMelodia(ArrayList* this)
{
    int retorno = 0;
    FILE* f;
    Emelodia *melodia;
    int flag = 0;

    char auxNota[10];
    char auxDuracion[25];
    char auxVolumen[25];

    if((f = fopen("files\\melodia.txt", "r"))==NULL)
    {
        retorno =-1;
    }

    else
    {
        rewind(f);
        while(!(feof(f)))
        {
            melodia = new_melodia();
            if(melodia!=NULL)
            {
                if(flag = 0)
                {
                    fscanf(f,"%[^;];%[^;];%[^\n]\n", auxNota, auxDuracion, auxVolumen);
                    flag = 1;
                }
                else
                {
                    fflush(stdin);
                    fscanf(f,"%[^;];%[^;];%[^\n]\n", auxNota, auxDuracion, auxVolumen);
                    strcpy(melodia->nota, auxNota);
                    melodia->duracion = atoi(auxDuracion);
                    melodia->volumen = atoi(auxVolumen);
                    al_add(this, melodia);
                    //printf("\n%d", melodia->volumen);
                }

            }
        }
    }
    fclose(f);
    free(melodia);
    return retorno;
}

int cargarFrecuencia(ArrayList* this)
{
    int retorno = 0;
    FILE* f;
    Efrecuencia *frecuencia;
    int flag = 0;

    char auxNota[10];
    char auxFrecuencia [25];

    if((f = fopen("files\\notas.txt", "r"))==NULL)
    {
        retorno =-1;
    }

    else
    {
        rewind(f);
        while(!(feof(f)))
        {
            frecuencia = new_frecuencia();
            if(frecuencia!=NULL)
            {
                if(flag == 0)
                {
                    fscanf(f,"%[^;];%[^\n]\n", auxNota, auxFrecuencia);
                    //printf("%s", auxNota);
                    flag = 1;
                }
                else
                {
                    fflush(stdin);
                    fscanf(f,"%[^;];%[^\n]\n", auxNota, auxFrecuencia);
                    strcpy(frecuencia->nota, auxNota);
                    frecuencia->frecuencia = atoi(auxFrecuencia);
                    al_add(this, frecuencia);
                    printf("\n%s", frecuencia->nota);
                }

            }
        }
    }
    fclose(f);
    free(frecuencia);
    return retorno;
}


void crearEstructuraNota(ArrayList*lista_melodia,ArrayList*lista_frecuencia,ArrayList* lista_nota)
{
    int i, j;
    Enota *nota;
    Emelodia *melodia;
    Efrecuencia *frecuencia;

    for(i=0;i<lista_melodia->size;i++)
    {
        melodia = al_get(lista_melodia, i);

        for(j=i+1;j<lista_frecuencia->size;j++)
        {
            frecuencia = al_get(lista_frecuencia,j);

            if(melodia[i].nota == frecuencia[j].nota)
            {
                nota = new_nota();
                melodia = new_melodia();
                frecuencia = new_frecuencia();

                nota->duration = melodia[i].duracion;
                nota->duration = melodia[i]->duracion;
                nota->nombre = melodia[i]->nota;
                nota->volume = melodia[i]->volumen;
                nota->freq = frecuencia[j]->frecuencia;

                al_add(lista_nota,nota);
            }
        }
    }
}

