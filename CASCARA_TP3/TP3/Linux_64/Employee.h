#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
}Employee;

Employee* Employee_new();
int Employee_delete();
Employee* employee_newConParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

int Employee_setId(Employee* this,int id);
int Employee_getId(Employee* this,int* id);

int Employee_setNombre(Employee* this,char* nombre);
int Employee_getNombre(Employee* this,char* nombre);

int Employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int Employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int Employee_setSueldo(Employee* this,float sueldo);
int Employee_getSueldo(Employee* this,float* sueldo);

int employee_criterioSortNombre(Employee* thisA,Employee* thisB);
Employee* employee_alta(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
#endif // EMPLOYEE_H_IN
