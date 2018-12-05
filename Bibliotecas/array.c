#include <stdio_ext.h>
#include <stdlib.h>
#include "array.h"

static int getInt(int* pResultado);
static int validacionInt(char* array);
static int ValidacionFloat(char* array);
static int getFloat(float* pResultado);

/**\brief Muestra los resultados de las diferentes de varias funciones array.
 *
 * \param Se declaran variables del tipo int para guardar los resultados de las funciones.
 * \param y se muestran mediante por un printf.
 * \return nada porque es void.
 *
 */

void array_mostrarInformacionDelArray(int listado[],int tamanio)
{
    int mayor;
    int menor;
    int sumaTotal;
    int promedio;
    int cantidadDePares;
    int aprobados;
    int aFinal;
    int desaprobados;

    mayor=array_notaMaxima(listado,tamanio);
    menor=array_notaMinima(listado,tamanio);
    sumaTotal=array_retornarTotal(listado,tamanio);
    promedio=array_retornarPromedio(listado,tamanio);
    cantidadDePares=array_retornarCantidadPares(listado,tamanio);
    aprobados=array_retornarCantidadEntreNotas(listado,tamanio,6,10);
    aFinal=array_retornarCantidadEntreNotas(listado,tamanio,4,5);
    desaprobados=array_retornarCantidadEntreNotas(listado,tamanio,0,3);

    printf("\n\nLa mayor nota es: %d",mayor);
    printf("\n\nLa menor nota es: %d",menor);
    printf("\n\nLa cantidad de pares es: %d",cantidadDePares);
    printf("\n\nLa suma total de las notas es: %d",sumaTotal);
    printf("\n\nEl promedio de las notas es: %d",promedio);
    printf("\n\nLa cantidad de aprobados es: %d",aprobados);
    printf("\n\nLa cantidad de gente a final es: %d",aFinal);
    printf("\n\nLa cantidad de desaprobados es: %d\n",desaprobados);
}

/** \brief Devuelve el total de la suma de los valores de los elementos del array.
 *
 * \param La variable sumaDeNotas se ultiliza como acumulador.
 * \param el for es ultilizado para pasar por todos los elementos del array.
 * \return SumaDeNotas con el total.
 *
 */

int array_retornarTotal(int listado[], int tamanio)
{
    int sumaDeNotas=0;
    int i;

        for(i=0;i<tamanio;i++)
        {
            sumaDeNotas=sumaDeNotas+listado[i];
        }
    return sumaDeNotas;
}

/** \brief Calcula el promedio.
 *
 * \param se declaran las variables int de suma y promedio para almacenar el resultado.
 * \param se llama a la funcion retornar total y el resultado se asigan a la variable suma para ser dividido
 * \param por la cantidad de elementos del array.
 * \return promedio.
 *
 */

int array_retornarPromedio(int listado[],int tamanio)
{
    int suma;
    int promedio;
    suma=array_retornarTotal(listado,tamanio);
    promedio=suma/tamanio;
    return promedio;
}

/** \brief muestra los valores de los elementos del array.
 *
 * \param se utiliza un for para pasar pasar los elementos del array.
 * \param printf para mostrar los resultados.
 * \return 0 si esta bien.
 *
 */

int array_mostrarListado(int listado[], int tamanio)
{
    int i;
    for(i=0;i<tamanio;i++)
    {
       printf("\n\nLa nota n°%d es: %d",i+1,listado[i]);
    }
    return 0;
}

/** \brief funcion utilizada para cargar los valores a los elementos del array.
 *
 * \param utilizamos un for para para pasar por lo diferentes elementos del array.
 * \param printf para decir al usuario que ingrese un valor y scanf para ingresar los valores.
 * \param fpurge para limpiar el buffer y un clear para limpiar la pantalla.
 * \return 0 si esta bien.
 *
 */

int array_cargarListado(int listado[], int tamanio)
{
    int i;
    int numero;
    for(i=0;i<tamanio;i++)
    {
        printf("\nIngrese la nota n°%d: ",i+1);
        scanf("%d",&numero);
        listado[i]=numero;
        __fpurge(stdin);
    }
    system("clear");
    return 0;
}

/** \brief funcion utilizada para mostrar la nota minima.
 *
 * \param utilizamos un for para para pasar por lo diferentes elementos del array.
 * \param con el if nos aseguramos que en la variable menor se asigne el valor del elemento del array mas chico.
 * \return menor.
 *
 */

