#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Empleado.h"

int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
{
    char bufferNombre[LEN];
//    char buffeSueldo[LEN];
    char bufferHorasTrabajadas[LEN];
    char bufferInt[LEN];
    char bufferText[LEN];
    int retorno = -1;
    int len;
    Employee* pEmpleado;
    FILE* pFile = fopen(fileName,"r");
    if(pFile!=NULL)
    {
        retorno = 0;
        while(!feof(pFile))
        {
            fgets(bufferText,sizeof(bufferText),pFile);
            len = strlen(bufferText);
            if(len > 5) //Minimo 5 caracteres tendra el fgets para que sea correcto.
            {
                strncpy(bufferInt,strtok(bufferText,","),LEN);
                strncpy(bufferNombre,strtok(NULL,","),LEN);
                strncpy(bufferHorasTrabajadas,strtok(NULL,"\n"),LEN);
                pEmpleado = employee_newConParametros(bufferInt,bufferNombre,bufferHorasTrabajadas,"10");
                if(pEmpleado!=NULL && atoi(bufferInt)>=0)
                {
                    ll_add(listaEmpleados,pEmpleado);
                }
            }
        }
    }
    fclose(pFile);
    return retorno;
}
