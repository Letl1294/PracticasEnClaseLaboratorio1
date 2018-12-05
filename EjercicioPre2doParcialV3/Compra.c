#include "Compra.h"
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"


static int isValidFloat(char* pBuffer,int limite)
{
    int retorno = 0;
    int i;
    int contadorPuntos=0;
    if(pBuffer != NULL && limite > 0 && strlen(pBuffer)>0)
    {
        retorno = 1;
        for(i=0;i < limite && pBuffer[i] != '\0';i++)
        {
            if(pBuffer[i] < '0' || pBuffer[i] > '9')
            {
                if((pBuffer[i]!='.') || (pBuffer[0]=='.') || (pBuffer[strlen(pBuffer)-1]=='.'))
                {
                    retorno = 0;
                    break;
                }
                if(pBuffer[i]=='.')
                {
                    contadorPuntos++;
                }
                if(contadorPuntos>1)
                {
                    retorno = 0;
                }
            }
         }
    }
    return retorno;
}

/** \brief Valida el nombre.
 *
 * \param Con un if validamos que solo haya letras. Con el For pasamos por los diferentes elementos del array.
 * \return return 1 si esta bien.
 *
 */

static int isValidNombre(char* pBuffer,int limite)
{
    int retorno = 0;
    int i;
    if(pBuffer!=NULL && limite > 0 && strlen(pBuffer)>0)
    {
        retorno = 1;
        for(i=0;i < limite && pBuffer[i] != '\0';i++)
        {
            if(tolower(pBuffer[i]) < 'a' || tolower(pBuffer[i]) > 'z')
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Valida el int.
 *
 * \param Con un if validamos que solo haya numeros. Con el For pasamos por los diferentes elementos del array.
 * \return return 1 si esta bien.
 *
 */

static int isValidInt(char* pBuffer,int limite)
{
    int retorno = 0;
    int i;
    if(pBuffer != NULL && limite > 0 && strlen(pBuffer)>0)
    {
        retorno = 1;
        for(i=0;i < limite && pBuffer[i] != '\0';i++)
        {
            if(pBuffer[i] < '0' || pBuffer[i] > '9')
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Reservo memoria para un nuevo empleado
 *
 * \param Declaro un puntero de empleado con la palabra reservada this.
 * \param a this le asigno la funcion malloc que nos dara una posicion de memoria para empleado.
 * \return this
 *
 */

Compra* compra_new()
{
    Compra* this;
    this = malloc(sizeof(Compra));
    return this;
}

/** \brief libera memoria
 *
 * \param utilizo un if para validar que this no este vacio.
 * \param si no esta vacio se libera la memoria.
 * \return 0
 *
 */

int Compra_delete(Compra* this)
{
    int retorno = 1;
    if(this != NULL)
    {
         free(this);
         retorno = 0;
    }
    return retorno;
}

/** \brief Cargo un empleado con sus parametros
 *
 * \param Les pasamos a la funcion string para el id, nombre, horastrabajas y sueldo.
 * \param Declaro un puntero de empleado con la palabra reservada this.
 * \param a this le asigno la funcion employee_new que no dara una posicion de memoria.
 * \param con un if valido que las funciones esten bien. En caso de no estarlo se libera la posicion de memoria.
 * \return this(el empleado con parametros). O NULL si esta mal.
 *
 */

Compra* compra_newConParametros(char* nombreCliente,char* idProducto, char* precioUnitario, char* unidades, char* iva)
{
    Compra* this;
    this = compra_new();
    printf("1");
    if((isValidNombre(nombreCliente,LEN)) &&
        isValidInt(idProducto,LEN)&&
        isValidFloat(precioUnitario,LEN)&&
        isValidInt(unidades,LEN) &&
        isValidFloat(iva,LEN))
    {
        printf("2");
        Compra_setId(this,atoi(idProducto));
        Compra_setNombre(this,nombreCliente);
        Compra_setPrecio(this,atof(precioUnitario));
        Compra_setUnidades(this,atoi(unidades));
        Compra_setIva(this,atof(iva));
        return this;
    }
    Compra_delete(this);
    return NULL;
}

/** \brief Genera un ID
 *
 * \param Declaro un variable estatica del tipo int llamado proximoId.
 * \param Con if y un else if valido que no sea NULL y el valor de id.
 * \return 0 si esta bien.
 *
 */

int Compra_setId(Compra* this,int id)
{
    int retorno=-1;
    if(this!=NULL && id!=0)
    {
        this->idProducto = id;
        retorno=0;
    }
    return retorno;
}

/** \brief Nos entrega el ID
 *
 * \param valida que el puntero de empleado que le pasamos no sea NULL.
 * \param y la direccion de memoria de id le asigna el valor de el id del empleado.
 * \return el id.
 *
 */

int Compra_getId(Compra* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id = this->idProducto;
        retorno=0;
    }
    return retorno;
}

/** \brief Le setea un nombre al empleado
 *
 * \param le pasamos un puntero de empleado y un nombre.
 * \param con un if validamos que no sea NULL ni el puntero a empleado ni el nombre.
 * \param le pasamos con la funcion strcpy el nombre al puntero empleado.
 * \return 0 si esta bien.
 *
 */

int Compra_setNombre(Compra* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombreCliente,nombre);
        retorno=0;
    }
    return retorno;
}

/** \brief Obtenemos el nombre
 *
 * \param con un if validamos que empleado y nombre no sean NULL
 * \param con la funcion strcpy le pasamos el nombre de empleado a el string nombre.
 * \return 0 si esta bien.
 *
 */

int Compra_getNombre(Compra* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombreCliente);
        retorno = 0;
    }
    return retorno;
}

/** \brief Le setea las horas trabajadas al empleado.
 *
 * \param le pasamos un puntero de empleado y un int.
 * \param con un if validamos que no sea NULL el puntero a empleado.
 * \param le pasamos las horas al puntero empleado.
 * \return 0 si esta bien.
 *
 */

int Compra_setPrecio(Compra* this,float precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->precioUnitario=precioUnitario;
        retorno=0;
    }
    return retorno;
}