int array_notaMinima(int listado[], int tamanio)
{
    int menor,i;
    for(i=0;i<tamanio;i++)
    {
        if(i==0 || listado[i]<menor)
        {
            menor=listado[i];
        }
    }
    return menor;
}

/** \brief funcion utilizada para mostrar la nota maxima.
 *
 * \param utilizamos un for para para pasar por lo diferentes elementos del array.
 * \param con el if nos aseguramos que en la variable mayor se asigne el valor del elemento del array mas grande.
 * \return mayor.
 *
 */

int array_notaMaxima(int listado[], int tamanio)
{
    int mayor,i;
    for(i=0;i<tamanio;i++)
    {
        if(i==0 || listado[i]>mayor)
        {
            mayor=listado[i];
        }
    }
    return mayor;
}

/** \brief funcion utilizada para mostrar la nota minima.
 *
 * \param utilizamos un for para para pasar por lo diferentes elementos del array.
 * \param con el if calculamos que el cociente del valor de array divido 2 sea 0 si el caso la variable
 * \param cantidadDePares aumenta.
 * \return cantidadDePares.
 *
 */

int array_retornarCantidadPares(int listado[], int tamanio)
{
    int cantidadDePares=0;
    int i;
    for(i=0;i<tamanio;i++)
    {
        if(listado[i]%2==0)
        {
         cantidadDePares++;
        }
    }
    return cantidadDePares;
}

/** \brief funcion utilizada para mostrar la nota minima.
 *
 * \param utilizamos un for para para pasar por lo diferentes elementos del array.
 * \param con el if calculamos que este entre entre los limites que podremos cambiar.
 * \param cantidadEntreNotas aumenta.
 * \return cantidadEntreNotas.
 *
 */

int array_retornarCantidadEntreNotas(int listado[], int tamanio, int limiteInferior, int limiteSuperior)
{
    int i;
    int cantidadEntreNotas=0;
    for(i=0;i<tamanio;i++)
    {
        if(listado[i]>=limiteInferior && listado[i]<=limiteSuperior)
        {
            cantidadEntreNotas++;
        }
    }
    return cantidadEntreNotas;
}

/** \brief Muestra los el valor y la posicion en el array.
 *
 * \param utilizamos un for para pasar por los diferentes elementos del array.
 * \param printf para mostrar el indice y el valor del array.
 * \return 0 si esta bien.
 *
 */

int array_mostrar(int* pArray, int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        printf("\nIndice: %d - Valor: %d - Direccion de memoria: %p",i,pArray[i],&pArray[i]);

    }
    return 0;
}

/** \brief Calcula el maximo valor del array.
 *
 * \param
 * \param
 * \return
 *
 */

