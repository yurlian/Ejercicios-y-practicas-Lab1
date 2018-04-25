#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Funciones.h"

/** \brief Carga un archivo
 *
 * \param this ArrayList*
 * \return 0 si lo cargó bien, -1 si hubo algún error
 *
 */
int CargarTickets(ArrayList* this)
{
    int returnAux = -1;
    char fecha[11], hora[6], mensaje[65], problema[5], gravedad[5];

    FILE* archivo1;

    if(this != NULL && (archivo1 = fopen("ticket.txt", "r")) != NULL)
    {
        while(!feof(archivo1))
        {
            eTickets* ticket = (eTickets*) malloc(sizeof(eTickets));

            if(ticket != NULL)
            {
                fscanf(archivo1, "%[^;];%[^;];%[^;];%[^;];%[^\n]\n", fecha, hora, problema, gravedad, mensaje);
                strcpy(ticket->mensaje, mensaje);
                strcpy(ticket->fecha, fecha);
                strcpy(ticket->hora, hora);
                ticket->idProblema = atoi(problema);
                ticket->gravedad = atoi(gravedad);

                if(this->add(this, ticket)==0)
                {
                    returnAux = 0;
                }
                else
                {
                    returnAux = -1;
                    break;
                }
            }
            else
            {
                returnAux = -1;
                break;
            }

        }
    }
    fclose(archivo1);

    return returnAux;
}

/** \brief Carga un archivo
 *
 * \param this ArrayList*
 * \return 0 si lo cargó bien, -1 si hubo algún error
 *
 */
int CargarProblemas(ArrayList* this)
{
    int returnAux = -1;
    char id[5], email[65], nombre[33];

    FILE* archivo1;

    if(this != NULL && (archivo1 = fopen("problemas.txt", "r")) != NULL)
    {
        while(!feof(archivo1))
        {
            eProblemas* problems = (eProblemas*) malloc(sizeof(eProblemas));

            if(problems != NULL)
            {
                fscanf(archivo1, "%[^;];%[^;];%[^\n]\n", id, nombre, email);
                strcpy(problems->email, email);
                strcpy(problems->nombre, nombre);
                problems->id = atoi(id);

                if(this->add(this, problems)==0)
                {
                    returnAux = 0;
                }
                else
                {
                    returnAux = -1;
                    break;
                }
            }
            else
            {
                returnAux = -1;
                break;
            }

        }
    }
    fclose(archivo1);

    return returnAux;
}

/** \brief Procesa la informacion
 *
 * \param ArrayList* listaTickets
 * \param ArrayList* listaProblemas
 * \return -1 si sale mal, 0 si sale bien
 *
 */
