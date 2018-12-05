#ifndef COMPRA_H_INCLUDED
#define COMPRA_H_INCLUDED
#include "LinkedList.h"
#define LEN 1024

struct S_Compra
{
  char nombreCliente[128];
  int idProducto;
  float precioUnitario;
  int unidades;
  float iva;
  float montoTotal;
};
typedef struct S_Compra Compra;

int Compra_setIva(Compra* this,float iva);
int Compra_getIva(Compra* this,float* iva);
int Compra_getUnidades(Compra* this,int* unidades);
int Compra_setUnidades(Compra* this,int unidades);
int Compra_getPrecioUnitario(Compra* this,float* precioUnitario);
int Compra_setPrecio(Compra* this,float precioUnitario);
int Compra_getNombre(Compra* this,char* nombre);
int Compra_setNombre(Compra* this,char* nombre);
int Compra_getId(Compra* this,int* id);
int Compra_setId(Compra* this,int id);
int Compra_setTotal(Compra* this,float total);
int Compra_getTotal(Compra* this,float* total);
Compra* compra_newConParametros(char* nombreCliente,char* idProducto, char* precioUnitario, char* unidades, char* iva);
int com_calcularMonto(void* p);
int Compra_mostrar(void* pCompra);
int compra_getById(LinkedList* pArrayListEmployee,int idIngresado);
int criterioId(void* this);
#endif // COMPRA_H_INCLUDED
