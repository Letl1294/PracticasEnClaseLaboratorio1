#include <stdio.h>
#include <stdlib.h>

int* newArray(int tamanio);
int initArray(int* arrayInt, int limite, int valor);
int showArray(int* arrayInt, int limite);
int deleteArray(int* arrayInt);
int* editSize(int* arrayInt, int limite);

int main()
{
    int* arrayInt;
    arrayInt = newArray(10);
    initArray(arrayInt,10,23);
    showArray(arrayInt,10);
    arrayInt = editSize(arrayInt,20);
    initArray(arrayInt,10,24);
    showArray(arrayInt,20);
    deleteArray(arrayInt);

return 0;
}

    int* newArray(int tamanio)
    {
        int* retorno = NULL;
        int* auxInt;
        if(tamanio>0)
        {
            auxInt = (int*) malloc(sizeof(int)*tamanio);
            if(auxInt != NULL)
            {
                retorno = auxInt;
            }
        }
        return retorno;
    }

    int initArray(int* arrayInt, int limite, int valor)
    {
        int retorno = -1;
        int i;
        if(arrayInt != NULL && limite >0)
        {
            for(i=0;i<limite;i++)
            {
                *(arrayInt+i)=valor;
            }
        }
        return retorno;
    }

    int showArray(int* arrayInt, int limite)
    {
        int retorno = -1;
        int i;
        if(arrayInt != NULL && limite >0)
        {
            for(i=0;i<limite;i++)
            {
              printf("Direccion de memoria: %p - Indice: [%d] - Valor: %d\n",(arrayInt+i),i,*(arrayInt+1));
            }
        }
        return retorno;
    }

    int deleteArray(int* arrayInt)
    {
        int retorno = -1;
        if(arrayInt != NULL)
        {
            free(arrayInt);
            retorno = 0;
        }
        return retorno;
    }

    int* editSize(int* arrayInt, int limite)
    {
        int* retorno = NULL;
        int* auxInt;
        if(arrayInt != NULL && limite>0)
        {
            auxInt = (int*) realloc(arrayInt,sizeof(int)*limite);
            if(auxInt != NULL)
            {
                retorno = auxInt;
            }
        }
        return retorno;
    }
