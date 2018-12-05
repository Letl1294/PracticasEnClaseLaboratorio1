#include <stdio_ext.h>
#include <stdlib.h>
#define CANTIDAD 5

int retornarTotal(int listado[],int tamanio);
int retornarPromedio(int listado[],int tamanio);
int cargarListado(int listado[],int tamanio);
int mostrarListado(int listado[],int tamanio);
int notaMinima(int listado[], int tamanio);
int notaMaxima(int listado[], int tamanio);
int retornarCantidadEntreNotas(int listado[],int tamanio, int limInferior,int limSuperior);
int retornarCantidadPares(int listado[], int tamanio);
void mostrarInformacionDelArray(int listado[],int tamanio);

int main()
{
    int listadoDeNotas[CANTIDAD];
    cargarListado(listadoDeNotas,CANTIDAD);
    mostrarListado(listadoDeNotas,CANTIDAD);
    mostrarInformacionDelArray(listadoDeNotas,CANTIDAD);
    return 0;
}
/*brief
    a- el mayor.
    b- el menor.
    c- cantidad de pares.
    d- suma total.
    e- promedio
*/
void mostrarInformacionDelArray(int listado[],int tamanio)
{
    int mayor;
    int menor;
    int sumaTotal;
    int promedio;
    int cantidadDePares;
    int aprobados;
    int aFinal;
    int desaprobados;

    mayor=notaMaxima(listado,tamanio);
    menor=notaMinima(listado,tamanio);
    sumaTotal=retornarTotal(listado,tamanio);
    promedio=retornarPromedio(listado,tamanio);
    cantidadDePares=retornarCantidadPares(listado,tamanio);
    aprobados=retornarCantidadEntreNotas(listado,tamanio,6,10);
    aFinal=retornarCantidadEntreNotas(listado,tamanio,4,5);
    desaprobados=retornarCantidadEntreNotas(listado,tamanio,0,3);

    printf("\n\nLa mayor nota es: %d",mayor);
    printf("\n\nLa menor nota es: %d",menor);
    printf("\n\nLa cantidad de pares es: %d",cantidadDePares);
    printf("\n\nLa suma total de las notas es: %d",sumaTotal);
    printf("\n\nEl promedio de las notas es: %d",promedio);
    printf("\n\nLa cantidad de aprobados es: %d",aprobados);
    printf("\n\nLa cantidad de gente a final es: %d",aFinal);
    printf("\n\nLa cantidad de desaprobados es: %d\n",desaprobados);
}

int retornarTotal(int listado[], int tamanio)
{
    int sumaDeNotas=0;
    int i;

        for(i=0;i<tamanio;i++)
        {
            sumaDeNotas=sumaDeNotas+listado[i];
        }
    return sumaDeNotas;
}

int retornarPromedio(int listado[],int tamanio)
{
    int suma;
    int promedio;
    suma=retornarTotal(listado,tamanio);
    promedio=suma/tamanio;
    return promedio;
}

int mostrarListado(int listado[], int tamanio)
{
    int i;
    for(i=0;i<tamanio;i++)
    {
       printf("\n\nLa nota n°%d es: %d",i+1,listado[i]);
    }
    return 0;
}

int cargarListado(int listado[], int tamanio)
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

int notaMinima(int listado[], int tamanio)
{
    int menor,i;
    for(i=0;i<CANTIDAD;i++)
    {
        if(i==0 || listado[i]<menor)
        {
            menor=listado[i];
        }
    }
    return menor;
}

int notaMaxima(int listado[], int tamanio)
{
    int mayor,i;
    for(i=0;i<CANTIDAD;i++)
    {
        if(i==0 || listado[i]>mayor)
        {
            mayor=listado[i];
        }
    }
    return mayor;
}

int retornarCantidadPares(int listado[], int tamanio)
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

int retornarCantidadEntreNotas(int listado[], int tamanio, int limiteInferior, int limiteSuperior)
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
/*
    printf("tamaño: %d",sizeof(numeroIngresado)); //Para mosstrar lo que ocupa en memoria la variable.
    printf("\ntamaño: %d",sizeof(listadoDeNotas)); //Para mosstrar lo que ocupa en memoria el array.
    printf("\ndireccion: %d",&numeroIngresado); //Para mostrar direecion de memoria.
    printf("\ndireccion: %d",listadoDeNotas); //Para mostrar la direccion de memoria de un array no hace falta "&".
*/
