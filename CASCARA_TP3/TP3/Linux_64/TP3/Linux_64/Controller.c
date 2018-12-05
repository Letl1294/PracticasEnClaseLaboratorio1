#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param le pasamos el patch del archivo, y un puntero de LinkedList.
 * \param Declaramos un puntero a FILE llamado pArchivo y le asignamos la funcion fopen(que abre el archivo en modo escritura).
 * \param validamos que no sea NULL y llamamos a la funcion parser para cargar los datos a empleado. Despues con la funcion fclose lo cierra.
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno = -1;
    pArchivo = fopen(path,"r");
    if(pArchivo!=NULL)
    {
        parser_EmployeeFromText(pArchivo,pArrayListEmployee);
        retorno = 0;
    }
    fclose(pArchivo);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param le pasamos un puntero de LinkedList.
 * \param
 * \return int
 *
 */

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param le pasamos un puntero de LinkedList.
 * \param
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    Employee* empleado;

    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        empleado = ll_get(pArrayListEmployee,i);
        if(empleado != NULL)
        {
            controller_show(empleado);
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

void controller_show(void* empleado)
{
    int id;
    char nombre[1024];
    int horasTrabajadas;
    float sueldo;
    Employee_getId(empleado,&id);
    Employee_getNombre(empleado,nombre);
    Employee_getHorasTrabajadas(empleado,&horasTrabajadas);
    Employee_getSueldo(empleado,&sueldo);
    printf("ID: %d - Nombre: %s - horas Trabajadas: %d - Sueldo: %.2f\n\n",id,nombre,horasTrabajadas,sueldo);
}