int array_calcularMaximo(int* pArray, int limite, int* pMaximo)
{
    int retorno=-1;
    int i;

    int maximo;
    int flagPrimerMaximo = false;

    if(pArray != NULL && limite > 0)
    {

        for(i=0;i<limite;i++)
        {
            if(pArray[i] != DATO_INVALIDO)
            {
                if(flagPrimerMaximo == false)
                {
                    maximo = pArray[i];
                    flagPrimerMaximo = true;
                }
                else if(pArray[i] > maximo)
                {
                    maximo = pArray[i];
                }
            }
        }

        if(flagPrimerMaximo == 0)
        {
            retorno = -2;
        }
        else
        {
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief  Pasa un valor entero de una variable a un array.
 *
 * \param utilizamos el if comprobar que el array no este vacio y que el limite sea mayor a 0.
 * \param con un for pasamos por los elementos del array. La variabe limite indica la cantidad de elementos en el array.
 * \param se asignara el valor de la variable del tipo int valor a todos los elementos del array.
 * \return
 *
 */

int array_ingresarELmismoValorAlArray(int* pArray, int limite, int valor)
{
    int retorno=-1;
    int i;
    if(pArray != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            pArray[i] = valor;
        }
        retorno = 0;
    }
    return retorno;
}

int array_minimoDesde(  int* pArray, int limite,
                        int desde, int* pMinimo)
{
    int retorno=-1;
    int i;
    int auxiliarValorMinimo;
    int auxiliarIndiceMinimo;

    if(pArray != NULL && limite > 0 && limite >= desde && pMinimo != NULL)
    {
        for(i=desde;i<limite;i++)
        {
            if(i == desde || pArray[i] < auxiliarValorMinimo)
            {
                auxiliarValorMinimo  = pArray[i];
                auxiliarIndiceMinimo = i;
            }
        }
        *pMinimo = auxiliarIndiceMinimo;
        retorno = 0;
    }
    return retorno;
}

void array_swap(int* elementoA,int* elementoB)
{
    int auxiliar;
    auxiliar = *elementoA;
    *elementoA = *elementoB;
    *elementoB = auxiliar;
}

void array_ordenarPorInsercion(int array[], int size)
{
	int i,j,auxiliar;

	for(i = 1; i < size; i++) {
		auxiliar = array[i];
		j = i;
		while(j > 0 && auxiliar < array[j - 1]) {
			array[j] = array[j - 1];
			j--;
		}
		array[j] = auxiliar;
	}
}


void array_ordenarPorBurbujeo(int array[], int size)
{
    int i,auxiliar,s = 1;

    while(s)
    {
        s = 0;
        for (i = 1; i < size; i++)
        {
            if (array[i] < array[i - 1])
            {
                auxiliar = array[i];
                array[i] = array[i - 1];
                array[i - 1] = auxiliar;
                s = 1;
            }
        }
    }
}

int array_minimoDesde(int array[], int size)
{
    int indice=1;
    int minimo = array[0];
    int indiceMinimo = 0;
    for ( ;indice < size; indice++)
    {
       if(array[indice] < minimo)
       {
           minimo = array[indice];
           indiceMinimo = indice;
       }

    }
    return indiceMinimo;
}

static int validacionInt(char* array)
{
    int retorno=-1;
    int i=0;
    while(array!=NULL)
    {
        if(array[i]<'0' || array[i]>'9')
        {
            break;
        }
        i++;
        if(array[i]=='\0')
        {
            retorno=1;
        }
    }
    return retorno;
}

/**
* \brief Solicita un numero al usuario y devuelve el resultado
* \param pResultado Puntero a la variable resultado
* \param mensaje Es el mensaje a ser mostrado
* \param mensajeError Es el mansaje a ser mostrador en caso de error
* \param minimo Es el numero minimo aceptado
* \param maximo Es el numero aceptado
* \param reintentos Es la cantidad de reintentos que tiene el usuario.
* \return En caso de exito retorna 0 y en caso de error -1
*/

int utn_getNumeroPorString(  int  * pResultado,    //dejar el resultado
                    char mensaje[],       //mensaje para ingresar
                    char mensajeError[],  //mensaje de error
                    int minimo,           //limite minimo
                    int maximo,           //limite maximo
                    int reintentos )      //cantidad de intentos
{
    int pedirNumero;
    printf("%s",mensaje);
    int i;
    for(i=0;i<reintentos;i++)
    {
        if(getInt(&pedirNumero)==0)
        {  //Porque el Scan te tiene que devolver 1 valor si es un numero si es una letra sera 0. Porque la mascara "%d" es para entero no caracteres.
            if(pedirNumero>minimo && pedirNumero<maximo)
            {
                *pResultado = pedirNumero;
                return 0;
            }
        }
        printf("%s",mensajeError);
    }
    return -1;
}

static int ValidacionFloat(char array[])
{
    int i=0;
    while(array[i]!='\0')
    {
        if(array[i]!='.' || array[i]<'0' || array[i]>'9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

static int getFloat(float* pResultado)
{
        char buffer[4];
        int retorno=-1;

        __fpurge(stdin);
        scanf("%s",buffer);
        if(ValidacionFloat(buffer))
        {
           *pResultado = atof(buffer);
           retorno=0;
        }
        return retorno;
}

int utn_getFLoatPorString(  float  * pResultado,    //dejar el resultado
                    char mensaje[],       //mensaje para ingresar
                    char mensajeError[],  //mensaje de error
                    float minimo,           //limite minimo
                    float maximo,           //limite maximo
                    int reintentos )      //cantidad de intentos
{
    float pedirNumero;
    printf("%s",mensaje);
    int i;
    for(i=0;i<reintentos;i++)
    {
        if(getFloat(&pedirNumero)==0)
        {  //Porque el Scan te tiene que devolver 1 valor si es un numero si es una letra sera 0. Porque la mascara "%d" es para entero no caracteres.
            if(pedirNumero>minimo && pedirNumero<maximo)
            {
                *pResultado = pedirNumero;
                return 0;
            }
        }
        printf("%s",mensajeError);
    }
    return -1;
}

static int getInt(int* pResultado)
{
        char buffer[8];
        int retorno=-1;

        __fpurge(stdin);
        scanf("%s",buffer);
        if(validacionInt(buffer))
        {
           *pResultado = atoi(buffer);
           retorno=0;
        }
        return retorno;
}
