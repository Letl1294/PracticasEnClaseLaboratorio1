#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"

#define DEFINE_DEL_ARCHIVO  "hola"

//Funciones privadas
static int proximoId(void);
static int buscarLugarLibre(Pantalla* array,int limite);
//__________________



/** \brief
 * \param array Pantalla*
 * \param limite int
 * \return int
 *
 */

int pantalla_init(Pantalla* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}

int pantalla_mostrarDebug(Pantalla* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("[DEBUG] - %d - %s - %s - %f - %d - %d\n",array[i].idPantalla, array[i].nombre,array[i].direccion,array[i].precio,array[i].tipo, array[i].isEmpty);
        }
    }
    return retorno;
}

int pantalla_mostrar(Pantalla* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                printf("[RELEASE] - %d - %s - %d\n",array[i].idPantalla, array[i].nombre, array[i].isEmpty);
        }
    }
    return retorno;
}

int pantalla_alta(Pantalla* array,int limite)
{
    int retorno = -1;
    int i;
    char nombre[50];
    char direccion[50];
    float precio;
    int tipo;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",nombre,40,2))
            {
                if(!getValidString("\nDireccion? ","\nEso no es un direccion","El maximo es 40",direccion,40,2))
                {
                    if(!getValidFloat("\nPrecio? ","\nEso no es un precio",&precio,0,9999999,2))
                    {
                        if(!getValidInt("\nTipo? ","\nEso no es un precio",&tipo,0,1,2))
                        {
                            retorno = 0;
                            strcpy(array[i].nombre,nombre);
                            strcpy(array[i].direccion,direccion);
                            array[i].precio = precio;
                            array[i].tipo = tipo;
                            //------------------------------
                            //------------------------------
                            array[i].idPantalla = proximoId();
                            array[i].isEmpty = 0;
                        }
                    }
                }
            }
            else
            {
                retorno = -3;
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}


int pantalla_baja(Pantalla* array,int limite, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    indiceAEliminar = pantalla_buscarPorId(array,limite,id);
    if(indiceAEliminar>=0)
    {
        array[indiceAEliminar].isEmpty=1;
        retorno=0;
    }
    return retorno;
}

int pantalla_modificacion(Pantalla* array,int limite, int id)
{
    int retorno = -1;
    int indiceAModificar;
    char buffer[50];

    indiceAModificar = pantalla_buscarPorId(array,limite,id);
    if(indiceAModificar>=0)
    {
        if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",buffer,40,2))
        {
            retorno = 0;
            strcpy(array[indiceAModificar].nombre,buffer);
            //------------------------------
            //TODO
        }
        else
        {
            retorno = -3;
        }
    }
    return retorno;
}

int pantalla_ordenar(Pantalla* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Pantalla auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && !orden)) //******
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

static int buscarLugarLibre(Pantalla* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



static int proximoId(void)
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}


int pantalla_buscarPorId(Pantalla* array,int limite, int id)
//static int buscarPorId(Pantalla* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idPantalla==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



int pantalla_altaForzada(Pantalla* array,int limite,char* nombre,char* direccion, float precio, int tipo)
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(array[i].nombre,nombre);
            strcpy(array[i].direccion,direccion);
            array[i].precio = precio;
            array[i].tipo = tipo;
            //------------------------------
            //------------------------------
            array[i].idPantalla = proximoId();
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}

void pantalla_Ordenar2(Pantalla* array, int limite)
{
    int i,s = 1;
    Pantalla auxiliar;

    while(s)
    {
        s = 0;
        for (i = 1; i < limite; i++)
        {
            if ((array[i].precio < array[i - 1].precio) ||
               (array[i].precio == array[i-1].precio && strcmp(array[i].nombre,array[i].nombre)>0))
            {
                auxiliar = array[i];
                array[i] = array[i - 1];
                array[i - 1] = auxiliar;
                s = 1;
            }
        }
    }
}

int pantalla_menor(Pantalla* array,int limite)
{

    int i,contador=0;

    for(i=0;i<limite;i++)
    {
        if((array[i].isEmpty==0) && (array[i].precio < 10))
        {
            printf("[DEBUG] - %d - %s - %s - %f - %d - %d\n",array[i].idPantalla, array[i].nombre,array[i].direccion,array[i].precio,array[i].tipo, array[i].isEmpty);
        }
    }
    return contador;
}

int pantalla_mayor(Pantalla* array,int limite)
{

    int i,contador=0;

    for(i=0;i<limite;i++)
    {
        if((array[i].isEmpty=0) && (array[i].precio > 10))
        {
            contador++;
        }
    }
    return contador;
}

double pantalla_Promedio(Pantalla* array, int limite)
{
    int i;
    double acumulador = 0;
    int contador = 0;
    double promedio;

    for(i=0;i<limite;i++)
    {
        if(array[i].isEmpty==0)
        {
            acumulador = +array[i].precio;
            contador++;
        }
    }
    promedio = acumulador/contador;
    return promedio;
}

int pantalla_SuperanPromedio(Pantalla* array, int limite)
{
    double promedio;
    int i;

    promedio = pantalla_Promedio(array,limite);

    for(i=0;i<limite;i++)
    {
        if(array[i].isEmpty==0 && array[i].precio>promedio)
        {
            printf("[RELEASE] - %d - %s - %d\n",array[i].idPantalla, array[i].nombre, array[i].isEmpty);
        }
    }
    return 0;
}

int pantalla_NoSuperanPromedio(Pantalla* array, int limite)
{
    double promedio;
    int i;

    promedio = pantalla_Promedio(array,limite);

    for(i=0;i<limite;i++)
    {
        if(array[i].isEmpty==0 && array[i].precio<promedio)
        {
            printf("[RELEASE] - %d - %s - %d\n",array[i].idPantalla, array[i].nombre, array[i].isEmpty);
        }
    }
    return 0;
}

Pantalla* pantalla_getByID(Pantalla array[],int limite,int id)
{
    Pantalla* retorno = NULL;
    int i;

    if(array != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
           if(!array[i].isEmpty && array[i].id == id)
            {
                retorno = array+i;
                break;
            }
        }
    }
    return retorno;
}
