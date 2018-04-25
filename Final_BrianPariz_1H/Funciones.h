typedef struct
{
    char fecha[11];
    char hora[6];
    char mensaje[65];
    int idProblema, gravedad;

}eTickets;

typedef struct
{
    int id;
    char nombre[33];
    char email[65];

}eProblemas;

int CargarTickets(ArrayList*);

int CargarProblemas(ArrayList*);

int mayorProblema (ArrayList*);

int mostrarEstadisticas(ArrayList*, ArrayList*);

int procesarInformacion (ArrayList*, ArrayList*);
