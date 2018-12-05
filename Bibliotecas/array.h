#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED
#define false 0
#define true 1
#define DATO_INVALIDO -1

int array_retornarTotal(int listado[],int tamanio);
int array_retornarPromedio(int listado[],int tamanio);
int array_cargarListado(int listado[],int tamanio);
int array_mostrarListado(int listado[],int tamanio);
int array_notaMinima(int listado[], int tamanio);
int array_notaMaxima(int listado[], int tamanio);
int array_retornarCantidadEntreNotas(int listado[],int tamanio, int limInferior,int limSuperior);
int array_retornarCantidadPares(int listado[], int tamanio);
void array_mostrarInformacionDelArray(int listado[],int tamanio);
int array_mostrar(int* pArray, int limite);
int array_calcularMaximo(int* pArray, int limite, int* pMaximo);
int array_ingresarELmismoValorAlArray(int* pArray, int limite, int valor);
int array_minimoDesde(  int* pArray, int limite,int desde, int* pMinimo);
int array_ordenarPorBurbujeo(int* pArray, int limite, int orden);
void array_swap(int* elementoA,int* elementoB);
int array_ordenarPorInsercion(int* pArray, int limite, int orden);
int utn_getFLoatPorString(  float  * pResultado,    //dejar el resultado
                    char mensaje[],       //mensaje para ingresar
                    char mensajeError[],  //mensaje de error
                    float minimo,           //limite minimo
                    float maximo,           //limite maximo
                    int reintentos );

int utn_getNumeroPorString(  int  * pResultado,    //dejar el resultado
                    char mensaje[],       //mensaje para ingresar
                    char mensajeError[],  //mensaje de error
                    int minimo,           //limite minimo
                    int maximo,           //limite maximo
                    int reintentos );      //cantidad de intentos

int utn_getNumero( int  * pResultado,    //dejar el resultado en la dirección de memoria de presultado porque es un puntero.
               char mensaje[],       //mensaje para ingresar entre corchetes porque es un array de caracteres.
               char mensajeError[],  //mensaje de error. Lo mismo que arriba.
               int minimo,           //limite minimo.
               int maximo,           //limite maximo.
               int reintentos );      //cantidad de intentos. Todo es el prototipo

int utn_getCaracter(  char  * pResultado,    //dejar el resultado en la dirección de memoria de presultado porque es un puntero.
                    char mensaje[],       //mensaje para ingresar entre corchetes porque es un array de caracteres.
                    char mensajeError[],  //mensaje de error. Lo mismo que arriba.
                    char minimo,           //limite minimo.
                    char maximo,           //limite maximo.
                    int reintentos );      //cantidad de intentos. Todo es el prototipo
#endif // ARRAY_H_INCLUDED
