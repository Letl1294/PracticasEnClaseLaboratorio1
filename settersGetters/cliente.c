#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Cliente* cliente_new()
{
    Cliente* this; //crear un puntero a cliente
    this=malloc(sizeof(Cliente));//asigna una posicion de memoria para trabajar y la asgina a this.
    return this; //posicion de memoria
}

void cliente_delete(Cliente* this)
{
    free(this);
}

Cliente* cliente_newConParametros(char* name,char* lastName,int clienteId,int isEmpty)
{
    Cliente* this;
    this=cliente_new();

    if(
    !cliente_setName(this,name)&&
    !cliente_setLastName(this,lastName)&&
    !cliente_setClienteId(this,clienteId)&&
    !cliente_setIsEmpty(this,isEmpty))
        return this;

    cliente_delete(this);
    return NULL;
}

int cliente_setName(Cliente* this,char* name)
{
    int retorno=-1;
    if(this!=NULL && name!=NULL)
    {
        strcpy(this->name,name);
        retorno=0;
    }
    return retorno;
}

int cliente_getName(Cliente* this,char* name)
{
    int retorno=-1;
    if(this!=NULL && name!=NULL)
    {
        strcpy(name,this->name);
        retorno=0;
    }
    return retorno;
}

int cliente_setLastName(Cliente* this,char* lastName)
{
    int retorno=-1;
    if(this!=NULL && lastName!=NULL)
    {
        strcpy(this->lastName,lastName);
        retorno=0;
    }
    return retorno;
}

int cliente_getLastName(Cliente* this,char* lastName)
{
    int retorno=-1;
    if(this!=NULL && lastName!=NULL)
    {
        strcpy(lastName,this->lastName);
        retorno=0;
    }
    return retorno;
}

int cliente_setClienteId(Cliente* this,int clienteId)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->clienteId=clienteId;
        retorno=0;
    }
    return retorno;
}

int cliente_getClienteId(Cliente* this,int* clienteId)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *clienteId=this->clienteId;
        retorno=0;
    }
    return retorno;
}

int cliente_setIsEmpty(Cliente* this,int isEmpty)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->isEmpty=isEmpty;
        retorno=0;
    }
    return retorno;
}

int cliente_getIsEmpty(Cliente* this,int* isEmpty)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *isEmpty=this->isEmpty;
        retorno=0;
    }
    return retorno;
}
