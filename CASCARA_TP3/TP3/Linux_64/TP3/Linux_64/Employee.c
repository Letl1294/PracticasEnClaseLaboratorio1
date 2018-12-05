#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** \brief Reservo memoria para un nuevo empleado
 *
 * \param Declaro un puntero de empleado con la palabra reservada this.
 * \param a this le asigno la funcion malloc que nos dara una posicion de memoria para empleado.
 * \return this
 *
 */

Employee* Employee_new()
{
    Employee* this;
    this = malloc(sizeof(Employee));
    return this;
}

/** \brief libera memoria
 *
 * \param utilizo un if para validar que this no este vacio.
 * \param si no esta vacio se libera la memoria.
 * \return 0
 *
 */

int Employee_delete(Employee* this)
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

Employee* employee_newConParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)//le ponemos Str porque son todos string.
{
    Employee* this;
    this = Employee_new();

    if(
    !Employee_setId(this,atoi(idStr))&&
    !Employee_setNombre(this,nombreStr)&&
    !Employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr))&&
    !Employee_setSueldo(this,atof(sueldoStr)))
    {
       return this;
    }
    Employee_delete(this);
    return NULL;
}

/** \brief Genera un ID
 *
 * \param Declaro un variable estatica del tipo int llamado proximoId.
 * \param Con if y un else if valido que no sea NULL y el valor de id.
 * \return 0 si esta bien.
 *
 */

int Employee_setId(Employee* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id = proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
        retorno=0;
    }
    else if(id==NULL)
    {
        this->id=proximoId;
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

int Employee_getId(Employee* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id = this->id;
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

int Employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
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

int Employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
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

int Employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
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

int Employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
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

int Employee_setSueldo(Employee* this,float sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

/** \brief Obtenemos el sueldo del empleado
 *
 * \param le pasamos un puntero de empleado y un float.
 * \param con un if validamos que no sea NULL empleado.
 * \param le pasamos al float el sueldo de empleado.
 * \return 0 si esta bien.
 *
 */

int Employee_getSueldo(Employee* this,float* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo = this->sueldo;
        retorno=0;
    }
    return retorno;
}

/** \brief Ordenamos nombres.
 *
 * \param le pasamos dos punteros de empleado.
 * \param con un if y strcmp comprobamos que los nombres sean igual o el primero mas chico que el segundo.
 * \param dependiendo el caso le paso a retorno un valor.
 * \return retorno.
 *
 */

int employee_criterioSortNombre(Employee* thisA,Employee* thisB)
{
    char nombreA[50];
    char nombreB[50];
    int retorno = 0;
    Employee_getNombre(thisA,nombreA);
    Employee_getNombre(thisB,nombreB);

    if(strcmp(nombreA,nombreB)>0)
    {
        retorno = 1;
    }
    else if(strcmp(nombreA,nombreB)<0)
    {
        retorno =-1;
    }
    return retorno;
}

Employee* employee_alta(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)//le ponemos Str porque son todos string.
{
    Employee* this;
    this = Employee_new();

    if(///this!=NULL
    ///this=new cpn paramentros(nombre, id, sueldo, horas)
    !Employee_setId(this,atoi(idStr))&&
    !Employee_setNombre(this,nombreStr)&&
    !Employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr))&&
    !Employee_setSueldo(this,atof(sueldoStr)))
    ///ll_add(linkedlisyt, this)

    {
       return this;
    }
    Employee_delete(this);
    return NULL;
}
