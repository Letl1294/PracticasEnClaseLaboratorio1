#include "LinkedList.h"
#include "Compra.h"
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int parser_parseCompras(char* fileName, LinkedList* lista)
{
    char nombreCliente[LEN];
    char idProducto[LEN];
    char precioUnitario[LEN];
    char unidades[LEN];
    char iva[LEN];
    int retorno = -1;
    int flagOnce = 1;
    Compra* pCompra;
    FILE* Pfile;
    Pfile = fopen(fileName,"r");

    if(Pfile!= NULL)
    {
        while(!feof(Pfile))
        {
            if(flagOnce)
            {
               flagOnce = 0;
               fscanf(Pfile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                                                nombreCliente,
                                                idProducto,
                                                precioUnitario,
                                                unidades,
                                                iva);
            }
            fscanf(Pfile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                                                nombreCliente,
                                                idProducto,
                                                precioUnitario,
                                                unidades,
                                                iva);

            pCompra = compra_newConParametros(nombreCliente,
                                                idProducto,
                                                precioUnitario,
                                                unidades,
                                                iva);
            if(pCompra != NULL)
            {
                retorno = 0;
                ll_add(lista,pCompra);
            }
        }
    }
    return retorno;
}

