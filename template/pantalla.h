#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
typedef struct
{
    char nombre[50];
    char direccion[50];
    float precio;
    int tipo;
    int id;
    //------------
    int idPantalla;
    int isEmpty;
}Pantalla;
#endif // PANTALLA_H_INCLUDED


int pantalla_init(Pantalla* array,int limite);
int pantalla_mostrar(Pantalla* array,int limite);
int pantalla_mostrarDebug(Pantalla* array,int limite);
int pantalla_alta(Pantalla* array,int limite);
int pantalla_baja(Pantalla* array,int limite, int id);
int pantalla_modificacion(Pantalla* array,int limite, int id);
int pantalla_ordenar(Pantalla* array,int limite, int orden);
int pantalla_buscarPorId(Pantalla* array,int limite, int id);
int pantalla_altaForzada(Pantalla* array,int limite,char* nombre,char* direccion, float precio, int tipo);
void pantalla_Ordenar2(Pantalla* array,int limite);
int pantalla_menor(Pantalla* array,int limite);
int pantalla_mayor(Pantalla* array,int limite);
int pantalla_SuperanPromedio(Pantalla* array, int limite);
double pantalla_Promedio(Pantalla* array, int limite);
int pantalla_NoSuperanPromedio(Pantalla* array, int limite);
Pantalla* pantalla_getByID(Pantalla array[],int limite,int id);
//int buscarLugarLibre(Pantalla* array,int limite);
//int proximoId();
//int pantalla_buscarPorId(Pantalla* array,int limite, int id);