int procesarInformacion (ArrayList* listaTickets, ArrayList* listaProblemas)
{
    int returnAux = -1;

    FILE* archivoSolucionar;
    FILE* archivoUrgente;

    if((archivoSolucionar = fopen("solucionar.txt", "w")) != NULL && (archivoUrgente = fopen("solucionarUrgente.txt", "w")) != NULL)
    {
        for(int i=0; i<listaTickets->len(listaTickets); i++)
        {
            for(int j=0; j<listaProblemas->len(listaProblemas); j++)
            {
                if(((eTickets*)listaTickets->pElements[i])->idProblema == ((eProblemas*)listaProblemas->pElements[j])->id)
                {
                    if(((eTickets*)listaTickets->pElements[i])->gravedad == 4)
                    {
                        if(((eTickets*)listaTickets->pElements[i])->idProblema != 3)
                        {
                            fprintf(archivoSolucionar, "%s;%s;%s;%s\n\n", ((eTickets*)listaTickets->pElements[i])->fecha, ((eTickets*)listaTickets->pElements[i])->hora, ((eProblemas*)listaProblemas->pElements[j])->nombre, ((eTickets*)listaTickets->pElements[i])->mensaje);
                        }
                    }
                }
                if(((eTickets*)listaTickets->pElements[i])->idProblema == ((eProblemas*)listaProblemas->pElements[j])->id)
                {
                    if(((eTickets*)listaTickets->pElements[i])->gravedad >= 5 && ((eTickets*)listaTickets->pElements[i])->gravedad <= 8)
                        fprintf(archivoUrgente, "%s;%s;%s;%s\n\n", ((eTickets*)listaTickets->pElements[i])->fecha, ((eTickets*)listaTickets->pElements[i])->hora, ((eProblemas*)listaProblemas->pElements[j])->nombre, ((eTickets*)listaTickets->pElements[i])->mensaje);
                }
                if(((eTickets*)listaTickets->pElements[i])->idProblema == ((eProblemas*)listaProblemas->pElements[j])->id)
                {
                    if(((eTickets*)listaTickets->pElements[i])->gravedad > 8)
                        printf("%s;%s;%s;%s;%s\n\n", ((eTickets*)listaTickets->pElements[i])->fecha, ((eTickets*)listaTickets->pElements[i])->hora, ((eProblemas*)listaProblemas->pElements[j])->nombre, ((eTickets*)listaTickets->pElements[i])->mensaje, ((eProblemas*)listaProblemas->pElements[j])->email);
                }
            }
        }
        returnAux = 0;
    }

    fclose(archivoSolucionar);
    fclose(archivoUrgente);

    return returnAux;
}

/** \brief muestra las estadisticas
 *
 * \param listaTickets ArrayList*
 * \param listaProblemas ArrayList*
 * \return int -1 si sale mal, 0 si sale bien
 *
 */
int mostrarEstadisticas(ArrayList* listaTickets, ArrayList* listaProblemas)
{
    int returnAux = -1, idMax, cont3=0, cont4=0, cont5_8=0, cont8=0;

    idMax = mayorProblema(listaTickets);

    for(int i=0; i<listaProblemas->len(listaProblemas); i++)
    {
        if(((eProblemas*)listaProblemas->pElements[i])->id == idMax)
        {
            printf("\nEl problema que mas usuarios reportaron fue el %s\n\n", ((eProblemas*)listaProblemas->pElements[i])->nombre);
            returnAux = 0;
        }
    }

    for(int i=0; i<listaTickets->len(listaTickets); i++)
    {
        if(((eTickets*)listaTickets->pElements[i])->gravedad <= 3)
            cont3++;
        else if(((eTickets*)listaTickets->pElements[i])->gravedad == 4)
            cont4++;
        else if(((eTickets*)listaTickets->pElements[i])->gravedad >= 5 && ((eTickets*)listaTickets->pElements[i])->gravedad <= 8)
            cont5_8++;
        else
            cont8++;
    }
    printf("La cantidad de reportes es de:\n\n");
    printf("Gravedad menor a 3: %d\nGravedad 4: %d\nGravedad entre 5 y 8: %d\nGravedad mayor a 8: %d\n\n", cont3, cont4, cont5_8, cont8);

    return returnAux;
}


/** \brief indica que problema es el que tiene mas tickets
 *
 * \param ArrayList* listaTickets
 * \return -1 si sale mal, id si sale bien
 *
 */
int mayorProblema (ArrayList* listaTickets)
{
    int returnAux = -1, cont = 0, cant, idMax, flag = 0;

    for(int i=0; i<listaTickets->len(listaTickets); i++)
    {
        for(int j=0; j<listaTickets->len(listaTickets); j++)
        {
            if(((eTickets*)listaTickets->pElements[i])->idProblema == ((eTickets*)listaTickets->pElements[j])->idProblema)
                cont++;
        }
        if(flag == 0)
        {
            cant = cont;
            idMax = ((eTickets*)listaTickets->pElements[i])->idProblema;
            flag = 1;
        }
        else
        {
            if(cont > cant)
            {
                cant = cont;
                idMax = ((eTickets*)listaTickets->pElements[i])->idProblema;
            }
        }
    }
    returnAux = idMax;
    return returnAux;
}
