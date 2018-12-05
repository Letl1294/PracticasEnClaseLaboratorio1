#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Contratacion.h"
#include "utn.h"
#include "pantalla.h"


int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit)
{
    int retorno = -1;

    return retorno;
}



int informar_ListarContrataciones(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;

    return retorno;
}


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;
    return retorno;
}

// F.Todas las contrataciones cuya cantidad de dias es menor o igual a 10,
// indicando nombre de la pantalla contratada, precio unitario, dias y precio total de la contratacion.

int informar_ContraMen10Dias(Pantalla* arrayUno,Contratacion* arrayDos,int limiteUno, int limiteDos)
{
    int i;
    int idPantalla;
    Pantalla* pantallaSeleccionada;
    double precioTotal=0;

    for(i=0;i<limiteDos;i++)
    {
        if(arrayDos[i].isEmpty==0 && arrayDos[i].dias<= 10)
        {
            printf("CHILE");
            idPantalla = arrayDos[i].idPantalla;
            pantallaSeleccionada = pantalla_getByID(arrayUno,limiteUno,idPantalla);
            precioTotal = pantallaSeleccionada->precio * arrayDos[i].dias;
        }
    }
    printf("Pantalla contratada: %s -Precio unitario: %f -Dias: %d  -Precio total: %f",pantallaSeleccionada->nombre,pantallaSeleccionada->precio,arrayDos[i].dias,precioTotal);

return 0;
}
