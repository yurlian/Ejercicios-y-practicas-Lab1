/** \brief Indica el criterio de orden
 *
 * \param elemento1 void*
 * \param elemento2 void*
 * \return 1 si es mayor, -1 si no
 *
 */
int tipoOrden(void* elemento1, void* elemento2)
{
    int retorno = -1;
    eTarea* tarea1 = (eTarea*)elemento1;
    eTarea* tarea2 = (eTarea*)elemento2;
    if(tarea1->tiempo > tarea2->tiempo)
        retorno = 1;
    return retorno;
}

/** \brief Valida que se ingresen letras
 *
 * \param Mensaje en pantalla que pide el dato
 * \param variable donde se guarda
 * \return void
 *
 */
void validarCadena(char mensaje[],char input[])
{
    int flag;
    char str[10];
    do
    {
        flag=0;
        printf("%s",mensaje);
        fflush(stdin);
        gets(str);

        for(int i=0; i<strlen(str); i++)
            if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
                flag=1;

        if(flag==0)
            strcpy(input,str);
        else
            printf("\nEl nombre ingresado no es valido\n\n");

    }while (flag!=0);
}



/** \brief Valida que se ingresen numeros
 *
 * \param Mensaje en pantalla que pide el dato
 * \return -1 si hubo error, el numero validado si salió bien.
 *
 */
int validarNumero(char mensaje[])
{
    int numero,i,k,flag=0, auxReturn = -1;
    char seguir[10];
    do
    {
        flag=0;
        printf("%s",mensaje);
        fflush(stdin);
        gets(seguir);
        k=strlen(seguir);

        for(i=0;i<k;i++)
        {
            if(isdigit(seguir[i]))
                flag++;
        }
        if(flag==k)
        {
            //if(strlen(seguir)>8)
                //printf("No se pueden ingresar mas de 8 digitos\n\n");

            numero=atoi(seguir);
            auxReturn = numero;
        }
        else
            printf("\nEl dato ingresado no es valido\n\n");

    }while (flag!=k);

    return auxReturn;
}




/** \brief Muestra un arraylist en pantalla
 *
 * \param ArrayList*
 * \return void
 *
 */
void mostrarLista(ArrayList* lista)
{
    numeroNatural* auxnum;
    auxnum = (numeroNatural*) malloc (sizeof(numeroNatural));

    printf("NUMERO\t\tNOMBRE\t\tPar\t\tIMPAR\t\tPRIMO\n");

    for(int i=0; i<lista->len(lista); i++)
    {
        if(auxnum != NULL)
        {
            auxnum = (numeroNatural*) lista->get(lista, i);
            printf("%d\t%25s%15d%15d%15d\n", auxnum->num, auxnum->nombre, auxnum->par, auxnum->impar, auxnum->primo);
        }
    }

    printf("\nTodos los numeros mostrados con exito!\n\n");
}



/** \brief Completa los campos de a cuerdo a si el numero leido es par, impar o primo.
 *
 * \param lista ArrayList*
 * \return void
 *
 */
void completarNumero(ArrayList* lista)
{
    int k;
    numeroNatural* numero;

    for(int i=0; i<lista->len(lista)-1; i++)
        {

            Numero=lista->get(lista,i);
            if((Numero->numero%2)==0)
                   numero->par=1;
            else
                   numero->impar=1;

            // SI ES PRIMO
            for(int j=numero->numero; j>0 ;j--)
            {
                if((numero->numero%j)==0)
                    k++;
            }
            if(k==2)
                numero->primo = 1;

            k = 0;
        }
}