/** \brief obtenemos las horas del empleado
 *
 * \param le pasamos un puntero de empleado y un int.
 * \param con un if validamos que no sea NULL empleado.
 * \param le pasamos al puntero de int las horas trabajas del empleado.
 * \return 0 si esta bien.
 *
 */

int Compra_getPrecioUnitario(Compra* this,float* precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {

        *precioUnitario=this->precioUnitario;
        retorno=0;
    }
    return retorno;
}

/** \brief Seteamos el sueldo del empleado
 *
 * \param le pasamos un puntero de empleado y un float.
 * \param con un if validamos que no sea NULL empleado.
 * \param le pasamos al puntero de empleado el sueldo.
 * \return 0 si esta bien.
 *
 */

int Compra_setUnidades(Compra* this,int unidades)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->unidades=unidades;
        retorno=0;
    }
    return retorno;
}

/** \brief Obtenemos el sueldo del empleado
 *
 * \param le pasamos un puntero de empleado y un int.
 * \param con un if validamos que no sea NULL empleado.
 * \param le pasamos al int el sueldo de empleado.
 * \return 0 si esta bien.
 *
 */

int Compra_getUnidades(Compra* this,int* unidades)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *unidades = this->unidades;
        retorno=0;
    }
    return retorno;
}

int Compra_setIva(Compra* this,float iva)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->iva=iva;
        retorno=0;
    }
    return retorno;
}

int Compra_getIva(Compra* this,float* iva)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *iva = this->iva;
        retorno=0;
    }
    return retorno;
}

int Compra_mostrar(void* pCompra)
{
    int retorno = -1;
    int auxId;
    char auxNombre[128];
    int auxUnidad;
    float auxIva;
    float auxPrecio;

    if(pCompra != NULL)
    {
        Compra_getId(pCompra,&auxId);
        if(auxId != -1)
        {
            Compra_getNombre(pCompra,auxNombre);
            Compra_getUnidades(pCompra,&auxUnidad);
            Compra_getPrecioUnitario(pCompra,&auxPrecio);
            Compra_getId(pCompra,&auxId);
            Compra_getIva(pCompra,&auxIva);

            printf("\nID: %d",auxId);
            printf(" Nombre: %s",auxNombre);
            printf(" Precio: %f",auxPrecio);
            printf(" Unidades: %d",auxUnidad);
            printf("Iva: %f",auxIva);
            retorno = 0;
        }
    }
    return retorno;
}

int compra_getById(LinkedList* pArrayListEmployee,int idIngresado)
{
    int retorno = -1;
    Compra* auxiliarCompra;
    int indice = 0;
    int auxiliarID = 0;
    idIngresado = 11;

    if(pArrayListEmployee != NULL)
    {
        for(indice=0; indice<ll_len(pArrayListEmployee); indice++)
        {
            auxiliarCompra = ll_get(pArrayListEmployee,indice);///En cada iteracion me guardo el empleado completo
            Compra_getId(auxiliarCompra,&auxiliarID);///Saco el ID del empleado
            if(auxiliarID == idIngresado) /// Comparo ID's
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}



int com_calcularMonto(void* pCompra)
{
    int retorno = -1;
    float total = 0;
    float precio= 0;
    float iva = 0;
    int unidades = 0;
    //char bufferTotal[1024];

    if(pCompra != NULL && !Compra_getIva(pCompra,&iva) && !Compra_getPrecioUnitario(pCompra,&precio) && !Compra_getUnidades(pCompra,&unidades))
    {
        total=iva*(precio*unidades)/100;
//        sprintf(bufferTotal,"%f",total);
        Compra_setTotal(pCompra,total);
        retorno = 0;
    }
return retorno;
}

int criterioId(void* this)
{
    int retorno = -1;
    char auxId[LEN];
    int elementId;
    static int flag = 0;

    if(this != NULL)
    {
        if(flag == 0)
        {
            utn_getSoloInt(auxId,LEN,"Ingrese el ID","ID invalido.",2);
            flag = 1;
        }
        if(!Compra_getId(this,&elementId) && elementId == atoi(auxId))
        {
            retorno = 0;
        }
    }
    return retorno;
}

int Compra_setTotal(Compra* this,float total)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->montoTotal=total;
        retorno=0;
    }
    return retorno;
}

int Compra_getTotal(Compra* this,float* total)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *total = this->montoTotal;
        retorno=0;
    }
    return retorno;
}
