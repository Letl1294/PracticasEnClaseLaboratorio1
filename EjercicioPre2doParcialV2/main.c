#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Empleado.h"
#include "LinkedList.h"
#include "Parser.h"

/**
    Realizar un programa que lee de un archivo los datos de empleados y los guarda en un arraylist de entidades
    empleado.
    Luego, debera calcular el campo "sueldo" de cada uno de los empleados leidos, segun la horas que trabajaron, con el
    siguiente criterio:
    Los valores de horas varian entre 80 y 240.
    - Las primeras 120 horas la hora vale $180
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350

    Para hacer este calculo, se debera desarrollar la funcion "map" en al biblioteca ArrayList, La cual recibe la lista y una funcion.
    La funcion map ejecutara la funcion recibida como parametro por cada item de la lista, y le pasaran en cada llamada, uno de los items.
    De esta manera la funcion pasada como parametro podra realizar un calculo con el item recibido, en este caso, calcular el sueldo.

    Una vez cargados los campos sueldo en las entidades, se debera generar un archivo de salida "sueldos.csv" el cual sera igual que el
    original pero con una columna mas al final, en donde se indicara el sueldo calculado.
*/

int generarArchivoSueldos(char* pFile,LinkedList* listaEmpleados);

int main()
{
    // Definir lista de empleados
    LinkedList* listaEmpleados = ll_newLinkedList();
    // Crear lista empledos
    //...
    // Leer empleados de archivo data.csv
    if(parser_parseEmpleados("data.csv",listaEmpleados)== 0)
    {
        // Calcular sueldos

        printf("Calculando sueldos de empleados\n");
        ll_map(listaEmpleados,Employee_CalcularSueldo);
        ll_map(listaEmpleados,Empleado_mostrar);
        printf("\nSize de la lista: %d",ll_len(listaEmpleados));
    }
//    //Generar archivo de salida
    if(generarArchivoSueldos("sueldos.csv",listaEmpleados)==0)
    {
        printf("Archivo generado correctamente\n");
//        ll_map(listaEmpleados,Empleado_mostrar);
    }
        else
        {
            printf("Error generando archivo\n");
        }
//    else
//    {
//        printf("Error leyando empleados\n");
//    }
    return 0;
}

int generarArchivoSueldos(char* pFile,LinkedList* listaEmpleados)
{
    int retorno = -1;
    Employee* pEmployee;
    int len;
    int indice;
    int bufferId;
    char bufferName[LEN];
    int bufferHorasTrabajadas;
    int bufferSueldo;
    FILE* file = fopen(pFile,"w");

    if(pFile!= NULL && listaEmpleados != NULL)
    {
        len = ll_len(listaEmpleados);
        fprintf(file,"id,nombre,horasTrabajadas,sueldo\n");
        for(indice=0;indice<len;indice++)//Recorro todo el array hasta el LEN
        {
            pEmployee = ll_get(listaEmpleados,indice);
            if(pEmployee!=NULL)//Obtengo el elemento del array en posicion index
            {
                Employee_getNombre(pEmployee,bufferName);
                Employee_getHorasTrabajadas(pEmployee,&bufferHorasTrabajadas);
                Employee_getSueldo(pEmployee,&bufferSueldo);
                Employee_getId(pEmployee,&bufferId);
                fprintf(file,"%d,%s,%d,%d\n",bufferId,bufferName,bufferHorasTrabajadas,bufferSueldo);
                retorno = 0;
            }
        }
    }
    return retorno;
}

