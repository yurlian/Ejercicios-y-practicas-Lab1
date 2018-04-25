typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;


typedef struct
{
    int legajo;
    char nombre[50];
    eFecha fechaIngreso;
} sEmpleado;


void cargarArray(sEmpleado* arrayEmpleados,int length);
void mostrarArray(sEmpleado* arrayEmpleados,int length);
void swap(sEmpleado* auxEmpleadoA,sEmpleado* auxEmpleadoB);
void bubleSort(sEmpleado* arrayEmpleados,int length);
void quickSort(sEmpleado* arrayEmpleados,int length);
void insertionSort(sEmpleado* arrayEmpleados,int length);
